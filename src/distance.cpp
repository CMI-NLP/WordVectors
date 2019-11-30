/*
 * File: distance.cpp
 * Project: src
 * Created Date: Friday, November 29th 2019, 6:12:26 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 7:06:29 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <armadillo>
#include <algorithm>

#include "../include/distance.hpp"
using namespace nlp;

distance::distance(std::string wvm_filename, std::string vocab_filename,
                   std::string target_word, nlp::wv_models wv_model, int distance_measure)
{
    this->wvm_filename = wvm_filename;
    this->vocab_filename = vocab_filename;
    this->target_word = target_word;

    if (distance_measure == nlp::COSINE_DISTANCE)
    {
        if (wv_model == nlp::HAL)
            cosine_hal();
        else
            cosine();
    }
}

distance::~distance()
{
}

void distance::cosine()
{
    std::ifstream inf;
    inf.open(this->vocab_filename);
    std::string key;
    std::map<std::string, int> vocab_map;
    unsigned long i = 0;
    while (!inf.eof())
    {
        inf >> key;
        vocab_map[key] = i++;
    }

    uint count = vocab_map.count(this->target_word);
    if (!count)
    {
        std::cerr << this->target_word << " not found in the vocabulary. Use a different word" << std::endl;
        exit(1);
    }
    std::vector<std::pair<double, std::string>> dist;

    arma::mat matrix;
    matrix.load(this->wvm_filename);
    matrix = matrix.t();
    arma::vec target(matrix.n_cols);
    target = matrix.col(vocab_map[this->target_word]); //மொழிகள்  ஊர் கணிதம் xகண்ணன்x கணினி கணினி
    //target = target.t();
    std::ofstream out;
    out.open(this->target_word + ".txt");
    out << "Distance,Word" << std::endl;
    i = 0;
    for (auto &v : vocab_map)
    {
        //vec a = hal_matrix.col(i++);
        if (i < matrix.n_cols)
        {
            //double distance = 1.0 - (arma::dot(target, matrix.col(i)) / (arma::norm(target, 2) * arma::norm(matrix.col(i), 2)));
            double distance = 1.0 - arma::norm_dot(target, matrix.col(i));
            i++;
            //std::cout << distance << " " << v.first << endl;
            dist.push_back(make_pair(distance, v.first));
        }
    }
    sort(dist.begin(), dist.end());
    for (auto &k : dist)
        out << k.first << "," << k.second << std::endl;
}

void distance::cosine_hal()
{
    std::ifstream inf;
    inf.open(this->vocab_filename);
    std::string key;
    std::map<std::string, int> vocab_map;
    unsigned long i = 0;
    while (!inf.eof())
    {
        inf >> key;
        vocab_map[key] = i++;
    }

    uint count = vocab_map.count(this->target_word);
    if (!count)
    {
        std::cerr << this->target_word << " not found in the vocabulary. Use a different word" << std::endl;
        exit(1);
    }
    std::vector<std::pair<double, std::string>> dist;

    arma::sp_mat matrix(vocab_map.size(), vocab_map.size());
    matrix.load(this->wvm_filename);
    arma::vec target(matrix.n_rows);

    //hal_matrix = hal_matrix.t();
    target = matrix.col(vocab_map[this->target_word]); //மொழிகள்  ஊர் கணிதம் xகண்ணன்x கணினி கணினி
    std::ofstream out;
    out.open(this->target_word + ".txt");
    out << "Distance,Word" << std::endl;
    i = 0;
    for (auto &v : vocab_map)
    {
        //vec a = hal_matrix.col(i++);
        if (i < matrix.n_cols)
        {
            double distance = 1.0 - (arma::dot(target, matrix.col(i)) / (arma::norm(target, 2) * arma::norm(matrix.col(i), 2)));
            i++;
            //std::cout << distance << " " << v.first << endl;
            dist.push_back(make_pair(distance, v.first));
        }
    }
    sort(dist.begin(), dist.end());
    for (auto &k : dist)
        out << k.first << "," << k.second << std::endl;
}
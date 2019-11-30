/*
 * File: vocabulary.cpp
 * Project: src
 * Created Date: Thursday, November 28th 2019, 8:12:37 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 5:00:55 am
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */



#include "../include/vocabulary.hpp"
#include "../include/dictionary.hpp"

#include <map>
#include <algorithm>
#include <fstream>
using namespace nlp;

vocabulary::vocabulary()
{
}

vocabulary::vocabulary(std::vector<std::string> tokens, int cutoff) 
{
    _build(tokens, cutoff);
}

vocabulary::~vocabulary() {
    vocab.erase(vocab.begin(), vocab.end());
    vocab.clear();
}

void vocabulary::_build(std::vector<std::string> tokens, int cutoff)
{
    nlp::dictionary dict;
    std::map<std::string, int> freqdist = dict.freq_dist(tokens);
    dict.write(std::string("dict.txt"));
    for (auto &kvp : freqdist)
    {
        if (kvp.second >= cutoff)
            vocab.emplace_back(kvp.first);
    }
    std::sort(vocab.begin(), vocab.end());
    save("vocabulary.txt");
}

/*
std::vector<std::string> vocabulary::build(std::vector<std::string> tokens, int cutoff)
{
    _build(tokens,cutoff);    
    return vocab;
}
*/

std::vector<std::string> vocabulary::get()
{
    return vocab;
}

void vocabulary::save(std::string filename)
{
    std::ofstream out;
    out.open(filename);
    for (auto i : vocab)
        out << i << std::endl;
    out.close();
}
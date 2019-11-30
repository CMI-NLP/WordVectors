/*
 * File: main.cpp
 * Project: src
 * Created Date: Tuesday, November 26th 2019, 8:27:58 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 7:32:08 pm
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
#include "../include/dictionary.hpp"
#include <iostream>
#include "../include/corpus.hpp"
#include "../include/vocabulary.hpp"
#include "../include/ngrams.hpp"
#include "../include/hal.hpp"
#include "distance.hpp"
#include "svd.hpp"

int main(int argc, char** argv)
{
    //nlp::dictionary dict;
    //nlp::corpus corpus("/home/ramaseshan/Documents/NLP/TaCorpus/ta_100_tokens.txt");
    //nlp::read_corpus read("/home/ramaseshan/word2vec-master/data/text8.en");
    //std::vector<std::string> tokens = corpus.get_tokens(0,0);

    //dict.freq_dist(tokens,2);

    //for (auto it:dict.tf_p)
    //std::cout << it.first << " " << it.second << std::endl;*/
    //std::cout << "Number of tokens = " << corpus.ntokens() << std::endl;
    //nlp::vocabulary v (tokens,100);
    //std::vector<std::string> vocab = v.build();
    //v.save("vocabulary.txt");
    //nlp::ngrams ngms;
    //std::vector<std::vector<std::string>> trigrams = ngms.extract(7,tokens,true);
    /*     for (auto &i: trigrams){
        std::cout << "(";
        for (auto j: i)
	        std::cout << j << " ";
        std::cout << ")" << std::endl;

    } */
    //wove::hal hal ("/home/ramaseshan/Documents/NLP/TaCorpus/ta_1000000_tokens.txt");
    //nlp::svd svd("hal_matrix.bin");
    nlp::distance dist("svd_hal_matrix.bin", "vocabulary.txt", argv[1],
                                     nlp::OTHERS,nlp::COSINE_DISTANCE);
    return 1;
}
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
	//pass  the location of the corpus - one single file
	//This will output 3 files 
	//dict.txt - frequency distribution of words of the corpus
	//vocabulary.txt - vocabulary of the corpus
	//hal_matrix.bin - Armadillo matrix of word vectors in binary form
	//wove::hal hal ("/home/ramaseshan/Documents/NLP/TaCorpus/ta_1000000_tokens.txt");
    	//To find the word vectors use the distance class
	nlp::distance dist("hal_matrix.bin", "vocabulary.txt", argv[1],
                                     nlp::HAL,nlp::COSINE_DISTANCE);
	//create left and singular matrices and singular values. 
	//Use the left singular values as word vectors. Pass the hal word vector file as argument.
	//This will create a word vector matrix from the left singular values
	//nlp::svd("hal_matrix.bin");
    	//nlp::distance dist("svd_hal_matrix.bin", "vocabulary.txt", argv[1],
        //                             nlp::OTHERS,nlp::COSINE_DISTANCE);
    return 1;
}

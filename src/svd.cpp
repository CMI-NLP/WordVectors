/*
 * File: svd.cpp
 * Project: src
 * Created Date: Saturday, November 30th 2019, 6:55:14 am
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 7:15:56 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#include "svd.hpp"
using namespace nlp;

svd::svd(std::string filename)
{

    this->filename = filename;
    arma::sp_mat wv_mat;
    wv_mat.load(filename);
    arma::mat U;
    arma::vec s;
    arma::mat V;
    arma::svds(U, s, V, wv_mat, 100);
    U.save("svd_"+ filename);   
}

svd::~svd()
{
}

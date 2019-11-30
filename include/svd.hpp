/*
 * File: svd.hpp
 * Project: include
 * Created Date: Saturday, November 30th 2019, 6:55:15 am
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 9:18:02 am
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */



#ifndef __SVD_H__
#define __SVD_H__
#include <string>
#include <armadillo>

namespace nlp{
class svd {
protected:
std::string filename;
public:
    svd(std::string cooccur_filename);
    ~svd();
    void decompose(arma::mat matrix);
};
}
#endif //__SVD_H__
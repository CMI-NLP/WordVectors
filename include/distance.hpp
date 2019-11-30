/*
 * File: distance.hpp
 * Project: include
 * Created Date: Friday, November 29th 2019, 6:12:27 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 11:37:29 am
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#ifndef __DISTANCE_HPP__
#define __DISTANCE_HPP__
#include <string>
#include "constants.hpp"

namespace nlp
{
class distance
{
protected:
    std::string wvm_filename;
    std::string vocab_filename;
    std::string target_word;
    void cosine_hal();
    void cosine();

public:
    distance(std::string wvm_filename, std::string vocab_filename, std::string target_word,
             nlp::wv_models wv_model, int measure = nlp::COSINE_DISTANCE);
    ~distance();
    void save(std::string output_filename);
};
} // namespace nlp
#endif // !__DISTANCE_HPP__

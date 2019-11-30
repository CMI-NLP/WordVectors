/*
 * File: vocabulary.hpp
 * Project: include
 * Created Date: Thursday, November 28th 2019, 8:12:38 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 5:00:42 am
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#ifndef __VOCABULARY__HPP__
#define __VOCABULARY__HPP__
#include <vector>
#include <string>
namespace nlp
{
class vocabulary
{
protected:
    std::vector<std::string> vocab;
    void _build(std::vector<std::string> tokens, int cutoff);

public:
    vocabulary();
    ~vocabulary();
    vocabulary(std::vector<std::string> tokens, int cutoff);
    //std::vector<std::string> build(std::vector<std::string> tokens, int cutoff);
    std::vector<std::string> get();
    void save(std::string filename);
};
} // namespace nlp
#endif // !__VOCABULARY__HPP__
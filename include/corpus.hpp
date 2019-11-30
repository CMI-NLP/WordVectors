/*
 * File: corpus.hpp
 * Project: include
 * Created Date: Wednesday, November 27th 2019, 6:40:38 am
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Friday, 29th November 2019 3:12:02 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#ifndef __CORPUS__HPP__
#define __CORPUS__HPP__
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace nlp
{
class corpus
{
    protected:
    std::ifstream in;
    ulong number_of_tokens;
    std::string filename;

public:
    std::vector<std::string> get_tokens(ulong seek_position, ulong ntokens_to_read);
    //ulong seek_position() const;
    ulong seek_position;
    ulong ntokens() const;
    corpus(std::string filename);
    ~corpus();

};
} // namespace nlp
#endif //__CORPUS__HPP__
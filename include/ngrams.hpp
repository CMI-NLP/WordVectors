/*
 * File: ngrams.hpp
 * Project: include
 * Created Date: Thursday, November 28th 2019, 11:21:49 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Friday, 29th November 2019 12:08:10 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#ifndef __NGRAMS_HPP__

#define __NGRAMS_HPP__
#include <vector>
#include <string>

namespace nlp{
class ngrams {
protected:
    std::vector<std::vector<std::string>> _extract(int n, std::vector<std::string> const &v);

public:
    ngrams();
    ~ngrams();
    std::vector<std::vector<std::string>> extract(int n, std::vector<std::string> const &v, bool padding=false);
};
}
#endif // !__NGRAMS_HPP__

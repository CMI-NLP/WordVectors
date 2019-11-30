/*
 * File: ngrams.cpp
 * Project: src
 * Created Date: Thursday, November 28th 2019, 11:21:48 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Friday, 29th November 2019 12:27:31 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#include "../include/ngrams.hpp"
#include <list>
#include <algorithm>

using namespace nlp;

ngrams::ngrams()
{
}

ngrams::~ngrams()
{
}

std::vector<std::vector<std::string>> ngrams::_extract(int n, std::vector<std::string> const &v)
{
    std::vector<std::vector<std::string>> ngrams_array;
    std::vector<std::string> vec;
    auto first = v.begin();
    auto last = v.end();
    for (auto i = first; i < (last - n+1); i++)
    {
            vec.assign(i, i + n);
            ngrams_array.push_back(vec);
    }
    return ngrams_array;
}

std::vector<std::vector<std::string>> ngrams::extract(int n, std::vector<std::string> const &v,bool padding)
{
    std::vector<std::string> dest;
    if ( !padding )
        return _extract(n,v);
    else
    {
        //insert markers
        for (int i= 0; i < n-1; i++)
            dest.push_back(std::string("<S>"));
        std::move(v.begin(), v.end(), std::back_inserter(dest));
        for (int i= 0; i < n-1; i++)
            dest.push_back(std::string("<S>"));
    }  
    return _extract(n,dest);  
}

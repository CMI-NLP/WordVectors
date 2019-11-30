/*
 * File: dictionary.cpp
 * Project: src
 * Created Date: Tuesday, November 26th 2019, 8:28:40 pm
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Friday, 29th November 2019 12:57:13 pm
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#include "../include/dictionary.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace nlp;

dictionary::dictionary()
{
}

dictionary::~dictionary()
{
    //std::cerr << "clearning tf_p" << std::endl;
    tf_p.erase(tf_p.begin(), tf_p.end());
}

void dictionary::add(nlp::tf_pair tfp)
{
    auto it = tf_p.find(tfp.first);
    if (it == tf_p.end())
    {
        tf_p.insert(tfp);
    }
    else
    {
        it->second += 1;
    }
}

std::map<std::string, int> dictionary::freq_dist(std::vector<std::string> tokens)
{
    for (auto token : tokens)
    {
        nlp::tf_pair tfp(token, 1);
        add(tfp);
    }

    std::map<std::string, int> ordered_map(tf_p.begin(), tf_p.end());
    return ordered_map;
}

bool dictionary::find(nlp::tf_pair tfp)
{
    auto it = tf_p.find(tfp.first);
    if (it == tf_p.end())
    {
        return false;
    }
    return true;
}

/*
std::map<std::string, ulong> dictionary::freq_dist(std::vector<std::string> const &t, int cut_off)
{
    std::map<std::string, ulong> tokens;
    std::string chars = ",()#!?\"\'.";
    std::string next_token;
    std::vector<std::string> copy_tokens(t);

    for (auto i : copy_tokens)
    {
        ++tokens[i];
    }

    auto it = tokens.begin();

    while (it != tokens.end())
    {
        // Check if value of this entry matches with given value
        if (it->second < cut_off)
        {
            // Erase the current element, erase() will return the
            // next iterator. So, don't need to increment
            it = tokens.erase(it);
        }
        else
        {
            // Go to next entry in map
            it++;
        }
    }

    typedef std::function<bool(std::pair<std::string, ulong>, std::pair<std::string, ulong>)> Comparator;

    Comparator sort_by_value =
        [](std::pair<std::string, ulong> elem1, std::pair<std::string, ulong> elem2) {
            return elem1.second > elem2.second;
        };
    std::vector<std::pair<std::string, ulong>> v(tokens.begin(), tokens.end());
    std::sort(v.begin(), v.end(), sort_by_value);
    return tokens;
}
*/


void dictionary::write(std::string filename)
{
    std::ofstream out;
    out.open(filename);
    for (auto i : tf_p)
        out << i.first << "," << i.second << std::endl;
    out.close();
}
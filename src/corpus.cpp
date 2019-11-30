/*
 * File: corpus.cpp
 * Project: src
 * Created Date: Wednesday, November 27th 2019, 6:40:37 am
 * Author: Ramaseshan Ramachandran
 * -----
 * Last Modified: Saturday, 30th November 2019 5:19:22 am
 * Modified By: Ramaseshan Ramachandran
 * -----
 * Copyright (c) 2019 JCR Labz
 * blah
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#include "corpus.hpp"
#include <regex>
#include <climits>

using namespace nlp;

corpus::corpus(std::string filename)
{
    this->filename = filename;
    this->number_of_tokens = 10000;
    this->seek_position = 0;
    //this->in.open(this->filename);
}

corpus::~corpus()
{
    if (this->in.is_open())
        this->in.close();
}

std::vector<std::string> corpus::get_tokens(ulong seek_position, ulong ntokens_to_read)
{
    std::string next_token;
    ulong count = 0;
    std::vector<std::string> tokens;

    ulong j = 0;
    //std::string chars = ",()#!?\"\'.=0123456789<>";
    std::string chars = ",()#!?\"\'.";

    if (seek_position == 0 && ntokens_to_read == 0)
    {
        this->seek_position = 0;
        count = LONG_MAX;
    }
    else
    {
        count = ntokens_to_read;
    }

    //this->in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        this->in.open(this->filename);
        this->in.seekg(seek_position);

        while (j < count && this->in >> next_token && !this->in.eof())
        {
            j++;
            next_token.erase(
                remove_if(next_token.begin(), next_token.end(),
                          [&chars](const char &c) {
                              return chars.find(c) != std::string::npos;
                          }),
                next_token.end());
            tokens.push_back(next_token);
            if ((j % 10000) == 0)
                std::cerr << "\r" << j << " Tokens processed";
        }
    }
    catch (std::ifstream::failure &e)
    {
        std::cerr << "Exception opening/reading/closing file\n";
    }
    if (!this->in.eof()){
        this->seek_position = this->in.tellg();
        this->number_of_tokens = j;
    }
    else {
        this->number_of_tokens = j;
    }
    in.close();

    return tokens;
}

/*
ulong corpus::seek_position() const
{
    return this->seek_position;
}
*/

ulong corpus::ntokens() const
{
    return this->number_of_tokens;
}

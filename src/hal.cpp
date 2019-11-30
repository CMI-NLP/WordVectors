#include "../include/hal.hpp"
#include <armadillo>
#include <map>
#include "../include/corpus.hpp"
#include "../include/constants.hpp"
#include "../include/vocabulary.hpp"

using namespace wove;

hal::hal(std::string corpus_name)
{
	this->corpus_name = corpus_name;
	nlp::corpus corpus(this->corpus_name);
	std::vector<std::string> tokens = corpus.get_tokens(0,0);
    nlp::vocabulary vocabulary (tokens,50);
	std::vector<std::string> vocab;
	vocab = vocabulary.get();
	word_vectors(tokens,vocab, true);
}

hal::~hal()
{
}

void hal::word_vectors(std::vector<std::string> tokens, std::vector<std::string> vocab, bool save)
{
	int size = tokens.size();
	int repeat_reading = 1;
	arma::sp_mat hal_matrix(vocab.size(),vocab.size());

	nlp::corpus corpus(this->corpus_name);
	corpus.seek_position = 0;

	if ( size > nlp::TOKENS_TO_READ )
		repeat_reading = size/nlp::TOKENS_TO_READ;


	for (int i = 0; i < repeat_reading; i++)
        {
            std::vector<std::string> partial_tokens = corpus.get_tokens(corpus.seek_position, nlp::TOKENS_TO_READ);
            if (i % 1000 == 0)
                std::cerr << "read = " << partial_tokens.size() << std::endl;
            hal_matrix += build_hal(partial_tokens, vocab, false);
        }
        std::cerr << "Completed l2r" << std::endl;

        corpus.seek_position = 0;

        for (long long i = 0; i < repeat_reading; i++)
        {
            std::vector<std::string> partial_tokens = corpus.get_tokens(corpus.seek_position, nlp::TOKENS_TO_READ);
            if (i % repeat_reading == 0)
                std::cerr << "count = " << partial_tokens.size() << std::endl;
            hal_matrix += build_hal(partial_tokens, vocab, true);
        }
        std::cerr << "Completed r2l" << std::endl;

        hal_matrix = hal_matrix / 2.0;
		if ( save )
			hal_matrix.save("hal_matrix.bin");
		else
		{
			arma::cout << hal_matrix;
		}
}


arma::sp_mat hal::build_hal(std::vector<std::string> tokens, std::vector<std::string> vocab, bool reverse_tokens)
{
	arma::sp_mat hal_matrix(vocab.size(), vocab.size());

	std::map<std::string, int> vocab_map;
	int i = 0;
	for (auto const &x : vocab)
	{
		vocab_map[x] = i++;
	}

	int gram_size = 11;

	std::vector<int> ramp;
	ramp.push_back(0);
	for (int i = gram_size - 1; i > 0; i--)
		ramp.push_back(i);

    std::vector<std::string> vec;
    auto first = tokens.begin();
    auto last = tokens.end();
    for (auto i = first; i < (last - gram_size+1); i++)
	{
		std::vector<std::string> grams;
		grams.assign(i, i + gram_size);

		if (reverse_tokens)
			reverse(grams.begin(), grams.end());

		long long m = 0;
		if (vocab_map.count(grams[0]))
		{
			m = vocab_map[grams[0]];
		}
		else
		{
			continue;
		}

		unsigned long k = 0;

		for (unsigned long j = 0; j < grams.size(); j++)
		{
			long n = 0;
			if (vocab_map.count(grams[j]) == 0)
			{
				continue;
			}
			else
			{
				n = vocab_map[grams[j]];
			}
			if ( ramp[k] > 0 ){
				hal_matrix(m, n) += ramp[k++];
			}
			else
				k++;
		}
	}

	return hal_matrix;
}
#ifndef __HAL_HPP__
#define __HAL_HPP__
#include <vector>
#include <string>
#include <algorithm>
#include <armadillo>

namespace wove
{
class hal
{
protected:
    std::string corpus_name;
public:
    hal(std::string corpus_name);
    ~hal();
    void word_vectors(std::vector<std::string> tokens, std::vector<std::string> vocab, bool save=true);
    void find_distance(std::string word);
    arma::sp_mat build_hal(std::vector<std::string>tokens, std::vector<std::string> vocab, bool reverse);
};
}
#endif // !__HAL_HPP__
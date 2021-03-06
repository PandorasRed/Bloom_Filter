#ifndef HASHKMER_HPP
#define HASHKMER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "readFastaFile.hpp"
uint64_t hashKmer(std::string kmer,const int len);
std::string deprecetiatedreverseComplement(std::string kmer, const int len);
std::string newkmer(std::string oldkmer,const int len,std::ifstream& fs);
std::string randomkmer(const int len);
std::string reverseComplement(std::string kmer, const int len);
std::string finishReverse(std::string kmer, const int len,std::string rev, int i);


#endif //HASHKMER_HPP
#ifndef HASHKMER_HPP
#define HASHKMER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "readFastaFile.hpp"
uint64_t hashKmer(std::string kmer,const int len);
std::string reverseComplement(std::string kmer, const int len);
std::string newkmer(std::string oldkmer,const int len,std::ifstream& fs);


#endif //HASHKMER_HPP
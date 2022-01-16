#ifndef HASHKMER_HPP
#define HASHKMER_HPP
#include <iostream>
#include <fstream>
#include <string>

uint64_t hashKmer(std::string kmer,const int len);
std::string reverseComplement(std::string kmer, const int len);


#endif //HASHKMER_HPP
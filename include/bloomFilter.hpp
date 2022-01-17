#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "hash.hpp"
class bloomFilter{
    private:
    uint64_t size;
    uint64_t nbf;
    uint8_t* bytesArray;
    public:
    bloomFilter(uint64_t newsize, u_int64_t nf);
    ~bloomFilter();
    void add_value(uint64_t x);
    void test();
    int is_present(uint64_t x);
};

#endif //BLOOM_FILTER_HPP
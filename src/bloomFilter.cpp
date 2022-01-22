#include <bloomFilter.hpp>
#include <bitset>
    /**
     * the constructor of the bloom filter, alocate and set the memory needed at 0
     * @param newsize the size of the bloom filter we want
     * @param nf the number of the hash function the bloom filter need to use
     * @return a new bloom filter
     */
    bloomFilter::bloomFilter(uint64_t newsize, unsigned int nf){
        bytesArray=new u_int8_t[(newsize/8)+1 ];
        for(uint64_t i=0;i<((newsize/8)+1);i++){
            bytesArray[i]=0;
        }
        nbf=nf;
        size=newsize;
    }
    //the destructor
    bloomFilter::~bloomFilter(){
        delete[] bytesArray;
    }
    /**
     * this function take a encoded kmer and enter it in the bloom filter
     * @param x the encoded kmer to enter
     * @return nothing
     */
    void  bloomFilter::add_value(uint64_t x){
        x++; // to be sure that 0 don't cause problem, just need to do the same for is_present
        uint64_t hashedCell[nbf];
        multihash(x,hashedCell,nbf,size-1);
        uint64_t tmp=0;
        int modtmp;
        for(unsigned int i=0;i<nbf;i++){
            tmp=hashedCell[i];
            modtmp=tmp%8;
            bytesArray[tmp/8]|=1<<(7-modtmp);
        }
    }
    /**
     * this function take a encoded kmer and check if it is in the bloom filter
     * @param x the endcoded kmer to test
     * @return 1 if present 0 otherwise
     */
    int bloomFilter::is_present(u_int64_t x){
        x++;
        uint64_t hashedCell[nbf];
        multihash(x,hashedCell,nbf,size-1);
        uint64_t tmp=0;
        int modtmp;
        for(unsigned int i=0;i<nbf;i++){
            tmp=hashedCell[i];
            modtmp=tmp%8;
            int b=(bytesArray[tmp/8]&(1<<(7-modtmp)));//read the bit we want;
            b=b>>(7-modtmp);//shift it to make it a 1 or a 0
            if(b!=1){ 
                return 0;
                }
            }
        return 1;
        }



    /**
     * a function to print the entierety of the bloom filter for debugging purpose;
     */
    void  bloomFilter::test(){
        for(unsigned int i=0;i<(size/8)+1;i++){
            std::cout << (std::bitset<8>) bytesArray[i] << '\n';
        }
    }



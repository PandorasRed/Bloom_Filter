#include <hashkmer.hpp>
/**
 * take a string reprensation of a kmer and return the hash of this kmer;
 * @param kmer string representation of a kmer
 * @param cursor the cursor to know where the first char is
 * @param len length of the kmer because its a const in the use we gonna do;
 * @return the hash of the kmer in param
 */
uint64_t hashkmer(std::string kmer, int cursor,const int len){
    int j=cursor;
    char a;
    uint64_t hashedkmer=0;
    //for qui lit correctement la string
    for(int i=(len-1)*2;i>=0;i-=2){
        a=kmer[j];
        j=(j+1)%len;
        switch(a){
            case 'C':
                hashedkmer=hashedkmer|1 << i;
                break;
            case 'T':
                hashedkmer=hashedkmer|2 << i;
                break;
            case 'G':
                hashedkmer=hashedkmer|3 << i;
                break;
            case 'A': //A is not necessary because its 00 in binary so if we force it or not its the same
                break;
        }

            
    }
    return hashedkmer;
}
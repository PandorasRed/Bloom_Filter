#include <kmer.hpp>
/**
 * take a string reprensation of a kmer and return the hash of this kmer;
 * @param kmer string representation of a kmer
 * @param cursor the cursor to know where the first char is
 * @param len length of the kmer;
 * @return the hash of the kmer in param
 */
uint64_t hashKmer(std::string kmer,const int len){
    int j=0;
    char a;
    uint64_t hashedkmer=0;
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
/** 
 * take a kmer and retunr the reverse complement if its less than the base kmer
 * @param kmer the kmer to reverse to check
 * @param len length of the kmer;
 * @return the reverseComplement if its less than the base kmer in lexiographic order
 */
std::string reverseComplement(std::string kmer,const int len){
    std::string rev=" ";
    rev.resize(len);
    for(int i=0;i<len;i++){
        switch(kmer[i]){
            case 'C':
                rev[(len-1)-i%len]='G';
                break;
            case 'G':
                rev[(len-1)-i%len]='C';
                break;
            case 'T':
                rev[(len-1)-i%len]='A';
                break;
            case 'A': 
                rev[(len-1)-i%len]='T';
                break;

        }
    }
    if(kmer<rev){
        return kmer;
    }else{
        return rev;
    }

}


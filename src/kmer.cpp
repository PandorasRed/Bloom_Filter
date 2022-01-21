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
 * take a kmer and return the reverse complement if its less than the base kmer
 * @param kmer the kmer to reverse to check
 * @param len length of the kmer;
 * @return the reverseComplement if its less than the base kmer in lexiographic order
 */
std::string reverseComplement(std::string kmer,const int len){
    if(kmer=="E"){
        return "E";
    }
    std::string rev=" ";
    rev.resize(len);
    for(int i=0;i<len;i++){
        switch(kmer[i]){
            case 'C':
                rev[(len-1)-i]='G';
                break;
            case 'G':
                rev[(len-1)-i]='C';
                break;
            case 'T':
                rev[(len-1)-i]='A';
                break;
            case 'A': 
                rev[(len-1)-i]='T';
                break;

        }
    }
    if(kmer<rev){
        return kmer;
    }else{
        return rev;
    }

}
/**
 * take a kmer and return the reverse complement if its less than the base kmer
 * better than the first function because checking to create better case, and the worst case stay the same.
 * @param kmer the kmer to reverse to check
 * @param len length of the kmer;
 * @return the reverseComplement if its less than the base kmer in lexiographic order
 */
/*std::string newreverseComplement(std::string kmer, const int len){
    if(kmer=="E"){
        return "E";
    }
    std::string rev;
    rev.resize(len);
    for(int i=len-1;i>=0;i--){ // reading the string from the end to the start
        switch(kmer[i]){
            case 'A':
                if(kmer[len-1-i]<'T'){ //only a if/else because a letter in our case can only be < or = to 'T'
                    return finishReverse(kmer,len,i);
                }else{
                    rev[len-1-i]='T';
                }
            case 'T':
                if(kmer[len-1-i]>'A'){

                }
        }
    }

}
std::string finishReverse(std::string kmer, const int len, int i,std::string rev){
    for(i;i>=0;i--){
        rev[len-1-i]=
    }
}*/
/**
 * take a kmer and return a new kmer with the first char supr
 * and the last char is the next char in the file
 * @param oldkmer previous kmer
 * @param len length of the kmer
 * @param fs the filestream where we take our next kmer;
 * @return the next kmer(give a totally new one is oldkmer has not the good size)
 */
std::string newkmer(std::string oldkmer,const int len,std::ifstream& fs){
    std::string newkmer=" ";
    newkmer.resize(len);
    if(oldkmer.size()!=(uint)len){
        for(int i=0;i<len;i++){
            newkmer[i]=nextC(fs); //we can estimate that we never ask for a kmer bigger than what the whole file contains
        }
        return newkmer;
    }
    char a=nextC(fs);
    if(a==EOF){
        return "E";
    }
    for(int i=1;i<len;i++){
        newkmer[i-1]=oldkmer[i];
    }
    newkmer[len-1]=a;
    return newkmer;

}
/**
 *take the len of the random kmer we want, suppose a call at srand before call;
 *@param len the length of the randomkmer 
 *@return a new randomkmer of the len
 */
std::string randomkmer(const int len){
    std::string r="";
    for(int i=0;i<len;i++){
        switch(rand()%4){
            case 0:
                r.append("A");
                break;
            case 1:
                r.append("C");
                break;
            case 2:
                r.append("T");

                break;
            case 3:
                r.append("G");
                break;
        }
    }
    return r;
}


#include "readFastaFile.hpp"

/**
 * take a ifstream with a fasta format for the file and put the cursor a the end of the first line if starting with >
 * can be upgraded easily to return the string  if needed for something;
 *@param fs filestream for the Fasta file;
 *@return void 
 */
void firstSuppr(std::ifstream& fs){
    std::string desc;
    if(fs.get()=='>'){
        getline(fs,desc);
    }
}
/**
 * take a ifstream and return the next char in this file if its a valid char, or EOF when ending;
 * @param fs filestream for the Fasta file ;
 * @return a the next char in the file or EOF;
 */
char nextC(std::ifstream& fs){
    char n;
    do{
        n=fs.get();
    }while( (n!='A')&&(n!='C')&& (n!='G')&&(n!='T')&&(n!=EOF)); 
    return n;
}

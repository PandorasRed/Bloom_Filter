#include <vector>
#include <bloomTest.hpp>
 
int main(int argc, char *argv[])
{
	if(argc!=6){
		
		
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p k t nbh nbt "<< std::endl;
		std::cout << "k la taille du kmer demander\np le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
	}else{
		std::ifstream fs(argv[1]);//ifstream of the fastaFile
		srand (time(NULL));//init for the random request
		const unsigned int k=atoi(argv[2]);
		uint64_t size = atol(argv[3]);
		const unsigned int nf=atoi(argv[4]);
		const uint64_t request = atol(argv[5]);//no precision for the max so assuming we want big number of request
		bloomFilter* a=new bloomFilter(size,nf);
		firstSuppr(fs);
		std::string t=newkmer("",k,fs);
		t=reverseComplement(t,k);
		a->add_value(hashKmer(t,k));

		while(t!="E"){ //loop to create the kmer and add it to the bloomfilter
			t=newkmer(t,k,fs);
			t=reverseComplement(t,k);
			if(t!="E"){
				a->add_value(hashKmer(t,k));
			}
		}
		fs.close();
		for(unsigned long int i=0;i<request;i++){//loop to do the number of request needed
			std::string test=randomkmer(k);
			std::string present="not present";
			if(a->is_present(hashKmer(reverseComplement(test,k),k))){
				present="present";
			}
			std::cout<<test<<" : "<<present<< std::endl; //
		}
		delete a;


		
	}	
	return 0;	
}
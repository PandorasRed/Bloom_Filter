#include <vector>
#include <main.hpp>
 
int main(int argc, char *argv[])
{
	/*std::vector<bool>*  vt=new std::vector<bool>(10,0);
	vt->resize(50000);
	std::cout<<vt->at(48546) << std::endl;
	vt->at(48546)=1;
	std::cout<<vt->at(48546) << std::endl;
	delete vt;*/
	/*uint8_t test=0;
	test|=(1<<7);
	std::cout<<(unsigned int)test<<std::endl;*/
	if(argc!=6){
		
		
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p t nbh nbt "<< std::endl;
		std::cout << "p le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
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

		while(t!="E"){
			t=newkmer(t,k,fs);
			t=reverseComplement(t,k);
			//std::cout<<t<< std::endl;
			if(t!="E"){
				a->add_value(hashKmer(t,k));
			}
		}
		//a->test();
		fs.close();
		for(unsigned long int i=0;i<request;i++){
			std::string test=randomkmer(k);
			std::cout<<test<<a->is_present(hashKmer(reverseComplement(test,k),k)) << std::endl;
		}
		delete a;


		
	}	
	return 0;	
}
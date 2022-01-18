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
	if(argc==6){
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p t nbh nbt "<< std::endl;
		std::cout << "p le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
	}else{
		srand (time(NULL));
		bloomFilter* a=new bloomFilter((unsigned long int)2000,5);
		std::ifstream fs(argv[1]);//fait le ifstream du fichier
		firstSuppr(fs);
		std::string t=newkmer("",5,fs);
		t=reverseComplement(t,5);
		a->add_value(hashKmer(t,5));

		while(t!="E"){
			t=newkmer(t,5,fs);
			t=reverseComplement(t,5);
			//std::cout<<t<< std::endl;
			if(t!="E"){
				a->add_value(hashKmer(t,5));
			}
		}
		
		fs.close();
		delete a;
		for(int i=0;i<10;i++){
			std::cout<<a->is_present(hashKmer(reverseComplement(randomkmer(5),5),5)) << std::endl;
		}

		
	}	
	return 0;	
}
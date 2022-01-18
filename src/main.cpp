#include <vector>
#include <main.hpp>
 
int main(int argc, char *argv[])
{
	if(argc==6){
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p t nbh nbt "<< std::endl;
		std::cout << "p le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
	}else{
		srand (time(NULL));
		bloomFilter* a=new bloomFilter(200,5);
		std::ifstream fs(argv[1]);//fait le ifstream du fichier
		firstSuppr(fs);
		std::string t=newkmer("",5,fs);
		t=reverseComplement(t,5);
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
		//std::cout<<b<<std::endl;
		for(int i=0;i<10;i++){
			std::cout<<a->is_present(hashKmer(reverseComplement(randomkmer(5),5),5)) << std::endl;
		}

		
	}	
	return 0;	
}
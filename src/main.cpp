
#include <main.hpp>
 
int main(int argc, char *argv[])
{
	if(argc==6){
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p t nbh nbt "<< std::endl;
		std::cout << "p le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
	}else{
		std::ifstream fs(argv[1]);//fait le ifstream du fichier
		firstSuppr(fs);
		std::string t=newkmer("",10,fs);
		for(int i=0;i<20;i++){
			t=newkmer(t,10,fs);
			std::cout << t << std::endl;
		}

		return 0;
	}
	
}
#include <fstream>

#include <main.hpp>
 
int main(int argc, char *argv[])
{
	if(argc!=6){
		std::cout << "nombre d'argument invalide, la syntaxe du programme est main p t nbh nbt "<< std::endl;
		std::cout << "p le path du fichier fasta;\nt la taille du filtre de bloom demander(max2^34);\nnbh le nombre de fonction de hashage demander;\nnbt le nombre de requette de test;\n";
	}else{
		std::ifstream fs(argv[1]);//fait le ifstream du fichier
		std::cout<<argc;
		firstSuppr(fs);
		char a;
		int i=0;
		while(a!=EOF && i<100){
			a=nextC(fs);
			std::cout << a ;
			i++;
		}
		std::cout << std::endl;
		return 0;
	}
	
}
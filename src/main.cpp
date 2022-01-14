#include "main.hpp"
#include <fstream>
 
 
int main(int argc, char *argv[])
{
	std::ifstream fs(argv[1]);//fait le ifstream du fichier
	firstSuppr(fs);
	char a;
	while(a!=EOF){
		a=nextC(fs);
		std::cout << a;
	}
	return 0;
}
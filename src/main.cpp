#include <fstream>

#include <main.hpp>
 
int main(int argc, char *argv[])
{
	(void) argc;
	std::ifstream fs(argv[1]);//fait le ifstream du fichier
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
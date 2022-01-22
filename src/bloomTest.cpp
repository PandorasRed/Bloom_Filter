#include <vector>
#include <bloomTest.hpp>
 
int main(int argc, char *argv[])
{
	if(argc!=6){
		std::cout << "invalid argument the command line is : bloomTest p k t nbh nbt "<< std::endl;
		std::cout << "p the path of the fasta file;\nk the size of the kmer;\nt the size of the bloom filter(max2^34);\nnumber of hash function for the bloom filter;\nnbt number of test request;\n";
	}else{
		std::ifstream fs(argv[1]);//ifstream of the fastaFile
		srand (time(NULL));//init for the random request
		const unsigned int k=atoi(argv[2]);
		const uint64_t size = atol(argv[3]);
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
				present="probably present";
			}
			std::cout<<test<<" : "<<present<< std::endl; //
		}
		delete a;


		
	}	
	return 0;	
}
#include <bloomFilter.hpp>
#include <bitset>
        bloomFilter::bloomFilter(uint64_t newsize, u_int64_t nf){
            bytesArray=new u_int8_t[(newsize/8)+1 ];
            nbf=nf;
            size=newsize;
        }
        //the destructor
        bloomFilter::~bloomFilter(){
            delete[] bytesArray;
        }
        //untested function, assume it don't work
        void  bloomFilter::add_value(uint64_t x){
            x=x+1; // to be sure that 0 don't cause problem, just need to do the same for is_present
            uint64_t hashedCell[nbf];
            multihash(x,hashedCell,nbf,size-1);
            uint64_t tmp=0;
            int modtmp;
            std::cout<<nbf<<std::endl;
            for(unsigned int i=0;i<nbf;i++){
                //std::cout<<"test"<<std::endl;
                tmp=hashedCell[i];
                modtmp=tmp%8;
                if(modtmp==0){
                    bytesArray[tmp-1/8]|=1;
                }else{
                    bytesArray[tmp/8]|=1<<(8-modtmp);

                }
            }
        }
        //untested function, assume it don't work
        //return 1 if present else 0
        int bloomFilter::is_present(u_int64_t x){
            int r;
            x=x+1;
            uint64_t hashedCell[nbf];
            multihash(x,hashedCell,nbf,size-1);
            uint64_t tmp=0;
            int modtmp;
            for(unsigned int i=0;i<nbf;i++){
                tmp=hashedCell[i];
                modtmp=tmp%8;
                if(modtmp==0){
                    if(bytesArray[tmp-1/8]&1!=1){
                        return 0;
                    }
                }else{
                    if(bytesArray[tmp/8]&1<<(8-modtmp)){ //WIP
                        return 0
                    }
                }
            }
        }




        void  bloomFilter::test(){
            for(unsigned int i=0;i<(size/8)+1;i++){
                std::cout << (std::bitset<8>) bytesArray[i] << '\n';
            }
        }



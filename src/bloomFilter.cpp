#include <bloomFilter.hpp>
#include <bitset>
        bloomFilter::bloomFilter(uint64_t newsize, u_int64_t nf){
            bytesArray=new u_int8_t[(newsize/8)+1 ];
            for(uint64_t i=0;i<((newsize/8)+1);i++){
                bytesArray[i]=0;
            }
            nbf=nf;
            size=newsize;
        }
        //the destructor
        bloomFilter::~bloomFilter(){
            delete[] bytesArray;
        }
        //work but need a redo of constructor so need to be modified
        void  bloomFilter::add_value(uint64_t x){
            x=x+1; // to be sure that 0 don't cause problem, just need to do the same for is_present
            uint64_t hashedCell[nbf];
            multihash(x,hashedCell,nbf,size-1);
            uint64_t tmp=0;
            int modtmp;
            for(unsigned int i=0;i<nbf;i++){
                tmp=hashedCell[i];
                modtmp=tmp%8;
                if(modtmp==0){
                    bytesArray[tmp-1/8]|=1;
                    //std::cout<<tmp<<std::endl;
                }else{
                    bytesArray[tmp/8]|=1<<(8-modtmp);
                    //std::cout<<tmp<<std::endl;


                }
            }
        }
        //work but need a redo of constructor so need to be modified
        //return 1 if present else 0
        int bloomFilter::is_present(u_int64_t x){
            x=x+1;
            uint64_t hashedCell[nbf];
            multihash(x,hashedCell,nbf,size-1);
            uint64_t tmp=0;
            int modtmp;
            for(unsigned int i=0;i<nbf;i++){
                tmp=hashedCell[i];
                modtmp=tmp%8;
                if(modtmp==0){
                    if((bytesArray[tmp-1/8]&1)!=1){//not sure its work so need more test;
                        return 0;
                    }
                }else{
                    int b=(bytesArray[tmp/8]&(1<<(8-modtmp)));//read the bit we want;
                    b=b>>(8-modtmp);//shift it to make it a 1 or a 0
                    if(b!=1){ 
                        return 0;
                        
                    }
                }
            }
            return 1;
        }




        void  bloomFilter::test(){
            for(unsigned int i=0;i<(size/8)+1;i++){
                std::cout << (std::bitset<8>) bytesArray[i] << '\n';
            }
        }



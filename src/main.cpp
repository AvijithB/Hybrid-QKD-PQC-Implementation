#include "bb84_clean.h"
#include "bb84_noisy.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <fstream>

int main(){
    srand(time(0));
    int choice;
    std::cout<<"Noisy[1] / Noiseless[2] ; NoisyGraph[3] / NoiselessGraph[4]" ;
    std::cin>> choice;

    if(choice==1){
        run_bb84_clean(20);

    }else if(choice==2){
        run_bb84_noisy(100l,0.1f,false);

    }else if(choice==3){
        std::ofstream out("/workspace/QBERData/noisy.csv");
        for(int i=0;i<30;i++){
            out << std::to_string(run_bb84_noisy(100l,0.1f,true)) + ",";
        }
        out.close();
        int returncode = system("python3 /workspace/Analysis/noisy.py '/workspace/QBERData/noisy.csv'");
    }else if(choice==4){
        std::ofstream out("/workspace/QBERData/clean.csv");
        for(int i=0;i<30;i++){
            out << std::to_string(run_bb84_noisy(100l,0.1f,false)) + ",";
        }
        out.close();
        int returncode = system("python3 /workspace/Analysis/clean.py '/workspace/QBERData/clean.csv'");
    }
    
    
    
    else {
        std::cout<<"damn no numbers D:\n";
    }

    return 0;
}


#include "bb84_clean.h"
#include "bb84_noisy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(){
    int choice;
    std::cout<<"May the gods look down upon us with grace as we pray that cpp doesn't act up" ;
    std::cin>> choice;

    if(choice==1){
        run_bb84_clean(20);

    }else if(choice==2){
        run_bb84_noisy(100l,0.1f);
    }else{
        std::cout<<"damn no numbers D:\n";
    }

    return 0;
}


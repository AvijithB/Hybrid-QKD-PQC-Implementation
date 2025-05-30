#include "bb84_clean.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "bb84Utils.h"

void run_bb84_clean(int n){
    std::vector<int> aliceBits(n);
    std::vector<char> aliceBases(n);
    std::vector<char> bobBases(n);
    std::vector<char> bobResults(n);
    std::vector<int> siftedAlice, siftedBob;
    
    for(int i=0;i<n;++i){
        aliceBits[i] = randomBit();
        aliceBases[i] = randomBasis();
    }

    for(int i=0;i<n;++i){
        bobBases[i] = randomBasis();
        if (bobBases[i]==aliceBases[i]){
            bobResults[i]= aliceBits[i];
        }
        else{
            bobResults[i] = randomBit();
        }
    }

    for(int i=0 ; i<n;++i){
        if(aliceBases[i]==bobBases[i]){
            siftedAlice.push_back(aliceBits[i]);
            siftedBob.push_back(bobResults[i]);
        }
    }

    std::cout << "\n<========== BB84 Simulation Please Work Else i will cry ===========>\n";
    std::cout << "Transimitted bit count is : " << n << "\n";
    std::cout << "The bases that match: " << siftedAlice.size() << "\n\n";

    std::cout << "Alice sifted Key is : ";
    for(int bit:siftedAlice) std::cout << bit;
    std::cout<<"\n";

    std::cout<<"Bob sifted Key: ";
    for(int bit: siftedBob) std::cout << bit;
    std::cout << "\n";

    int errors = 0;
    for (size_t i =0 ; i<siftedAlice.size();++i){
        if(siftedAlice[i]!= siftedBob[i]) errors++;
    }
    double qber = (siftedAlice.empty()) ? 0.0 : (double)errors/siftedAlice.size();
    std::cout<<"QBER: " << qber*100<<"\n";
}

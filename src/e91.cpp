#include "e91.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int randomBitE91() {
    return rand() % 2;
}

char randomBasisE91() {
    char bases[3] = {'Z', 'X', 'Y'};
    return bases[rand() % 3];
}

int simulateEntangledOutcome(char aliceBasis, char bobBasis) {
    return (aliceBasis == bobBasis) ? randomBitE91() : randomBitE91();
}

void run_e91_simulation(int n) {
    std::vector<char> aliceBases(n), bobBases(n);
    std::vector<int> aliceResults(n), bobResults(n);

    for (int i = 0; i < n; ++i) {
        aliceBases[i] = randomBasisE91();
        bobBases[i] = randomBasisE91();

        int sharedBit = randomBitE91();
        if (aliceBases[i] == bobBases[i]) {
            aliceResults[i] = sharedBit;
            bobResults[i] = sharedBit;
        } else {
            aliceResults[i] = sharedBit;
            bobResults[i] = simulateEntangledOutcome(aliceBases[i], bobBases[i]);
        }
    }

    std::vector<int> siftedKey;
    for (int i = 0; i < n; ++i) {
        if (aliceBases[i] == bobBases[i]) {
            siftedKey.push_back(aliceResults[i]);
        }
    }

    std::cout << "\n e91 Simultion\n";
    std::cout << "total bits: " << n << "\n";
    std::cout << "siftyboi: " << siftedKey.size() << "\n";
    std::cout << "Sifted Key: ";
    for (int bit : siftedKey) std::cout << bit;
    std::cout << "\n";
}

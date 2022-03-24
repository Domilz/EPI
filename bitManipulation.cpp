#include <iostream>
#include <cmath>

// 010100 | 010011= 010111
int rightPropagate(int x) {
    return x | x-1;
}

// x & (rightPropagate(pow) - pow) = 18 & rightPropagate(16) - 16 = 10010 & (11111 - 10000) = 10010 & 01111 = 00010 = 2
int moduloPowerOfTwo(int x, int pow) {
    return x & (rightPropagate(pow) - pow);
}   
//10000 & 01111 == 0, 10100 & 10011 > 0
bool isPower(int x) {
    return (x & x-1) == 0;
}


// 101010 & 101001 = 101000
unsigned long clearLowestBit(unsigned long x) {
    return x & (x-1);
}

// 00101101100 & ~00101101011 = 00101101100 & 11010010100
unsigned long extractLowestBit(unsigned long x) {
    return x & ~(x-1);
}

//Find and clear lsb until 0
short countBits(unsigned long x) {
    short count = 0;
    while (x) {
        count++;
        x = clearLowestBit(x);
    }
    return count;
}


unsigned long swapBits(unsigned long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        unsigned long bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }
    return x;
}

// Check if # of bits is odd or not
short parity(unsigned long x) {
    short result = 0;
    while (x) {
        result ^= 1;
        x &= (x - 1);
    }
    return result;
}


unsigned long closestIntegerSameWeight(unsigned long x) {
    unsigned long y;
    if (x != 0) {
        unsigned long lsb = x & ~(x-1);
        if (lsb != 1) {
            y = (x & (x-1)) + lsb / 2;
        }
        else {
            y = (x & (x-1)) + lsb * 2;
        }
    }
    else {
        y = 0;
    }
    return y;
}

int main() {
    std::cout << closestIntegerSameWeight(7);
}
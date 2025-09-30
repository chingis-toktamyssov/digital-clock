#include "digits.h"

int zeroHT[] = {25, 28, 31, 30, 29, 26};
int oneHT[] = {28, 31};
int twoHT[] = {25, 28, 27, 29, 30};
int threeHT[] = {25, 28, 27, 31, 30};
int fourHT[] = {26, 27, 28, 31};
int fiveHT[] = {25, 26, 27, 31, 30};
int sixHT[] = {25, 26, 27, 31, 30, 29};
int sevenHT[] = {25, 28, 31};
int eightHT[] = {25, 26, 27, 28, 29, 30, 31};
int nineHT[] = {25, 26, 27, 28, 31};

int* HT[] = {zeroHT, oneHT, twoHT, threeHT, fourHT, fiveHT, sixHT, sevenHT, eightHT, nineHT};

int zeroHO[] = {9, 10, 12, 13, 14, 15};
int oneHO[] = {12, 15};
int twoHO[] = {9, 12, 11, 13, 14};
int threeHO[] = {9, 12, 11, 15, 14};
int fourHO[] = {10, 11, 12, 15};
int fiveHO[] = {9, 10, 11, 15, 14};
int sixHO[] = {9, 10, 11, 15, 14, 13};
int sevenHO[] = {9, 12, 15};
int eightHO[] = {9, 10, 12, 11, 13, 14, 15};
int nineHO[] = {9, 10, 11, 12, 15};

int* HO[] = {zeroHO, oneHO, twoHO, threeHO, fourHO, fiveHO, sixHO, sevenHO, eightHO, nineHO};

int zeroMT[] = {17, 20, 16, 23, 22, 18};
int oneMT[] = {20, 16};
int twoMT[] = {17, 20, 19, 22, 23};
int threeMT[] = {17, 20, 19, 16, 23};
int fourMT[] = {18, 19, 20, 16};
int fiveMT[] = {17, 18, 19, 16, 23};
int sixMT[] = {17, 18, 19, 16, 23, 22};
int sevenMT[] = {17, 20, 16};
int eightMT[] = {17, 18, 19, 20, 22, 16, 23};
int nineMT[] = {17, 18, 19, 20};

int* MT[] = {zeroMT, oneMT, twoMT, threeMT, fourMT, fiveMT, sixMT, sevenMT, eightMT, nineMT};

int zeroMO[] = {1, 4, 7, 6, 5, 2};
int oneMO[] = {4, 7};
int twoMO[] = {1, 4, 3, 5, 6};
int threeMO[] = {1, 4, 3, 7, 6};
int fourMO[] = {2, 3, 4, 7};
int fiveMO[] = {1, 2, 3, 7, 6};
int sixMO[] = {1, 2, 3, 7, 6, 5};
int sevenMO[] = {1, 4, 7};
int eightMO[] = {1, 2, 3, 4, 5, 6, 7};
int nineMO[] = {1, 2, 3, 4, 7};

int* MO[] = {zeroMO, oneMO, twoMO, threeMO, fourMO, fiveMO, sixMO, sevenMO, eightMO, nineMO};
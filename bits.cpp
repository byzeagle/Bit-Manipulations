#include <iostream>
#include <bitset>

#define b0000 0x0
#define b0001 0x1
#define b0010 0x2
#define b0011 0x3
#define b0100 0x4
#define b0101 0x5
#define b0110 0x6
#define b0111 0x7
#define b1000 0x8
#define b1001 0x9
#define b1010 0xA
#define b1011 0xB
#define b1100 0xC
#define b1101 0xD
#define b1110 0xE
#define b1111 0xF

using namespace std;

typedef bitset<8> BYTE;

int main()
{
	int n = 0;
	bitset<4> a (b1010);
	bitset<4> b (b1111);
	bitset<4> c (b0010);
	bitset<4> d (b0011);

	cout << (a & c) << endl;

	return 0;
}

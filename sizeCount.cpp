#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Bitfield_First {
	unsigned int x : 8;
	unsigned int y : 8;
	unsigned int z : 8;
};

struct Bitfield_Second {
	unsigned char x : 8;
	unsigned char y : 8;
	unsigned char z : 8;
};

struct Bitfield_Third {
	unsigned int x : 1;
};

struct Bitfield_Fourth {
	unsigned char x : 1;
};

struct Alignment1 {
	char x;
	int y;
	char z;
};

struct Alignment2 {
	char array[3];
	double duable;
	float flo;
	char x;
};

struct Alignment3 {
	short x;
	double y;
	char z;
	double a;
};

struct Alignment4 {
	double x;
	short y;
	char z;
	char arr[3];
};

struct Alignment5 {
	char* p;     /* 8 bytes */
	char c;      /* 1 byte */
};

template <typename T, typename N>
T getBitField(const N& arr) {
	return *(T*)arr;
}

int main()
{
	unsigned int arr[3] = { 0xFF, 0xAA, 0x05 };

	cout << endl;

	for (auto val : arr)
		cout << val << " ";

	cout << endl;
	cout << arr << " " << arr + 1 << " " << arr + 2 << endl;

	cout << "Sizeof bitfield_first is : " << sizeof(Bitfield_First) << endl;
	cout << "Sizeof bitfield_second is : " << sizeof(Bitfield_Second) << endl;
	cout << "Sizeof bitfield_third is : " << sizeof(Bitfield_Third) << endl;
	cout << "Sizeof bitfield_fourth is : " << sizeof(Bitfield_Fourth) << endl;

	cout << "Alignment1 is : " << sizeof(Alignment1) << endl;
	cout << "Alignment2 is : " << sizeof(Alignment2) << endl;
	cout << "Alignment3 is : " << sizeof(Alignment3) << endl;
	cout << "Alignment4 is : " << sizeof(Alignment4) << endl;
	cout << "Alignment5 is : " << sizeof(Alignment5) << endl;

	cout << endl;

	auto res = getBitField<Bitfield_First>(arr);
	cout << "res.x : " << res.x << endl;
	cout << "res.y : " << res.y << endl;
	cout << "res.z : " << res.z << endl;

	cout << endl;

	auto res2 = getBitField<Bitfield_Second>(arr);
	cout << "res2.x : " << res2.x << endl;
	cout << "res2.y : " << res2.y << endl;
	cout << "res2.z : " << res2.z << endl;

	return 0;
}

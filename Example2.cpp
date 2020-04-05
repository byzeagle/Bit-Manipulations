#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

template <typename T, typename N>
auto sum(T a, N b) {
	return a + b;
}

struct Data {
	string name = "";
	int age = 0;
	int skill = 0;
	int experience = 0;
	vector<int> numbers = { 0 , 0 , 0 , 0 , 0 , 0 };
};

constexpr int factorial_size(int n) {
	if (n == 1) return 1;
	return n * factorial_size(n - 1);
}

template <typename T>
void displayData(const T& data) {
	cout << data.name << endl;
	cout << data.age << endl;
	cout << data.experience << endl;
	cout << data.skill << endl;
}

int main() {
	
	ofstream my_file;
	my_file.open("data.bin", ios::out | ios::binary);
	if (!my_file.is_open()) {
		cout << "There is an error opening the file (ofstream)" << endl;
		my_file.close();
		exit(EXIT_FAILURE);
	}

	Data player1;

	player1.name = "Ugur Buyukdurak";
	player1.age = 27;
	player1.experience = 10;
	player1.skill = 5;
	player1.numbers[5] = 5;

	Data player2;

	player2.name = "For trial purposes";
	player2.age = 60;
	player2.experience = 20;
	player2.skill = 8;
	player2.numbers[5] = 3;

	my_file.write((char*)&player1, sizeof(Data));
	my_file.write((char*)&player2, sizeof(Data));

	my_file.close();

	ifstream infile;
	infile.open("data.bin", ios::in | ios::binary);
	if (!infile.is_open()) {
		cout << "There is an error opening the file (ifstream)" << endl;
		infile.close();
		exit(EXIT_FAILURE);
	}

	Data player3;
	infile.read((char*)&player3, sizeof(Data));
	displayData(player3);

	Data player4;
	infile.read((char*)&player4, sizeof(Data));
	displayData(player4);

	infile.close();

	return 0; 
}
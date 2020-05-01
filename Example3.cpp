#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <chrono>
#include <tuple>
#include <vector>
#include <algorithm>
#include <type_traits>

namespace UgurEngine {
	namespace Graphics {
		namespace Rendering {
			class OpenGLRender {

			};
		}
	}
}

// C++17 nested namespace declaration
namespace UgurEngine::Graphics::Rendering {
	class OpenGLRender2 {

	};
}

using namespace std::chrono;

template<typename T, typename N>
auto sum(T a, N b) {
	return a + b;
}

template <typename T>
T max(const T& t1, const T& t2) {
	return t1 < t2; t2: t1;
}

auto buildCoolMap() {
	std::map<std::string, long long int> result;
	return result;
}

constexpr int Fibonacci(int n) {
	switch (n) {
		case 0: return 0;
		case 1: return 1;
		default: return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

[[deprecated("DoSomething is inefficient")]]
void doSomething() {

}

void doSomethingBetter() {
	int n{ 64 };
	double speed{ 10.0 };
	bool success{ true };
}

void print(milliseconds ms) {
	std::cout << ms.count() << "ms " << std::endl;
}

// Example class X
class X {
public:
	X() {
		std::cout << "X Constructor" << std::endl;
	}
	~X() {
		std::cout << "X Destructor" << std::endl;
	}
	void sayHi() {
		std::cout << "X says hi! ;)" << std::endl;
	}
private:
	int m1{};
	double m2{ 3.14 };
};

// C++14: Template Variables
template <typename T>
constexpr T pi = T(3.1432424242342);

template <typename T>
constexpr T maxValue = T(1000);

template<>
constexpr double maxValue<double> = 2000;

template<>
constexpr char maxValue<char> = 'Z';

// C++17: consexpr if
template <typename T>
auto length(const T& value) {
	if constexpr (std::is_integral<T>::value)
		return value;
	else
		return value.length();
}

int main() {
	auto sum2 = sum(2, 3.4);
	auto res = max(2, 3);

	auto map2 = buildCoolMap();

	static_assert(Fibonacci(10) == 55, "Fibonacci Number");

	// Seperator
	long xk = 10'000'000;
	std::cout << xk << std::endl;

	// Binary literals and seperator
	auto c = 0b11000001'01011010;
	std::cout << c << std::endl;

	//doSomething();

	// Variable templates
	std::cout << "maxValue<int> : " << maxValue<int> << std::endl;
	std::cout << "maxValue<double> : " << maxValue<double> << std::endl;
	std::cout << "maxValue<char> : " << maxValue<char> << std::endl;
	std::cout << "maxValue<float> : " << maxValue<float> << std::endl;

	// Allocating memory from the heap is slower than allocating memory on the stack
	double* heap = new double[100];
	delete[] heap;
	heap = nullptr;

	// Create a uniqu_ptr to an array of 1000 doubles
	auto p = std::make_unique<double[]>(1000);

	// Examples with class X
	std::cout << "------------" << std::endl;
	X* pX = new X{};
	pX->sayHi();
	delete pX;
	pX = nullptr;

	// Unique pointer example
	auto pX2 = std::make_unique<X>();
	pX2->sayHi();

	// unique_ptr move
	std::unique_ptr<X> ptr1;
	std::unique_ptr<X> ptr2;
	//ptr1 = ptr2; // Not allowed
	ptr1 = std::move(ptr2); // Pointer can be moved

	// Time unit literals
	seconds ssec{ 10 };
	auto x = 2s;
	auto y = 150ms;
	constexpr auto timelimit = 3s;
	constexpr auto min = 30min;

	// Tuple : Collection of heterogeneous values
	std::tuple<int, std::string, double, char> tp {3, "hello", 2.34, 'c'};

	// Lambda : Function without a name
	auto lambda = [](int a, int b) {};

	// Generic Lambda
	auto lambda2 = [](auto a, auto b) {};

	// Vector sort with lambda
	std::vector<std::string> vec = { "hello", "dennis", "deneme", "connor", "ali", "veli", "said" };
	
	// For-each loop
	for (const auto& s : vec)
		std::cout << s << " ";
	std::cout << std::endl;

	// C++11 lambda
	std::sort(vec.begin(), vec.end(), 
		[](const std::string& s1, const std::string& s2) { 
			return s1.length() < s2.length();
		});

	// C++14 lambda : called generic lambdas
	std::sort(vec.begin(), vec.end(),
		[](const auto & s1, const auto & s2) {
			return s1.length() < s2.length();
		});

	// Lambda capture list
	[x, y](auto a, auto b) {

	};

	// C++14 : Init-capture list
	[x, &y, value = 64](auto a, auto b) {

	};

	// Init-capture example
	auto ptr3 = std::make_unique<int>(64);
	[ptr = std::move(ptr3)](){
		std::cout << *ptr << std::endl;
	}();

	// C++17: if constexpr  example
	int n{ 64 };
	std::string s{ "Connie" };
	std::cout << "n = " << n << "; length(n) = " << length(n) << std::endl;
	std::cout << "s = " << s << "; length(s) = " << length(s) << std::endl;

	return 0;
}
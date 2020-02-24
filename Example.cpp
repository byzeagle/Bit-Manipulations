#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Deneme
{
    T arr;
    Deneme(T x) : arr(x) {}
};

template <typename T>
constexpr T constFunc(T var)
{
    return var;
}

template <typename T, typename ...Args>
constexpr T constFunc(T var, Args... args)
{
    return var * constFunc(args...);
}

template <typename T>
auto function(T x) {
    vector<Deneme<T>> vec;
    vec.push_back(Deneme<T>(x));
    return vec;
}

template <typename T>
T functionX(T x)
{
    return x;
}

template <typename T>
void f(const T& param) {}

template <typename T, size_t N>
constexpr size_t arraySize(T (&arr)[N])
{
    return N;
}

void f2(int x) {}

// Has a pointer to a function as the parameter
void f3(int x, void (*fp)(int)) {}

int main()
{
    // Template argument deduction test
    auto object = function(100);
    vector<Deneme<int>> x = function(200);

    // constexpr function
    int arr[constFunc(1, 2, 3, 4, 5)] = { 0 };

    // Just a pointer
    int* ptr3 = arr;

    // Pointer to an array
    int(*ptr)[120] = &arr;

    // Reference to an array
    int(&ptr2)[120] = arr;

    // Pointer to a function
    void (*fp)(int x) = f2;
    fp(2);

    // Returns the size of the array
    int sizeArr = arraySize(arr);
    cout << "Size of arr is : " << sizeArr << endl;

    cout << object[0].arr << endl;
    cout << x[0].arr << endl;
    cout << constFunc(5) << endl;
    cout << constFunc(2.55) << endl;
    cout << constFunc(1.0, 2, 3, 4, 5) << endl;

    int y = 5;
    const int den = 5;
    const int & den2 = 5;
    const int* p = &den;

    // Template argument deduction test
    functionX(2);
    functionX(den);
    functionX(den2);
    functionX(*p);

    // Template Argument deduction test
    f(den);
    f(den2);
    f(y);

    return 0;
}
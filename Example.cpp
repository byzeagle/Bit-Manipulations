#include <iostream>
#include <vector>
#include <type_traits>
#include <bitset>

using namespace std;

// Type deduction in templates only take place for function templates
// Partial Specialization of templates are only possible for class templates
// Since C++17, class template arguments can automatically be deduced from constructors
// There are nontype template parameters
// There is something called variadic templates

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

// Has a pointer to a function as function parameter
void f3(int x, void (*fp)(int)) {}

// Aliases for function pointers
typedef void (*functiontype)();

// From C++ 11 on
using functiontype2 = void (*)();
using functiontype3 = std::add_pointer<void()>::type;

// Regarding function overloading and function template specialization
int sum(int a, int b)
{
    cout << "int sum(int a, int b)" << endl;
    return a + b;
}

double sum(double a, double b)
{
    cout << "double sum(double a, double b)" << endl;
    return a + b;
}

template <typename T>
T sum(T a, T b)
{
    cout << "template <typename T> T sum(T a, T b)" << endl;
    return a + b;
}

template<>
int sum<int>(int a, int b)
{
    cout << "template <> int sum<int>(int a, int b)" << endl;
    return a + b;
}

void foo(int(&arr)[5])
{

}

auto foo(int(&arr)[3]) -> int(*)(int, int)
{
    return sum;
}

// Interesting use
int even[] = { 1,2 };
decltype(even)* foo2() {
    return &even;
}

using funcType = void(int, int); // Function type
using funcPointerType = void(*)(int, int); // Function pointer type

void foo5(int, int) {}

funcPointerType foo4()
{
    return foo5;
}

//funcType foo4() { // Error because function types cannot be returned
//                  // Array types cannot be returned either
//}

// decltype(foo2) is a function type, it cannot be returned
// decltype(foo2) * is a pointer type, it can be returned
decltype(foo2)* foo3(int x)
{
    return foo2;
}

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

    // Function Pointer array
    void(*fp2[10])(int x);
    fp2[0] = f2;
    fp2[0](2);

    // Reference to a function
    void(&fp3)(int x) = f2;
    fp3(2);

    // A pointer to function pointer
    void(**func_ptr_ptr)(void);

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

    // Function sum test
    sum(2, 3);
    sum<int>(2, 3);
    sum(2.0, 3.0);
    sum<double>(2, 3);

    // Function foo test
    int array[] = { 1, 2, 3 ,4 ,5 };
    foo(array);

    int array2[] = { 1, 2, 3 };
    auto sum = foo(array2);
    sum(1, 2);

    // float binary representation with union and pointer cast
    union
    {
        float f;
        int u;
    } u1;
    u1.f = 0.3f;
    bitset<sizeof(float) * CHAR_BIT> a(u1.u);
    cout << a << endl;
    cout << "u1.f : " << u1.f << endl;
    cout << "u1.u : " << u1.u << endl;

    float f = 0.3f;
    int* pt = (int*)&f;
    bitset<sizeof(float) * CHAR_BIT> b(*pt);
    cout << b << endl;
    cout << "f : " << f << endl;
    cout << "*pt :" << *pt << endl;

    f = 5.5f;
    std::bitset<sizeof(float) * CHAR_BIT> foobitset(*reinterpret_cast<unsigned long*>(&f));
    cout << "foobitset : " << foobitset << endl;

    // Conversion through pointer vs direct cast
    int n = -1;
    unsigned int n3 = (unsigned int)n;
    unsigned int* n2 = (unsigned int*)&n;
    unsigned int n4 = (unsigned int)f;
    cout << *n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl; // With float, it does not work as expected, gives 0

    // int and float comparison
    int abc = 12345;
    float cba = (float)abc;
    cout << "abc : " << abc << endl;
    cout << "cba : " << cba << endl;
    bitset<32> bitsetabc(abc);
    bitset<32> bitsetcba(*(int*)&cba);
    cout << "abc bit sequence : " << bitsetabc << endl;
    cout << "cba bit sequence : " << bitsetcba << endl;

    // Overflow cases
    int deneme = 0x7FFFFFFF;
    cout << "deneme : " << deneme << endl;
    cout << "deneme + 1 :" << deneme + 1 << endl;

    unsigned int deneme2 = 0xFFFFFFFF;
    cout << "deneme2 : " << deneme2 << endl;
    cout << "deneme2 + 1 : " << deneme2 + 1 << endl;

    // Pointers
    union {
        int intArray[3] = { 1, 2 ,3 };
        unsigned char charArray[12];
    }u2;
    cout << "intArray : " << (void*)u2.intArray << endl;
    cout << "intArray + 1 : " << u2.intArray + 1 << endl;
    cout << "intArray + 2 : " << u2.intArray + 2 << endl;
    cout << "intArray + 3 : " << u2.intArray + 3 << endl;

    cout << "charArray : " << (void *)u2.charArray << endl;
    cout << "charArray + 1 : " << (void*)(u2.charArray + 1) << endl;
    cout << "charArray + 2 : " << (void*)(u2.charArray + 2)<< endl;
    cout << "charArray + 3 : " << (void*)(u2.charArray + 3) << endl;

    cout << "charArray[0] : " << (int)u2.charArray[0] << endl;
    cout << "charArray[1] : " << (int)u2.charArray[1] << endl;
    cout << "charArray[2] : " << (int)u2.charArray[2] << endl;
    cout << "charArray[4] : " << (int)u2.charArray[4] << endl;
    cout << "charArray[8] : " << (int)u2.charArray[8] << endl;
    cout << "charArray[9] : " << (int)u2.charArray[9] << endl;

    char charString[6] = "Hello";
    cout << "charString : " << charString << endl;

    return 0;
}
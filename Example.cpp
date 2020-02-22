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
auto function(T x) {
    vector<Deneme<T>> vec;
    vec.push_back(Deneme<T>(x));
    return vec;
}

int main()
{
    auto object = function(100);
    vector<Deneme<int>> x = function(200);
    cout << object[0].arr << endl;
    cout << x[0].arr << endl;

    return 0;
}
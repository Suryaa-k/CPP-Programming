#include <iostream>
using namespace std;

int main() {
    // True lambda expression, introduced in C++11
    auto square = [](int x) { return x * x; };
    auto add = [](int a, int b) { return a + b; };

    cout << "Square: " << square(5) << endl;
    cout << "Add: " << add(3, 4) << endl;

    // Lambda with capture clause (captures external variable by value)
    int factor = 10;
    auto multiplyByFactor = [factor](int x) { return x * factor; };
    cout << "Multiply: " << multiplyByFactor(5) << endl;

    return 0;
}
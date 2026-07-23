#include <iostream>
using namespace std;

int globalVar = 100;

int add(int a, int b) {
    int localVar = 10;
    return a + b + localVar - localVar;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << "Add: " << add(5, 3) << endl;
    cout << "Factorial: " << factorial(5) << endl;
    cout << "Global: " << globalVar << endl;

    // True lambda expression (C++11+)
    auto square = [](int x) { return x * x; };
    cout << "Square via lambda: " << square(4) << endl;
    return 0;
}

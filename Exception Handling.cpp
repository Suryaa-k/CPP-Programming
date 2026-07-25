#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;

    try {
        if (b == 0) {
            throw runtime_error("Division by zero not allowed"); // raise equivalent
        }
        int result = a / b;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) { // except equivalent
        cout << "Error: " << e.what() << endl;
    }
    // C++ has NO native 'finally' or 'else' clause.
    // Cleanup is simulated using RAII (destructors) or manual code after the block.
    cout << "Program continues (finally-equivalent block)" << endl;

    return 0;
}
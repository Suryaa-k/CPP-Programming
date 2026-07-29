#include <iostream>
using namespace std;

int main() {
    int list[5];
    for (int i = 0; i < 5; i++) {
        list[i] = (i + 1) * 10;
    }
    for (int i = 0; i < 5; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}
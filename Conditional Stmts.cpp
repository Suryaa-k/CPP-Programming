#include <iostream>
using namespace std;

int main() {
    int score = 82;

    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 75) {
        cout << "Grade: B" << endl;
    } else if (score >= 50) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    int day = 3;
    switch (day) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        default: cout << "Invalid day" << endl;
    }
    return 0;
}
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom exception class inheriting from std::exception
class InsufficientBalanceException : public exception {
private:
    string message;
public:
    InsufficientBalanceException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void withdraw(int balance, int amount) {
    if (amount > balance) {
        throw InsufficientBalanceException("Insufficient balance: cannot withdraw " + to_string(amount) + " from " + to_string(balance));
    }
    cout << "Withdrawal successful" << endl;
}

int main() {
    try {
        withdraw(500, 700);
    }
    catch (const InsufficientBalanceException& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
#define CAPACITY 10

int list[CAPACITY];
int size = 0;

void insert(int index, int value) {
    if (size >= CAPACITY || index < 0 || index > size) return;
    for (int i = size; i > index; i--) {
        list[i] = list[i - 1];
    }
    list[index] = value;
    size++;
}

void deleteAt(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
}

int search(int value) {
    for (int i = 0; i < size; i++) {
        if (list[i] == value) return i;
    }
    return -1;
}

void update(int index, int value) {
    if (index < 0 || index >= size) return;
    list[index] = value;
}

void traverse() {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main() {
    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    traverse();

    insert(1, 15);
    traverse();

    deleteAt(2);
    traverse();

    update(0, 99);
    traverse();

    cout << "Search 15 -> index " << search(15) << endl;
    return 0;
}
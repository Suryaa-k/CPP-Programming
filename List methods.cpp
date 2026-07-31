#include <iostream>
using namespace std;

class List {
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    List() { capacity = 2; size = 0; data = new int[capacity]; }
    ~List() { delete[] data; }

    void append(int value) {
        if (size == capacity) resize();
        data[size++] = value;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) return;
        if (size == capacity) resize();
        for (int i = size; i > index; i--) data[i] = data[i - 1];
        data[index] = value;
        size++;
    }

    int indexOf(int value) {
        for (int i = 0; i < size; i++) if (data[i] == value) return i;
        return -1;
    }

    void removeValue(int value) {
        int idx = indexOf(value);
        if (idx == -1) return;
        for (int i = idx; i < size - 1; i++) data[i] = data[i + 1];
        size--;
    }

    int pop(int index) {
        if (index < 0 || index >= size) return -1;
        int val = data[index];
        for (int i = index; i < size - 1; i++) data[i] = data[i + 1];
        size--;
        return val;
    }

    void reverse() {
        int left = 0, right = size - 1;
        while (left < right) {
            swap(data[left], data[right]);
            left++; right--;
        }
    }

    bool isEmpty() { return size == 0; }
    int getSize() { return size; }

    void print() {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    List l;
    l.append(10); l.append(20); l.append(30);
    l.print();

    l.insert(1, 15);
    l.print();

    l.removeValue(20);
    l.print();

    int popped = l.pop(0);
    cout << "Popped: " << popped << endl;
    l.print();

    l.reverse();
    l.print();

    cout << "Size: " << l.getSize() << ", Empty: " << l.isEmpty() << endl;
    return 0;
}
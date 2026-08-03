#include <iostream>
using namespace std;

class NestedList {
    int** rows;
    int* rowSizes;
    int rowCount;
    int rowCapacity;

    void resize() {
        rowCapacity *= 2;
        int** newRows = new int*[rowCapacity];
        int* newSizes = new int[rowCapacity];
        for (int i = 0; i < rowCount; i++) { newRows[i] = rows[i]; newSizes[i] = rowSizes[i]; }
        delete[] rows;
        delete[] rowSizes;
        rows = newRows;
        rowSizes = newSizes;
    }

public:
    NestedList() {
        rowCapacity = 2;
        rowCount = 0;
        rows = new int*[rowCapacity];
        rowSizes = new int[rowCapacity];
    }

    void addRow(int arr[], int n) {
        if (rowCount == rowCapacity) resize();
        int* newRow = new int[n];
        for (int i = 0; i < n; i++) newRow[i] = arr[i];
        rows[rowCount] = newRow;
        rowSizes[rowCount] = n;
        rowCount++;
    }

    int get(int row, int col) { return rows[row][col]; }
    void set(int row, int col, int value) { rows[row][col] = value; }

    void traverse() {
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < rowSizes[i]; j++) cout << rows[i][j] << " ";
            cout << endl;
        }
    }

    void flatten(int out[], int& outSize) {
        int idx = 0;
        for (int i = 0; i < rowCount; i++)
            for (int j = 0; j < rowSizes[i]; j++)
                out[idx++] = rows[i][j];
        outSize = idx;
    }
};

int main() {
    NestedList nl;
    int r1[] = {1, 2, 3};
    int r2[] = {4, 5};
    int r3[] = {6, 7, 8, 9};
    nl.addRow(r1, 3);
    nl.addRow(r2, 2);
    nl.addRow(r3, 4);

    nl.traverse();

    cout << "get(2,1) = " << nl.get(2, 1) << endl;
    nl.set(0, 0, 99);
    nl.traverse();

    int flat[20], flatSize;
    nl.flatten(flat, flatSize);
    cout << "Flattened: ";
    for (int i = 0; i < flatSize; i++) cout << flat[i] << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int* generateArray(int size, int min, int max) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
    return array;
}

int calcSumOfOdd(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            sum += array[i];
        }
    }
    return sum;
}

int calcFirstNegative(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            return i;
        }
    }
    return -1;  
}

int calcLastNegative(int array[], int size) {
    int idxOfLastNeg = -1;  
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            idxOfLastNeg = i;
        }
    }
    return idxOfLastNeg;
}

int calcSumBetweenNeg(int array[], int firstNegativeIdx, int lastNegativeIdx) {
    int sum = 0;
    for (int i = firstNegativeIdx; i <= lastNegativeIdx; i++) {
        sum += array[i];
    }
    return sum;
}

void compressArray(int array[], int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (abs(array[i]) > 1) {
            array[index] = array[i];
            index++;
        }
    }

    for (int i = index; i < size; i++) {
        array[i] = 0;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int n;
    cout << "n = ";
    cin >> n;
    int* array = generateArray(n, -5, 5);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << array[i] << " ";  
    }
    cout << endl;

    cout << "sum of elements with odd indices: " << calcSumOfOdd(array, n) << endl;
    cout << endl;

    int firstNeg = calcFirstNegative(array, n);
    if (firstNeg != -1) {
        int lastNeg = calcLastNegative(array, n);
        cout << "the sum of elements between the first and last negative elements: " << calcSumBetweenNeg(array, firstNeg, lastNeg) << endl;
        cout << endl;
    }
    else {
        cout << "-" << endl;
        cout << endl;
    }

    compressArray(array, n);

    cout << "modified array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << array[i] << " ";
    }
    cout << endl;
    cout << endl;

    delete[] array;
    return 0;
}

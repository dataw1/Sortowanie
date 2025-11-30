#include <iostream>
#include <vector>
#include "MergeSorter.h"

using namespace std;

// Funkcja pomocnicza do wypisywania wektora
template <typename T>
void printVector(const vector<T>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Instancja 1: Liczby całkowite (int)
    cout << "--- Test Int ---" << endl;
    vector<int> intTab = { 12, 11, 13, 5, 6, 7 };
    MergeSorter<int> intSorter;

    cout << "Przed sortowaniem: ";
    printVector(intTab);

    intSorter.sort(intTab);

    cout << "Po sortowaniu:     ";
    printVector(intTab);

    // Instancja 2: Liczby zmiennoprzecinkowe (double)
    cout << "\n--- Test Double ---" << endl;
    vector<double> doubleTab = { 4.5, 2.1, 9.9, 0.5, 2.1, -3.2 };
    MergeSorter<double> doubleSorter;

    cout << "Przed sortowaniem: ";
    printVector(doubleTab);

    doubleSorter.sort(doubleTab);

    cout << "Po sortowaniu:     ";
    printVector(doubleTab);

    return 0;
}
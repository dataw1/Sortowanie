#pragma once
#include <vector>
#include <iostream>
#include "pch.h"


template <typename T>
class MergeSorter {
public:
    // Publiczna metoda do wywo³ania sortowania
    void sort(std::vector<T>& arr) {
        if (arr.empty()) {
            return; // Obs³uga pustej tablicy bez rzucania wyj¹tkiem
        }
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

private:
    // G³ówna funkcja rekurencyjna
    void mergeSort(std::vector<T>& arr, int left, int right) {
        if (left < right) {
            // ZnajdŸ œrodek (zapobiega overflow dla du¿ych l i r)
            int mid = left + (right - left) / 2;

            // Sortuj pierwsz¹ i drug¹ po³owê
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Scal posortowane po³owy
            merge(arr, left, mid, right);
        }
    }

    // Funkcja scalaj¹ca dwie podtablice
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Utwórz tablice tymczasowe
        std::vector<T> L(n1);
        std::vector<T> R(n2);

        // Kopiuj dane do tablic tymczasowych L[] i R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Scal tablice tymczasowe z powrotem do arr[left..right]
        int i = 0; // Indeks pocz¹tkowy pierwszej podtablicy
        int j = 0; // Indeks pocz¹tkowy drugiej podtablicy
        int k = left; // Indeks pocz¹tkowy scalonej podtablicy

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Skopiuj pozosta³e elementy L[], jeœli s¹
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Skopiuj pozosta³e elementy R[], jeœli s¹
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};
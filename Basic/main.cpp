//
// Created by Tao on 6/7/20.
//

#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        //寻找[i，n）区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
    //i代表向右移动
    for (int i = 1; i < n; ++i) {
        //j代表向左移动
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
    return;
}

int main() {

    int n = 20000;

    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Section Sort", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;

    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(a, 10);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    float b[4] = {4.4, 3.3, 2.2, 1.1};
    selectionSort(b, 4);
    for (int i = 0; i < 4; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    string c[4] = {"D",
                   "C",
                   "B",
                   "A"};
    selectionSort(c, 4);
    for (int i = 0; i < 4; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    Student d[4] = {{"D", 90},
                    {"C", 100},
                    {"B", 95},
                    {"A", 95}};
    selectionSort(d, 4);
    for (int i = 0; i < 4; i++)
        cout << d[i];
    cout << endl;

    return 0;
}


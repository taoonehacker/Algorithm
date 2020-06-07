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

template<typename T>
void insertionSortAdvance(T arr[], int n) {
    //i代表向右移动
    for (int i = 1; i < n; ++i) {
        //j代表向左移动
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
    return;
}

//冒泡排序
template<typename T>
void bubbleSort(T arr[], int n) {
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

//冒泡排序优化
template<typename T>
void bubbleSortAdvance(T arr[], int n) {
    int newn;
    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                // 记录最后一次交换的位置，在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        }
        n = newn;
    } while (newn > 0);
}

//希尔排序
template<typename T>
void shellSort(T arr[], int n) {
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while (h < n / 3)
        h = 3 * h + 1;

    while (h >= 1) {

        // h-sort the array
        for (int i = h; i < n; i++) {

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for (j = i; j >= h && e < arr[j - h]; j -= h)
                arr[j] = arr[j - h];
            arr[j] = e;
        }

        h /= 3;
    }
}

int main() {

    int n = 20000;

    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSortAdvance, arr1, n);
    SortTestHelper::testSort("Section Sort", selectionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<<endl;

    // 测试2 测试近乎有序的数组
    int swapTimes = 100;

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

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


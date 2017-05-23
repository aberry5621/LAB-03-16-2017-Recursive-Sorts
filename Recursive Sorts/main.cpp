//
//  main.cpp
//  Recursive Sorts
//
//  Created by ax on 3/16/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include <iostream>

using namespace std;

// show any array in the program
void displayArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
}

void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);

int main() {
    cout << "Recursive Sorting FTW!\n";
    
    const int ARR_SIZE = 6;
    int arrB[ARR_SIZE] = { 43, 2, 99, 34, 27, 1 };
    cout.width(30);
    cout << "Unsorted data:\t";
    displayArray(arrB, ARR_SIZE);
    cout << endl;
    cout.width(30);
    cout << "Result of bubble-sort:\t";
    
    cout << endl;
    
    // bubble sort
    bubbleSort(arrB, ARR_SIZE);
    displayArray(arrB, ARR_SIZE);
    cout << endl;
    cout.width(30);
    
    
    cout << "Result of selection-sort:\t";
    int arrA[6] = { 43, 2, 99, 34, 27, 1 };
    selectionSort(arrA, ARR_SIZE);
    displayArray(arrA, ARR_SIZE);
    cout << endl;
    
    cout.width(30);
    cout << "Result of insertion-sort:\t";
    int arrC[6] = { 43, 2, 99, 34, 27, 1 };
    insertionSort(arrC, ARR_SIZE);
    displayArray(arrC, ARR_SIZE);
    cout << endl;
    /* */
    
    return 0;
    
}

// bubble sort
void bubbleSortHelper(int arr[], int arrSize, int flagPos) {
    //cout << "RECUR BUB SORT HELPER \n";
    //base case
    // flag is at end of array
    if (flagPos == 0) {
        cout << "RECUR BUB SORT HELPER COMPLETE \n";
        return;
    } else {
        for (int i = 0; i < flagPos; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        bubbleSortHelper(arr, arrSize, flagPos-1);
    }
}

void bubbleSort(int arr[], int arrSize) {
    cout << "RECUR BUB SORT \n";
    bubbleSortHelper(arr, arrSize, arrSize-1);
}

// selection sort
//Get the index of the smallest element from a range
//This is a helper function for selection sort
int findMinIndex(int arr[], int fromIndex, int toIndex) {
    int min = arr[fromIndex];
    int minIndex = fromIndex;
    for (int i = fromIndex + 1; i <= toIndex; i++) {
        if (min > arr[i]) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSortHelper(int arr[], int arrSize, int minIdx) {
    
    // base case
    if (minIdx == arrSize -1) {
        // min idx is at arr size - 1
        return;
    } else {
        for (int i = minIdx; i < arrSize; i++) {
            if (arr[minIdx] > arr[i]) {
                swap(arr[i], arr[minIdx]);
            }
        }
        // task / recur
        selectionSortHelper(arr, arrSize, minIdx+1);
    }
    
}

void selectionSort(int arr[], int arrSize) {
    cout << "\nREcur Selection SOrt KEEYA!!\n";
    selectionSortHelper(arr, arrSize, 0);
    
}

// insertion sort
void insertionSortHelper(int arr[], int arrSize, int unsortedIdx) {
    cout << "\n Insertion Sort HELPER Invoked \n";
    // base case
    if (unsortedIdx == arrSize) {
        // unsorted Index reached end of array
        return;
    } else {
        int firstItemInUnsortedList = arr[unsortedIdx];
        int postitionToInsert = unsortedIdx;
        int j = unsortedIdx-1;
        while (j >=0 && arr[j] > firstItemInUnsortedList) {
            arr[j + 1] = arr[j];
            postitionToInsert = j;
            j--;
        }
        if (postitionToInsert != unsortedIdx) {
            arr[postitionToInsert] = firstItemInUnsortedList;
        }
    }
    // recur task
    // evaluate items in shrinking unsorted list for placement in sorted list
    insertionSortHelper(arr, arrSize, unsortedIdx+1);
}

void insertionSort(int arr[], int arrSize) {
    cout << "\n Insertion Sort Invoked \n";
    insertionSortHelper(arr, arrSize, 1);
}







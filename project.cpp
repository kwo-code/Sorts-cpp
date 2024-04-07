#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

long getRandomlong(long min, long max) {
    return floor(min + static_cast<long>(rand()) / (static_cast<long>(RAND_MAX / (max - min))));
}

void prlongArray(long arr[], long size, long hide) {
    if (hide != 1) {
        for (long i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    }
    
}

void copyArray(long arr[], long arrCopy[], long size) {
    for (long i = 0; i < size; ++i) {
        arrCopy[i] = arr[i];
    }
}


void bubbleSort(long arr[], long size) {
    for (long i = 0; i < size - 1; ++i) {
        for (long j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertsSort(long arr[], long size) {
    for (long i = 1; i < size; ++i) {
        long value = arr[i];
        long position = i;
        while (position > 0 && arr[position - 1] > value) {
            arr[position] = arr[position - 1];
            position--;
        }
        
        arr[position] = value;
    }
}

void choiseSort(long arr[], long size) {
    for (long i = 0; i < size-1; ++i){ 
        long min = i;
        for (long x = i+1; x < size; ++x) {
            if (arr[x] < arr[min]) {
                min = x;
            }
        }
        if (min != i){
            long temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void shellSort(long arr[], long size) {
    for (long longerval = size / 2; longerval > 0; longerval /= 2) {
        for (long i = longerval; i < size; i++) {
            long temp = arr[i];
            long j;
            for (j = i; j >= longerval && arr[j - longerval] > temp; j -= longerval) {
                arr[j] = arr[j - longerval];
            }
            arr[j] = temp;
        }
    }
}

long partition(long arr[], long low, long high) {
    long pivot = arr[high];
    long i = low - 1;

    for (long j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    long temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(long arr[], long low, long high) {
    if (low < high) {
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long main() {
    long size;
    int hide;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    std::cout << "Hide arr? 1/0: ";
    std::cin >> hide;

    long *arr = new long[size];
    long *arrCopy = new long[size];
    for (long i = 0; i < size; ++i) {
        arr[i] = getRandomlong(-1000.0f, 1000.0f);
    }

    if (hide != 1) std::cout << "Source array:\n";
    
    prlongArray(arr, size, hide);

    copyArray(arr, arrCopy, size);
    auto start = std::chrono::steady_clock::now();
    bubbleSort(arrCopy, size);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nBubble sorting:\n Time: " << duration.count() << " microsec" << std::endl;
    prlongArray(arrCopy, size, hide);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    insertsSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nInsert sorting:\n Time: " << duration.count() << " microsec" << std::endl;
    prlongArray(arrCopy, size, hide);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    choiseSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nChoise sorting:\n Time: " << duration.count() << " microsec" << std::endl;
    prlongArray(arrCopy, size, hide);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    shellSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nShell sorting:\n Time: " << duration.count() << " microsec" << std::endl;
    prlongArray(arrCopy, size, hide);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    quickSort(arrCopy, 0, size-1);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nQuick sorting:\n Time: " << duration.count() << " microsec" << std::endl;
    prlongArray(arrCopy, size, hide);
    system("pause");
    return 0;
}
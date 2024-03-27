#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

float getRandomFloat(float min, float max) {
    return floor(min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min))));
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void copyArray(float arr[], float arrCopy[], int size) {
    for (int i = 0; i < size; ++i) {
        arrCopy[i] = arr[i];
    }
}

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertsSort(float arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int value = arr[i];
        int position = i;
        while (position > 0 && arr[position - 1] > value) {
            arr[position] = arr[position - 1];
            position--;
        }
        
        arr[position] = value;
    }
}

void choiseSort(float arr[], int size) {
    for (int i = 0; i < size-1; ++i){ 
        int min = i;
        for (int x = i+1; x < size; ++x) {
            if (arr[x] < arr[min]) {
                min = x;
            }
        }
        if (min != i){
            float temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void shellSort(float arr[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

int partition(float arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));

    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    float *arr = new float[size];
    float *arrCopy = new float[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = getRandomFloat(-1000.0f, 1000.0f);
    }

    std::cout << "Source array:\n";
    printArray(arr, size);

    copyArray(arr, arrCopy, size);
    auto start = std::chrono::steady_clock::now();
    bubbleSort(arrCopy, size);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nBubble sorting:\n";
    std::cout << "Time: " << duration.count() << " microsec" << std::endl;
    printArray(arrCopy, size);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    insertsSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nInsert sorting:\n";
    std::cout << "Time: " << duration.count() << " microsec" << std::endl;
    printArray(arrCopy, size);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    choiseSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nChoise sorting:\n";
    std::cout << "Time: " << duration.count() << " microsec" << std::endl;
    printArray(arrCopy, size);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    shellSort(arrCopy, size);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nShell sorting:\n";
    std::cout << "Time: " << duration.count() << " microsec" << std::endl;
    printArray(arrCopy, size);

    copyArray(arr, arrCopy, size);
    start = std::chrono::steady_clock::now();
    quickSort(arrCopy, 0, sizeof(arr)/sizeof(arr[0])-1);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start); 
    std::cout << "\nQuick sorting:\n";
    std::cout << "Time: " << duration.count() << " microsec" << std::endl;
    printArray(arrCopy, size);

    system("pause");
    return 0;
}
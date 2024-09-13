
// Author: Lena Kemmelmeier
// Date: 7/3/23
// Purpose: PA5 - sorting algorithms & time complexity

#include <cstdlib>
#include <ctime>
// #include <iostream>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

// misc functions
void fillArrRandNums(int* numsArr, int size);
void copyArr(int numsArr[], int newArr[], int size);
// void printArrValues(int* numsArr, int size); //for checking values

// sorting functions
void bubbleSort(int* numsArr, int size, long int* comps, long int* swaps); //main algorithm
void selectionSort(int* numsArr, int size, long int* comps, long int* swaps); //extra credit algorithm
void insertionSort(int* numsArr, int size, long int* comps, long int* swaps); //main algorithm
void quickSort(int* numsArr, int low, int high, long int* comps, long int* swaps); //main algorithm
int partition(int* numsArr, int low, int high, long int* comps, long int* swaps); //helper for quickSort
void mergeSort(int* numsArr, int left, int right, int* sortArr, long int* comps, long int* swaps); //extra credit algorithm
void merge(int* numsArr, int left, int mid, int right, int* sortArr, long int* comps, long int* swaps); //helper for mergeSort

// tests for sorting functions
void testBubbleSort(int size, int* unsortedNums);
void testInsertionSort(int size, int* unsortedNums);
void testQuickSort(int size, int* unsortedNums);
void testMergeSort(int size, int* unsortedNums);
void testSelectionSort(int size, int* unsortedNums);

int main(){

    // unsorted arrays sized 1, 10, and 100 thousand
    int unsorted1000[1000], unsorted10000[10000], unsorted100000[100000];

    // fill the unsorted array with random numbers
    fillArrRandNums(unsorted1000, 1000);
    fillArrRandNums(unsorted10000, 10000);
    fillArrRandNums(unsorted100000, 100000);

    // test bubble sort
    testBubbleSort(1000, unsorted1000);
    testBubbleSort(10000, unsorted10000);
    testBubbleSort(100000, unsorted100000);

    // test insertion sort
    testInsertionSort(1000, unsorted1000);
    testInsertionSort(10000, unsorted10000);
    testInsertionSort(100000, unsorted100000);

    // test quick sort
    testQuickSort(1000, unsorted1000);
    testQuickSort(10000, unsorted10000);
    testQuickSort(100000, unsorted100000);  

    // test merge sort
    testMergeSort(1000, unsorted1000);  
    testMergeSort(10000, unsorted10000);  
    testMergeSort(100000, unsorted100000); 

    // test selection sort
    testSelectionSort(1000, unsorted1000);
    testSelectionSort(10000, unsorted10000);
    testSelectionSort(100000, unsorted100000);
   
    return 0;
}

void fillArrRandNums(int* numsArr, int size){
    srand((unsigned) time(NULL));

    for (int i = 0; i < size; i++){
         numsArr[i] = (rand() % 1000000) + 1;
    }
}

// for checking values
// void printArrValues(int* numsArr, int size){
//     for (int i = 0; i < size; i++){
//         cout << numsArr[i] << endl;
//     }
// }

void bubbleSort(int* numsArr, int size, long int* comps, long int* swaps){
    int tempVal;
    *comps = 0; *swaps = 0;

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            *comps = *comps + 1;

            if (numsArr[j] > numsArr[j + 1]){
                tempVal = numsArr[j];
                numsArr[j] = numsArr[j + 1];
                numsArr[j + 1] = tempVal;

                *swaps = *swaps + 1;
            }
        }
    }
}

void selectionSort(int* numsArr, int size, long int* comps, long int* swaps){
    int smallIndx, tempVal;
    *comps = 0; *swaps = 0;

    for(int i = 0; i < size - 1; i++){
        smallIndx = i;

        for(int j = i + 1; j < size; j++){
            *comps = *comps + 1;

            if (numsArr[j] < numsArr[smallIndx]){
                smallIndx = j;
            }
        }

        tempVal = numsArr[i];
        numsArr[i] = numsArr[smallIndx];
        numsArr[smallIndx] = tempVal;
        *swaps = *swaps + 1;
    }
}

void insertionSort(int* numsArr, int size, long int* comps, long int* swaps){
    int j, tempVal;
    *comps = 0; *swaps = 0;

    for(int i = 0; i < size; i++){
        j = i;

        *comps = *comps + 1;
        while(j > 0 && numsArr[j] < numsArr[j - 1]){
            tempVal = numsArr[j];
            numsArr[j] = numsArr[j - 1];
            numsArr[j - 1] = tempVal;
            j--;
            *swaps = *swaps + 1;
        }
    }
}

void copyArr(int numsArr[], int newArr[], int size){
    for(int i = 0; i < size; i++){
        newArr[i] = numsArr[i];
    }
}

void quickSort(int* numsArr, int low, int high, long int* comps, long int* swaps){
    int pivotIndx;

    if(low < high){
        pivotIndx = partition(numsArr, low, high, comps, swaps);
        quickSort(numsArr, low, pivotIndx - 1, comps, swaps);
        quickSort(numsArr, pivotIndx + 1, high, comps, swaps);
    }
}

int partition(int* numsArr, int low, int high, long int* comps, long int* swaps){
    int pivot = numsArr[high], i = low, tempVal;

    for(int j = low; j < high + 1; j++){
        *comps = *comps + 1;

        if (numsArr[j] < pivot){
            tempVal = numsArr[j];
            numsArr[j] = numsArr[i];
            numsArr[i] = tempVal;

            i++;
            *swaps = *swaps + 1;
        }
    }
    tempVal = numsArr[high];
    numsArr[high] = numsArr[i];
    numsArr[i] = tempVal;
    *swaps = *swaps + 1;

    return i;
}

void mergeSort(int* numsArr, int left, int right, int* sortArr, long int* comps, long int* swaps){
    int middle;

    if(right > left){
        middle = (left + right)/2;
        mergeSort(numsArr, left, middle, sortArr, comps, swaps);
        mergeSort(numsArr, middle + 1, right, sortArr, comps, swaps);
        merge(numsArr, left, middle, right, sortArr, comps, swaps);
    }
}

void merge(int* numsArr, int left, int mid, int right, int* sortArr, long int* comps, long int* swaps){
    int left1 = left, right1 = mid, left2 = mid + 1, right2 = right, k;

    for (k = left1; (left1 <= right1) && (left2 <= right2); k++){
        *comps = *comps + 1;
        if(numsArr[left1] <= numsArr[left2]){
            sortArr[k] = numsArr[left1];
            left1++;
            *swaps = *swaps + 1;
        }
        else{
            sortArr[k] = numsArr[left2];
            left2++;
            *swaps = *swaps + 1;
        }
    }

    while(left2 <= right2){
        sortArr[k] = numsArr[left2];
        left2++;
        *swaps = *swaps + 1;
        k++;
    }

    while(left1 <= right1){
        sortArr[k] = numsArr[left1];
        left1++;
        *swaps = *swaps + 1;
        k++;
    }

    for(int h = left; h <= right; h++){
        numsArr[h] = sortArr[h];
    }
}

void testBubbleSort(int size, int* unsortedNums){
    int sortedNums[size], bubbleSortedNums[size];
    long int numComps = 0, numSwaps = 0;
    string fName = "Bubble" + to_string(size) + ".csv";

    //make the sorted version of the array
    copyArr(unsortedNums, sortedNums, size);
    quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);

    ofstream file(fName);
    file << "Run Time, Comparisons, Swaps" << endl << "Unsorted,," << endl;

    for(int i = 0; i < 10; i++){
        copyArr(unsortedNums, bubbleSortedNums, size);

        time_point<high_resolution_clock> start = high_resolution_clock::now();
        bubbleSort(bubbleSortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file << endl << "Sorted,," << endl;
    for(int i = 0; i < 10; i++){
        
        time_point<high_resolution_clock> start = high_resolution_clock::now();
        bubbleSort(sortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file.close();
}

void testInsertionSort(int size, int* unsortedNums){
    int sortedNums[size], insertSortedNums[size];
    long int numComps = 0, numSwaps = 0;
    string fName = "Insertion" + to_string(size) + ".csv";

    //make the sorted version of the array
    copyArr(unsortedNums, sortedNums, size);
    quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);

    ofstream file(fName);
    file << "Run Time, Comparisons, Swaps" << endl << "Unsorted,," << endl;

    for(int i = 0; i < 10; i++){
        copyArr(unsortedNums, insertSortedNums, size);

        time_point<high_resolution_clock> start = high_resolution_clock::now();
        insertionSort(insertSortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file << endl << "Sorted,," << endl;
    for(int i = 0; i < 10; i++){
        
        time_point<high_resolution_clock> start = high_resolution_clock::now();
        insertionSort(sortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file.close();
}

void testQuickSort(int size, int* unsortedNums){
    int sortedNums[size], quickSortedNums[size];
    long int numComps = 0, numSwaps = 0;
    string fName = "Quick" + to_string(size) + ".csv";

    //make the sorted version of the array
    copyArr(unsortedNums, sortedNums, size);
    quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);

    ofstream file(fName);
    file << "Run Time, Comparisons, Swaps" << endl << "Unsorted,," << endl;

    for(int i = 0; i < 10; i++){
        copyArr(unsortedNums, quickSortedNums, size);
        numComps = 0, numSwaps = 0;

        time_point<high_resolution_clock> start = high_resolution_clock::now();
        quickSort(quickSortedNums, 0, size-1, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file << endl << "Sorted,," << endl;
    for(int i = 0; i < 10; i++){
        numComps = 0, numSwaps = 0;
        
        time_point<high_resolution_clock> start = high_resolution_clock::now();
        quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file.close();
}

void testMergeSort(int size, int* unsortedNums){
    int sortedNums[size], mergeSortedNums[size], tempArr[size];
    long int numComps = 0, numSwaps = 0;
    string fName = "Merge" + to_string(size) + ".csv";

    //make the sorted version of the array
    copyArr(unsortedNums, sortedNums, size);
    quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);

    ofstream file(fName);
    file << "Run Time, Comparisons, Swaps" << endl << "Unsorted,," << endl;

    for(int i = 0; i < 10; i++){
        copyArr(unsortedNums, mergeSortedNums, size);
        numComps = 0, numSwaps = 0;

        time_point<high_resolution_clock> start = high_resolution_clock::now();
        mergeSort(mergeSortedNums, 0, size-1, tempArr, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file << endl << "Sorted,," << endl;
    for(int i = 0; i < 10; i++){
        numComps = 0, numSwaps = 0;
        
        time_point<high_resolution_clock> start = high_resolution_clock::now();
        mergeSort(sortedNums, 0, size-1, tempArr, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file.close();  
}

void testSelectionSort(int size, int* unsortedNums){
    int sortedNums[size], selSortedNums[size];
    long int numComps = 0, numSwaps = 0;
    string fName = "Selection" + to_string(size) + ".csv";

    //make the sorted version of the array
    copyArr(unsortedNums, sortedNums, size);
    quickSort(sortedNums, 0, size-1, &numComps, &numSwaps);

    ofstream file(fName);
    file << "Run Time, Comparisons, Swaps" << endl << "Unsorted,," << endl;

    for(int i = 0; i < 10; i++){
        copyArr(unsortedNums, selSortedNums, size);

        time_point<high_resolution_clock> start = high_resolution_clock::now();
        insertionSort(selSortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file << endl << "Sorted,," << endl;
    for(int i = 0; i < 10; i++){
        
        time_point<high_resolution_clock> start = high_resolution_clock::now();
        insertionSort(sortedNums, size, &numComps, &numSwaps);
        time_point<high_resolution_clock> stop = high_resolution_clock::now();

        file << duration_cast<microseconds>(stop - start).count() << "," << numComps << "," << numSwaps << endl;
    }

    file.close();    
}
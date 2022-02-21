#include <iostream>
#include <cmath>

using namespace std;

int allEvens(int evens[], int array[], int evenSize, int arraySize);

int main(){
    int array[7] ={ 4, 9, 17, 22, 100, 1, 23};
    int evens[7] = {};
    allEvens(evens, array, 0, 7);
    for (int i=0; i<7; i++) {
        cout << evens[i] << endl;
    }

}

int allEvens(int evens[], int array[], int evenSize, int arraySize){
    if (arraySize == 0) {
        return -1;
    }
    if (array[arraySize-1]%2 == 0) {
        evens[evenSize] = array[arraySize-1];
        return allEvens(evens, array, evenSize+1, arraySize-1);
    }
    return allEvens(evens, array, evenSize, arraySize-1);

}



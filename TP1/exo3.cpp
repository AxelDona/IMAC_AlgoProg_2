#include <iostream>
#include <cmath>

using namespace std;

int search(int value, int array[], int size);

int main(){
    int array[10] = {5, 14, 13, 9, 2, 3, 89, 12, 0, 56};
    cout << search(5, array, 10) << endl;
}

int search(int value, int array[], int size){
    if(value == array[size-1]){
        return size-1;
    } else if(size == 0){
        return -1;
    }
    return search(value, array, size-1);
}



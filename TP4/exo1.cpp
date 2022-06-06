#include <iostream>
#include <array>

using namespace std;

struct heap{
    int *heapArr;
    int size = 0;

    void displayHeap(){
        cout << endl << "-- Heap display --" << endl;
        for(int i=0; i < (this->size); i++){
            cout << this->heapArr[i] << ", ";
        }
        cout << endl;
    };

    void insertHeapNode(int value){
        int i = this->size;
        this->heapArr[i] = value;
        heapify(i);
        this->size++;
    }

    void heapify(int i){
        int parent;
        parent = (i-1)/2;
        if(parent>=0){
            if(this->heapArr[parent] < this->heapArr[i]){
                swap(this->heapArr[parent],this->heapArr[i]);
                heapify(parent);
            }
        }
    }

    void buildHeap(int array[], int size){
        for (int i = 0; i < size; i++){
            this->insertHeapNode(array[i]);
        }
    }
};

int main(){
    heap* myHeap = new heap;
    myHeap->insertHeapNode(9);
    myHeap->insertHeapNode(8);
    myHeap->insertHeapNode(14);
    myHeap->insertHeapNode(22);
    myHeap->insertHeapNode(3);
    myHeap->insertHeapNode(43);
    myHeap->insertHeapNode(12);
    myHeap->displayHeap();
    cout << endl << "Building new heap from array..." << endl << endl;
    int array[7] = {5, 16, 18, 2, 188, 4, 13};
    heap* anotherHeap = new heap;
    anotherHeap->buildHeap(array, 7);
    anotherHeap->displayHeap();
}

#include <iostream>

using namespace std;

void displayTab(int tab[], int size);
void triSelection(int* tab, int size);

int main(){
    int size = 7;
    int tab[size] = {5, 12, 1, 99, 8, 56, 13};
    cout << endl;
    displayTab(tab, size);
    cout << endl << "--- TRI PAR SÉLECTION ---" << endl << endl;
    triSelection(tab, size);
    displayTab(tab, size);
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}

void triSelection(int* tab, int size){
    int min;
    int index;

    for(int j=0;j<size;j++){
        min = tab[j];
        index = tab[j];
        for(int i=j+1;i<size;i++){
            if(tab[i] < min){
                min = tab[i];
                index = i;
            }
        }
        tab[index] = tab[j];
        tab[j] = min;
    }
}
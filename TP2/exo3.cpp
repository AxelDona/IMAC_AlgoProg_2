#include <iostream>

using namespace std;

void displayTab(int tab[], int size);
void triBulles(int* tab, int size);

int main(){
    int size = 7;
    int tab[size] = {5, 12, 1, 99, 8, 56, 13};
    cout << endl;
    displayTab(tab, size);
    cout << endl << "--- TRI À BULLES ---" << endl << endl;
    triBulles(tab, size);
    displayTab(tab, size);
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}

void triBulles(int* tab, int size){
    int stock;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(tab[j] > tab[j+1]){
                stock = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = stock;
            }
        }
    }
}
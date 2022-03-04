#include <iostream>

using namespace std;

void displayTab(int tab[], int size);
void triRapide(int* tab, int size);

int main(){
    int size = 7;
    int tab[size] = {5, 12, 1, 99, 8, 56, 13};
    cout << endl;
    displayTab(tab, size);
    cout << endl << "--- TRI RAPIDE ---" << endl << endl;
    triRapide(tab, size);
    displayTab(tab, size);
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}

void triRapide(int* tab, int size){

    if(size<=1){
        return;
    }

    int pivot = tab[0];
    int lowers[size];
    int lowersSize=0;
    int greaters[size];
    int greatersSize=0;

    for(int i=1; i<size; i++){
        if(tab[i]>pivot){
            greaters[greatersSize]=tab[i];
            greatersSize++;
        } else {
            lowers[lowersSize]=tab[i];
            lowersSize++;
        }
    }

    triRapide(greaters, greatersSize);
    triRapide(lowers, lowersSize);

    for(int j=0; j<lowersSize; j++){
        tab[j]=lowers[j];
    }
    tab[lowersSize]=pivot;
    for(int k=0; k<greatersSize; k++){
        tab[k+lowersSize+1]=greaters[k];
    }

}
#include <iostream>

using namespace std;

int binarySearch(int tab[], int toSearch, int size);
void displayTab(int tab[], int size);

int main(){
    int size = 11;
    int tab[size] = {2, 6, 7, 9, 15, 22, 51, 53, 57, 68, 75};
    int toSearch;
    displayTab(tab, size);
    cout << "Entrez le nombre à rechercher dans le tableau :" << endl;
    cin >> toSearch;
    cout << binarySearch(tab, toSearch, size) << endl;
}

int binarySearch(int tab[], int toSearch, int size){

    int start = 0;
    int end = size;
    int mid = 0;

    while(start < end){
        mid = (start+end)/2;

        if (toSearch == tab[mid]){
            int foundIndex = mid;
            return foundIndex;
        } else if (toSearch > tab[mid]){
            start = mid+1;
        } else if (toSearch < tab[mid]){
            end = mid;
        }
    }
    return -1;
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}
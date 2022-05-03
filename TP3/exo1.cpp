#include <iostream>

using namespace std;

int binarySearch(int tab[], int toSearch, int start, int end);
void displayTab(int tab[], int size);

int main(){
    int size = 11;
    int tab[size] = {2, 6, 7, 9, 15, 22, 51, 53, 57, 68, 75};
    int start = 0;
    int end = size;
    int toSearch;
    cout << displayTab(tab, size) << endl;
    cout << "Entrez le nombre à rechercher dans le tableau :" << endl;
    cin >> toSearch;
    binarySearch(tab, toSearch, start, end);
}

int binarySearch(int tab[], int toSearch, int start, int end){
    while(start < end){
        int mid = (start+end)/2;

        if (toSearch === mid){
            int foundIndex = mid;
            return foundIndex;
        } else if (toSearch > tab[mid]){
            start = mid+1;
            binarySearch(tab, toSearch, start, end);
        } else if (toSearch < tab[mid]){
            end = mid;
            binarySearch(tab, toSearch, start, end);
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
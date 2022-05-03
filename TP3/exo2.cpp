#include <iostream>

using namespace std;

void binarySearchAll(int tab[], int toSearch, int size, int* indexMin, int* indexMax);
void displayTab(int tab[], int size);

int main(){
    int size = 12;
    int tab[size] = {6, 7, 7, 9, 17, 17, 17, 17, 22, 23, 28, 56};
    int toSearch;
    int indexMin = -1;
    int indexMax = -1;
    displayTab(tab, size);
    cout << "Entrez le nombre à rechercher dans le tableau :" << endl;
    cin >> toSearch;
    binarySearchAll(tab, toSearch, size, &indexMin, &indexMax);
    cout << "Index minimum : " << indexMin << endl;
    cout << "Index maximum : " << indexMax << endl;
}

void binarySearchAll(int tab[], int toSearch, int size, int* indexMin, int* indexMax){

    int start = 0;
    int end = size;
    int mid;

    while(start < end){

        if (*indexMin == -1 || *indexMax == -1) {

            mid = (start + end) / 2;

            if (toSearch == tab[mid]) {

                if (tab[mid-1] != toSearch && tab[mid+1] != toSearch){
                    *indexMin = mid;
                    *indexMax = mid;
                    return;
                }

                if (tab[mid - 1] != toSearch) {
                    cout << "Minimum trouvé" << endl;
                    *indexMin = mid;
                    start = mid+1;
                    end = size;
                }

                if (tab[mid + 1] != toSearch) {
                    cout << "Maximum trouvé" << endl;
                    *indexMax = mid;
                    end = mid-1;
                    start = 0;
                }

                if (tab[mid-1] == toSearch && tab[mid+1] == toSearch){
                    if(*indexMin != -1){
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }

            } else if (toSearch > tab[mid]) {
                start = mid + 1;
            } else if (toSearch < tab[mid]) {
                end = mid;
            }

        } else {
            return;
        }
    }
    return;
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}
#include <iostream>

using namespace std;

void displayTab(int tab[], int size);
void triInsertion(int* tab, int size);

int main(){
    int size = 7;
    int tab[size] = {5, 12, 1, 99, 8, 56, 13};
    cout << endl;
    displayTab(tab, size);
    cout << endl << "--- TRI PAR INSERTION ---" << endl << endl;
    triInsertion(tab, size);
    displayTab(tab, size);
}

void displayTab(int tab[], int size){
    cout << "Tableau : ";
    for(int i=0; i<size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}

void triInsertion(int* tab, int size){
    int result[size];
    result[0] = tab[0];
    int resultTaille = 1;
    bool bouclePassee = false;                              // Booléen de contrôle pour vérifier si on est passé dans la boucle k
    for(int i=1; i<size; i++){                              // Pour chaque valeur du tableau initial (exceptée la toute première qui est déjà stockée dans result)
        bouclePassee = false;                                   // On réinitialise le booléen de contrôle
        for(int j=0; j<resultTaille; j++){                      // Pour chaque valeur du Result
            if(tab[i] < result[j]){                                 // Si la valeur du tableau initial est inférieure à la valeur de l'index j de Result
                for(int k = resultTaille; k > j; k--) {                 // Alors en partant de la dernière valeur de Result, et en s'arrêtant juste avant d'atteindre la nouvelle valeur
                    result[k] = result[k-1];                                // On prend cette valeur et on la met dans le cellule suivante
                }
                result[j] = tab[i];                                     // Puis on remplace la valeur de l'index j par le tab[i]
                bouclePassee = true;
                break;                                                  // Si le if est rempli, on sort de la boucle j
            }
        }
        resultTaille++;
        if(bouclePassee == false){
            result[resultTaille-1] = tab[i];
        }
    }

    for(int i=0; i<size; i++){
        tab[i] = result[i];
    }
}
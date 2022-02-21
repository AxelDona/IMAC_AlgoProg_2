#include <iostream>
#include <cmath>

using namespace std;

struct DynaTableau{
    int tailleMax;
    int taille;
    int* tab;
};

void ajoute(int val, DynaTableau* dyn);
void affiche(DynaTableau dyn);

int main(){
    DynaTableau leDyn;
    leDyn.taille = 4;
    leDyn.tailleMax = 5;
    int tableau[leDyn.tailleMax] = {12, 4, 5, 84};
    leDyn.tab = tableau;
    cout << endl;
    affiche(leDyn);
    ajoute(8, &leDyn);
    cout << endl;
    cout << "On ajoute une valeur (8)" << endl;
    cout << endl;
    affiche(leDyn);
    ajoute(14, &leDyn);
    cout << endl;
    cout << "On ajoute encore une valeur (14)" << endl;
    cout << endl;
    affiche(leDyn);
}

void ajoute(int val, DynaTableau* dyn){
    if(dyn->taille < dyn->tailleMax){
        dyn->tab[dyn->taille] = val;
        dyn->taille +=1;
    } else {
        int* copieTab = new int[dyn->tailleMax+1];
        for (int i = 0; i<=dyn->taille; i++){
            copieTab[i] = dyn->tab[i];
        }
        dyn->taille +=1;
        dyn->tailleMax += 1;
        copieTab[dyn->tailleMax-1] = val;
        dyn->tab = copieTab;
    }
}

void affiche(DynaTableau dyn){
    cout << "Taille max : " << dyn.tailleMax << endl;
    cout << "Taille : " << dyn.taille << endl;
    for(int i = 0; i<dyn.taille; i++){
        cout << dyn.tab[i] << ", ";
    }
    cout << endl;
}
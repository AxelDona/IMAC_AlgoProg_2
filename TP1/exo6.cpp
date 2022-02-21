#include <iostream>
#include <cmath>

using namespace std;

struct DynaTableau{
    int tailleMax;
    int taille;
    int* tab;
};

struct Liste {
    int val;
    Liste *nxt;
} ;

void ajouteDyn(int val, DynaTableau* dyn);
void afficheDyn(DynaTableau dyn);
int recupereDyn(int n, DynaTableau dyn);
int chercheDyn(int n, DynaTableau dyn);
void stockeDyn(int n, int valeur, DynaTableau *dyn);
void ajouteLst(int val, Liste* lis);
int recupereLst(int n, Liste lis);
int chercheLst(int n, Liste* lis);
void stockeLst(int n, int newValeur, Liste *lis);

int main(){
    DynaTableau leDyn;
    leDyn.taille = 4;
    leDyn.tailleMax = 5;
    int tableau[leDyn.tailleMax] = {12, 4, 5, 84};
    leDyn.tab = tableau;
    cout << endl;
    cout << "-- DYNATABLEAUX-- " << endl << endl;
    afficheDyn(leDyn);
    ajouteDyn(8, &leDyn);
    cout << endl;
    cout << "On ajoute une valeur (8)" << endl;
    cout << endl;
    afficheDyn(leDyn);
    ajouteDyn(14, &leDyn);
    cout << endl;
    cout << "On ajoute encore une valeur (14)" << endl;
    cout << endl;
    afficheDyn(leDyn);
    cout << endl;
    cout << "On récupère la 5ème valeur du tableau :" << endl;
    cout << recupereDyn(4, leDyn) << endl;
    cout << endl;
    cout << "On cherche l'index de la valeur 84 dans le tableau :" << endl;
    cout << chercheDyn(84, leDyn) << endl;
    cout << endl;
    cout << "On redéfinit en 99 la valeur de l'index 2 du tableau :" << endl;
    stockeDyn(2, 99, &leDyn);
    afficheDyn(leDyn);
    cout << endl;
}

// FONCTIONS DYNATABLEAUX

void ajouteDyn(int val, DynaTableau* dyn){
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

void afficheDyn(DynaTableau dyn){
    cout << "Taille max : " << dyn.tailleMax << endl;
    cout << "Taille : " << dyn.taille << endl;
    for(int i = 0; i<dyn.taille; i++){
        cout << dyn.tab[i] << ", ";
    }
    cout << endl;
}

int recupereDyn(int n, DynaTableau dyn){
    return (dyn.tab[n]);
}

int chercheDyn(int n, DynaTableau dyn){
    for (int i=0; i<dyn.taille; i++) {
        if (dyn.tab[i] == n) {
            return i;
        }
    }
    return -1;
}

void stockeDyn(int n, int newValeur, DynaTableau *dyn){
    dyn->tab[n] = newValeur;
}

// FONCTIONS LISTE

void ajouteLst(int val, Liste* lis){
    Liste* add = new Liste;
    add->val = val;
    lis->nxt = add;
}

int recupereLst(int n, Liste lis){
    if (n == 0){
        return lis.val;
    }
    else {
        return (recupereLst(n-1, *(lis.nxt)));
    }
}

int chercheLst(int n, Liste* lis){
    int index = 0;
    while (lis != nullptr){
        if ((lis->val)==n){
            return index;
        }
        index++;
        lis = lis->nxt;
    }
    return -1;
}

void stockeLst(int n, int newValeur, Liste *lis){
    int index = 0;
    while (lis != nullptr){
        if (index == n){
            lis->val = newValeur;
        }
        index++;
        lis = lis->nxt;
    }
}


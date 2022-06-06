#include <iostream>
#include <array>

using namespace std;

struct HashTable {

    int size;
    string* tab;

    void display() {
        for (int i = 0; i < this->size; i++) {
            cout << this->tab[i] << ", " ;
        }
        cout << endl << endl;
    }

    int hash(string a) {

        if (this->size < (int)a[0]) {
            return (int)a[0] % this->size;
        }

        return (int)a[0];
    }

    void insert(string a) {
        int value = hash(a);
        this->tab[value] = a;
    }

    bool contains(string a) {
        for (int i=0; i<this->size; i++) {
            if (this->tab[i] == a) {
                return true;
            }
        }
        return false;
    }
};


int main(){
    HashTable* newHash = new HashTable;
    newHash->size = 7;
    string words[] = {"Oui", "Grille-pain", "Zidane", "Piste", "Nuit", "Ohlala", "Gugu"};
    newHash->tab = words;

    cout << "--- Affichage des mots ---" << endl << endl;
    newHash->display();

    cout << "--- Insertion d'un mot ---" << endl << endl;
    newHash->insert("Cramoisissant");
    newHash->display();

    cout << "--- Test de présence de mots ---" << endl << endl;
    cout << "Non : " << newHash->contains("Non") << endl;
    cout << "Cramoisissant : " << newHash->contains("Cramoisissant") << endl;

}

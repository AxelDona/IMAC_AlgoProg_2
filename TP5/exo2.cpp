#include <iostream>
#include <array>
#include <math.h>

using namespace std;

struct MapNode {

    string key;
    int keyHash;

    int value;
    MapNode* left;
    MapNode* right;

    MapNode(string key, int val) {

        this->key = key;
        this->value = val;
        this->keyHash = hash(key);

        this->left = this->right = nullptr;
    }


    void insertNode(MapNode* node) {

        if (node->keyHash < this->keyHash) {
            if (this->left == NULL) {
                this->left = node;
            } else {
                this->left->insertNode(node);
            }
        } else {
            if (this->right == NULL) {
                this->right = node;
            } else {
                this->right->insertNode(node);
            }
        }
    }

    void insertNode(string key, int value) {

        this->insertNode(new MapNode(key, value));

    }

    int hash(string key) {

        int i = 0;
        int val = 0;

        while (key[i]!='\0'){

            int pw = key.size() - (i + 1);
            val += (int)key[i] * pow(128,pw);

            i++;
        }
        return val;
    }

};

struct Map {

    Map() {
        this->root = nullptr;
    }

    void insert(string key, int value) {

        if (this->root == NULL) {
            this->root = new MapNode(key, value);
        } else {
            this->root->insertNode(key, value);
        }

    }

    int get(string key) {

        MapNode* node = this->root;

        while (node != NULL) {
            if (node->keyHash == hash(key)) {
                return node->value;
            } else if (node->keyHash < hash(key)) {
                node = node->right;
            } else if (node->keyHash > hash(key)) {
                node= node->left ;
            }
        }
        return 0;
    }

    int hash(string key) {

        int i = 0;
        int val = 0;

        while (key[i]!='\0'){

            int pw = key.size() - (i + 1);
            val += (int)key[i] * pow(128,pw);

            i++;
        }
        return val;
    }

    MapNode* root;
};



int main(){

    Map* newMap = new Map;

    newMap->insert("Zinédine", 10);
    newMap->insert("Jacky", 36);
    newMap->insert("Sacha", 77);
    newMap->insert("Doug", 16);

    cout << "--- RECHERCHE D'UN NOM ---" << endl;
    cout << "Jacky : " << newMap->get("Jacky") << endl;
    cout << "Donatien : " << newMap->get("Donatien") << endl;

}

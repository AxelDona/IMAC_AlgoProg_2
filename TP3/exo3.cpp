#include <iostream>

using namespace std;

struct binarySearchTree{
    int value;
    binarySearchTree* left = nullptr;
    binarySearchTree* right = nullptr;

    void displayTree() {

        if (!this) {
            cout << endl << "Il n'y a rien ici." << endl;
        }

        else {

            cout << endl << endl << "----- Noeud : " << this->value << " -----" << endl << endl;

            cout << "Est une feuille : ";
            this->isLeaf() ? cout << "Oui" << endl : cout << "Non" << endl;

            if (this->left){
                cout << endl << "[En bas à gauche de " << this->value << " => " << this->left->value << "]" << endl;
                this->left->displayTree();
            }

            if (this->right){
                cout << endl << "[En bas à droite de " << this->value << " => " << this->right->value << "]" << endl;
                this->right->displayTree();
            }

        }

    }

    void insertNumber(int value){

        binarySearchTree* Node  = new binarySearchTree;
        Node->value = value;

        if (value < this->value) {
            if (!this->left) {
                this->left = Node;
            }
            else {
                (this->left)->insertNumber(value);
            }
        }

        else {
            if (!this->right) {
                this->right = Node;
            }
            else {
                (this->right)->insertNumber(value);
            }
        }
    }

    int height() const {

        int hgtLeft = 1;
        int hgtRight = 1;

        if (this->left) {
            hgtLeft += this->left->height();
        }
        if (this->right) {
            hgtRight += this->right->height();
        }
        if (hgtRight > hgtLeft){
            return hgtRight;
        } else {
            return hgtLeft;
        }
    }

    int binarySearchTreesCount() const{

        int binarySearchTrees = 1;

        if (this->right){
            binarySearchTrees += this->right->binarySearchTreesCount();
        }
        if (this->left){
            binarySearchTrees += this->left->binarySearchTreesCount();
        }

        return binarySearchTrees;
    }

    bool isLeaf() const{
        return (!this->left && !this->right);
    }

    void allLeaves(binarySearchTree *leaves[], int &leavesCount) {

        if (this->isLeaf()) {

            leaves[leavesCount] = this;
            leavesCount++;

        } else {

            if (this->left) {
                this->left->allLeaves(leaves, leavesCount);
            }

            if (this->right) {
                this->right->allLeaves(leaves, leavesCount);
            }
        }
    }

    binarySearchTree* find(int targetValue) {
        if(this->value == targetValue){
            return this;
        } else if(this->value>targetValue && this->left){
            return this->left->find(targetValue);
        } else if(this->value<targetValue && this->right){
            return this->right->find(targetValue);
        }
        return nullptr;
    }

    void inorderTravel(binarySearchTree* binarySearchTrees[], int& binarySearchTreesCount) {

        if(this->left){
            this->left->inorderTravel(binarySearchTrees,binarySearchTreesCount);
        }

        binarySearchTrees[binarySearchTreesCount]=this;
        binarySearchTreesCount++;

        if(this->right){
            this->right->inorderTravel(binarySearchTrees,binarySearchTreesCount);
        }
    }

    void preorderTravel(binarySearchTree* binarySearchTrees[], int& binarySearchTreesCount) {

        binarySearchTrees[binarySearchTreesCount]=this;
        binarySearchTreesCount++;

        if(this->left){
            this->left->preorderTravel(binarySearchTrees,binarySearchTreesCount);
        }

        if(right){
            this->right->preorderTravel(binarySearchTrees,binarySearchTreesCount);
        }

    }

    void postorderTravel(binarySearchTree* binarySearchTrees[], int& binarySearchTreesCount) {

        if(this->left){
            this->left->inorderTravel(binarySearchTrees,binarySearchTreesCount);
        }

        if(this->right){
            this->right->inorderTravel(binarySearchTrees,binarySearchTreesCount);
        }

        binarySearchTrees[binarySearchTreesCount]=this;
        binarySearchTreesCount++;
    }

};


int main(){
    binarySearchTree* tree = new binarySearchTree;
    tree->value = 2;

    tree->insertNumber(7);
    tree->insertNumber(14);
    tree->insertNumber(6);
    tree->insertNumber(9);
    tree->insertNumber(2);
    tree->insertNumber(35);
    tree->insertNumber(8);
    tree->insertNumber(-1);

    cout << endl << "____________" << endl << endl << "Affichage de l'arbre : " << endl;
    tree->displayTree();

    cout << endl << "____________" << endl << endl << "Hauteur de l'arbre : " << tree->height() << endl;
    cout << endl << "____________" << endl << endl << "Nombre de noeuds de l'arbre : " << tree->binarySearchTreesCount() << endl;

    binarySearchTree* leaves[99];
    int leavesNumber=0;
    tree->allLeaves(leaves, leavesNumber);

    cout << endl << "____________" << endl << endl << "Nombre de feuilles de l'arbre : " << leavesNumber << endl;

    cout << endl << "____________" << endl << endl << "Recherche de noeuds contenant 9 : " << endl;
    tree->find(9)->displayTree();
    cout << "____________" << endl << endl << "Recherche de noeuds contenant 1465 : " << endl;
    tree->find(1465)->displayTree();
}
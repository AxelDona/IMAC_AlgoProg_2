#include <iostream>
#include <cmath>

using namespace std;

int power(int value, int n);

int main(){
    cout << power(5, 3) << endl;
}

int power(int value, int n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return value;
    } else {
        return (power(value, n-1))*value;
    }
}
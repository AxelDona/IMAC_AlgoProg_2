#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int n);

int main(){
    cout << fibonacci(7) << endl;
}

int fibonacci(int n){
    if(n == 0 || n == 1){
        return 0;
    } else if(n == 2){
        return 1;
    } else {
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}


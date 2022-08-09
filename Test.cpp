#include <iostream>

void changeInt(int*x);

using std::cout;
using std::endl;

int main(){
    int x = 1;
    int*xptr = &x;
    changeInt(xptr);
    cout << x << endl;
}

void changeInt(int*x){
    int*y = x;
    *y = 200;
}
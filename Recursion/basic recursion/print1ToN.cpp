#include <iostream>
using namespace std;

void print1ToN(int n) {
    if (n == 0) return;  
    print1ToN(n - 1);     // recursive call
    cout << n << " ";     // print after recursion
}



// void printNTo1(int n) {
//     if (n == 0) return;
//     cout << n << " ";    // print before recursion
//     printNTo1(n - 1);
// }


int main() {
    int n = 5;
    print1ToN(n);
    return 0;
}

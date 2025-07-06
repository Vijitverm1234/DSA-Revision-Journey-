/*
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

Examples:

Example 1:

Input: V = 70

Output: 2


*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int>arr={ 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n;
    cout<<"\nEnter n : ";
    cin>>n;
 
    int m=arr.size();
    int count=0;
    int i=m-1;

    while(n!=0){
        while(n>=arr[i]){
         count+=1;
         n-=arr[i];
        }
        i--;
    }
    cout<<"\nMinimum notes : "<<count;
}
/*

You are given an array a1,a2,…,an
 of positive integers.

You can make this operation multiple (possibly zero) times:

Choose two indices i
, j
 (1≤i,j≤n
, i≠j
).
Assign ai:=⌈aiaj⌉
. Here ⌈x⌉
 denotes x
 rounded up to the smallest integer ≥x
.
Is it possible to make all array elements equal by some sequence of operations (possibly empty)? If yes, print any way to do it in at most 30n
 operations.

It can be proven, that under the problem constraints, if some way exists to make all elements equal, there exists a way with at most 30n
 operations.

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases. Descriptions of test cases follow.

The first line of each test case description contains a single integer n
 (1≤n≤100
).

The second line of each test case description contains n
 integers a1,a2,…,an
 (1≤ai≤109
).

It is guaranteed, that the sum of n
 for all test cases does not exceed 1000
.

Output
For each test case print a single integer q
 (−1≤q≤30n
). If q=−1
, there is no solution, otherwise q
 is equal to the number of operations.

If q≥0
, on the next q
 lines print two integers i
, j
 (1≤i,j≤n
, i≠j
) — descriptions of operations.

If there are multiple solutions, you can print any.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;
int main(){
int n=4;
vector<int> arr={19,40,19,55};
int q=0;
while(true){
    sort(arr.begin(),arr.end());
    int temp=arr[0];
    int i=0;
    while(temp==1){
        temp=arr[i];
        i++;
    }
    arr.back()=ceil(arr.back()/temp);
    q+=1;
    int sum=accumulate(arr.begin(),arr.end(),0);
    if(sum==arr.size()){
        break;
    }
     bool all_equal = all_of(arr.begin(), arr.end(), [&](int x) { return x == arr[0]; });
    if (all_equal) break;
}
cout<<"operation "<<q;
}
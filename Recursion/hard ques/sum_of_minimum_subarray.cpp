#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long sum = 0;
    const int mod = 1e9 + 7;
    void solve(const vector<int>& arr, int start, int end) {
        int n = arr.size();
        if (start == n) return;
        if (end == n) {
            solve(arr, start + 1, start + 1);
            return;
        }
        int mini = INT_MAX;
        for (int i = start; i <= end; i++) {
            mini = min(mini, arr[i]);
        }
        sum = (sum + mini) % mod;
        solve(arr, start, end + 1);
    }

    int sumSubarrayMins(vector<int>& arr) {
        solve(arr, 0, 0);
        return (int)sum;
    }
};
int main(){
    vector<int> arr={11,81,94,43,3};
    Solution s;
    int res=s.sumSubarrayMins(arr);
    cout<<res;
}
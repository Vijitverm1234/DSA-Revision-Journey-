#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {12, 5, 2, 89, 10};
    
    // Define priority queue with min-heap using lambda comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                   decltype([](const pair<int, int>& a, const pair<int, int>& b) {
                       if (a.first != b.first) return a.first > b.first; // Min-heap on value
                       return a.second > b.second; // Break ties by index
                   })> pq;

    int n = arr.size();
    vector<int> rank(n, 0);
    
    // Push elements as {value, index}
    for (int i = 0; i < n; i++) {
        pq.push({arr[i], i});
    }
    
    int count = 0;
    int currRank = 1;
    int prev = -1; // Sentinel value for first element
    
    // Process priority queue
    while (!pq.empty()) {
        auto [element, ind] = pq.top();
        pq.pop(); // Remove top element
        
        // Update rank for new value
        if (prev == -1 || element != prev) {
            currRank += count;
            count = 1;
        } else {
            count++; // Increment for ties
        }
        
        rank[ind] = currRank;
        prev = element;
    }
    
    // Output ranks
    cout << "Rank Matrix" << endl;
    for (auto it : rank) {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}
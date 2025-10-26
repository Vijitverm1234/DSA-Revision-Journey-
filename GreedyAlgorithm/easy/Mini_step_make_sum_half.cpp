class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double sum=0;
        for(auto it :arr){
            sum+=it;
        }
        double target=sum/2;
        priority_queue<double>pq;
        int op=0;
        for (int x : arr) pq.push(x);
        while(sum>target){
            double el=pq.top();
            pq.pop();
            double curr=el/2;
            sum-=curr;
            op++;
            pq.push(curr);
        }
        return op;
    }
};
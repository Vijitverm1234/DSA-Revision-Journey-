class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : arr){
            pq.push(it);
            if(pq.size()==k+1){
                arr[i]=pq.top();
                pq.pop();
                i++;
            }
        }
        while(!pq.empty()){
            arr[i++]=pq.top();
            pq.pop();
        }
       
    }
};
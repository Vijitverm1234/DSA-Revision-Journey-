class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int currgas=0;
        int start=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            currgas+=(gas[i]-cost[i]);
            if(currgas<0){
                start=i+1;
                currgas=0;
            }
        }
        currgas=0;
        for(int i=0;i<n;i++){
            int ind=(i+start)%n;
            currgas+=(gas[ind]-cost[ind]);
            if(currgas<0){
                return -1;
            }
        }
        return start;
    }
};

// vector<int> res;
// void solve(vector<int> arr,int i,int k,vector<int>&temp){
//    if(i==arr.size()){
// 	   int sum=accumulate(temp.begin(),temp.end(),0);
// 	   res.push_back(sum);
//       return ;
//    }
//    temp.push_back(arr[i]);
//    solve(arr,i+1,k,temp);
//    temp.pop_back();
//    solve(arr,i+1,k,temp);
// }
// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	vector<int> temp;
// 	solve(arr,0,k,temp);
//    int count=0;
//    for(int i=0;i<res.size();i++){
//       if(res[i]==k){
//          count++;
//       }
//    }
//    return count;
// }

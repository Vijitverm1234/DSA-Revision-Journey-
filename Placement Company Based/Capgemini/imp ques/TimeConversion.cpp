class Solution {
  public:
   int stoi(string temp) {
    int n=temp.size();
    int res=0;
    int power=1;

    for (int i=n-1;i>=0;i--) {
        res+=(temp[i]-'0')*power;
        power*=10;
    }
    return res;
}

    int solve(string st){
        vector<int> arr;
        int n=st.size();
        string temp="";
        for(int i=0;i<n;i++){
          
            if(st[i]==':'){
                arr.push_back(stoi(temp));
                temp="";
            }
            else{
                temp+=st[i];
            }
        }
        arr.push_back(stoi(temp));
        return arr[0]*3600+arr[1]*60+arr[2];
    }
    int minDifference(vector<string> &arr) {
        // code here
        int n=arr.size();
        vector<int> temp(n,0);
        for(int i=0;i<arr.size();i++){
            temp[i]=solve(arr[i]);
        }
        sort(temp.begin(),temp.end());
        int res=INT_MAX;
        for(int i=1;i<n;i++){
            res=min(res,temp[i]-temp[i-1]);
        }
        return min(res,86400-(temp[n-1]-temp[0]));
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> res(n,0);

        // for(int i=0;i<temp.size();i++){
        //     int count=1;
        //     bool found=false;
        //     for(int j=i+1;j<temp.size();j++)
        //     {
               
        //         if(temp[i]<temp[j]){
        //             res.push_back(count);
        //             count=1;
        //             found=true;
        //             break;
        //         }
        //         else{
        //             count++;
        //         }
        //     }
        
        // if(!found){
        //     res.push_back(0);
        // }
        // }
        // return res;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
                int prev=st.top();
                res[prev]=i-prev;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
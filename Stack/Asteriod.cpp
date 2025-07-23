class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        for(auto it : arr){
            bool des=false;
            while(!st.empty() && it<0 && st.top()>0){
               if(st.top()<-it){
                st.pop();
               }
               else if(st.top()==abs(it)){
                st.pop();
                des=true;
                break;
               }
               else{
                des=true;
                break;
               }
            }
            if(!des){
                st.push(it);
            }
        }
        vector<int> res;
        while(!st.empty()){
            int el=st.top();
            st.pop();
            res.push_back(el);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
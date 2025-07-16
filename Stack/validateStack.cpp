class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int index=0;
        stack<int> st;
        for(auto it: pushed){
            st.push(it);
            while(!st.empty() && index<popped.size() && st.top()==popped[index]){
                st.pop();
                index++;
            }
        }
        return st.empty();
    }
};
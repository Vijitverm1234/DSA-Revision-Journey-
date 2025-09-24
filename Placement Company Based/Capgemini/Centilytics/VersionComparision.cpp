class Solution {
public:
    int compareVersion(string s1, string s2) {
      int n=s1.size();
      int m=s2.size();
      int i=0;
      int j=0;
        int num1=0;
        int num2=0;
      while(i<n || j<m){
         while(i<n && s1[i]!='.'){
            num1=num1*10+(s1[i++]-'0');
         }
          while(j<m && s2[j]!='.'){
            num2=num2*10+(s2[j++]-'0');
         }
         if(num1> num2){
            return 1;
         }
         if(num1<num2){
            return -1;
         }
         num1=0;
         num2=0;
         i++;
         j++;
      }
      return 0;
    }
};
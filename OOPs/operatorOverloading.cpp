#include<iostream>
#include<algorithm>
using namespace std;
class StringClass{
    public:
    string str;
    StringClass(string s):str(s){}
    StringClass operator +(const StringClass&  obj) const {
        return StringClass(str+obj.str);
    }
};
int main(){
    StringClass st1("Vijit ");
    StringClass st2("Verma");
    cout<<"Appplying operator overloading"<<endl;
    StringClass s3=st1+st2;
    cout<<s3.str<<endl;uu
    
}
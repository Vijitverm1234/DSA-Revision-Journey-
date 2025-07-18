#include<iostream>
using namespace std;
class Fun{
    private:
    string name;
    string password;
    public:
    Fun(){    //Default;
        name="Vijit Verma";
        password="1234";
    }
    Fun(string name,string password){
        this->name=name;
        this->password=password;
    }
    void display(){
        cout<<"Name : "<<name<<" "<<" password "<<password<<endl;
    }

};
int main(){
   Fun f;
   f.display();
   Fun f2("Mohit","hSILA");
    f2.display();
}
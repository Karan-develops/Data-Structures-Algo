#include<iostream>
using namespace std;
void findString(string s,string a){
    int index=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]){
            
        }
    }
    if(index){
        cout<<"Sub-String found at index:"<<index;
    }
    else{
        cout<<"Sub-String not found";
    }
}
int main(){
    string s="Karan Aggarwal";
    string a;
    cout<<"Enter subString to find:";
    getline(cin,a);
    findString(s,a);
    return 0;
}
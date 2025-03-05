#include<iostream>
using namespace std;
void reverseStr(string& str,int i,int n){
    if(i>=n) return;
    swap(str[i],str[n]);
    reverseStr(str,i+1,n-1);
}
int main(){
    string str="abcdefg";
    int i=0,n=str.length();
    reverseStr(str,i,n-1);
    cout<<"Answer is: "<<str;
    return 0;
}
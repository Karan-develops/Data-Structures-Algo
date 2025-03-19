#include<iostream>
using namespace std;
// If we don't pass by-reference we don't need back-tracking line
void permute(string& str,int i,int n){
    if(i>=n){
        cout<<str<<" ";
        return;
    }
    for(int j=i;j<n;j++){
        // swap
        swap(str[i],str[j]);
        // recursive call
        permute(str,i+1,n);
        // backtracking -> to re-create the original input string
        swap(str[i],str[j]);
    }
}
int main(){
    string str="abc";
    int n=str.length();
    permute(str,0,n);
    return 0;
}
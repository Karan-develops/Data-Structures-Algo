#include<iostream>
#include<vector>
using namespace std;
void printSubsequences(string str,string output,int i,int n,vector<string>& ans){
    if(i>=n){
        ans.push_back(output);
        return;
    }
    // exclude
    printSubsequences(str,output,i+1,n,ans);
    // include
    output+=str[i];
    printSubsequences(str,output,i+1,n,ans);
}
int main(){
    string str="abc";
    string output="";
    int i=0;
    int n=str.length();
    vector<string>ans;
    printSubsequences(str,output,i,n,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
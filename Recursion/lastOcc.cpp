#include<iostream>
using namespace std;
void solveLTR(string& str,char& ch,int i,int& n,int& ans){
    if(i>=n) return;
    if(str[i]==ch) ans=i;
    solveLTR(str,ch,i+1,n,ans);
}
void solveRTL(string& str,char& ch,int i,int& ans){
    if(i<0) return;
    if(str[i]==ch){
        ans=i;
        return;
    }
    solveRTL(str,ch,i-1,ans);
}
int main(){
    string str="abcdeddef";
    char ch='d';
    int n=str.length();
    int ans1=-1;
    int ans2=-1;
    solveLTR(str,ch,0,n,ans1);
    solveRTL(str,ch,n-1,ans2);
    cout<<"Answer is:"<<ans1<<endl;
    cout<<"Answer is:"<<ans2;
    return 0;
}
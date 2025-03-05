// Pending
#include<iostream>
#include<algorithm>
using namespace std;
int charToInt(char s) { return s - '0'; }
char intToChar(int a) { return a + '0'; }
void addStrs(string& str1,string& str2,int i,int j,string& ans,int carry){
    if(i<0 && j<0){
        if(carry){
            ans.push_back(carry);
            return;
        }
        return;
    }
    int sum=charToInt(str1[i])+charToInt(str2[j])+carry;
    int sol=sum%10;
    ans.push_back(intToChar(sol));
    carry=sum/10;
    addStrs(str1,str2,i-1,j-1,ans,carry);
}
int main(){
    string str1="223";
    string str2="321";
    string ans="";
    int n1=str1.length(),n2=str2.length();
    addStrs(str1,str2,n1-1,n2-1,ans,0);
    reverse(ans.begin(),ans.end());
    cout<<"Answer is: "<<ans;
    return 0;
}
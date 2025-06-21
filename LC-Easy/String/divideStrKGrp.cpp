// LC - 2138 - Easy - Divide a String Into Groups of Size k
#include<iostream>
#include<vector>
using namespace std;
vector<string> divideString(string s,int k,char fill){
    int n=s.length();
    vector<string>ans;

    for(int i=0;i<n;i+=k){
        if(i+k<=n) ans.push_back(s.substr(i,k));
        else{
            string temp=s.substr(i);
            temp+=string(k-temp.length(),fill);
            ans.push_back(temp);
        }
    }
    return ans;
}
int main(){
    // Output: ["abc","def","ghi"]
    string s="abcdefghi";
    int k=3;
    char fill='x';
    // Output: ["abc","def","ghi","jxx"]
    string s2="abcdefghij";
    int k2=3;
    char fill2='x';
    return 0;
}
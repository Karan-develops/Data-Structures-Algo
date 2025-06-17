// LC - 2729 - Easy - Check if The Number is Fascinating
#include<iostream>
#include<unordered_map>
using namespace std;
bool isFascinating(int n){
    string temp=to_string(n);

    int val1=2*n,val2=3*n;

    string s=temp+to_string(val1)+to_string(val2);

    unordered_map<char,int>mp;
    for(char &ch:s){
        if(ch=='0') return false;
        mp[ch]++;
        if(mp[ch]>1) return false;
    }
    return true;
}
int main(){
    // Output: true
    int n=192;
    // Output: false
    int n2=100;
    cout<<isFascinating(n)<<endl;
    cout<<isFascinating(n2);
    return 0;
}
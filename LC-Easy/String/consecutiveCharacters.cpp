// LC - 1446 - Easy - Consecutive Characters
#include<iostream>
using namespace std;
int maxPower(string s){
    char prevCh=s[0];
    int ans=0,count=0;

    for(char &ch:s){
        if(ch==prevCh){
            count++;
        } else{
            count=1;
            prevCh=ch;
        }
        ans=max(ans,count);
    }
    return ans;
}
int main(){
    // Output: 2
    string s="leetcode";
    // Output: 5
    string s2="abbcccddddeeeeedcba";
    cout<<maxPower(s)<<endl;
    cout<<maxPower(s2);
    return 0;
}
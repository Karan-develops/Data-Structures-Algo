// LC - 3442 - Easy - Maximum Difference Between Even and Odd Frequency I
#include<iostream>
#include<vector>
using namespace std;
int maxDifference(string s) {
    int ans=0;
    vector<int>v(26,0);

    for(char &ch:s) v[ch-'a']++;

    int maxEven=INT_MAX,maxOdd=INT_MIN;
    for(int i=0;i<26;i++){
        if(v[i]>0){
            if(v[i]&1) maxOdd=max(maxOdd,v[i]);
            else maxEven=min(maxEven,v[i]);
        }
    }
    
    return maxOdd-maxEven;
}
int main(){
    // Output: 3
    string s="aaaaabbc";
    // Output: 1
    string s2="abcabcab";
    cout<<maxDifference(s)<<endl;
    cout<<maxDifference(s2);
    return 0;
}
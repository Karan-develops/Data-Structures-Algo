// LC - 3707 - Easy - Equal Score Substrings
#include<iostream>
#include<vector>
using namespace std;
bool scoreBalance(string s){
    int n=s.length();
    
    vector<int>prefix(n,0);
    prefix[0]=s[0]-'a'+1;

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(s[i]-'a'+1);
    }

    int total=prefix[n-1];

    for(int i=0;i<n;i++){
        int left=prefix[i];
        int right=total-left;

        if(left==right) return true;
    }
    return false;
}
int main(){
    // Output: true
    string s="adcb";
    // Output: false
    string s2="bace";
    cout<<scoreBalance(s)<<endl;
    cout<<scoreBalance(s2);
    return 0;
}
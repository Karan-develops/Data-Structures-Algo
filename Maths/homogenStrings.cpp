// LC - 1759 - Medium - Count Number of Homogenous Substrings
#include<iostream>
using namespace std;
const int MOD=1e9+7;
int countHomogenous(string s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        long long count=1;
        while(i+1<n && s[i]==s[i+1]){
            count++;
            i++;
        }
        ans=(ans+((count*(count+1))/2))%MOD;
    }
    return ans;
}
int main(){
    // Output: 13
    string s="abbcccaa";
    // Output: 2
    string s2="xy";
    // Output: 15
    string s3="zzzzz";
    cout<<countHomogenous(s)<<endl;
    cout<<countHomogenous(s2)<<endl;
    cout<<countHomogenous(s3);
    return 0;
}
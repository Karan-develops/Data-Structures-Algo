// LC - 3234 - Medium - Count the Number of Substrings With Dominant Ones
// 2 Approaches
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// Approach 1 - Prefix Sum - TLE
int numberOfSubstringsPrefix(string s){
    int n=s.length();

    vector<int>prefix(n,0);
    prefix[0]=s[0]-'0';

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(s[i]-'0');
    }

    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ones=prefix[j]-(i>0?prefix[i-1]:0);
            int zeroes=(j-i+1)-ones;

            if((zeroes*zeroes)<=ones) ans++;
        }
    }

    return ans;
}
// Approach 2 - Optimized - ACCEPTED
int numberOfSubstrings(string s){
    int n=s.length();

    vector<int>prefix(n,0);
    prefix[0]=s[0]-'0';

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(s[i]-'0');
    }

    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ones=prefix[j]-(i>0?prefix[i-1]:0);
            int zeroes=(j-i+1)-ones;

            if((zeroes*zeroes)>ones){
                // skip j to avoid waste indices
                int wasteIndices=(zeroes*zeroes)-ones;
                j+=wasteIndices-1;
            } else if((zeroes*zeroes)==ones){
                ans+=1;
            } else{ // (zeroes * zeroes) < ones
                // [i....j] is a valid substring
                ans+=1;

                // try to see how much j can shift to right until substring remains dominant
                int k=sqrt(ones)-zeroes;
                int next=j+k;

                if(next>=n){ // out of bound, means all indices are valid
                    ans+=(n-j-1);
                    break; // early break
                } else{
                    ans+=k;
                }
                j=next;
            }
        }
    }

    return ans;
}
int main(){
    // Output: 5
    string s="00011";
    // Output: 16
    string s2="101101";
    cout<<numberOfSubstrings(s)<<endl;
    cout<<numberOfSubstrings(s2);
    return 0;
}
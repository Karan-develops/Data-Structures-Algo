#include<iostream>
using namespace std;
int minimumRecolors(string s,int k){
    int n=s.length();
    int i=0,j=0;
    int white=0;
    int ans=k;
    while(j<n){
        if(s[j]=='W') white++;
        if(j-i+1==k){
            ans=min(ans,white);
            if(s[i]=='W') white--;
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    string s1="WBBWWBBWBW";
    int k1=7;
    string s2="WBWBBBW";
    int k2=2;
    cout<<minimumRecolors(s1,k1)<<endl;
    cout<<minimumRecolors(s2,k2)<<endl;
    return 0;
}
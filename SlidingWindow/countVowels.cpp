// LC - 1456 - Medium - Maximum Number of Vowels in a Substring of Given Length
#include<iostream>
using namespace std;
int maxVowels(string s, int k) {
    int n=s.length();
    int i=0,j=0;
    int count=0;
    int ans=0;

    auto isVowel=[&](char &ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    };

    while(j<n){
        if(isVowel(s[j])) count++;

        if(j-i+1>=k){
            ans=max(ans,count);
            if(isVowel(s[i])) count--;
            i++;
        }

        j++;
    }
    return ans;
}
int main(){
    // Output: 3
    string s="abciiidef";
    int k=3;
    // Output: 2
    string s2="aeiou";
    int k2=2;
    // Output: 2
    string s3="leetcode";
    int k3=3;
    cout<<maxVowels(s,k)<<endl;
    cout<<maxVowels(s2,k2)<<endl;
    cout<<maxVowels(s3,k3);
    return 0;
}
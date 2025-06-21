// LC - 3085 - Medium - Minimum Deletions to Make String K-Special
#include<iostream>
#include<vector>
using namespace std;
int minimumDeletions(string word,int k){
    int n=word.length();
    int ans=INT_MAX;

    vector<int>v(26,0);
    for(char &ch:word) v[ch-'a']++;

    for(int i=0;i<26;i++){
        if(v[i]==0) continue;

        int curr=0;
        for(int j=0;j<26;j++){
            // If it is smaller just Delete it
            if(v[i]>v[j]) curr+=v[j];
            else if(abs(v[j]-v[i])>k){
                curr+=abs(v[j]-v[i]-k);
            }
        }
        ans=min(ans,curr);
    }
    return ans;
}
int main(){
    // Output: 3
    string word="aabcaba";
    int k=0;
    // Output: 2
    string word2="dabdcbdcdcd";
    int k2=2;
    // Output: 1
    string word3="aaabaaa";
    int k3=2;
    cout<<minimumDeletions(word,k)<<endl;
    cout<<minimumDeletions(word2,k2)<<endl;
    cout<<minimumDeletions(word3,k3);
    return 0;
}
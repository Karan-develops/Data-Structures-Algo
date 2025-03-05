#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1{1,3,5,7};
    vector<int>v2{2,4,6,8};
    vector<int>ans;
    int i=0,j=0;
    int s1=v1.size(),s2=v2.size();
    while(i<s1 && j<s2){
        if(v1[i]<v2[j]){
            ans.push_back(v1[i++]);
        } else{
            ans.push_back(v2[j++]);
        }
    }
    while(i<s1){
        ans.push_back(v1[i++]);
    }
    while(j<s2){
        ans.push_back(v2[j++]);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
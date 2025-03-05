#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1{1,2,3,8,12,18};
    vector<int>v2{3,12,19,22};
    vector<int>ans;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                v2[j]=INT_MIN;
            }
        }
    }
    for(int i=0;i<v1.size();i++){
        ans.push_back(v1[i]);
    }
    for(int i=0;i<v2.size();i++){
        ans.push_back(v2[i]);
    }
    for(auto i:ans){
        if(i!=INT_MIN){
            cout<<i<<" ";
        }
    }
    return 0;
}
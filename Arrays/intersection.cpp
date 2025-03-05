#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1{1,2,2,3,4,5,6,8,12};
    vector<int>v2{5,5,6,6,10,12};
    vector<int>ans;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                ans.push_back(v1[i]);
                v1[i]=-1; // Flag for handling wrong count
                v2[j]=-1; // Flag for handling wrong count
            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
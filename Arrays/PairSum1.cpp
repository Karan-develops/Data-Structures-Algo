// Doublet
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{1,3,5,7,2,4,6};
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if((v[i]+v[j])==9){
                cout<<"("<<v[i]<<","<<v[j]<<")"<<" ";
            }
        }
    }
    return 0;
}
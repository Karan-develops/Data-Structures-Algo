#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>v{1,5,3,4,3,5,6};
    unordered_map<int,int>hash;
    for(int i=0;i<v.size();i++){
        hash[v[i]]++;
    }
    for(int i=0;i<v.size();i++){
        if(hash[v[i]]>1){
            cout<<i+1;
            break;
        }
    }
    return 0;
}
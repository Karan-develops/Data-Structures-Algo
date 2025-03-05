#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{0,1,0,1,1,0,1,1,0,1};
    int start=0;
    int end=v.size()-1;
    while(start<end){
        if(v[start]==0){
            start++;
        }
        else{
            swap(v[start],v[end]);
            end--;
        }
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr1[5]={3,42,2,24,5};
    int sizeA=5;
    int arr2[3]={12,35,8};
    int sizeB=3;
    vector<int>vec;
    for(int i=0;i<sizeA;i++){
        vec.push_back(arr1[i]);
    }
    for(int i=0;i<sizeB;i++){
        vec.push_back(arr2[i]);
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}
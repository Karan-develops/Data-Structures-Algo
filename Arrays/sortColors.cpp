#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{1,2,1,0,0,2,1,2,0,1,2,1,2,0};
    int l=0;
    int m=0;
    int h=v.size()-1;
    while(m<=h){
        if(v[m]==0){
            swap(v[l],v[m]);
            l++;
            m++;
        }
        else if(v[m]==1){
            m++;
        }
        else{
            swap(v[m],v[h]);
            h--;
        }
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
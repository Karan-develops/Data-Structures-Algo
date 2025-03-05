#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x;
    int window;
    vector<int>v{12,16,22,30,35,39,42,45,48,50,53,55,56};
    vector<int>ans;
    cout<<"Enter target element x:";
    cin>>x;
    cout<<"Enter number of closest elements in window:";
    cin>>window;
    int low=0;
    int high=v.size();
    while((high-low)>=window){
        if(x-v[low]<v[high]-x){
            high--;
        }
        else{
            low++;
        }
    }
    for(int i=low;i<=high;i++){
        ans.push_back(v[i]);
    }
    for(auto i:ans){
        cout<<i<<" "; 
    }
    return 0;
}
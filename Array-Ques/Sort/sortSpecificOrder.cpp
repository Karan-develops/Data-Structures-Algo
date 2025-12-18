// GFG - Medium - Sort in specific order
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortIt(vector<int>&arr){
    vector<int>odds,evens;
    
    for(int &i:arr){
        if(i&1) odds.push_back(i);
        else evens.push_back(i);
    }
    
    sort(begin(odds),end(odds),greater<>());
    sort(begin(evens),end(evens));
    
    arr.clear();
    
    arr.insert(end(arr),begin(odds),end(odds));
    arr.insert(end(arr),begin(evens),end(evens));
}
void sortIt(vector<int>&arr){
    auto lambda=[&](int a,int b){
        bool aOdd=(a&1);
        bool bOdd=(b&1);
        
        if(aOdd && bOdd) return a>b;
        
        if(!aOdd && !bOdd) return a<b;
        
        return aOdd;
    };
    
    sort(begin(arr),end(arr),lambda);
}
int main(){
    // Output: [7, 5, 3, 1, 2, 4, 10]
    vector<int>arr={1,2,3,5,4,7,10};
    // Output: [7, 5, 3, 1, 0, 2, 4]
    vector<int>arr2={0,4,5,3,7,2,1};
    return 0;
}
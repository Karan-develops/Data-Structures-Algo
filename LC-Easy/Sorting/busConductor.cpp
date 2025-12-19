// GFG - Easy - Bus Conductor
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMoves(vector<int>&chairs,vector<int>&passengers){
    int n=chairs.size();
    
    sort(begin(chairs),end(chairs));
    sort(begin(passengers),end(passengers));
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        ans+=abs(chairs[i]-passengers[i]);
    }
    
    return ans;
}
int main(){
    // Output: 4
    vector<int>chairs={3,1,5},passengers={2,7,4};
    // Output: 4
    vector<int>chairs2={2,2,6,6},passengers2={1,3,2,6};
    cout<<findMoves(chairs,passengers)<<endl;
    cout<<findMoves(chairs2,passengers2);
    return 0;
}
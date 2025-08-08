// LC - 2391 - Medium - Minimum Amount of Time to Collect Garbage
#include<iostream>
#include<vector>
using namespace std;
int garbageCollection(vector<string>&garbage,vector<int>&travel){
    int n=garbage.size();

    int M_idx=0,P_idx=0,G_idx=0;
    int ans=0;

    for(int i=0;i<n;i++){
        for(char &ch:garbage[i]){
            if(ch=='M') M_idx=i;
            else if(ch=='P') P_idx=i;
            else G_idx=i;
            ans++;
        }
    }

    for(int i=1;i<travel.size();i++){
        travel[i]+=travel[i-1];
    }

    ans+=(M_idx-1>=0?travel[M_idx-1]:0);
    ans+=(P_idx-1>=0?travel[P_idx-1]:0);
    ans+=(G_idx-1>=0?travel[G_idx-1]:0);
    
    return ans;
}
int main(){
    // Output: 21
    vector<string>garbage={"G","P","GP","GG"};
    vector<int>travel={2,4,3};
    // Output: 37
    vector<string>garbage2={"MMM","PGM","GP"};
    vector<int>travel2={3,10};
    cout<<garbageCollection(garbage,travel)<<endl;
    cout<<garbageCollection(garbage2,travel2);
    return 0;
}
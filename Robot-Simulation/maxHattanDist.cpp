// LC - 3443 - Medium - Maximum Manhattan Distance After K Changes
#include<iostream>
#include<vector>
using namespace std;
int maxDistance(string s,int k){
    int ans=0;

    int east=0,west=0,south=0,north=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='N') north++;
        else if(s[i]=='S') south++;
        else if(s[i]=='E') east++;
        else west++;

        int currMD=abs(north-south)+abs(east-west);
        
        int steps=i+1;
        int wastage=steps-currMD;

        int extra=0;
        // Steps!=currMD (Best Case should be steps==currMD)
        // By correcting one wrong direction we are gaining 2 points
        if(wastage!=0) extra=min(wastage,2*k);

        currMD+=extra;
        ans=max(ans,currMD);
    }
    return ans;
}
int main(){
    // Output: 3
    string s="NWSE";
    int k=1;
    // Output: 6
    string s2="NSWWEW";
    int k2=3;
    cout<<maxDistance(s,k)<<endl;
    cout<<maxDistance(s2,k2);
    return 0;
}
// LC - 1996 - Medium - The Number of Weak Characters in the Game
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numberOfWeakCharacters(vector<vector<int>>& properties) {
    auto lambda=[&](vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    };

    sort(properties.begin(),properties.end(),lambda);
    int maxDef=0,weak=0;

    for(int i=properties.size()-1;i>=0;--i){
        if(properties[i][1]<maxDef) weak++;
        else maxDef=max(maxDef,properties[i][1]);
    }
    return weak;
}
int main(){
    // Output: 0
    vector<vector<int>>properties={{5,5},{6,3},{3,6}};
    // Output: 1
    vector<vector<int>>properties2={{2,2},{3,3}};
    // Output: 1
    vector<vector<int>>properties3={{1,5},{10,4},{4,3}};
    cout<<numberOfWeakCharacters(properties)<<endl;
    cout<<numberOfWeakCharacters(properties2)<<endl;
    cout<<numberOfWeakCharacters(properties3);
    return 0;
}
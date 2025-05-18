// LC - 2410 - Medium - Maximum Matching of Players With Trainers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int matchPlayersAndTrainers(vector<int>&players,vector<int>&trainers){
    sort(begin(players),end(players));
    sort(begin(trainers),end(trainers));

    int ans=0;
    int i=0,j=0;
    int m=players.size(),n=trainers.size();
    while(i<m && j<n){
        if(players[i]<=trainers[j]){
            ans++;
            i++,j++;
        }
        else j++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>players={4,7,9},trainers={8,2,5,8};
    // Output: 1
    vector<int>players2={1,1,1},trainers2={10};
    cout<<matchPlayersAndTrainers(players,trainers)<<endl;
    cout<<matchPlayersAndTrainers(players2,trainers2);
    return 0;
}
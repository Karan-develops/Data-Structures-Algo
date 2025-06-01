// LC - 874 - Medium - Walking Robot Simulation
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int robotSim(vector<int>&commands,vector<vector<int>>&obstacles){
    unordered_set<string>obs;

    for(auto &vec:obstacles){
        int x=vec[0];
        int y=vec[1];

        string key=to_string(x)+"_"+to_string(y);
        obs.insert(key);
    }

    int ans=0;
    int x=0,y=0;
    // North
    pair<int,int>dir={0,1};

    for(int &i:commands){
        // Left
        if(i==-2){
            dir={-dir.second,dir.first};
        } else if(i==-1){ // Right
            dir={dir.second,-dir.first};
        } else{
            for(int steps=0;steps<i;steps++){
                int newX=x+dir.first;
                int newY=y+dir.second;

                string key=to_string(newX)+"_"+to_string(newY);
                if(obs.find(key)!=obs.end()){
                    break;
                }

                x=newX;
                y=newY;
            }
        }
        ans=max(ans,(x*x+y*y));
    }
    return ans;
}
int main(){
    // Output: 25
    vector<int>commands={4,-1,3};
    vector<vector<int>>obstacles={};
    // Output: 65
    vector<int>commands2={4,-1,4,-2,4};
    vector<vector<int>>obstacles2={{2,4}};
    // Output: 36
    vector<int>commands3={6,-1,-1,6};
    vector<vector<int>>obstacles3={{0,0}};
    cout<<robotSim(commands,obstacles)<<endl;
    cout<<robotSim(commands2,obstacles2)<<endl;
    cout<<robotSim(commands3,obstacles3);
    return 0;
}
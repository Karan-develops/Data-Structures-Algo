// LC - 1298 - HARD - Maximum Candies You Can Get from Boxes
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
int maxCandies(vector<int>&status,vector<int>&candies,vector<vector<int>>&keys,vector<vector<int>>&containedBoxes,vector<int>&initialBoxes){
    int ans=0;
    
    unordered_set<int>visited;
    unordered_set<int>foundBoxes;
    queue<int>q;

    // Insert those which you have now and you can open it
    for(int &i:initialBoxes){
        foundBoxes.insert(i);
        if(status[i]==1){
            q.push(i);
            visited.insert(i);
            ans+=candies[i];
        }
    }

    while(!q.empty()){
        int box=q.front();
        q.pop();

        for(int &insideBox:containedBoxes[box]){
            foundBoxes.insert(insideBox);
            if(status[insideBox]==1 && !visited.count(insideBox)){
                q.push(insideBox);
                visited.insert(insideBox);
                ans+=candies[insideBox];
            }
        }

        for(int &boxKey:keys[box]){
            // Can be opened in future if we reach this box
            status[boxKey]=1;
            if(foundBoxes.count(boxKey) && !visited.count(boxKey)){
                q.push(boxKey);
                visited.insert(boxKey);
                ans+=candies[boxKey];
            }
        }
    }
    return ans;
}
int main(){
    // Output: 16
    vector<int>status={1,0,1,0};
    vector<int>candies={7,5,4,100};
    vector<vector<int>>keys={{},{},{1},{}};
    vector<vector<int>>containedBoxes={{1,2},{3},{},{}};
    vector<int>initialBoxes={0};
    // Output: 6
    vector<int>status2={1,0,0,0,0,0};
    vector<int>candies2={1,1,1,1,1,1};
    vector<vector<int>>keys2={{1,2,3,4,5},{},{},{},{},{}};
    vector<vector<int>>containedBoxes2={{1,2,3,4,5},{},{},{},{},{}};
    vector<int>initialBoxes2={0};

    cout<<maxCandies(status,candies,keys,containedBoxes,initialBoxes)<<endl;
    cout<<maxCandies(status2,candies2,keys2,containedBoxes2,initialBoxes2);
    return 0;
}
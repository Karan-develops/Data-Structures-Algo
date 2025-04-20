// LC - 781 - Medium - Rabbits in Forest
#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;
int numRabbits(vector<int>&answers){
    unordered_map<int, int> mp;
    for(int &x:answers) mp[x]++;

    int ans=0;
    for(auto &it:mp){
        // The answer given by rabbit
        int x=it.first;
        // How many rabbits gave that answer
        int count=it.second;

        int groupSize=x+1;
        int groups=ceil((double)count/groupSize);

        ans+=groups*groupSize;
    }
    return ans;
}
int main(){
    // Output: 5
    vector<int>answers={1,1,2};
    // Output: 11
    vector<int>answers2={10,10,10};
    cout<<numRabbits(answers)<<endl;
    cout<<numRabbits(answers2);
    return 0;
}
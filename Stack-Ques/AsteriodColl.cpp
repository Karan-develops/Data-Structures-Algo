// LC - 735 - Medium - Asteroid Collision
#include<iostream>
#include<vector>
using namespace std;
vector<int> asteroidCollision(vector<int>&asteroids){
    vector<int>ans;
    // i=0 -> to break the loop
    for(int &i:asteroids){
        while(!ans.empty() && i<0 && ans.back()>0){
            int sum=i+ans.back();
            if(sum<0) ans.pop_back();
            else if(sum>0) i=0;
            else{
                ans.pop_back();
                i=0;
            }
        }
        if(i!=0) ans.push_back(i);
    }
    return ans;
}
int main(){
    // Output: [5,10]
    vector<int>asteroids={5,10,-5};
    // Output: []
    vector<int>asteroids2={8,-8};
    // Output: [10]
    vector<int>asteroids3={10,2,-5};
    vector<int>ans=asteroidCollision(asteroids);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}
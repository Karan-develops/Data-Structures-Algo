// LC - 3623 - Medium - Count Number of Trapezoids I
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Maths{
    const int M=1e9+7;
    public:
    int countTrapezoids(vector<vector<int>>&points){
        // y->count
        unordered_map<int,int>mp;

        for(auto &point:points){
            int y=point[1];
            mp[y]++;
        }

        long long ans=0;
        long long prevHorizontalLines=0;

        for(auto &it:mp){
            int count=it.second;

            long long horizontalLines=(long long)count*(count-1)/2; // countC2

            ans+=horizontalLines*prevHorizontalLines;

            prevHorizontalLines+=horizontalLines;
        }
        return ans%M;
    }
};
int main(){
    // Output: 3
    vector<vector<int>>points={{1,0},{2,0},{3,0},{2,2},{3,2}};
    // Output: 1
    vector<vector<int>>points2={{0,0},{1,0},{0,1},{2,1}};

    Maths sol;
    cout<<sol.countTrapezoids(points)<<endl;
    cout<<sol.countTrapezoids(points2);
    return 0;
}
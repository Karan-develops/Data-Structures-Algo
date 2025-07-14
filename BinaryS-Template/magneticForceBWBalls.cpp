// LC - 1552 - Medium - Magnetic Force Between Two Balls
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int n;
    bool isPossible(vector<int>&position,int m,int force){
        int prevPosition=position[0];
        int count=1;

        for(int i=1;i<n;i++){
            if(position[i]-prevPosition>=force){
                prevPosition=position[i];
                count++;
            }
            if(count==m) return true;
        }
        return false;
    }
    public:
    int maxDistance(vector<int>&position,int m){
        n=position.size();

        sort(begin(position),end(position));

        int l=1;
        int r=position[n-1]-position[0];
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(isPossible(position,m,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 3
    vector<int>position={1,2,3,4,7};
    int m=3;
    // Output: 999999999
    vector<int>position2={5,4,3,2,1,1000000000};
    int m2=2;

    BinarySearch sol;
    cout<<sol.maxDistance(position,m)<<endl;
    cout<<sol.maxDistance(position2,m2);
    return 0;
}
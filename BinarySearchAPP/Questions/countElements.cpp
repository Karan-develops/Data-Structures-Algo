// GFG - Counting elements in two arrays
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    int n;
    int binarySearch(vector<int>&b,int target){
        int l=0,r=n-1;
        int ans=INT_MIN;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(b[mid]<=target){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans==INT_MIN?0:ans+1;
    }
    public:
    vector<int> countLessEq(vector<int>&a,vector<int>&b){
        n=b.size();
        vector<int>ans;
        
        sort(begin(b),end(b));
        
        for(int &i:a){
            ans.push_back(binarySearch(b,i));
        }
        return ans;
    }
};
int main(){
    // Output: [5, 6, 6, 6, 3]
    vector<int>a={4,8,7,5,1},b={4,48,3,0,1,1,5};
    // Output: [0, 0]
    vector<int>a2={10,20},b2={30,40,50};
    return 0;
}
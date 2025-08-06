// LC - 3477 - Easy - Fruits Into Baskets II
// LC - 3479 - Medium - Fruits Into Baskets III
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    vector<int>segTree;
    void buildSegTree(vector<int>&baskets,int i,int l,int r){
        if(l==r){
            segTree[i]=baskets[l];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(baskets,2*i+1,l,mid);
        buildSegTree(baskets,2*i+2,mid+1,r);

        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }
    bool querySegTree(int i,int l,int r,int val){
        // No Basket in this segment
        if(segTree[i]<val){
            return false;
        }

        if(l==r){
            // Mark Basket Used
            segTree[i]=-1;
            return true;
        }

        int mid=l+(r-l)/2;
        bool placed=false;

        if(segTree[2*i+1]>=val){
            placed=querySegTree(2*i+1,l,mid,val);
        } else{
            placed=querySegTree(2*i+2,mid+1,r,val);
        }

        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
        return placed;
    }
    public:
    int numOfUnplacedFruits(vector<int>&fruits,vector<int>&baskets){
        int n=fruits.size();

        segTree.resize(4*n,-1);
        buildSegTree(baskets,0,0,n-1);

        int ans=0;
        for(int &i:fruits){
            if(!querySegTree(0,0,n-1,i)){
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 1
    vector<int>fruits={4,2,5},baskets={3,5,4};
    // Output: 0
    vector<int>fruits2={3,6,1},baskets2={6,4,7};

    Segment_Tree sol;
    cout<<sol.numOfUnplacedFruits(fruits,baskets)<<endl;
    cout<<sol.numOfUnplacedFruits(fruits2,baskets2);
    return 0;
}
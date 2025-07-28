// Update Query
// T.C : Building => O(n)
// T.C : Updating => log(n)
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    void buildSegTree(vector<int>&nums,vector<int>&segTree,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[r];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,segTree,2*i+1,l,mid);
        buildSegTree(nums,segTree,2*i+2,mid+1,r);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    void updateSegTree(vector<int>&segTree,int i,int l,int r,int val,int idx){
        if(l==r){
            segTree[i]=val;
            return;
        }
        
        int mid=l+(r-l)/2;
        
        if(idx<=mid){
            updateSegTree(segTree,2*i+1,l,mid,val,idx);
        } else{
            updateSegTree(segTree,2*i+2,mid+1,r,val,idx);
        }
        
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    void validate(vector<int>&nums,vector<int>&segTree){
        // Validate: root of segTree should match sum of nums
        int expectedSum=0;
        for(int &i:nums) expectedSum+=i;

        cout<<"Expected Root Value After Update: "<<expectedSum<<endl;

        if(segTree[0]==expectedSum) cout<<"Update Validated Successfully.";
        else cout<<"Something is wrong with the update.";
    }
    public:
    void segTreeAfterUpdation(vector<int>&nums){
        int n=nums.size();
        
        vector<int>segTree(4*n);
        buildSegTree(nums,segTree,0,0,n-1);

        cout<<"Before Updation:"<<endl;
        for(int &i:segTree) cout<<i<<" ";
        cout<<endl;
        
        int idx=1,val=15;
        nums[idx]=val;
        updateSegTree(segTree,0,0,n-1,val,idx);
        
        cout<<"After Updation:"<<endl;
        for(int &i:segTree) cout<<i<<" ";
        cout<<endl;

        validate(nums,segTree);
    }
};
int main(){
    vector<int>nums={1,3,5,7,9,11};

    Segment_Tree tree;
    tree.segTreeAfterUpdation(nums);
    
    return 0;
}
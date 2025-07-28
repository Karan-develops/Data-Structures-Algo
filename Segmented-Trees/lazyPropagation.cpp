// Lazy Propagation
// When we have to update element in a range
// Take a seperate lazy tree
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    vector<int>segTree;
    vector<int>lazyTree;
    void buildSegTree(vector<int>&nums,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[r];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,2*i+1,l,mid);
        buildSegTree(nums,2*i+2,mid+1,r);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    void lazyPropagation(int i,int l,int r,int start,int end,int val){
        if(lazyTree[i]!=0){
            segTree[i]=(r-l+1)*val;

            // Not a Leaf
            if(l!=r){
                segTree[2*i+1]+=val;
                segTree[2*i+2]+=val;
            }
            
            // Reset the lazy tree node
            lazyTree[i]=0;
        }

        // Out of Range
        if(l>end || r<start || l>r){
            return;
        }

        // Exactly in Range
        if(l>=start && r<=end){
            // Set Current node's Value
            segTree[i]=(r-l+1)*val;

            // Set Lazy tree nodes value so that if we visited them later we will update.
            if(l!=r){
                lazyTree[2*i+1]+=val;
                lazyTree[2*i+2]+=val;
            }
            // Early Return (Coz we're Lazy 😁)
            return;
        }

        int mid=l+(r-l)/2;

        lazyPropagation(2*i+1,l,mid,start,end,val);
        lazyPropagation(2*i+2,mid+1,r,start,end,val);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    public:
    void updateSegTree(vector<int>&nums,int start,int end,int val){
        int n=nums.size();

        segTree.resize(4*n);
        lazyTree.resize(4*n);

        buildSegTree(nums,0,0,n-1);
        cout<<"Before Updation: "<<segTree[0]<<endl;
        
        lazyPropagation(0,0,n-1,start,end,val);
        cout<<"After Updation: "<<segTree[0];
    }
};
int main(){
    vector<int>nums={1,3,5,7,9,11};

    Segment_Tree tree;
    tree.updateSegTree(nums,2,5,10);

    return 0;
}
// LC - 1361 - Medium - Validate Binary Tree Nodes
// Also in Trees-Ques
#include<iostream>
#include<vector>
using namespace std;
class DSU{
    vector<int>parent;
    int components;
    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }
    bool Union(int P,int C){
        if(find(C)!=C) return false;
        
        if(find(P)==C) return false;

        parent[C]=P;
        components-=1;

        return true;
    }
    public:
    bool validateBinaryTreeNodes(int n,vector<int>&leftChild,vector<int>&rightChild){
        components=n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            int node=i;
            int lC=leftChild[i];
            int rC=rightChild[i];

            if(lC!=-1 && Union(node,lC)==false) return false;
            if(rC!=-1 && Union(node,rC)==false) return false;
        }
        return components==1;
    }
};
int main(){
    // Output: true
    int n=4;
    vector<int>leftChild={1,-1,3,-1},rightChild={2,-1,-1,-1};
    // Output: false
    int n2=4;
    vector<int>leftChild2={1,-1,3,-1},rightChild2={2,3,-1,-1};
    // Output: false
    int n3=2;
    vector<int>leftChild3={1,0},rightChild3={-1,-1};

    DSU sol;
    cout<<sol.validateBinaryTreeNodes(n,leftChild,rightChild)<<endl;
    cout<<sol.validateBinaryTreeNodes(n2,leftChild2,rightChild2)<<endl;
    cout<<sol.validateBinaryTreeNodes(n3,leftChild3,rightChild3);
    return 0;
}
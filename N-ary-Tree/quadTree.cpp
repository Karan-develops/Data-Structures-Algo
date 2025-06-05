// LC - 427 - Medium - Construct Quad Tree
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    Node(int data,bool isLeaf){
        this->data=data;
        this->isLeaf=isLeaf;
    }
};
class QuadTree{
public:
    bool isSame(vector<vector<int>>&grid,int n,int x,int y){
        int val=grid[x][y];

        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(grid[i][j]!=val) return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>&grid,int n,int x,int y){
        if(isSame(grid,n,x,y)){
            return new Node(grid[x][y],true);
        }
        
        Node* newNode=new Node(0,false);

        newNode->topLeft=solve(grid,n/2,x,y);
        newNode->topRight=solve(grid,n/2,x,y+n/2);
        newNode->bottomLeft=solve(grid,n/2,x+n/2,y);
        newNode->bottomRight=solve(grid,n/2,x+n/2,y+n/2);

        return newNode;
    }
    Node* construct(vector<vector<int>>&grid){
        return solve(grid,grid.size(),0,0);
    }
};
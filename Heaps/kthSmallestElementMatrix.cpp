// GFG - Medium - Kth smallest element in a Matrix
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthSmallest(int k,vector<vector<int>>&mat){
    int n=mat.size();
    
    priority_queue<int>pq;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(mat[i][j]);
            
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    return pq.top();
}
int main(){
    // Output: 27
    int k=3;
    vector<vector<int>>mat={{16,28,60,64},{22,41,63,91},{27,50,87,93},{36,78,87,94}};
    // Output: 30
    int k2=7;
    vector<vector<int>>mat2={{10,20,30,40},{15,25,35,45},{24,29,37,48},{32,33,39,50}};
    cout<<kthSmallest(k,mat)<<endl;
    cout<<kthSmallest(k2,mat2);
    return 0;
}
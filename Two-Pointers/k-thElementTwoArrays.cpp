// GFG - Medium - K-th element of two Arrays
#include<iostream>
#include<vector>
using namespace std;
int kthElement(vector<int>&a,vector<int>&b,int k){
    int m=a.size();
    int n=b.size();
    
    int i=0,j=0;
    
    int ans=0;
    
    for(int x=0;x<k;x++){
        if(i<m && j<n){
            if(a[i]<b[j]){
                ans=a[i++];
            }
            else ans=b[j++];
        }
        
        else if(i<m) ans=a[i++];
        else ans=b[j++];
    }
    
    return ans;
}
int main(){
    // Output: 6
    int k=5;
    vector<int>a={2,3,6,7,9},b={1,4,8,10};
    // Output: 10
    int k2=6;
    vector<int>a2={1,4,8,10,12},b2={5,7,11,15,17};
    cout<<kthElement(a,b,k)<<endl;
    cout<<kthElement(a2,b2,k2);
    return 0;
}
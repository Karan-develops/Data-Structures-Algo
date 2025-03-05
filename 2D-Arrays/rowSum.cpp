#include<iostream>
using namespace std;
int main(){
    int arr[5][4]={{1,2,3,4},{2,3,4,1},{5,6,1,3},{2,4,6,8},{1,9,9,6}};
    int rows=5;
    int cols=4;
    for(int i=0;i<rows;i++){
        int ans=0;
        for(int j=0;j<cols;j++){
            ans+=arr[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
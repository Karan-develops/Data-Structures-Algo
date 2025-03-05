#include<iostream>
#include<vector>
using namespace std;
void wavePrint(vector<vector<int>>v){
    int rows=v.size();
    int cols=v[0].size();
    for(int j=0;j<cols;j++){
        // For even cols -> Top to Bottom
        if((j&1)==0){
            for(int i=0;i<rows;i++){
                cout<<v[i][j]<<" ";
            }
        }
        // For odd cols -> Bottom to Top
        else{
            for(int i=rows-1;i>=0;i--){
                cout<<v[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>v{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    wavePrint(v);
    return 0;
}
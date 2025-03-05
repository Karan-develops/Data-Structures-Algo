#include<iostream>
#include<vector>
using namespace std;
void spiralPrint(vector<vector<int>>v){
    vector<int>ans;
    int rows=v.size();
    int cols=v[0].size();
    int total_elements=rows*cols;
    int startingRow=0;
    int endingCol=cols-1;
    int endingRow=rows-1;
    int startingCol=0;
    int count=0;
    while(count<total_elements){
        for(int i=startingCol;i<=endingCol && count<total_elements;i++){
            ans.push_back(v[startingRow][i]);
            count++;
        }
        startingRow++;
        for(int i=startingRow;i<=endingRow && count<total_elements;i++){
            ans.push_back(v[i][endingCol]);
            count++;
        }
        endingCol--;
        for(int i=endingCol;i>=startingCol && count<total_elements;i--){
            ans.push_back(v[endingRow][i]);
            count++;
        }
        endingRow--;
        for(int i=endingRow;i>=startingRow && count<total_elements;i--){
            ans.push_back(v[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}
int main(){
    vector<vector<int>>v{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    spiralPrint(v);
    return 0;
}
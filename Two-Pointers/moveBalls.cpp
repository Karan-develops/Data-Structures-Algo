// LC - 1769 - Medium - Minimum Number of Operations to Move All Balls to Each Box
#include<iostream>
#include<vector>
using namespace std;
vector<int> minOperations(string boxes) {
    int n=boxes.length();
    vector<int>ans(n,0);

    for(int i=0;i<n;i++){
        if(boxes[i]=='1'){
            for(int j=0;j<n;j++){
                ans[j]+=abs(j-i);
            }
        }
    }
    return ans;
}
int main(){
    // Output: [1,1,3]
    string boxes="110";
    // Output: [11,8,5,4,3,4]
    string boxes2="001011";
    return 0;
}
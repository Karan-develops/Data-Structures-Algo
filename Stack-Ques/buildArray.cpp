// LC - 1441 - Medium - Build an Array With Stack Operations
// Stream -> [1-n]
#include<iostream>
#include<vector>
using namespace std;
vector<string> buildArray(vector<int>& target, int n) {
    vector<string>ans;
    int stream=1,i=0;
    while(stream<=n){
        if(i<target.size() && stream==target[i]){
            ans.push_back("Push");
            i++;
        } else if(i<target.size()){
            ans.push_back("Push");
            ans.push_back("Pop");
        }
        stream++;
    }
    return ans;
}
vector<string> buildArrayCleaner(vector<int>&target, int n){
    vector<string>ans;
    int stream=1,i=0;
    while(stream<=n && i<target.size()){
        ans.push_back("Push");
        if(stream==target[i]) i++;
        else ans.push_back("Pop");
        stream++;
    }
    return ans;
}
int main(){
    // Output: ["Push","Push","Pop","Push"]
    vector<int>target={1,3};
    int n=3;
    // Output: ["Push","Push","Push"]
    vector<int>target2={1,2,3};
    int n2=3;
    // Output: ["Push","Push"]
    vector<int>target3={1,2};
    int n3=4;
    vector<string>ans=buildArrayCleaner(target,n);
    for(string &s:ans) cout<<s<<" ";
    return 0;
}
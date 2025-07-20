// LC - 1233 - Medium - Remove Sub-Folders from the Filesystem
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// Approach 1 - Using Set
vector<string> removeSubfolders(vector<string>&folder){
    unordered_set<string>st(begin(folder),end(folder));
    vector<string>ans;

    for(string &curr:folder){
        bool isSubFolder=false;
        string temp=curr;

        while(!curr.empty()){
            size_t position=curr.find_last_of('/');

            curr=curr.substr(0,position);

            if(st.find(curr)!=st.end()){
                isSubFolder=true;
                break;
            }
        }

        if(!isSubFolder){
            ans.push_back(temp);
        }
    }
    return ans;
}
// Approach 2 - Sorting
vector<string> removeSubfolders(vector<string>&folder){
    sort(begin(folder),end(folder));
    vector<string>ans;

    ans.push_back(folder[0]);

    for(int i=1;i<folder.size();i++){
        string curr=folder[i];
        string lastFolder=ans.back();
        lastFolder+='/';

        if(curr.find(lastFolder)!=0){
            ans.push_back(curr);
        }
    }
    return ans;
}
int main(){
    // Output: ["/a","/c/d","/c/f"]
    vector<string>folder={"/a","/a/b","/c/d","/c/d/e","/c/f"};
    // Output: ["/a"]
    vector<string>folder2={"/a","/a/b/c","/a/b/d"};
    // Output: ["/a/b/c","/a/b/ca","/a/b/d"]
    vector<string>folder3={"/a/b/c","/a/b/ca","/a/b/d"};
    return 0;
}
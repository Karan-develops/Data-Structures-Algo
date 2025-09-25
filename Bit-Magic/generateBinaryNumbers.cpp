// GFG - Generate Binary Numbers
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - Generating Numbers
class BitMagic{
    string convertToBinary(int n){
        string s;
        
        while(n){
            s=to_string(n&1)+s;
            
            n>>=1;
        }
        return s;
    }
    public:
    vector<string> generateBinary(int n){
        vector<string>ans;
        
        for(int i=1;i<=n;i++){
            ans.push_back(convertToBinary(i));
        }
        
        return ans;
    }
};
// Approach 2 - Using BFS
class BFS{
    public:
    vector<string> generateBinary(int n){
        vector<string>ans;
        
        queue<string>q;
        q.push("1");
        
        for(int i=1;i<=n;i++){
            string curr=q.front();
            q.pop();
            
            ans.push_back(curr);
            
            q.push(curr+"0");
            q.push(curr+"1");
        }
        return ans;
    }
};
int main(){
    // Output: ["1", "10", "11", "100"]
    int n=4;
    // Output: ["1", "10", "11", "100", "101", "110"]
    int n2=6;
    return 0;
}
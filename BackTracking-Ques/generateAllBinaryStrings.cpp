// GFG - Generate All Binary Strings
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int N;
    void solve(vector<string>&ans,string temp){
        if(temp.size()==N){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('0');
        solve(ans,temp);
        temp.pop_back();
        
        temp.push_back('1');
        solve(ans,temp);
        temp.pop_back();
    }
    public:
    vector<string> binstr(int n){
        N=n;
        vector<string>ans;
        
        solve(ans,"");
        
        return ans;
    }
};
int main(){
    // Output: [00, 01, 10, 11]
    int n=2;
    // Output: [000, 001, 010, 011, 100, 101, 110, 111]
    int n2=3;
    return 0;
}
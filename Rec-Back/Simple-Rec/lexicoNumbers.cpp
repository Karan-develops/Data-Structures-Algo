// LC - 386 - Medium - Lexicographical Numbers
#include<iostream>
#include<vector>
using namespace std;
class LexicoNumbers{
    void solve(vector<int>&ans,int n,int curr){
        if(curr>n) return;

        ans.push_back(curr);

        for(int next_digit=0;next_digit<=9;next_digit++){
            int nextNum=curr*10+next_digit;

            if(nextNum>n) return;

            solve(ans,n,nextNum);
        }
    }
    public:
    vector<int> lexicalOrder(int n){
        vector<int>ans;

        for(int i=1;i<=9;i++){
            solve(ans,n,i);
        }
        return ans;
    }
};
int main(){
    // Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
    int n=13;
    // Output: [1,2]
    int n2=2;

    LexicoNumbers sol;
    vector<int>ans=sol.lexicalOrder(n);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}
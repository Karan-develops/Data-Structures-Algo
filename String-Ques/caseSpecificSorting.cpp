// GFG - Case-specific Sorting of Strings
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int getNextIdx(vector<int>&v,int &idx){
        while(idx<26){
            if(v[idx]>0){
                v[idx]--;
                return idx;
            }
            idx++;
        }
        return -1;
    }
    public:
    string caseSort(string &s){
        int n=s.length();
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        
        for(int i=0;i<n;i++){
            if(islower(s[i])) lower[s[i]-'a']++;
            else upper[s[i]-'A']++;
        }
        
        int i=0,j=0;
        string ans;
        
        for(char &ch:s){
            if(islower(ch)){
                int idx=getNextIdx(lower,i);
                ans+=(char)(idx+'a');
            } else{
                int idx=getNextIdx(upper,j);
                ans+=(char)(idx+'A');
            }
        }
        return ans;
    }
};
int main(){
    // Output: EGekS
    string s="GEekS";
    // Output: MPQSWX
    string s2="XWMSPQ";

    Solution sol;
    cout<<sol.caseSort(s)<<endl;
    cout<<sol.caseSort(s2);
    return 0;
}
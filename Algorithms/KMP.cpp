// Knuth-Morris-Pratt KMP String Matching Algorithm | Search Pattern
// Compute Longest-Prefix-Suffix Array
#include<iostream>
#include<vector>
using namespace std;
class KMP{
    int m,n;
    void computeLPS(vector<int>&lps,string pattern){
        int len=0;
        lps[0]=0;
        int i=1;

        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            } else{
                if(len!=0){
                    //You can also write, len=lps[len-1];
                    len=len-1;
                } else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    public:
    vector<int> search(string pattern,string txt){
        m=pattern.length(),n=txt.length();

        // Compute LPS
        vector<int>lps(m,0);
        computeLPS(lps,pattern);

        int i=0,j=0;
        vector<int>ans;
        while(i<n){
            if(txt[i]==pattern[j]){
                i++,j++;
            }
            if(j==m){
                ans.push_back(i-j);
                j=lps[j-1];
            } else if(i<n && txt[i]!=pattern[j]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }
};
int main(){
    // OP - [0, 3]
    string txt1="abcab",pat1="ab";
    // OP - []
    string txt2="abesdu",pat2="edu";
    // OP - [0, 9, 12]
    string txt3="aabaacaadaabaaba",pat3="aaba";
    KMP obj;
    vector<int>ans1=obj.search(pat1,txt1);
    vector<int>ans2=obj.search(pat2,txt2);
    vector<int>ans3=obj.search(pat3,txt3);
    for(int &i:ans1) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans2) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans3) cout<<i<<" ";
    return 0;
}
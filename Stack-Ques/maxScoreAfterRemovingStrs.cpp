// LC - 1717 - Medium - Maximum Score From Removing Substrings
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Stack{
    string solve(string &s,string &str){
        stack<char>st;

        for(char &ch:s){
            if(!st.empty() && st.top()==str[0] && ch==str[1]){
                st.pop();
            } else{
                st.push(ch);
            }
        }
        
        string remainingString;
        while(!st.empty()){
            remainingString+=st.top();
            st.pop();
        }

        reverse(begin(remainingString),end(remainingString));
        return remainingString;
    }
    public:
    int maximumGain(string s,int x,int y){
        int n=s.length();
        int ans=0;

        string maxStr=(x>y)?"ab":"ba";
        string minStr=(x<=y)?"ab":"ba";

        string chooseMax=solve(s,maxStr);
        int maxEliminatedCount=(n-chooseMax.length())/2;

        ans+=maxEliminatedCount*max(x,y);

        // Now operating on string left after choosing max pairs
        string chooseMin=solve(chooseMax,minStr);
        int minEliminatedCount=(chooseMax.length()-chooseMin.length())/2;

        ans+=minEliminatedCount*min(x,y);

        return ans;
    }
};
int main(){
    // Output: 19
    string s="cdbcbbaaabab";
    int x=4,y=5;
    // Output: 20
    string s2="aabbaaxybbaabb";
    int x2=5,y2=4;

    Stack sol;
    cout<<sol.maximumGain(s,x,y)<<endl;
    cout<<sol.maximumGain(s2,x2,y2);
    return 0;
}
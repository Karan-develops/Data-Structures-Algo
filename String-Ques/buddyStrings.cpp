// LC - 859 - Easy - Buddy Strings
#include<iostream>
#include<vector>
using namespace std;
class String{
    bool checkFreq(string &s){
        vector<int>v(26,0);

        for(char &ch:s){
            v[ch-'a']++;
            
            if(v[ch-'a']>1) return true;
        }
        return false;
    }
    public:
    bool buddyStrings(string s,string goal){
        if(s.length()!=goal.length()) return false;

        if(s==goal){
            return checkFreq(s);
        }

        vector<int>indices;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                indices.push_back(i);
            }
        }

        if(indices.size()!=2) return false;

        swap(s[indices[0]],s[indices[1]]);
        return s==goal;
    }
};
int main(){
    // Output: true
    string s="ab",goal="ba";
    // Output: false
    string s2="ab",goal2="ab";
    // Output: true
    string s3="aa",goal3="aa";

    String sol;
    cout<<sol.buddyStrings(s,goal)<<endl;
    cout<<sol.buddyStrings(s2,goal2)<<endl;
    cout<<sol.buddyStrings(s3,goal3);
    return 0;
}
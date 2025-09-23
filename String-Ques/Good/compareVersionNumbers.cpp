// LC - 165 - Medium - Compare Version Numbers
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class String{
    vector<string> getTokens(string version){
        vector<string>v;

        stringstream ss(version);
        string token;

        while(getline(ss,token,'.')){
            v.push_back(token);
        }
        return v;
    }
    public:
    int compareVersion(string version1,string version2){
        vector<string>v1=getTokens(version1);
        vector<string>v2=getTokens(version2);

        int m=v1.size();
        int n=v2.size();

        int i=0;
        while(i<m || i<n){
            int a=i<m?stoi(v1[i]):0;
            int b=i<n?stoi(v2[i]):0;
            
            if(a>b) return 1;
            else if(b>a) return -1;
            else i++;
        }
        return 0;
    }
};
int main(){
    // Output: -1
    string version1="1.2",version2="1.10";
    // Output: 0
    string version3="1.01",version4="1.001";
    // Output: 0
    string version5="1.0",version6="1.0.0.0";

    String sol;
    cout<<sol.compareVersion(version1,version2)<<endl;
    cout<<sol.compareVersion(version3,version4)<<endl;
    cout<<sol.compareVersion(version5,version6);
    return 0;
}
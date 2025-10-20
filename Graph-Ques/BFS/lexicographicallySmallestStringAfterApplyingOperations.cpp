// LC - 1625 - Medium - Lexicographically Smallest String After Applying Operations
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;
class BFS{
    void rotate(string &s,int k){
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+k);
        reverse(begin(s)+k,end(s));
    }
    public:
    string findLexSmallestString(string s,int a,int b){
        string smallestString=s;

        queue<string>q;
        unordered_set<string>visited;

        q.push(s);
        visited.insert(s);

        while(!q.empty()){
            string curr=q.front();
            q.pop();

            if(curr<smallestString){
                smallestString=curr;
            }

            // Add 'a'
            string temp=curr;
            for(int i=1;i<temp.length();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }

            // Rotate
            rotate(curr,b);
            if(!visited.count(curr)){
                visited.insert(curr);
                q.push(curr);
            }
        }

        return smallestString;
    }
};
int main(){
    // Output: "2050"
    string s="5525";
    int a=9,b=2;
    // Output: "24"
    string s2="74";
    int a2=5,b2=1;
    // Output: "0011"
    string s3="0011";
    int a3=4,b3=2;

    BFS sol;
    cout<<sol.findLexSmallestString(s,a,b)<<endl;
    cout<<sol.findLexSmallestString(s2,a2,b2)<<endl;
    cout<<sol.findLexSmallestString(s3,a3,b3);
    return 0;
}
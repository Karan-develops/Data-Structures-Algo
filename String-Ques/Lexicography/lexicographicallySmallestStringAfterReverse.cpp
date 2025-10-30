// LC - 3722 - Medium - Lexicographically Smallest String After Reverse
#include<iostream>
#include<algorithm>
using namespace std;
string lexSmallest(string s){
    int n=s.length();
    string ans=s;

    for(int k=1;k<=n;k++){
        string temp1=s;
        string temp2=s;

        reverse(begin(temp1),begin(temp1)+k);
        ans=min(ans,temp1);

        reverse(end(temp2)-k,end(temp2));
        ans=min(ans,temp2);
    }

    return ans;
}
int main(){
    // Output: "acdb"
    string s="dcab";
    // Output: "aabb"
    string s2="abba";
    // Output: "xzy"
    string s3="zxy";
    cout<<lexSmallest(s)<<endl;
    cout<<lexSmallest(s2)<<endl;
    cout<<lexSmallest(s3);
    return 0;
}
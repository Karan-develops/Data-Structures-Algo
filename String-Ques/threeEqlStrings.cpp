// LC - 2937 - Easy - Make Three Strings Equal
#include<iostream>
using namespace std;
int findMinimumOperations(string s1,string s2,string s3){
    if((s1[0]!=s2[0]) || (s2[0]!=s3[0])) return -1;

    int x=s1.length(),y=s2.length(),z=s3.length();

    int diff=min(x,min(y,z));
    int ans=abs(x-diff)+abs(y-diff)+abs(z-diff);

    for(int i=0;i<diff;i++){
        if((s1[i]!=s2[i]) || (s2[i]!=s3[i]) || (s1[i]!=s3[i])){
            ans+=(3*(diff-i));
            break;
        }
    }
    return ans;
}
int main(){
    // Output: 2
    string s1="abc",s2="abb",s3="ab";
    // Output: -1
    string s4="dac",s5="bac",s6="cac";
    cout<<findMinimumOperations(s1,s2,s3)<<endl;
    cout<<findMinimumOperations(s4,s5,s6);
    return 0;
}
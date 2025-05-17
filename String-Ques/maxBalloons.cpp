// LC - 1189 - Easy - Maximum Number of Balloons
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxNumberOfBalloons(string text){
    vector<int>v(26,0);
    for(char &ch:text) v[ch-'a']++;

    return min({v['b'-'a'],v['a'-'a'],v['l'-'a']/2,v['o'-'a']/2,v['n'-'a']});
}
int main(){
    // Output: 1
    string text="nlaebolko";
    // Output: 2
    string text2="loonbalxballpoon";
    // Output: 0
    string text3="leetcode";
    cout<<maxNumberOfBalloons(text)<<endl;
    cout<<maxNumberOfBalloons(text2)<<endl;
    cout<<maxNumberOfBalloons(text3);
    return 0;
}
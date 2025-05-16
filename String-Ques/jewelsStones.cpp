// LC - 771 - Easy - Jewels and Stones
#include<iostream>
#include<vector>
using namespace std;
int numJewelsInStones(string jewels, string stones) {
    vector<int>low(26,0);
    vector<int>up(26,0);

    for(char &ch:jewels){
        if(islower(ch)) low[ch-'a']++;
        else up[ch-'A']++;
    }
    int ans=0;
    for(char &ch:stones){
        if(islower(ch) && low[ch-'a']>0) ans++;
        else if(isupper(ch) && up[ch-'A']>0) ans++;
    }
    return ans;
}
int main(){
    // Output: 3
    string jewels="aA",stones="aAAbbbb";
    // Output: 0
    string jewels2="z",stones2="ZZ";
    cout<<numJewelsInStones(jewels,stones)<<endl;
    cout<<numJewelsInStones(jewels2,stones2);
    return 0;
}
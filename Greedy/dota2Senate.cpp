// LC - 649 - Medium - Dota2 Senate
#include<iostream>
#include<queue>
using namespace std;
string predictPartyVictory(string senate) {
    // Store Indices
    int n=senate.length();
    queue<int>dQ,rQ;
    for(int i=0;i<n;i++){
        if(senate[i]=='D') dQ.push(i);
        else rQ.push(i);
    }
    while(!dQ.empty() && !rQ.empty()){
        int rIdx=rQ.front(); rQ.pop();
        int dIdx=dQ.front(); dQ.pop();

        if(rIdx<dIdx) rQ.push(rIdx+n);
        else dQ.push(dIdx+n);
    }
    return rQ.empty()?"Dire":"Radiant";
}
int main(){
    // Output: "Radiant"
    string senate="RD";
    // Output: "Dire"
    string senate2="RDD";
    cout<<predictPartyVictory(senate)<<endl;
    cout<<predictPartyVictory(senate2);
    return 0;
}
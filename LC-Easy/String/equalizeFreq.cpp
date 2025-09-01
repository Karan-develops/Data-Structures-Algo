// LC - 2423 - Easy - Remove Letter To Equalize Frequency
#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool equalFrequency(string word){
    vector<int>mapping(26,0);
    
    for(char ch:word) mapping[ch-'a']++;

    for(int &val:mapping){
        val--;
        
        set<int>st;
        for(int &val:mapping) if(val) st.insert(val);
        
        if(st.size()==1) return true;
        
        val++;
    }
    return false;
}
int main(){
    // Output: true
    string word="abcc";
    // Output: false
    string word2="aazz";
    cout<<equalFrequency(word)<<endl;
    cout<<equalFrequency(word2);
    return 0;
}
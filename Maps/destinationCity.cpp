// LC - 1436 - Easy - Destination City
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string destCity(vector<vector<string>>& paths) {
    unordered_map<string,bool>mp;
    for(auto &vec:paths){
        string start=vec[0];
        string end=vec[1];

        mp[start]=true;
        if(mp.count(end)){
            mp[end]=true;  
            continue;
        }
        mp[end]=false;
    }
    for(auto &it:mp){
        if(it.second==false) return it.first;
    }
    return "";
}
int main(){
    // Output: "Sao Paulo"
    vector<vector<string>>paths={{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    // Output: "A"
    vector<vector<string>>paths2={{"B","C"},{"D","B"},{"C","A"}};
    // Output: "Z"
    vector<vector<string>>paths3={{"A","Z"}};
    cout<<destCity(paths)<<endl;
    cout<<destCity(paths2)<<endl;
    cout<<destCity(paths3);
    return 0;
}
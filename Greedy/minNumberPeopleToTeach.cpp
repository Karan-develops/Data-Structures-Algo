// LC - 1733 - Medium - Minimum Number of People to Teach
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int minimumTeachings(int n,vector<vector<int>>&languages,vector<vector<int>>&friendships){
    unordered_set<int>sadUsers;

    for(auto &vec:friendships){
        // 0-based Indexing
        int u=vec[0]-1;
        int v=vec[1]-1;

        // u ko konsi languages aati h
        unordered_set<int>langKnown(begin(languages[u]),end(languages[u]));
        bool canTalk=false;

        for(int &lang:languages[v]){
            if(langKnown.count(lang)){
                canTalk=true;
                break;
            }
        }

        if(!canTalk){
            sadUsers.insert(u);
            sadUsers.insert(v);
        }
    }

    // Max Known languages in friends
    vector<int>maxKnownLang(n+1,0);
    int mostKnownLang=0;

    for(int user:sadUsers){
        for(int &lang:languages[user]){
            maxKnownLang[lang]++;
            mostKnownLang=max(mostKnownLang,maxKnownLang[lang]);
        }
    }

    return sadUsers.size()-mostKnownLang;
}
int main(){
    // Output: 1
    int n=2;
    vector<vector<int>>languages={{1},{2},{1,2}},friendships={{1,2},{1,3},{2,3}};
    // Output: 2
    int n2=3;
    vector<vector<int>>languages2={{2},{1,3},{1,2},{3}},friendships2={{1,4},{1,2},{3,4},{2,3}};
    cout<<minimumTeachings(n,languages,friendships)<<endl;
    cout<<minimumTeachings(n2,languages2,friendships2);
    return 0;
}
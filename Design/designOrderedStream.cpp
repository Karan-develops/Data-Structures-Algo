// LC - 1656 - Easy - Design an Ordered Stream
#include<iostream>
#include<vector>
using namespace std;
class Design{
    int N;
    int ptr;
    vector<string>stream;
    public:
    Design(int n){
        N=n;
        ptr=1;
        stream=vector<string>(N+1);
    }
    vector<string> insert(int idKey,string value){
        if(ptr!=idKey){
            stream[idKey]=value;
            return {};
        }
        
        stream[idKey]=value;
        vector<string>ans;
        
        while(ptr<=N){
            if(stream[ptr]=="") break;

            ans.push_back(stream[ptr++]);
        }

        return ans;
    }
};
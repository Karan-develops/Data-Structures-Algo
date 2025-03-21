// LC - 433 - Medium - Minimum Genetic Mutation
#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution{
    public:
    int minMutation(string startGene,string endGene,vector<string>&bank){
        int level=0;

        // Using Set for O(1) Lookups
        unordered_set<string>bankSet(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>q;

        visited.insert(startGene);
        q.push(startGene);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                string currString=q.front();
                q.pop();

                if(currString==endGene) return level;

                for(char ch:"ACGT"){
                    // Process Current String
                    for(int i=0;i<currString.length();i++){
                        string ngbr=currString;
                        ngbr[i]=ch;

                        if(visited.find(ngbr)==visited.end() && 
                            bankSet.find(ngbr)!=bankSet.end()){
                                q.push(ngbr);
                                visited.insert(ngbr);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
int main(){
    // OP - 1
    string startGene="AACCGGTT",endGene="AACCGGTA";
    vector<string>bank={"AACCGGTA"};
    // OP - 2
    string startGene2="AACCGGTT",endGene2="AAACGGTA";
    vector<string>bank2={"AACCGGTA","AACCGCTA","AAACGGTA"};
    Solution sol;
    cout<<sol.minMutation(startGene,endGene,bank)<<endl;
    cout<<sol.minMutation(startGene2,endGene2,bank2);
    return 0;
}
// LC - 2115 - Medium - Find All Possible Recipes from Given Supplies
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
class Topo{
    public:
    vector<string> findAllRecipes(vector<string>&recipes,vector<vector<string>>&ingredients,vector<string>&supplies){
        int n=recipes.size();

        unordered_map<string,vector<int>>adj;
        unordered_set<string>supSet(supplies.begin(),supplies.end());
        vector<int>inDegree(n,0);

        for(int i=0;i<n;i++){
            for(string &ing:ingredients[i]){
                if(!supSet.count(ing)){
                    adj[ing].push_back(i);
                    inDegree[i]++;
                }
            }
        }

        queue<int>q;
        vector<string>ans;

        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int i=q.front();
            q.pop();

            string recipe=recipes[i];
            ans.push_back(recipe);

            for(int &idx:adj[recipe]){
                inDegree[idx]--;
                if(inDegree[idx]==0){
                    q.push(idx);
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: {"bread"}
    vector<string>recipes={"bread"},supplies={"yeast","flour","corn"};
    vector<vector<string>>ingredients={{"yeast","flour"}};
    // Output: {"bread","sandwich"}
    vector<string>recipes2={"bread","sandwich"},supplies2={"yeast","flour","meat"};
    vector<vector<string>>ingredients2={{"yeast","flour"},{"bread","meat"}};
    // Output: {"bread","sandwich","burger"}
    vector<string>recipes3={"bread","sandwich","burger"},supplies3={"yeast","flour","meat"};
    vector<vector<string>>ingredients3={{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};

    Topo obj;
    vector<string>ans=obj.findAllRecipes(recipes3,ingredients3,supplies3);
    for(auto &x:ans) cout<<x<<" ";
    return 0;
}
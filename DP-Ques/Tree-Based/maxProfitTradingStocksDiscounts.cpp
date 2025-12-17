// LC - 3562 - HARD - Maximum Profit from Trading Stocks with Discounts
// Super Hard
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TreeDP{
    void dfs(vector<vector<vector<int>>>&statesProfit,unordered_map<int,vector<int>>&adj,const vector<int>&present,const vector<int>&future,int budget,int u){
        // childrenStatesProfit:
        // first  -> child profit if parent NOT bought
        // second -> child profit if parent IS bought
        vector<pair<vector<int>,vector<int>>>childrenStatesProfit;

        // Process children first
        for(int &v:adj[u]){
            dfs(statesProfit,adj,present,future,budget,v);
            childrenStatesProfit.push_back({statesProfit[v][0],statesProfit[v][1]});
        }

        // parentBought = 0 or 1
        for(int parentBought=0;parentBought<=1;parentBought++){
            int price=(parentBought==0)?present[u]:(present[u]/2);
            int profit=future[u]-price;

            vector<int>bestProfitAtU(budget+1,0);

            // Case 1 : Don't buy node at u
            vector<int>childrenProfitIfUNotBought(budget+1,0);

            for(const auto &child:childrenStatesProfit){
                vector<int>temp(budget+1,0);

                for(int used=0;used<=budget;used++){
                    for(int take=0;used+take<=budget;take++){ 
                        temp[used+take]=max(temp[used+take],childrenProfitIfUNotBought[used]+child.first[take]);
                    }
                }
                childrenProfitIfUNotBought=move(temp);
            }

            for(int b=0;b<=budget;b++){
                bestProfitAtU[b]=max(bestProfitAtU[b],childrenProfitIfUNotBought[b]);
            }

            // Case 2 : Buy at node u
            if(price<=budget){
                 vector<int>childrenProfitIfUBought(budget+1,0);

                for(const auto &child:childrenStatesProfit){
                    vector<int>temp(budget+1,0);

                    for(int used=0;used<=budget;used++){
                        for(int take=0;used+take<=budget;take++){
                            temp[used+take]=max(temp[used+take],childrenProfitIfUBought[used]+child.second[take]);
                        }
                    }
                    childrenProfitIfUBought=move(temp);
                }

                for(int b=price;b<=budget;b++){
                    bestProfitAtU[b]=max(bestProfitAtU[b],childrenProfitIfUBought[b-price]+profit);
                }
            }
            statesProfit[u][parentBought]=move(bestProfitAtU);
        }
    }
    public:
    int maxProfit(int n,vector<int>&present,vector<int>&future,vector<vector<int>>&hierarchy,int budget){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:hierarchy){
            int u=vec[0]-1;
            int v=vec[1]-1;

            adj[u].push_back(v);
        }

        // statesProfit[u][0][b] => profit at u when it's parent had not bought stock
        // statesProfit[u][1][b] => profit at u when it's parent had bought stock
        vector<vector<vector<int>>>statesProfit(n+1,vector<vector<int>>(2,vector<int>(budget+1,0)));

        dfs(statesProfit,adj,present,future,budget,0);

        int ans=0;

        for(int b=0;b<=budget;b++){
            // CEO
            ans=max(ans,statesProfit[0][0][b]);
        }

        return ans;
    }
};
int main(){
    // Output: 5
    int n=2,budget=3;
    vector<int>present={1,2},future={4,3};
    vector<vector<int>>hierarchy={{1,2}};
    // Output: 4
    int n2=2,budget2=4;
    vector<int>present2={3,4},future2={5,8};
    vector<vector<int>>hierarchy2={{1,2}};
    // Output: 10
    int n3=3,budget3=10;
    vector<int>present3={4,6,8},future3={7,9,11};
    vector<vector<int>>hierarchy3={{1,2},{1,3}};
    // Output: 12
    int n4=3,budget4=7;
    vector<int>present4={5,2,3},future4={8,5,6};
    vector<vector<int>>hierarchy4={{1,2},{2,3}};

    TreeDP sol;
    cout<<sol.maxProfit(n,present,future,hierarchy,budget)<<endl;
    cout<<sol.maxProfit(n2,present2,future2,hierarchy2,budget2)<<endl;
    cout<<sol.maxProfit(n3,present3,future3,hierarchy3,budget3)<<endl;
    cout<<sol.maxProfit(n4,present4,future4,hierarchy4,budget4);
    return 0;
}
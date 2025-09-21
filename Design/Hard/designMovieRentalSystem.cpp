// LC - 1912 - HARD - Design Movie Rental System
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
class Design{
    typedef pair<int,int>P;
    unordered_map<int,set<P>>available;
    unordered_map<int,set<P>>movieToShopPrice;
    set<tuple<int,int,int>>rented;
    public:
    Design(int n,vector<vector<int>>&entries){
        for(auto &vec:entries){
            int shop=vec[0];
            int movie=vec[1];
            int price=vec[2];

            available[movie].insert({price,shop});
            movieToShopPrice[movie].insert({shop,price});
        }
    }
    vector<int> search(int movie){
        vector<int>searchResults;

        int count=0;
        if(available.count(movie)){
            for(auto &[_,shop]:available[movie]){
                searchResults.push_back(shop);
                count++;

                if(count==5) break;
            }
        }

        return searchResults;
    }
    void rent(int shop,int movie){
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN});
        int price=it->second;

        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    void drop(int shop,int movie){
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN});
        int price = it->second;

        available[movie].insert({price,shop});
        rented.erase({price,shop,movie});
    }
    vector<vector<int>> report(){
        vector<vector<int>>generatedReport;
        int count=0;

        for(auto &[price,shop,movie]:rented){
            generatedReport.push_back({shop,movie});
            count++;

            if(count>=5) break;
        }

        return generatedReport;
    }
};
// LC - 2353 - Medium - Design a Food Rating System
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
class Design{
public:
    unordered_map<string,string>foodCuisines;
    unordered_map<string,int>foodRatings;
    unordered_map<string,set<pair<int,string>>>cuisineRatings;
    Design(vector<string>&foods,vector<string>&cuisines,vector<int>&ratings){
        int n=foods.size();

        for(int i=0;i<n;i++){
            string food=foods[i];
            string cuisine=cuisines[i];
            int rating=ratings[i];

            foodRatings[food]=rating;
            foodCuisines[food]=cuisine;
            cuisineRatings[cuisine].insert({-rating,food});
        }
    }
    void changeRating(string food,int newRating){
        int oldRating=foodRatings[food];
        string cuisine=foodCuisines[food];

        cuisineRatings[cuisine].erase({-oldRating,food});

        foodRatings[food]=newRating;
        cuisineRatings[cuisine].insert({-newRating,food});
    }
    string highestRated(string cuisine){
        return begin(cuisineRatings[cuisine])->second;
    }
};
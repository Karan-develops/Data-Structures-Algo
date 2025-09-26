// LC - 355 - Medium - Design Twitter
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
class Design{
    struct Tweet{
        int time;
        int tweetId;
        Tweet(int t,int id): time(t),tweetId(id){}
    };
    int time;
    unordered_map<int,vector<Tweet>>userTweets;
    unordered_map<int,unordered_set<int>>following;
    
    public:
    Design(){
        time=0;
    }
    void postTweet(int userId,int tweetId){
        userTweets[userId].emplace_back(time++,tweetId);
    }
    vector<int> getNewsFeed(int userId){
        priority_queue<pair<int,int>>pq;

        for(const Tweet &tweet:userTweets[userId]){
            pq.emplace(tweet.time,tweet.tweetId);
        }

        for(int followeeId:following[userId]){
            for(const Tweet &tweet:userTweets[followeeId]){
                pq.emplace(tweet.time,tweet.tweetId);
            }
        }

        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    void follow(int followerId,int followeeId){
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId,int followeeId){
        following[followerId].erase(followeeId);
    }
};
// LC - 3709 - Medium - Design Exam Scores Tracker
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Design{
    vector<pair<int,long long>>prefix;
    public:
    void record(int time,int score){
        long long total=score;

        if(!prefix.empty()){
            total+=prefix.back().second;
        }

        prefix.push_back({time,total});
    }
    long long totalScore(int startTime,int endTime){
        auto sIt=upper_bound(begin(prefix),end(prefix),make_pair(startTime-1,LLONG_MAX));
        auto eIt=upper_bound(begin(prefix),end(prefix),make_pair(endTime,LLONG_MAX));

        if(sIt==begin(prefix) && eIt==begin(prefix)){
            return 0;
        }
        if(eIt==begin(prefix)){
            return 0;
        }
        
        long long start=(sIt==begin(prefix))?0:prev(sIt)->second;
        long long end=(eIt==begin(prefix))?0:prev(eIt)->second;

        return end-start;
    }
};
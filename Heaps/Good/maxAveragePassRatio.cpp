// LC - 1792 - Medium - Maximum Average Pass Ratio
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Not Accepted - MLE
double maxAverageRatio(vector<vector<int>>&classes,int extraStudents){
    int n=classes.size();

    vector<double>PR(n);
    for(int i=0;i<n;i++){
        PR[i]=(double)classes[i][0]/classes[i][1];
    }

    while(extraStudents--){
        vector<double>updatedPR(n);

        for(int i=0;i<n;i++){
            updatedPR[i]=(double)(classes[i][0]+1)/(classes[i][1]+1);
        }

        int bestClassIdx=0;
        double bestDelta=0;

        for(int i=0;i<n;i++){
            double delta=updatedPR[i]-PR[i];
            if(delta>bestDelta){
                bestDelta=delta;
                bestClassIdx=i;
            }
        }

        PR[bestClassIdx]=updatedPR[bestClassIdx];
        classes[bestClassIdx][0]++;
        classes[bestClassIdx][1]++;
    }

    double ans=0;
    for(int i=0;i<n;i++){
        ans+=PR[i];
    }

    return ans/n;
}
// ACCEPTED
typedef pair<double,int>P;
double maxAverageRatio(vector<vector<int>>&classes,int extraStudents){
    int n=classes.size();

    priority_queue<P>pq;

    for(int i=0;i<n;i++){
        double curr_PR=(double)classes[i][0]/classes[i][1];
        double updated_PR=(double)(classes[i][0]+1)/(classes[i][1]+1);

        double delta=updated_PR-curr_PR;
        pq.push({delta,i});
    }

    while(extraStudents--){
        auto curr=pq.top();
        pq.pop();

        double delta=curr.first;
        int idx=curr.second;

        classes[idx][0]++;
        classes[idx][1]++;

        double curr_PR=(double)classes[idx][0]/classes[idx][1];
        double updated_PR=(double)(classes[idx][0]+1)/(classes[idx][1]+1);

        delta=updated_PR-curr_PR;
        pq.push({delta,idx});
    }

    double ans=0;
    for(int i=0;i<n;i++){
        ans+=(double)classes[i][0]/classes[i][1];
    }

    return ans/n;
}
int main(){
    // Output: 0.78333
    vector<vector<int>>classes={{1,2},{3,5},{2,2}};
    int extraStudents=2;
    // Output: 0.53485
    vector<vector<int>>classes2={{2,4},{3,9},{4,5},{2,10}};
    int extraStudents2=4;
    cout<<maxAverageRatio(classes,extraStudents)<<endl;
    cout<<maxAverageRatio(classes2,extraStudents2);
    return 0;
}
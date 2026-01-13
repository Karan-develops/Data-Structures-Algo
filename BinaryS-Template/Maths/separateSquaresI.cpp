// LC - 3453 - Medium - Separate Squares I
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    bool check(vector<vector<int>>&squares,double mid_y,double total){
        double bot_area=0;

        for(auto &square:squares){
            double y=square[1];
            double l=square[2];

            double boty=y;
            double topy=y+l;

            if(mid_y>=topy){
                // full square below
                bot_area+=l*l;
            } else if(mid_y>boty){
                //partial area below
                bot_area+=(mid_y-boty)*l;
            }
        }

        // Is bottom area more than above ?
        return bot_area>=total/2.0;
    }
    public:
    double separateSquares(vector<vector<int>>&squares){
        double low=INT_MAX;
        double high=INT_MIN;
        double total=0.00000;

        for(auto &square:squares){
            double x=square[0];
            double y=square[1];
            double l=square[2];
            total+=l*l;

            low=min(low,y);
            high=max(high,y+l);
        }

        double result_y=0.00000;

        while(high-low>1e-5){
            double mid_y=low+(high-low)/2;
            
            result_y=mid_y;

            // bottom area is greater
            // shift mid_y down side to balance area
            if(check(squares,mid_y,total)==true){
                high=mid_y;
            } else{
                low=mid_y;
            }
        }

        return result_y;
    }
};
int main(){
    // Output: 1.00000
    vector<vector<int>>squares={{0,0,1},{2,2,1}};
    // Output: 1.16667
    vector<vector<int>>squares2={{0,0,2},{1,1,1}};

    BinarySearch sol;
    cout<<sol.separateSquares(squares)<<endl;
    cout<<sol.separateSquares(squares2);
    return 0;
}
// LC - 2469 - Easy - Convert the Temperature
#include<iostream>
#include<vector>
using namespace std;
vector<double> convertTemperature(double celsius) {
    vector<double> ans;
    ans.push_back(celsius+273.15);
    ans.push_back((celsius*1.80)+32);
    return ans;
}
int main(){
    // Output: [309.65000,97.70000]
    double celsius=36.50;
    // Output: [395.26000,251.79800]
    double celsius2=122.11;
    return 0;
}
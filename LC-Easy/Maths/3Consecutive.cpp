// LC - 2177 - Medium - Find Three Consecutive Integers That Sum to a Given Number
#include<iostream>
#include<vector>
using namespace std;
vector<long long> sumOfThree(long long num){
    if(num%3!=0) return {};
    return {(num/3)-1,(num/3),(num/3)+1};
}
int main(){
    // Output: [10,11,12]
    int num=33;
    // Output: []
    int num2=4;
    return 0;
}
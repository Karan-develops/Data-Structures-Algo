// LC - 1603 - Easy - Design Parking System
#include<iostream>
using namespace std;
class Solution{
    int B,M,S;
    Solution(int big, int medium, int small) {
        B=big,M=medium,S=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && B==0) return false;
        if(carType==2 && M==0) return false;
        if(carType==3 && S==0) return false;

        if(carType==1) B--;
        if(carType==2) M--;
        if(carType==3) S--;
        return true;
    }
};
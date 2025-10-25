// LC - 2043 - Medium - Simple Bank System
#include<iostream>
#include<vector>
using namespace std;
class Design{
    int N;
    vector<long long>bankBalance;
    public:
    Design(vector<long long>&balance){
        N=balance.size();
        bankBalance=balance;
    }
    bool transfer(int account1,int account2,long long money){
        if(account1>N || account2>N || bankBalance[account1-1]<money){
            return false;
        }

        bankBalance[account1-1]-=money;
        bankBalance[account2-1]+=money;
        
        return true;
    }
    bool deposit(int account,long long money){
        if(account>N) return false;

        bankBalance[account-1]+=money;
        
        return true;
    }
    bool withdraw(int account,long long money){
        if(account>N || bankBalance[account-1]<money) return false;

        bankBalance[account-1]-=money;

        return true;
    }
};
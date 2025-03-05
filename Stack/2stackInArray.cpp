#include<iostream>
using namespace std;
class Stack{
    private:
    int* arr;
    int size;
    int top1;
    int top2;
    public:
    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->top1=-1;
        this->top2=size;
    }
    void pushIn1(int data){
        if(top1+1==top2){
            cout<<"Stack Overflow."<<endl;
        } else{
            arr[++top1]=data;
        }
    }
    void pushIn2(int data){
        if(top1+1==top2){
            cout<<"Stack Overflow."<<endl;
        } else{
            arr[--top2]=data;
        }
    }
    void popIn1(){
        if(top1==-1){
            cout<<"Stack is already Empty."<<endl;
        } else{
            arr[top1]=0;
            top1--;
        }
    }
    void popIn2(){
        if(top2==size){
            cout<<"Stack is already Empty."<<endl;
        } else{
            arr[top2]=0;
            top2++;
        }
    }
    int peek1(){
        if(top1==-1){
            return -1;
        } else{
            return arr[top1];
        }
    }
    int peek2(){
        if(top2==size){
            return -1;
        } else{
            return arr[top2];
        }
    }
    int getL1(){
        if(top1==-1){
            return 0;
        } else{
            return top1+1;
        }
    }
    int getL2(){
        if(top2>=size){
            return 0;
        } else{
            return size-top2;
        }
    }
    bool isEmpty1(){
        if(top1==-1) return true;
        return false;
    }
    bool isEmpty2(){
        if(top2>=size) return true;
        return false;
    }
};
int main(){
    Stack st(5);
    st.pushIn1(1);
    st.pushIn1(2);
    st.pushIn1(3);
    st.pushIn2(4);
    st.pushIn2(5);
    cout<<st.peek1()<<endl;
    cout<<st.peek2()<<endl;
    cout<<st.getL1()<<endl;
    cout<<st.getL2()<<endl;
    while(!st.isEmpty1()){
        cout<<st.peek1()<<" ";
        st.popIn1();
    }
    cout<<endl;
    while(!st.isEmpty2()){
        cout<<st.peek2()<<" ";
        st.popIn2();
    }
    return 0;
}
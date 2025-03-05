// 1st way is to divide the array into s/n.
// 2nd way is to make two addition array (top and next)
// where top array's size will be equal to number of stacks to be made.
// and next array will store the next free space available in main array.
#include<iostream>
using namespace std;
class N_Stacks{
    private:
    int *a,*top,*next;
    int n; // no.of stacks
    int size; // size of main array
    int freeSpot; // tells free space in main array
    public:
    N_Stacks(int _n,int _size): n(_n), size(_size) {
        freeSpot=0;
        a=new int[size];
        top=new int[n];
        next=new int[size];
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
    }
    bool push(int data,int stackNo){
        if(freeSpot==-1){
            cout<<"Stack Overflow."<<endl;
            return false;
        }
        // 1. find Index
        int index=freeSpot;
        // 2. update Freespot
        freeSpot=next[index];
        // 3. insert in main Array
        a[index]=data;
        // 4. update next
        next[index]=top[stackNo-1];
        // 5. update top
        top[stackNo-1]=index;
        cout<<"Data: "<<data<<" has been pushed successfully in stack No. "<<stackNo<<endl;
        return true;
    }
    int pop(int stackNo){
        if(top[stackNo-1]==-1){
            cout<<"Stack No. "<<stackNo<<" is already Empty."<<endl;
            return -1;
        }
        // 1. find index
        int index=top[stackNo-1];
        // 2. update top
        top[stackNo-1]=next[index];
        // 3. get the popped element
        int poppedElement=a[index];
        // 4. update next
        next[index]=freeSpot;
        // 5. update freespot
        freeSpot=index;
        cout<<"Element: "<<poppedElement<<" has been popped from stack No."<<stackNo<<endl;
        return poppedElement;
    }
    ~N_Stacks(){
        delete a;
        delete top;
        delete next;
    }
};
int main(){
    N_Stacks st(3,9);
    st.push(10,1);
    st.push(20,1);
    st.push(30,2);
    st.pop(1);
    st.push(20,1);
    return 0;
}
#include<iostream>
using namespace std;
class K_Q{
    private:
    int *a,*front,*rear,*next;
    int k,size,freeSpot;
    public:
    K_Q(int size,int k){
        this->size=size;
        this->freeSpot=0;
        a=new int[size];
        front=new int[k];
        rear=new int[k];
        next=new int[size];
        for(int i=0;i<k;i++){
            front[i]=rear[i]=-1;
        }
        for(int i=0;i<size;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
    }
    void push(int data,int qNo){
        if(freeSpot==-1){
            cout<<"Queue No: "<<qNo<<" is Full."<<endl;
            return;
        }
        // 1. find free index
        int index=freeSpot;
        // 2. update freeSpot
        freeSpot=next[index];
        // 3. if first element in queue
        // **next array is maintaining the links of main array.
        if(front[qNo-1]==-1){
            front[qNo-1]=index;
        } else{
            // Link new element to that Q's rearest element
            next[rear[qNo-1]]=index;
        }
        // 4. update next
        next[index]=-1;
        // 5. update rear
        rear[qNo-1]=index;
        // 6. insert data
        a[index]=data;
        cout<<"Data: "<<data<<" has been successfully pushed in Queue: "<<qNo<<endl;
    }
    void pop(int qNo){
        if(front[qNo-1]==-1){
            cout<<"Queue No: "<<qNo<<" is already Empty."<<endl;
            return;
        }
        // 1. find index to pop
        int index=front[qNo-1];
        // 2. update front
        front[qNo-1]=next[index];
        // 3. update freespot
        next[index]=freeSpot;
        freeSpot=index;
        cout<<"Element: "<<a[index]<<" has been popped from Queue No: "<<qNo<<endl;
    }
};
int main(){
    K_Q q(8,3);
    q.push(1,1);
    q.push(2,1);
    q.push(5,2);
    q.push(3,1);
    q.pop(2);
    q.pop(2);
    q.pop(1);
    return 0;
}
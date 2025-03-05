// 2 Approaches
// count0,count1,count2 to store number of occs then make LL.T.C->O(n) S.C->O(1).
// Dutch flag sorting algorithm. -> it doesn't change values in LL.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void addNewNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        head->next=tail;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
void sort012UsingVars(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* temp=head;
    int count0=0;
    int count1=0;
    int count2=0;
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
        }
        if(temp->data==1){
            count1++;
        }
        if(temp->data==2){
            count2++;
        }
        temp=temp->next;
    }
    temp=head;
    while(count0--){
        temp->data=0;
        temp=temp->next;
    }
    while(count1--){
        temp->data=1;
        temp=temp->next;
    }
    while(count2--){
        temp->data=2;
        temp=temp->next;
    }
}
void secondWayToSort(Node* &head){
    // Create Dummy Node
    Node* zeroKaHead=NULL;
    Node* zeroKiTail=NULL;
    Node* oneKaHead=NULL;
    Node* oneKiTail=NULL;
    Node* twoKaHead=NULL;
    Node* twoKiTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            if(zeroKaHead==NULL){
                zeroKaHead=temp;
                zeroKiTail=temp;
            } else{
                zeroKiTail->next=temp;
                zeroKiTail=temp;
            }
        } else if(temp->data==1){
            if(oneKaHead==NULL){
                oneKaHead=temp;
                oneKiTail=temp;
            } else{
                oneKiTail->next=temp;
                oneKiTail=temp;
            }
        } else{
            if(twoKaHead==NULL){
                twoKaHead=temp;
                twoKiTail=temp;
            } else{
                twoKiTail->next=temp;
                twoKiTail=temp;
            }
        }
        temp=temp->next;
    }
    if(zeroKaHead!=NULL){
        head=zeroKaHead;
    }
    if(zeroKaHead==NULL){
        if(oneKaHead!=NULL) head=oneKaHead;
        else head=twoKaHead;
    }
    if(oneKaHead!=NULL){
        zeroKiTail->next=oneKaHead;
    }
    if(twoKaHead!=NULL){
        oneKiTail->next=twoKaHead;
    }
    if(twoKiTail!=NULL){
        twoKiTail->next=NULL;
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,0);
    addNewNodeAtTail(head,tail,0);
    addNewNodeAtTail(head,tail,0);
    printList(head);
    secondWayToSort(head);
    printList(head);
    return 0;
}
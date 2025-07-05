// LC - 21 - Easy - Merge Two Sorted Lists
// 2 Approachs - Recursive - Iterative
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
// Recursive is Better
class LL{
    public:
    Node* mergeTwoLists(Node* list1,Node* list2){
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next,list2);

            return list1;
        }
        
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
};
class LL2{
    public:
    Node* mergeTwoLists(Node* list1,Node* list2){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        Node* ansList=new Node(-1);
        Node* ansTail=ansList;
        
        while(list1 && list2){
            if(list1->val>list2->val){
                ansTail->next=list2;
                ansTail=list2;
                list2=list2->next;
            } else{
                ansTail->next=list1;
                ansTail=list1;
                list1=list1->next;
            }
        }

        if(list1) ansTail->next=list1;
        if(list2) ansTail->next=list2;

        return ansList->next;
    }
};
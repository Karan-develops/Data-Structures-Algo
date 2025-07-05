// LC - 432 - HARD - All O`one Data Structure
// Topics --> Hash Table, Linked List, Design, Doubly-Linked List
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class AllOne{
    private:
    struct Node{
        int count;
        unordered_set<string>keys;
        Node* prev;
        Node* next;
        Node(int c){
            c=count;
            prev=NULL;
            next=NULL;
        }
    };
    unordered_map<string,Node*>mp;
    Node* head;
    Node* tail;
    
    void addNewNodeAfter(Node* prevNode,int count){
        Node* newNode=new Node(count);

        newNode->prev=prevNode;
        newNode->next=prevNode->next;

        if(prevNode->next){
            prevNode->next->prev=newNode;
        }
        prevNode->next=newNode;

        if(tail==prevNode){
            tail=newNode;
        }
    }
    void removeNode(Node* curr){
        curr->prev->next=curr->next;
        
        if(curr->next){
            curr->next->prev=curr->prev;
        }

        if(tail==curr){
            tail=curr->prev;
        }
        delete curr;
    }
    public:
    AllOne(){
        head=new Node(0);
        tail=head;
    }
    void inc(string key){
        if(mp.find(key)==mp.end()){
            // Key doesn't exist, add it to the list after the head with count 1
            if(head->next==NULL || head->next->count!=1){
                addNewNodeAfter(head,1);
            }
            mp[key]=head->next;
            head->next->keys.insert(key);
        } else{
            // Key exists, move it to the next count
            Node *curr=mp[key];
            int currCount=curr->count;

            if(curr->next==NULL || curr->next->count!=currCount+1){
                addNewNodeAfter(curr,currCount+1);
            }

            curr->next->keys.insert(key);
            mp[key]=curr->next;
            curr->keys.erase(key);

            if(curr->keys.empty()){
                removeNode(curr);
            }
        }
    }
    void dec(string key){
        Node* curr=mp[key];
        int currCount=curr->count;

        curr->keys.erase(key);
        if(currCount==1){
            mp.erase(key);
        } else{
            // Move it to the previous count
            if(curr->prev==head || curr->prev->count!=currCount){
                addNewNodeAfter(curr->prev,currCount-1);
            }
            curr->prev->keys.insert(key);
            mp[key]=curr->prev;
        }
        // Remove the current node if it has no more keys
        if(curr->keys.empty()){
            removeNode(curr);
        }
    }
    string getMaxKey(){
        if(tail==head) return "";

        return *tail->keys.begin();
    }
    string getMinKey(){
        if(head->next==NULL) return "";

        return *head->next->keys.begin();
    }
};
/*
Input:
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output:
[null, null, null, "hello", "hello", null, "hello", "leet"]
*/
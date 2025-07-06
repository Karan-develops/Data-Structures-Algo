// LC - 2130 - Medium - Maximum Twin Sum of a Linked List
// 3 Approaches - Vector - Stack - Reverse
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
};
class LL{
    public:
    // Approach 1 - Using extra space with vector
    int pairSum(Node* head){
        vector<int>vec;
        
        Node* temp=head;
        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int i=0,j=vec.size()-1;
        int ans=0;
        
        while(i<j){
            ans=max(ans,vec[i]+vec[j]);
            i++,j--;
        }
        return ans;
    }
    // Approach 2 - Using Stack
    int pairSum(Node* head){
        stack<int>st;
        Node* curr=head;
        
        while(curr){
            st.push(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        int count=1;
        int N=st.size();
        int ans=0;
        
        while(count<=N/2){
            ans=max(ans,curr->val+st.top());
            curr=curr->next;
            st.pop();
            count++;
        }
        return ans;
    }
    // Approach 3 - Reverse
    int pairSum(Node* head){
        // Step 1 : Find Mid
        Node* mid=NULL;

        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        mid=slow;

        // Step 2 : Reverse
        Node* prev=NULL;

        while(mid){
            Node* next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }

        // Step 3 : Find Ans
        Node* curr=head;
        int ans=0;

        while(prev){
            ans=max(ans,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        
        return ans;
    }
};
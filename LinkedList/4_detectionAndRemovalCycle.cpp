#include<iostream>
using namespace std;
class node {
    public: 
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};
void addAtTail(node* &head, int val) {
    node* n = new node(val);
    if(head==NULL) {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool checkCycle(node* head) {
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}
void makeCycle(node* &head, int pos) {
    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next!=NULL) {
        if(count==pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
void removeCycle(node* &head) {
    node* slow = head;
    node* fast = head;
    do {
       slow = slow->next;
       fast = fast->next->next; 
    } while(slow!=fast);
    fast = head;
    while(fast->next!=slow->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}
int main() {
    int n, a;
    cin>>n;
    node* head = NULL;
    for(int i=0; i<n; i++) {
        cin>>a;
        addAtTail(head, a);
    }
    display(head);
    makeCycle(head, 3);
    cout<<checkCycle(head)<<endl;
    removeCycle(head);
    cout<<checkCycle(head)<<endl;
    return 0;
}
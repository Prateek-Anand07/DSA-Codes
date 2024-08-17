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
        head = n;
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
        temp = temp->next;
    }
    cout<<"NULL\n";
}
node* reversek(node* &head, int k) {
    int count = 0;
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL && count<k) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL) {
        head->next = reversek(nextptr, k);
    }
    return prevptr;
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
    node* newhead = reversek(head, 3);
    display(newhead);
    return 0;
}
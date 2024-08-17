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
void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if(head==NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next=n;
}
void display(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
node* reverse(node* &head) {
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
node* reverseRec(node* &head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    node* newhead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
int main() {
    node* head = NULL;
    // int n, arr[100];
    // cin>>n;
    // for(int i=0; i<n; i++) {
    //     cin>>arr[i];
    //     insertAtTail(head, arr[i]);
    // }
    display(head);
    node* newhead = reverse(head);
    // node* newhead = reverseRec(head); // Time complexity: O(N)
    display(newhead);
    return 0;
}
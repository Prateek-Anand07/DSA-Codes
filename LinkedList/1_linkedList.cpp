#include<bits/stdc++.h>
using namespace std;
class node {
    public: 
    int data;
    node* next;
    public:
    node(int val) {
        data = val;
        next = NULL;
    }
};

node* convertArr2LL(vector<int> &arr) {
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// traversing through LL and printing values
void display(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int lengthOfLL(node* head) {
    int count = 0;
    node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next=head;
    head=n;
}
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

bool search(node* head, int key) {
    node* temp = head;
    while(temp!=NULL) {
        if(temp->data==key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteatHead(node* &head) {
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* &head, int val) {
    if(head==NULL) { // if linked list is empty
        return;
    }
    if(head->next==NULL) { // if there is only one block in list
        deleteatHead(head);
        return;
    }
    if(head->data==val) { // if deleting block is head itself
        deleteatHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val) {
        temp=temp->next;
    }
    node* todelete = temp->next; // to delete nth node reach at (n-1)th node
    temp->next=temp->next->next; // in (n-1)th node->next put (n+1)th node
    delete todelete;
}

int main() {
    // node* y = new node(2); // A pointer pointing to the node
    // cout << y->data; //data can be accesed like this 
    
    // vector<int> arr = {2, 4, 6, 5, 9};
    // node* head = convertArr2LL(arr);
    // cout << head->data;
    // display(head);
    // cout<<lengthOfLL(head);

    node* head = NULL;
    addAtTail(head, 1);
    addAtTail(head, 2);
    addAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    // cout<<search(head, 5)<<endl;
    // cout<<search(head, 3)<<endl;
    deletion(head, 3);
    display(head);
    return 0;
}
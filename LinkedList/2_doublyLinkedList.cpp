#include<iostream>
using namespace std;
class node {
    public: 
        int data;
        node* prev;
        node* next;
        public:
        node(int val) {
            data = val;
            next = NULL;
            prev = NULL;
        }
};
void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    if(head!=NULL) {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node* &head, int val) {
    if(head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void deleteAtHead(node* &head) {
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head, int pos) {
    if(pos==1) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos) {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

node* reverse(node* head) {
    if(head==NULL || head->next==NULL) 
        return head;
    node* curr = head;
    node* last = NULL;
    while(curr != NULL) {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    return last->prev;
}

int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // insertAtHead(head, 5);
    // display(head);
    // deletion(head, 5); 
    // display(head);
    node* newhead = reverse(head);
    display(newhead);
    return 0;
}
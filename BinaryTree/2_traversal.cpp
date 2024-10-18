#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Preorder traversal: Time complexity = O(N) & Space complexity = O(N), where N is number of nodes
// Root-left-right
void preorder(Node* node) {
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
// Inorder traversal: Time complexity = O(N) & Space complexity = O(N), where N is number of nodes
// Left-root-right
void inorder(Node* root) {
    if(root == NULL) 
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Postorder traversal: Time complexity = O(N) & Space complexity = O(N), where N is number of nodes
// Left-right-root
void postorder(Node* root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
vector<int> preorderTraversal(Node* root) { // Iterative way, it also has same time and space complexity
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* node = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right) 
            st.push(node->right);
        if(node->left)
            st.push(node->left);
    }
    return ans;
}
vector<int> inorderTraversal(Node* root) { // Iterative way, it also has same time and space complexity
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node*> st;
    while(root!=NULL || !st.empty()) {
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        root = root->right;
    }
    return ans;
}
vector<vector<int>> levelOrderTraversal(Node* root) { // Time complexity = O(N) & Space complexity = O(N)
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++) {
            Node* ele = q.front();
            q.pop();
            if(ele->left)
                q.push(ele->left);
            if(ele->right)
                q.push(ele->right);
            level.push_back(ele->data);
        }
        ans.push_back(level);
    }
    return ans;
}
vector<int> postorderTraversal2stack(Node* root) { // Time complexity = O(N) & Space complexity = O(2N)
    vector<int> result;
    if(root == NULL)
        return result;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        Node* nd = st1.top();
        st1.pop();
        st2.push(nd);
        if(nd->left)
            st1.push(nd->left);
        if(nd->right)
            st1.push(nd->right);
    }
    while(!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }
    return result;
}
vector<int> postorderTraversal1stack(Node* root) { // Time complexity = O(2N) & Space complexity = O(N)
    vector<int> result;
    if(root == NULL)
        return result;
    stack<Node*> st;
    while(root!=NULL || !st.empty()) {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            Node* temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                result.push_back(temp->data);
                while(!st.empty() && st.top()->right==temp) {
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->data);
                }
            }
            else    
                root = temp;
        }
    }
    return result;
}
// Pre, in and post all in one code
vector<int> preinposttraversal(Node* root) { // Time complexity = O(3N) & Space complexity = O(4N)
    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    if(root == NULL)
        return;
    st.push({root, 1});
    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left, 1});
        }
        else if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right, 1});
        }
        else 
            post.push_back(it.first->data);
    }
    // any order can be returned from here
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    vector<vector<int>> nodes = levelOrderTraversal(root);
    for(auto ele: nodes) {
        for(auto x: ele) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
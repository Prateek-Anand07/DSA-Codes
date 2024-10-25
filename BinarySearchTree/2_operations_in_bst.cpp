#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};
// Conditions:
    // All the values of node are unique.
    // It's guaranteed that val does not exist in the original BST.
//  Return the root node of the BST after the insertion
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) {
        TreeNode* curr = new TreeNode(val);
        return curr;
    }
    TreeNode* curr = root;
    while(curr) {
        if(curr->val < val) {
            if(curr->right)
                curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                curr = NULL;
            }
        }
        else {
            if(curr->left) 
                curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                curr = NULL;
            }
        }
    }
    return root;
}
TreeNode* deleteHead(TreeNode* root) {
    if(root == NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL) {
        delete root;
        return NULL;
    }
    if(root->right == NULL) {
        TreeNode* ans = root->left;
        delete root;
        return ans;
    }
    else {
        TreeNode* temp = root->right;
        while(temp->left) {
            temp = temp->left;
        }
        temp->left = root->left;
        TreeNode* ans = root->right;
        delete root;
        return ans;
    }
}

// Deletion of node of BST:
// Time complexiyt: O(height) which will be O(log N) in case of balanced binary tree as their height is equal to log N
// Space complexity: O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL)
         return NULL;
    if(root->val == key)
        return deleteHead(root);
    TreeNode* curr = root;
    TreeNode* prev = NULL;
    while(curr) {
        if(curr->val == key) {
            if(prev == NULL) {
                return deleteHead(curr);
            }
            else {
                if(prev->left == curr)
                    prev->left = deleteHead(curr);
                else 
                    prev->right = deleteHead(curr);
            }
            return root;
        }
        else if(curr->val > key) {
            prev = curr;
            curr = curr->left;
        }
        else {
            prev = curr;
            curr = curr->right;
        }
    }
    return root;
}
int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* list[26];
    int wordCnt = 0;
    int prefixCount = 0;
    Node() {
        for(int i=0; i<26; i++) {
            list[i] = NULL;
        }
    }
    bool containsKey(char ch) {
        return (list[ch-'a'] != NULL);
    }
    void put(char ch, Node* node) {
        list[ch-'a'] = node;
    }
    Node* get(char ch) {
        return list[ch-'a'];
    }
};

class Trie{
    private:
        Node* root;
        bool eraseHelper(Node* node, string &word, int depth) {
            if(depth == word.length()) {
                node->wordCnt--;
                return (node->prefixCount == 0);
            }
            char ch = word[depth];
            Node* nextNode = node->get(ch);
            nextNode->prefixCount--;
            bool isDelete = eraseHelper(nextNode, word, depth+1);
            if(isDelete) {
                delete nextNode;
                node->list[ch-'a'] = NULL;
                return (node->prefixCount == 0);
            }
            return false;
        }

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    // Time complexity: O(m), where m is the word length
    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->prefixCount++;
        }
        node->wordCnt++;
    }

    // Time complexity: O(m), where m is the word length
    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->wordCnt;
    }

    // Time complexity: O(m), where m is the word length
    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->prefixCount;
    }

    // Time complexity: O(m), where m is the word length
    void erase(string &word){
        // Write your code here.
        eraseHelper(root, word, 0);
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        // Time complexity: O(m), where m is the word length
        void insert(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node->containsKey(word[i])) 
                    node->put(word[i], new Node());
                // move to reference trie
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        // Time complexity: O(m), where m is the word length
        bool search(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node->containsKey(word[i])) 
                    return false;
                node = node->get(word[i]);
            }
            return node->isEnd();
        }
        // Time complexity: O(m), where m is the word length
        bool startsWith(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node->containsKey(word[i])) 
                    return false;
                node = node->get(word[i]);
            }
            return true;
        }
};
int main() {
    return 0;
}
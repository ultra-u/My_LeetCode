#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Trie{
public:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->children[index]==nullptr){
                node->children[index]=new TrieNode();
            }
            node=node->children[index];
        }
        node->isEnd=true;
    }
    bool search(string word){
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node=node->children[index];
        }
        return node->isEnd;
    }
    bool startsWith(string prefix){
        TrieNode* node=root;
        for(char c:prefix){
            int index=c-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node=node->children[index];
        }
        return true;
    }
};

int main(){
    Trie trie;
    trie.insert("apple");
    cout << "search('apple'): " << (trie.search("apple") ? "true" : "false") << endl;  // true
    cout << "search('app'): " << (trie.search("app") ? "true" : "false") << endl;      // false
    cout << "startsWith('app'): " << (trie.startsWith("app") ? "true" : "false") << endl; // true
    trie.insert("app");
    cout << "search('app'): " << (trie.search("app") ? "true" : "false") << endl;      // true
}
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    int keyno;
    TrieNode *children[26];
    // Initialize your data structure here.
    TrieNode() {
        keyno = 0;
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }
    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.length();
        TrieNode* crawl = root;

        for(int i=0;i<len;i++){

            if(crawl->children[word[i]-'a']==NULL){
                crawl->children[word[i]-'a'] = new TrieNode();
            }

            crawl = crawl->children[word[i]-'a'];
        }
        crawl->keyno = ++count;
    }
    // Returns if the word is in the trie.
    bool search(string word) {
        int len = word.length();
        TrieNode* crawl = root;   

        for(int i=0;i<len;i++) {
            if(crawl->children[word[i]-'a']==NULL)return false;
            else crawl = crawl->children[word[i]-'a'];
        }
        if(crawl->keyno)return true;
        return false;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* crawl = root;   

        for(int i=0;i<len;i++) {
            if(crawl->children[prefix[i]-'a']==NULL)return false;
            else crawl = crawl->children[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
    int count;
};


int main(){
    Trie trie;
    trie.insert("hello");
    trie.insert("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.startsWith("abcd")<<endl;
    cout<<trie.search("hello")<<endl;
    cout<<trie.startsWith("hel")<<endl;
    return 0;
}
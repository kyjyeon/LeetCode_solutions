struct TrieNode{
    bool end;
    TrieNode* next[26];
    TrieNode(){
        end = false;
        for(int i =0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            int key = word[i] - 'a';
            if(!node->next[key])
                node->next[key] = new TrieNode;
            
            node = node->next[key];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            int key = word[i] - 'a';
            if(!node->next[key])
                return false;
            node = node->next[key];
        }
        return (node != NULL && node->end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TrieNode* node = root;
        for(int i=0; i<prefix.length(); i++){
            int key = prefix[i] - 'a';
            if(!node->next[key])
                return false;
            node = node->next[key];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

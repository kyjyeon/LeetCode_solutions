
//Trie Algorithm 
struct Trie {
    bool finish;    //flag for checking the last letter of the word
    Trie* next[26];    //26 alphabet container

    //contructor
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    //deconstructor
    ~Trie() {
        //if the letter exists delete it
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }
    //insertion letter function
    void insert(const char* key) {
        if (*key == '\0')
            finish = true;    //if the param is finishing letter from char
        else {
            int curr = *key - 'A';
            if (next[curr] == )
                next[curr] = new Trie();    //dynamic allocation if new finding point
            next[curr]->insert(key + 1);    //
        }
    }
    Trie* find(const char* key) {
        if (*key == '\0')return this;//return the location of string end
        int curr = *key - 'A';
        if (next[curr] == NULL)return NULL;//finding value does not exist
        return next[curr]->find(key + 1); //search for next char
    }
};
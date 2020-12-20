class Trie {
public:
    /** Initialize your data structure here. */
    Trie* next[26] = {nullptr};
    bool isEnd=false;
    Trie() {
    //     vector<Trie*>next(26);
    //     bool isEnd=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie*cur=this;
        for(int i=0, sz=word.size();i<sz;i++){
            int t = word[i] - 'a';
            if(cur->next[t]==nullptr){
                cur->next[t]=new Trie();
            }
            cur=cur->next[t];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur=this;
        for(int i=0, sz=word.size();i<sz;i++){
            int t = word[i] - 'a';
            if(cur->next[t]==nullptr) return false;
            cur=cur->next[t];
        }
        if(!cur->isEnd)return false;
        return true;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur=this;
        for(int i=0, sz=prefix.size();i<sz;i++){
            int t = prefix[i] - 'a';
            if(cur->next[t]==nullptr) return false;
            cur=cur->next[t];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Trie {
    public:
    Trie* fanout[26];
    bool tail;
    
    Trie() :tail(false){
        for (int i = 0; i < 26; i++)
            fanout[i]=nullptr;
    }
    
    void insert(string s) {
        Trie* nod = this;
        for (char c : s) {
            c-='a';
            if (nod->fanout[c]==nullptr)
                nod->fanout[c]=new Trie();
            nod = nod->fanout[c];
        }
        nod->tail=true;
    }
    
    Trie* search(char c) {
        return fanout[c-'a'];
    }
};

// 加密解密字符串 模拟 字典树 dfs
class Encrypter {
    // "ei" -> 'a'
    unordered_map<string,vector<char>> mp;
    // 'a' -> "ei"
    string vals[26];
    Trie* root;
    int ans;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for (int i = 0; i < n; i++) {
            vals[keys[i]-'a']=values[i];
            mp[values[i]].push_back(keys[i]);
        }
        root=new Trie();
        for (string s : dictionary)
            root->insert(s);
    }
    
    string encrypt(string word1) {
        string r;
        for (char c : word1)
            r += vals[c-'a'];
        return r;
    }
    void dfs(const string & s, int pos, Trie * t) {
        if (t->tail&&pos==s.size()) {
            ans++;
            return;
        }
        string sub = s.substr(pos,2);
        Trie* child;
        for (char c : mp[sub]) {
            child = t->search(c);
            if (child!=nullptr)
                dfs(s, pos+2, child);
        }
    }
    
    int decrypt(string word2) {
        ans=0;
        dfs(word2, 0, root);
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
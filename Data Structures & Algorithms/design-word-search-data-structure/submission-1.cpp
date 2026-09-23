class WordDictionary {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        bool isWord;

        TrieNode() {
            isWord = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TrieNode* curr, string& word, int i) {
        // Reached the end of the word
        if (i == word.size()) {
            return curr->isWord;
        }

        char c = word[i];

        // Normal letter
        if (c != '.') {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }

            return dfs(curr->children[index], word, i + 1);
        }

        // '.': try every possible letter
        for (int j = 0; j < 26; j++) {
            if (curr->children[j] != nullptr) {
                if (dfs(curr->children[j], word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
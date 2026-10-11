#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

// Trie structure
struct Trie
{
    unordered_map<char, Trie*> ch_trie;
    bool isTerminal = false;

    Trie() : ch_trie(), isTerminal(false) {};
};

// Iteratively grow the trie by adding characters to it
void build_followup(Trie* t, string& word)
{
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        
        // If key does not exist
        if (!t->ch_trie.count(ch)) 
            t->ch_trie[ch] = new Trie(); 
        
        // Always move pointer despite inserting new or existing
        t = t->ch_trie[ch];
    }

    // Set the last letter as terminal
    t->isTerminal = true;
}

// Build the trie word by word
Trie* build_trie(vector<string>& words)
{
    Trie* new_trie = new Trie();

    for (string& word : words) build_followup(new_trie, word);

    return new_trie;
}

// Iteratively check if each charater exist in the word
void check_followup(string& word, Trie* root)
{
    Trie* t = root;

    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];

        if (t->ch_trie.count(ch))
        {
            cout << ch << "";
            t = t->ch_trie[ch];
        }
    }
}

// Check if word exist in trie
void check_words(vector<string>& words, Trie* root)
{
    if (!root) return;

    for (string word : words)
    {
        check_followup(word, root);
        cout << endl;
    }
}

int main()
{
    vector<string> input_words = {"flower", "flow", "flight"};

    Trie* root = build_trie(input_words);

    vector<string> val_words = {"flower", "flight", "turn"};

    check_words(val_words, root);

    return 0;
}
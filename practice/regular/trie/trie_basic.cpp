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

    Trie() : ch_trie() {};
};

// Build a followup trie
Trie* build_followup(Trie* t, string& word, int idx)
{
    // If index is same as string size then return
    if (idx == word.size()) return t;
    
    char ch = word[idx];

    // DEBUG
    cout << ch << " ";
    // DEBUG

    // If key does not exist
    if (!t->ch_trie.count(ch))
    {
        Trie* followup = new Trie();
        t->ch_trie[ch] = build_followup(followup, word, idx + 1);
    }
    // If key does exist
    else if (t->ch_trie.count(ch)) build_followup(t->ch_trie[ch], word, idx + 1);

    return t;
}

Trie* build_trie(vector<string>& words)
{
    // Build a new empty trie
    Trie* new_trie = new Trie();

    // Iterate through each word from the words array and build a followup tree if not existing
    for (string& word : words) build_followup(new_trie, word, 0);

    return new_trie;
}

// Check followup characters for a word to check if the word is in the trie
void check_followup(string word, Trie* t, int idx)
{
    char ch = word[idx];

    if (t->ch_trie[ch])
    {
        cout << ch << "";
        check_followup(word, t->ch_trie[ch], idx + 1);
    }
}

// Check if words are available in trie
void check_words(vector<string>& words, Trie* root)
{
    int idx = 0;

    for (string& word : words)
    {
        cout << endl;
        check_followup(word, root, idx);
    }

    cout << endl;
}

int main()
{
    vector<string> input_words = {"flower", "flow", "flight"};

    Trie* root = build_trie(input_words);

    vector<string> val_words = {"flower", "flight", "turn"};

    check_words(val_words, root);

    return 0;
}
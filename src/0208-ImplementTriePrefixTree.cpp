#include "..\tools.h"

/*
    A prefix tree (also known as a trie) is a tree data structure used to
    efficiently store and retrieve keys in a set of strings.

    Some applications of this data structure include auto-complete and spell checker systems.

Solution:
    implemented with an internal map of pointers
    you dont really need to store the letter as it's in the key of the map
    you do need to store a flag that says if it's a full word
    sould be done with an array[26] or whatever the size of the alphabel

*/

struct Node
{
    std::map<char, Node*> children;
    bool is_word = false;
};

class PrefixTree {
public:
    PrefixTree() {
        root = new Node();
    }

    void insert(std::string word)
    {
        if (word.empty())
            return;

        Node* node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                node->children[word[i]] = new Node();
            }

            node = node->children[word[i]];
        }

        node->is_word = true;
    }

    bool search(std::string word) {
        if (word.size() == 0)
            return true;

        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            auto found = node->children.find(word[i]);
            if (found == node->children.end())
                return false;

            node = found->second;
        }

        return node->is_word;
    }

    bool startsWith(std::string prefix) {
        if (prefix.size() == 0)
            return true;

        Node* node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            auto found = node->children.find(prefix[i]);
            if (found == node->children.end())
                return false;

            node = found->second;
        }

        return true;
    }

private:
    Node* root = nullptr;


};


void lc_0208()
{
    PrefixTree t;

    t.insert("cat");
    t.insert("car");
}
#include <bits/stdc++.h>
using namespace std ;
class Trienode{
public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch){
        this->data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public: 
    Trienode* root;

    Trie(){
        root = new Trienode('\0');
    }

    // Insertion of word
    void insertUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assume word will be in lower case
        int index = word[0] - 'a';
        Trienode* child;

        // If already present move ahead
        if(root->children[index]  != NULL){
            child = root->children[index];
        }else{
            // If Absent create and attach
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    // Searching word
    bool searchUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            if(root->isTerminal){
                return true;
            }else{
                return false;
            }
        }

        int index = word[0] - 'a';
        Trienode* child;

        // WORD PRESENT
        if(root->children[index] != NULL){
             child = root->children[index];
        }else{
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }
    bool  searchWord(string word){
        return searchUtil(root, word);
    }

    // Deletion of word
    void deleteUtil(Trienode* root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        // Assume word will be in lower case
        int index = word[0] - 'a';
        Trienode* child;

        // As word exists move ahead
        child = root->children[index];

        // Recursion
        deleteUtil(child, word.substr(1));
    }
    void deleteWord(string word){
        if(searchWord(word)){
            deleteUtil(root, word);
        }
        else{
            cout<<"WORD DOESN'T EXIST"<<"\n";
        }
    }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("sahil");
    t->insertWord("don");
    t->insertWord("game");
    t->insertWord("hello");

    cout<<"Present OR Absent: "<<t->searchWord("sahil")<<"\n";
    cout<<"Present OR Absent: "<<t->searchWord("sah")<<"\n";

    t->deleteWord("sahil");
    cout<<"Present OR Absent: "<<t->searchWord("sahil")<<"\n";
    t->deleteWord("sah");

    return 0;
}

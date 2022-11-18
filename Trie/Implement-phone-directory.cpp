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
    
    void getSuggestions(Trienode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        
        for(char ch ='a' ; ch <= 'z' ; ch++){
            Trienode* next = curr->children[ch - 'a'];
            
            if(next != NULL){
                prefix.push_back(ch);
                getSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string> > getSuggestions(string str){
        vector<vector<string> > result;
        Trienode* prev = root;
        string prefix = "";
        
        for(int i = 0 ; i < str.length(); i++){
            char last_char = str[i];
            prefix.push_back(last_char);
            // Check if last character exists as child of current node
            Trienode* curr = prev->children[last_char - 'a'];
            
            //If not found
            if(curr == NULL){
                break;
            }
            // If found
            vector<string> temp;
            getSuggestions(curr, temp, prefix);
            result.push_back(temp);
            temp.clear();
            prev = curr;  
        }
        return result;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // Creation of trie;
    Trie* t = new Trie();
    
    // Insert all conact in trie
    for(auto i: contactList ){
       t->insertWord(i);
    }
    
    // Answer
    return t->getSuggestions(queryStr);
}

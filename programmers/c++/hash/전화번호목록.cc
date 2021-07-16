#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(string a, string b){
    return a.size() < b.size();
}

struct trie{
    bool end;
    struct trie *mat[10];
    
    trie(){
        end = 0;
        for(int i = 0; i < 10; ++i){
            mat[i] = NULL;
        }
    }
    
    bool make_trie(const char *ch){
        if(end == true) return false;
        if(*ch == '\0'){
            end = true;
            return true;
        }
        int a = *ch - '0';
        if(mat[a] ==NULL) mat[a] = new trie();
        return mat[a] -> make_trie(ch + 1);
    }
};


bool solution(vector<string> phone_book) {
    bool answer = true;
    struct trie *root = new trie();
    sort(phone_book.begin(), phone_book.end(), gg);
    for(int i = 0; i < phone_book.size(); ++i){
        const char *ch;
        ch = phone_book[i].c_str();
        if(root -> make_trie(ch));
        else{
            return false;
        }
    }
    
    
    return answer;
}
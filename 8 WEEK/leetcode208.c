
typedef struct Node{
    char val;
    _Bool isWord;
    struct Node *next[26];
}Trie,*Triee;
Triee create_node(char val){
    // 创建新节点
    Trie *newNode;
    newNode = (Trie *)malloc(sizeof(Trie));

    newNode->val = val;
    newNode->isWord = false;
    for (int i=0; i<26; i++){
        newNode->next[i] = NULL;
    }

    return newNode;
}
//添加
void add(char *word,Triee root){
    for(int i=0;i<strlen(word);i++){
        char c=word[i];
        int index=c-'a';
        if( root->next[index]==NULL){
            root->next[index] = create_node(c);
        }
        root=root->next[index];
    }

    if(!root->isWord)
        root->isWord=true;
}
//查询
_Bool contains(char *word,Triee root){
    for(int i=0;i<strlen(word);i++){
        char c=word[i];
        int index=c-'a';
        if( root->next[index]==NULL){return false;}
        root=root->next[index];
    }
    return root->isWord;
}
//查询是否有前缀
_Bool isPrefix(char *word,Triee root){
    for(int i=0;i<strlen(word);i++){
        char c=word[i];
        int index=c-'a';
        if( root->next[index]==NULL){return false;}
        root=root->next[index];
    }
    return true;
}

Trie* trieCreate() {
    return  create_node(0);
}

void trieInsert(Trie* obj, char * word) {
    add(word,obj);
}

bool trieSearch(Trie* obj, char * word) {
    return contains(word,obj);
}

bool trieStartsWith(Trie* obj, char * prefix) {
    return isPrefix(prefix,obj);
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->next[i]) {
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/
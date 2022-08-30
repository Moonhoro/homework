typedef struct {
    char val;
    _Bool isWord;
    struct Node *next[26];
} WordDictionary,*Tire;
Tire create_node(char val){
    // 创建新节点
    WordDictionary *newNode;
    newNode = (WordDictionary *)malloc(sizeof(WordDictionary));

    newNode->val = val;
    newNode->isWord = false;
    for (int i=0; i<26; i++){
        newNode->next[i] = NULL;
    }

    return newNode;
}
void add(char *word,Tire root){
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
_Bool contains(char *word,Tire root){
    int ret = false;
    int len = strlen(word);
    for(int i = 0;i<len;i++){
        if(word[i] == '.'){
            for(int j = 0;j<26;j++){
                if(root->next[j] != NULL){
                    _Bool ret = contains(word+i+1,root->next[j]);
                    if(ret){
                        return true;
                    }
                }
            }
            return false;   //没匹配到，返回false.
        }
        else{
            if(root->next[word[i] - 'a'] == NULL){
                return false;
            }
            root = root->next[word[i] - 'a'];
        }
    }
    return root->isWord;  //匹配到最后一个字符，tree还没到叶子节点，直接返回当前节点的finish标志。
}

WordDictionary* wordDictionaryCreate() {
    return  create_node(0);
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    add(word,obj);
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return contains(word,obj);
}

void wordDictionaryFree(WordDictionary* obj) {
    for (int i = 0; i < 26; i++){
        if (obj->next[i]){
            wordDictionaryFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/
#include <string>
typedef struct Node{
    char val;
    _Bool isWord;
    struct Node *next[26];
}Tiree,*Trie;
Tire create_node(char val){
    // 创建新节点
    Tiree *newNode;
    newNode = (Tiree *)malloc(sizeof(Triee));

    newNode->val = val;
    newNode->isWord = false;
    for (int i=0; i<26; i++){
        newNode->next[i] = NULL;
    }

    return newNode;
}
//添加
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
//查询
_Bool contains(char *word,Tire root){
    for(int i=0;i<strlen(word);i++){
        char c=word[i];
        int index=c-'a';
        if( root->next[index]==NULL){return false;}
        root=root->next[index];
}
    return root->isWord;
}
//查询是否有前缀
_Bool isPrefix(char *word,Tire root){
    for(int i=0;i<strlen(word);i++){
        char c=word[i];
        int index=c-'a';
        if( root->next[index]==NULL){return false;}
        root=root->next[index];
    }
    return true;
}
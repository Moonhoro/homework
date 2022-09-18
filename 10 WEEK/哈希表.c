#include <stdlib.h>
//链地址法
#define static SIZE 9;
typedef struct ListNode{
    int key;
    struct ListNode *next;
}*Node;
typedef struct HashTable{
    struct ListNode *table;
}*HashTable;
//创建哈希表
void  init(HashTable hashTable){
    hashTable->table=malloc(sizeof(struct ListNode)*SIZE);
    for (int i = 0; i < SIZE; ++i) {
        hashTable->table[i].key=-1;
        hashTable->table->next=NULL;
    }
}
int hash(int key){
    return key%SIZE;
}
Node createNode(int key){
    Node Node=malloc(sizeof(struct ListNode));
Node->key=key;
Node->next=NULL;
    return Node;
}
//添加
void insert(HashTable hashTable,int key){
    int hashCode= hash(key);
    Node head=hashTable->table+hashCode;
    while(head->next)head=head->next;
    head->next= createNode(key);
}
//查找
_Bool find(HashTable hashTable, int key){
    int hashCode = hash(key);
    Node head = hashTable->table + hashCode;
    while (head->next && head->key != key)
        head = head->next;
    return head->key == key;
}
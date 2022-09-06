#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int e;
    struct Node *left, *right;
    int height;
} * Node;
//初始化
Node createNode(int e){
    Node new = malloc(sizeof(struct Node));
    new->e = e;
    new->left = NULL;
    new->right = NULL;
    new->height=1;
    return new;
}
int max(int a,int b){
    retuen a>b?a:b;
}
int getHeight(Node root){
    if(root==NULL)return  0;
    return root->height;
}
Node leftRotation(Node root){
    Node newRoot=root->right;
    root->right=newRoot->left;
    newRoot->left=root;
    root->height=max(getHeight(root->left), getHeight(root->right))+1;
    newRoot->height=max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
    return newRoot;
}
Node rightRotation(Node root){
    Node newRoot=root->left;
    root->left=newRoot->right;
    newRoot->right=root;
    root->height=max(getHeight(root->left), getHeight(root->right))+1;
    newRoot->height=max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
    return newRoot;
}
Node  rightLeftRotation(Node root){
    root->right= rightRotation(root->right);
    return leftRotation(root);
}
Node  leftRightRotation(Node root){
    root->left= leftRotation(root->left);
    return rightRotation(root);
}
Node insert(Node root, E element){
    if(root == NULL) {
        root = createNode(element);
    }else if(root->element > element) {
        root->left = insert(root->left, element);
        if(getHeight(root->left) - getHeight(root->right) > 1) {
            if(root->left->element > element)
                root = rightRotation(root);
            else
                root = leftRightRotation(root);
        }
    }else if(root->element < element){
        root->right = insert(root->right, element);
        if(getHeight(root->left) - getHeight(root->right) < -1){
            if(root->right->element < element)
                root = leftRotation(root);
            else
                root = rightLeftRotation(root);
        }
    }
    //前面的操作完成之后记得更新一下树高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;  //最后返回root到上一级
}
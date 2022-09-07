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
int Max(int a,int b){
    return a>b?a:b;
}
int getHeight(Node root){
    if(root==NULL)return  0;
    return root->height;
}
Node leftRotation(Node root){
    Node newRoot=root->right;
    root->right=newRoot->left;
    newRoot->left=root;
    root->height=Max(getHeight(root->left), getHeight(root->right))+1;
    newRoot->height=Max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
    return newRoot;
}
Node rightRotation(Node root){
    Node newRoot=root->left;
    root->left=newRoot->right;
    newRoot->right=root;
    root->height=Max(getHeight(root->left), getHeight(root->right))+1;
    newRoot->height=Max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
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
Node insert(Node root, int element){
    if(root == NULL) {
        root = createNode(element);
    }else if(root->e > element) {
        root->left = insert(root->left, element);
        if(getHeight(root->left) - getHeight(root->right) > 1) {
            if(root->left->e > element)
                root = rightRotation(root);
            else
                root = leftRightRotation(root);
        }
    }else if(root->e < element){
        root->right = insert(root->right, element);
        if(getHeight(root->left) - getHeight(root->right) < -1){
            if(root->right->e < element)
                root = leftRotation(root);
            else
                root = rightLeftRotation(root);
        }
    }
    root->height = Max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
//寻找最小元素
Node minimum(Node root)
{
    if (root == NULL)
        return;
    if (root->left == NULL)
        return root;
    return minimum(root->left);
}
//寻找最大元素
Node Maxmum(Node root)
{
    if (root == NULL)
        return;
    if (root->right == NULL)
        return root;
    return Maxmum(root->right);
}
//删除
Node remove(Node root,int e) {
    if (root == NULL) return NULL;
    if (root->e > e) {
        root->left = remove(root->left, e);
        if (getHeight(root->right) - getHeight(root->left) > 1) {
            Node r = root->right;
            if (getHeight(r->left) > getHeight(r->right))
                root = rightLeftRotation(root);
            else
                root = rightRotation(root);
        }
    } else if (root->e < e) {
        root->right = remove(root->right, e);
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            Node l = root->left;
            if (getHeight(l->right) > getHeight(l->left))
                root = leftRightRotation(root);
            else
                root = leftRotation(root);
        }
    } else {
        if ((root->right)&&(root->left)) {
            if (getHeight(root->left) > getHeight(root->right)) {
                Node m = Maxmum(root->left);
                root->e = m->e;
                root->left = remove(root->left, m->e);
            } else {
                Node mi = minimum(root->right);
                root->e = mi->e;
                root->right = remove(root->right, min);
            }
        } else {
            Node tmp = root;
            root = root->left ? root->left : root->right;
            free(tmp);
        }
    }
    return root;
}

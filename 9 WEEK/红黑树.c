#include <stdlib.h>
typedef struct RBTree {
    int e;
    struct RBTree *left, *right;
    _Bool Red;
}*RBTree ;
RBTree createNode(int e){
    RBTree new = malloc(sizeof(struct RBTree));
    new->e = e;
    new->left = NULL;
    new->right = NULL;
    new->Red=ture;
    return new;
}
//左旋转
RBTree leftRotate(RBTree root){
    RBTree x=root->right;
    x->left=root;
    x->Red=root->Red;
    root->Red=ture;
    return  x;
}
//颜色反转
void flipColors(RBTree root){
    root->Red=ture;
    root->left->Red=false;
    root->right->Red=false;
}
//右旋转
RBTree rightRotate(RBTree root){
    RBTree x=root->right;
   root->left=x->right;
   x->right=root;
   x->Red=root->Red;
   root->Red=ture;
    return  x;
}

RBTree add(RBTree root, int e)
{
    if (root == NULL)
    {
        createNode(e);
    }
    else
    {
        if (e > root->e)
        {
            root->right = add(root->right, e);
        }
        else if (e < root->e)
        {
            root->left = add(root->left, e);
        } else{
            root->e=e;
        }
        if(root->left->Red&&!root->right->Red){
            root= leftRotate(root);
        }
        if(root->left->Red&&root->left->left->Red){
            root= rightRotate(root);
        }
        if(root->left->Red&&root->right->Red){
            flipColors(root);
        }
        return root;
    }}
void add_(RBTree root){
    add(root);
    root->Red=false;
}
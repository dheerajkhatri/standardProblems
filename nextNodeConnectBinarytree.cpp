/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode* getNext(TreeLinkNode* parent, TreeLinkNode* child){
    if(parent==NULL || child==NULL)return NULL;
    
    
    if(child==parent->left && parent->right!=NULL)return parent->right;
    
    TreeLinkNode* cur = parent->next;
    while(cur){
        if(cur->left){
            return cur->left;
        }else if(cur->right){
            return cur->right;
        }
        else cur = cur->next;
    }
    if(cur==NULL)return cur;
}
 
void nextConnect(TreeLinkNode* node){
    TreeLinkNode *cur,*leftmost;
    
    if(node==NULL)return;
    
    cur = node;
    cur->next = NULL;
    
    while(cur){
        leftmost = cur;
        
        while(cur){
            if(cur->left!=NULL)cur->left->next = getNext(cur,cur->left);
            if(cur->right!=NULL)cur->right->next = getNext(cur,cur->right);
            cur = cur->next;
        }
        
        while(leftmost && (leftmost->left==NULL && leftmost->right==NULL)){
            leftmost = leftmost->next;
        }
        
        if(leftmost==NULL)return;
        else if(leftmost->left!=NULL)cur = leftmost->left;
        else if(leftmost->right!=NULL) cur = leftmost->right;
    }
}
 
void Solution::connect(TreeLinkNode* A) {
    nextConnect(A);
    return;
}

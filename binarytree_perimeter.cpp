#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

Node* createNode(int n){
	Node* newnode = new Node;
	newnode->data = n;
	newnode->left = newnode->right = NULL;
	return newnode;
}

Node* makeTree(){
	Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    /*root->left->left = createNode(4);
    root->left->left->right = createNode(10);*/
    root->left->right = createNode(5);
    root->left->right->left = createNode(11);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->right = createNode(8);
    root->right->right->right = createNode(9);
    return root;
}

void rightPart(Node* root){
	if(!root || (root->left==NULL && root->right==NULL))return;
	cout<<root->data<<" ";
	if(root->right!=NULL)rightPart(root->right);
	else rightPart(root->left);
}

void leftPart(Node* root){
	if(!root || (root->left==NULL && root->right==NULL))return;	
	if(root->left!=NULL)rightPart(root->left);
	else rightPart(root->right);
	cout<<root->data<<" ";
}

void base(Node* root){
	if(!root)return;
	base(root->right);
	if(root->left==NULL && root->right==NULL)cout<<root->data<<" ";
	base(root->left);
}

void perimeter(Node* root){
	if(!root)return;
	cout<<root->data<<" ";
	//cout<<"right part.."<<endl;
	rightPart(root->right);
	//cout<<endl;cout<<"leaf part.."<<endl;
	base(root);
	//cout<<endl;cout<<"left part.."<<endl;
	leftPart(root->left);	
}


int main(){
	
	Node *root = makeTree();
	perimeter(root);cout<<endl;
	return 0;
}
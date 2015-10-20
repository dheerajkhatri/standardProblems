#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
int n;
//say n =3

struct Node{
	int data;
	struct Node** adj;
	int vc;
};

Node* getNode(int val){
	Node* newnode = new Node;
	newnode->data = val;
	newnode->vc = 0;
	newnode->adj = new Node*[n];
	for(int i=0;i<n;i++)
		newnode->adj[i] = NULL;
	return newnode;
}

Node* createTree(){
	Node* root;
	root = getNode(1);
	root->adj[0] = getNode(2);
	root->adj[1] = getNode(3);
	root->adj[2] = getNode(7);
	(root->adj[0])->adj[0] = getNode(4);
	(root->adj[1])->adj[0] = getNode(5);
	(root->adj[1])->adj[1] = getNode(6);
	return root;
}

void printTree(Node* root){
	if(!root)return;
	cout<<root->data<<" ";
	for(int i=0;i<n;i++){
		printTree(root->adj[i]);
	}
}

int vCover(Node* root){
	//base case
	if(!root)return 0;
	
	//base case
	bool allnull = true;
	for(int i=0;i<n;i++){
		if(root->adj[i]!=NULL){
			allnull = false;
			break;
		}
	}
	if(allnull)return 0;
	
	
	if(root->vc)return root->vc;
	int size_incl = 1,size_excl=0;
	
	for(int i=0;i<n;i++)
		size_incl += vCover(root->adj[i]);
	
	for(int i=0;i<n;i++){
		if(root->adj[i]){
			size_excl += 1;
			for(int j=0;j<n;j++){
				size_excl += vCover((root->adj[i])->adj[j]);
			}
		}
	}
	root->vc = min(size_incl,size_excl);
	return root->vc;
}

int main() {
	cin>>n;
	Node* root = createTree();
	/*cout<<"tree build successfully"<<endl;
	printTree(root);*/
	cout<<vCover(root)<<endl;
	return 0;
}
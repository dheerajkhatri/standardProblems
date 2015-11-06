/*:-Dheeraj Khatri*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;


struct Node{
	int data;
	Node *left,*right;	
};

Node* newNode(int val){
	Node* newnode = new Node;
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Node* createTree(){
	Node *node1 = newNode(1);	
	Node *node2 = newNode(2);
	Node *node3 = newNode(3);
	Node *node4 = newNode(4);
	Node *node5 = newNode(5);
	Node*root = node1;
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node4->left = newNode(6);
	return root;
}

int getheight(Node* root){
	if(!root)return 0;
	int lh = getheight(root->left);
	int rh = getheight(root->right);
	return 1+max(lh,rh);
}

void root2leftPath(Node* root, int curlevel,int height, vector<int>& curpath){
	if(!root)return;
	curpath[curlevel] = root->data;

	if(root->left==NULL && root->right==NULL){
		for(int i=0;i<=curlevel;i++)cout<<curpath[i]<<" ";cout<<endl;
		return;
	}
	root2leftPath(root->left,curlevel+1,height,curpath);
	root2leftPath(root->right,curlevel+1,height,curpath);
}

void levelOrderByQueue(Node*root){
	if(!root)return;
	Node*temp;
	deque<Node*>q;
	q.push_front(root);
	while(!q.empty()){
		temp = q.front();
		q.pop_front();
		cout<<temp->data<<" ";
		if(temp->left)q.push_back(temp->left);
		if(temp->right)q.push_back(temp->right);
	}
	cout<<endl;	
}

vector<vector<Node*>> levelOrderByVV(Node* root,int height){
	vector<vector<Node*>>levels(height);
	if(!root)return levels;
	int curlevel = 0;
	levels[curlevel++] = {root};
	Node *temp;	
	while(curlevel<height){
		for(int i=0;i<levels[curlevel-1].size();i++){
			temp = (levels[curlevel-1])[i];
			if(temp->left)levels[curlevel].push_back(temp->left);
			if(temp->right)levels[curlevel].push_back(temp->right);
		}
		curlevel++;
	}
	return levels;
}

void printLevels(vector<vector<Node*>>& v){
	for(auto it:v){
		for(auto jt:it){
			cout<<jt->data<<" ";
		}
		cout<<endl;
	}
}

int DiameterLen(Node* root, int& curheight){
	int lh,rh,ld,rd;
	if(!root){
		curheight = 0;
		return 0;
	}
	ld = DiameterLen(root->left,lh);
	rd = DiameterLen(root->right,rh);
	curheight = max(lh,rh)+1;

	return max(ld,max(rd,lh+rh+1));
}

bool isHeightBalanced(Node* root, int& curheight){
	if(!root){
		curheight = 0;
		return true;
	}
	int lh,rh;
	bool leftok,rightok;
	leftok = isHeightBalanced(root->left,lh);
	rightok = isHeightBalanced(root->right,rh);
	if(!leftok || !rightok)return false;
	curheight = max(lh,rh)+1;
	return abs(lh-rh)>1 ? false:true;
}

void width(Node* root, int curdistance, int& maxwidth){
	if(!root)return;
	if(maxwidth < abs(curdistance))
		maxwidth = abs(curdistance);

	if(root->left)width(root->left,curdistance-1,maxwidth);	
	if(root->right)width(root->right,curdistance+1,maxwidth);	
}

bool pathSum(Node* root, int cursum, int sum){
	if(!root){
		return cursum==sum;
	}
	bool leftans=false,rightans=false;
	
	leftans = pathSum(root->left,cursum+root->data,sum);	
	rightans = pathSum(root->right,cursum+root->data,sum);
	return leftans||rightans;
}

int maxSumPath(Node* root){
	static int maxsum = INT_MIN;
	if(!root)return maxsum;
	vector<pair<Node*,int>>cur,next;
	cur.push_back(make_pair(root,root->data));
	while(!cur.empty()){
		for(auto it=cur.begin();it!=cur.end();it++){
			if(it->first->left==NULL && it->first->right==NULL){
				maxsum = max(maxsum,it->second);
			}
			if(it->first->left!=NULL){
				next.push_back(make_pair(it->first->left,it->second + (it->first->left)->data));
			}
			if(it->first->right!=NULL){
				next.push_back(make_pair(it->first->right,it->second + (it->first->right)->data));
			}
		}
		cur.clear();
		cur.swap(next);
	}
	return maxsum;
}


void inorderStack(Node* root){
	stack<Node*>s;
	if(!root)return;	
	Node* cur = root;

	while(!s.empty() || cur){		
		while(cur){
			s.push(cur);
			cur = cur->left;
		}

		cur = s.top();
		s.pop();
		cout<<cur->data<<" ";
		cur = cur->right;
	}
	cout<<endl;
}

Node* buildTreeByInPre(vector<int>&inorder,int ins, int ine,vector<int>&preorder,int& pos){
	if(pos>=preorder.size() || ins>ine)return NULL;
	//find pos value in inorder
	int newrootpos;

	for(int i=ins;i<=ine;i++){
		if(inorder[i]==preorder[pos])
			newrootpos = i;
	}

	Node* root = newNode(preorder[pos]);
	pos++;
	root->left = buildTreeByInPre(inorder,ins,newrootpos-1,preorder,pos);
	root->right = buildTreeByInPre(inorder,newrootpos+1,ine,preorder,pos);
	return root;
}

int main() {
	std::ios::sync_with_stdio(false);
	Node* root = createTree();

	/*int height = getheight(root);
	cout<<height<<endl;

	cout<<"Print all root to leaf paths"<<endl;
	vector<int>curpath(height);
	root2leftPath(root,0,height-1,curpath);

	cout<<"Level order using deque"<<endl;
	levelOrderByQueue(root);

	cout<<"Level order using vector of vector "<<endl;
	vector<vector<Node*>>levels = levelOrderByVV(root,height);	
	printLevels(levels);

	cout<<"Max len of Diameter is "<<endl;
	int curheight = 0;
	cout<<DiameterLen(root,curheight)<<endl;

	curheight = 0;
	cout<<"Is height balanced"<<endl;
	cout<<isHeightBalanced(root,curheight)<<endl;

	cout<<"Maximum width is"<<endl;
	int curdistance=0,maxwidth=0;
	width(root,curdistance,maxwidth);
	cout<<maxwidth<<endl;

	cout<<"Has root to leaf sum = 13"<<endl;
	cout<<pathSum(root,0,13)<<endl;

	cout<<"Inorder using Stack"<<endl;
	inorderStack(root);

	cout<<"Tree from Inorder and Preorder"<<endl;
	vector<int>inorder = {4,2,5,1,6,3};
	vector<int>preorder = {1,2,4,5,3,6};
	int prepos = 0;
	Node* root2 = buildTreeByInPre(inorder,0,5,preorder,prepos);
	inorderStack(root2);*/

	cout<<maxSumPath(root)<<endl;
	return 0;
}
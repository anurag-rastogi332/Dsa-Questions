#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

//return root node of the tree
Node* buildTree() {
	int val;
	cin >> val;

	if(val == -1) {
		return NULL;
	}
	else {
		Node* root = new Node(val);
		//1 case maine krdia, baaki recursion 
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
}

//NLR - preorder
void preOrderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}
	//1 case main solve krunga , baaki recursion sambhal lega 
	//N 
	cout << root->data << " ";
	//L
	preOrderTraversal(root->left);
	//R
	preOrderTraversal(root->right);
}

//LNR - inorder
void inorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}
	//LNR
	//L
	inorderTraversal(root->left);
	//N
	cout << root->data << " ";
	//R
	inorderTraversal(root->right);
}


//LRN - postorder
void postorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}
	//LRN
	//L
	postorderTraversal(root->left);
	//R
	postorderTraversal(root->right);
	//N
	cout << root->data << " ";
}


void levelOrderTraversal(Node* root) {
	//empty tree
	if(root == NULL) {
		return;
	}
	//LOT
	queue<Node* > q;
	//initial state maintain 
	q.push(root);
	//using NULL as a marker
	q.push(NULL);

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();
		if(front == NULL) {
			//current elvel ki saari node print ho chuki h 
			//go to next line 
			cout << endl;
			///agar q empty h, then do not insert NULL -> infinite loop fas skta h thats why
			//agar q non empty h, then insert NULL ->to indicate the rightmost NODE or end of level
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}


int main() {
	//10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1 
	Node* root = buildTree();
	cout << endl;
	cout << "Printing Preorder traversal: " << endl;
	preOrderTraversal(root);

	cout << endl << "Printing Inorder traversal: " << endl;
	inorderTraversal(root);

	cout << endl << "Printing PostOrder traversal: " << endl;
	postorderTraversal(root);

	cout << endl << "Printing Level Order traversal: " << endl;
	levelOrderTraversal(root);



	return 0;
}

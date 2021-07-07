#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(): data(0), left(nullptr), right(nullptr) {}
	Node(int x): data(x), left(nullptr), right(nullptr) {}
};

int maxDepth(Node *root){
	if(root == nullptr)	return 0;
	
	return 1 + max(
		maxDepth(root->left), 
		maxDepth(root->right)
	);
}

int main(){
	Node *root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);


	cout << maxDepth(root) << "\n";

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	} else {
		node* root = new node(x);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
}

void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	//Root:
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int countnodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int x = countnodes(root->left);
	int y = countnodes(root->right);
	int ans = x + y + 1;
	return ans;
}
int sum(node* root) {
	if (root == NULL) {
		return 0;
	}
	int x = sum(root->left);
	int y = sum(root->right);
	int ans = x + y + root->data;
	return ans;
}

int height(node* root) {
	if (root == NULL) {
		return 0;
	}
	int left_subtree_height = height(root->left);
	int right_subtree_height = height(root->right);
	int ans = max(left_subtree_height, right_subtree_height) + 1;
	return ans;
}

void mirror(node* &root) {
	if (root == NULL) {
		return;
	}
	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}
int diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = diameter(root->left);
	int option2 = diameter(root->right);
	//Diameter goes through the root:
	int option3 = height(root->left) + height(root->right);

	return max(option1, max(option2, option3));
}
//Time Complexity: O(n^2);



// root:
// two pointer: left and right:

// the subtree which was ealier pointed by the pointer left
// now will be pointed by the pointer right.

int main() {
	node* root = buildTree();
	/*preorder(root);
	cout << endl;*/
	/*inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	cout << countnodes(root) << endl;
	cout << sum(root) << endl;
	cout << height(root) << endl;*/
	mirror(root);
	preorder(root);
	cout << endl;
	node* root1 = buildTree();
	preorder(root1);
	cout << endl;
	cout << diameter(root);
}
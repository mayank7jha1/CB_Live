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


class Pair2 {
public:
	int height;
	int diameter;
};

Pair2 fastdiameter(node* root) {
	Pair2 p;

	if (root == NULL) {
		p.diameter = 0;
		p.height = 0;
		return p;
	}

	Pair2 left_subtree = fastdiameter(root->left);
	Pair2 right_subtree = fastdiameter(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	p.diameter = max(left_subtree.diameter, max(right_subtree.diameter,
	                 left_subtree.height + right_subtree.height));
	return p;

}



class Pair3 {
public:
	int height;
	bool isbalanced;
};

Pair3 isheightbalanced(node* root) {
	Pair3 p;

	if (root == NULL) {
		p.isbalanced = true;
		p.height = 0;
		return p;
	}

	Pair3 left_subtree = isheightbalanced(root->left);
	Pair3 right_subtree = isheightbalanced(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	if (left_subtree.isbalanced == 1 and right_subtree.isbalanced == 1
	        and abs(left_subtree.height - right_subtree.height) <= 1) {
		p.isbalanced = true;
	} else {
		p.isbalanced = false;
	}
	return p;
}


node *buildTreefromarray(int *a, int s, int e) {
	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;

	node* root = new node(a[mid]);
	root->left = buildTreefromarray(a, s, mid - 1);
	root->right = buildTreefromarray(a, mid + 1, e);
	return root;
}


void printkthlevel(node* root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	printkthlevel(root->left, k - 1);
	printkthlevel(root->right, k - 1);
}

void printAllLevel(node* root) {
	int H = height(root);
	for (int i = 1; i <= H; i++) {
		printkthlevel(root, i);
		cout << endl;
	}
}

void bfs(node* root) {
	queue<node*>q;

	q.push(root);
	while (!q.empty()) {
		node* first = q.front();
		cout << first->data << " ";
		q.pop();
		if (first->left != NULL) {
			q.push(first->left);
		}
		if (first->right) {
			q.push(first->right);
		}
	}
}

void bfs2(node* root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* first = q.front();
		if (first == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << first->data << " ";
			q.pop();
			if (first->left != NULL) {
				q.push(first->left);
			}
			if (first->right) {
				q.push(first->right);
			}
		}
	}
}

node* buildTreefrompreandin(int *in, int *pre, int s, int e) {
	if (s > e) {
		return NULL;
	}
	static int i = 0;
	node* root = new node(pre[i]);
	// root=2;i will always become 0 in the stack every time
	// recursion calls;
	int index = -1;

	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	i++;//i=1;

	root->left = buildTreefrompreandin(in, pre, s, index - 1);
	root->right = buildTreefrompreandin(in, pre, index + 1, e);
	return root;
}

//Because you can insert and pop an element from
//queue in O(1) time that means you are doinf
//this for the n elements hence tC=
//O(2n) i.e linear why because every element
//is inserted and removed only one time.

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
	// mirror(root);
	// preorder(root);
	// cout << endl;
	/*node* root1 = buildTree();
	preorder(root1);
	cout << endl;
	cout << diameter(root) << endl;
	Pair2 p = fastdiameter(root);
	cout << p.diameter << " " << p.height << endl;
	Pair3 p1 = isheightbalanced(root);
	cout << p1.isbalanced << " " << p1.height << endl;
	cout << endl;

	int a[] = {9, 7, 1, 2, 5, 17, 3};
	node* root4 = buildTreefromarray(a, 0, 6);
	preorder(root4);
	cout << endl;
	cout << diameter(root4) << endl;
	cout << height(root4) << endl;

	printkthlevel(root, 2);
	cout << endl;

	printAllLevel(root);
	cout << endl;
	bfs(root);
	cout << endl;
	bfs2(root);
	cout << endl;*/

	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	int in[] = {9, 4, 2, 3, 10};
	int pre[] = {2, 9, 4, 10, 3};
	node* root9 = buildTreefrompreandin(in, pre, 0, 4);
	preorder(root9);
	cout << endl;
}
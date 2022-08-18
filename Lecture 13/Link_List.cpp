#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

class node {
public:
	int data;
	node* next;//Self Referencing Pointer:

	//Constructor:
	//Initialisation:
	node(int inputdata) {
		data = inputdata;
		next = NULL;
	}
};



void InsertAtHead(node*&head, int value) {
	node *n = new node(value);//Constructor ke through initialise;
	//Dynamic kYu banaya hain?
	n->next = head;
	head = n;
}
/*10=head;

20->10:
head=20*/

void InsertAtTail(node*&head, int value) {
	if (head == NULL) {

		/*
			node* n=new node(value);
			head=n;
		*/

		head = new node(value);
		return;
	}

	//Pehla kaam kya hain?
	//Main ll me last element par kaise jaau?
	//directly nahi jaasakta?

	node* temp = head;

	/*
		temp!=NULL
		this means it will stop when temp =NULL

		temp->next!=NULL
		this means it will stop when we reach at the
		last element because the next element to this is null.
	*/

	while (temp->next != NULL) {
		temp = temp->next;
	}

	//Last element par khada hu?

	temp->next = new node(value);
	/*
		node* n=new node(value);
		temp->next=n;
	*/
	return;
}

void Print(node*&head) {
	node*temp = head;

	while (temp != NULL) {
		cout << (*temp).data << "->";
		temp = temp->next;
	}
}


int len(node* head) {
	int length = 0;
	node* temp = head;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}


int midPoint(node* head) {
	int mid = len(head) / 2;

	node* temp = head;
	while (mid > 0) {
		temp = temp->next;
		mid--;
	}
	return temp->data;
}

node* midPoint1(node* head) {
	int mid = len(head) / 2;

	node* temp = head;
	while (mid > 0) {
		temp = temp->next;
		mid--;
	}
	return temp;
}
/*
ek pointer=2x;
ek pointer=x;
2x ka pointer exhaust hojayega to x vaala pointer mid par hoga:*/

node* midPoint2(node* head) {
	node* slow = head;
	node* fast = head;
	while (fast->next != NULL and fast != NULL) {
		/*fast = fast->next;
		fast = fast->next;*/
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*10->20->30->40->50->60->NULL;

s = 30
    f = NULL*/

bool searchIterative(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool searchRecursive(node* head, int key) {
	node* temp = head;
	if (temp == NULL) {
		return false;
	}

	if (temp->data == key) {
		return true;
	} else {
		return searchRecursive(head->next, key);
	}
}


void ReverseLL(node*&head) {
	node* current = head;
	node* prev = NULL;
	node* n;

	while (current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}
	head = prev;
}
//Using recursion isko reverse karna?



/*10->20->30->NULL;

p = NULL
    c = 10
        n = 20

            10->NULL
            p = 10;
c = 20
    20->10->NULL

    prev = 20;
c = 30
    n = NULL
        30->20->10->null
        prev = 30;
current = NULL;


head = 10;
new ll ka head is 30
head = 30;*/
int main() {
	int n;
	cin >> n;
	node* head = NULL;
	node* head1 = NULL;
	//Constructor ke through initialise = and ek bar function?

	//Head naam ka ek node block hain jo null null store kar rha hain:

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		InsertAtHead(head, x);
		InsertAtTail(head1, x);
	}
	Print(head);
	cout << endl;
	cout << len(head) << endl;
	Print(head1);
	cout << endl;
	cout << len(head1) << endl;
	cout << midPoint(head) << endl;
	cout << midPoint(head1) << endl;

	node* x = midPoint1(head);
	cout << x->data << endl;
	node* y = midPoint2(head);
	cout << y->data << endl;

	cout << searchIterative(head, 140) << endl;
	cout << searchRecursive(head, 40) << endl;
	ReverseLL(head);
	Print(head);
	cout << endl;

}

//Input:
/*
	5
	10 20 30 40 50

	10->20->30->40->50;

	head=first
	node
	tail =last node?
	 given nahi hota
	 tumko nikalna padhta hian.

*/
//50->40->30->20->10->NULL
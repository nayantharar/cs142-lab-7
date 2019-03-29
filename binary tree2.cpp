//include library
#include <iostream>
using namespace std;


//create class node
class Node
{
	public:
	int data;
	
	Node *left;
	Node *right;
	Node *parent;

//initialisation
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};


//create class bist
class bist
{
	
	
	public:
	Node *root;

	bist() {
	 root = NULL;
	  }


//insertion of elements

	void insert(int value)
	{ insertHelper(root, value);}

	void insertHelper(Node *curr, int value)
	{
		if (root == NULL)
		{
			root = new Node(value);
		}
		// Else compare the curr data with value
		else if (value < curr->data)
		{
			// else move left and call insertH
			if (curr->left == NULL)
			{
				curr->left = new Node(value);
				curr->left->parent=curr;
			}
			else
				insertHelper(curr->left, value);
		}
		else
		{
			// Else move right and call insertH
			if (curr->right == NULL)
			{
				curr->right = new Node(value);
				curr->right->parent=curr;
			}
			else
				insertHelper(curr->right, value);
		}
  	}

	Node* find_min(Node * curr)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(curr->left!=NULL)
		{
			return find_min(curr->left);
		}
		else
		{
			return curr;
		}
	}

	int count(Node* curr)
	{
		return counthelper(curr,0);
	}

	int counthelper(Node* curr, int c)
	{
		int a=0,b=0;
		c++;
		if(curr->left!=NULL)
		{
			a=counthelper(curr->left,0);
		}
		if(curr->right!=NULL)
		{
			b=counthelper(curr->right,0);
		}
			return c+a+b;
	}



//dislpay of the tree
  	void display()
	{
		displayHelper(root);
		cout<<endl;
	}

  	void displayHelper(Node *curr)
	{
		// Base condition
		if (curr == NULL)
			return;
		// Display left.
		displayHelper(curr->left);
		// Display current
		cout << curr->data << ",";
		// Display right
		displayHelper(curr->right);
	}

	void displayFancy()
	{
		displayFancyHelper(root,0);
	}

	void displayFancyHelper(Node * cur,int s)
	{
		//when at the end of a trail return
		if(cur==NULL)
		{return;}
		//go left and increase the number of spaces
		displayFancyHelper(cur->left,s+1);
		//print the spaces
		for(int i=0;i<4*s;i++){cout<<" ";}
		//print the data
		cout<<cur->data<<endl;
		//go right and increase the number of spaces
		displayFancyHelper(cur->right,s+1);
  	}

	Node* search(Node * cur,int value)
	{
		if(cur==NULL)
		{return NULL;}
		if(cur->data==value)
		{return cur;}
		if(cur->data<value)
		{return search(cur->right,value);}
		else
		{return search(cur->left,value);}
	}


//deletion
	void binary_delete(Node * cur)
	{
		Node* temp=cur;
		if(cur->right!=NULL)
		{
			temp=temp->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			cur->data=temp->data;
			if(temp->right!=NULL)
			{binary_delete(temp);}
			else
			{
				temp->parent->right=NULL;
				delete temp;
			}
		}
		else
		{
			temp=temp->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			cur->data=temp->data;
			if(temp->left!=NULL)
			{binary_delete(temp);}
			else
			{
				temp->parent->left=NULL;
				delete temp;
			}
		}
	}
};

int main()
{
	bist b1;
	b1.insert(8);
	b1.insert(4);
	b1.insert(13);
	b1.insert(6);
	b1.insert(7);
	b1.insert(3);
	b1.insert(9);

	b1.display();
	b1.displayFancy();
	if(b1.search(b1.root,2)==NULL)
	{
		cout<<"Not Found"<<endl;
	}
	else
	{
		cout<<"Found"<<endl;
	}
	cout<<b1.count(b1.root)<<endl;
	b1.binary_delete(b1.root);
	b1.displayFancy();
}

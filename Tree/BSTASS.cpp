#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int _data)
	{
		data = _data;
		left = NULL;
		right = NULL;
	}
	Node(int _data, Node *_left, Node *_right)
	{
		data = _data;
		left = _left;
		right = _right;
	}
};

struct BST
{
	Node *root;

	BST()
	{
	 root = NULL;
	}

	void insert(int value)
	{
		if (root == NULL)
		{
			root = new Node(value, NULL, NULL);
		}
		else
		{
			Node *it = root;
			while(1)
			{
				if(value <= it->data )
				{
					if(it->left == NULL)
					{
						it->left = new Node(value);
						break;
					}
					else it = it->left;
				}

				else
				{
					if(it->right == NULL)
					{
						it->right = new Node(value);
						break;
					}
					else it = it->right;
				}
			}
		}
	}


	void printjustleft(Node *it)
	{
		while(it != NULL)
		{
			printf(" < - %d ", it->data);

			it = it->left;
		}

	}

		void printright(Node *it)
	{

		while(it != NULL)
		{
			printf(" - > %d ", it->data);
			if(it->left != NULL)
			{
				Node *c = it;
				printf(" ( ");
				printjustleft(c->left);
				printf(" ) ");
			}
			it = it->right;
		}
		// if(it == NULL )
		// printf("\n ^ \n");
	}

	void print()
	{
		Node *it = root;
		Node *st;

		while(it != NULL)
		{
			printf(" %d ", it->data);
			st = it;
			printright(st->right);

			it = it->left;
			if(it != NULL)
			printf("\n ^ \n");
		}
		printf("\n");
	}

	void printPreorderTraversal(){

		PreorderTraversal(root);
		printf("\n");
		return;
	}

	void PreorderTraversal(Node *root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
	void printInorderTraversal(){

		InorderTraversal(root);
		printf("\n");
		return;
	}



	void InorderTraversal(Node *root){
		if(root==NULL){
			return;
		}

		InorderTraversal(root->left);
		cout<<root->data<<" ";
		InorderTraversal(root->right);
	}



	void printPostorderTraversal(){

		PostorderTraversal(root);
		printf("\n");
		return;
	}
	void PostorderTraversal(Node *root){
		if(root==NULL){
			return;
		}

		PostorderTraversal(root->left);

		PostorderTraversal(root->right);
		cout<<root->data<<" ";
	}

	Node* traverse(Node *root, int q)
	{
		if(root == NULL)
		{
			return NULL;
		}
		if(q == root->data)
		{
			return root;
		}
		traverse(root->left, q);
		traverse(root->right, q);
	}

	Node *traverselow(Node *root, int q)
	{
		Node *ans;
		if(root == NULL)
		{
			return ans;
		}

		ans = root;

		if(q <= root->data)
		{
			if(root->left!=NULL)
			traverselow(root->left, q);
			else return root;
		}

		else
		{
			if(root->right != NULL)
			traverselow(root->right, q);
			else return root;
		}

	}


	Node *traverseupp(Node *root, int q)
	{
		Node *ans;
		if(root == NULL)
		{
			return ans;
		}

		ans = root;

		if(q < root->data)
		{
			if(root->left!=NULL)
			traverseupp(root->left, q);
			else return root;
		}

		else
		{
			if(root->right != NULL)
			traverseupp(root->right, q);
			else return root;
		}

	}

	Node* search(int q)
	{
		Node *ans = traverse(root, q);
		return ans;
	}

	Node *lowerbound(int q)
	{
		Node *ans = traverselow(root, q);
		return ans;
	}

	Node *upperbound(int q)
	{
		Node *ans = traverseupp(root, q);
		return ans;
	}


	void deletefromtree(int q)
	{
		root = deletenode(root, q);
		return;
	}

	Node *deletenode(Node *cur, int q)
	{
		Node* temp = cur;

		if(cur == NULL) return NULL;

		else if(q < cur->data)
		{
		 	cur->left = deletenode(cur->left, q);
		}

        else if(q > cur->data)
    	{
    		cur->right = deletenode(cur->right, q);
    	}
    	else if(cur->left == NULL && cur->right == NULL)
    	{
    		cur = NULL;
    		delete temp;
    	}
    	else if(cur->left != NULL && cur->right != NULL)
        {
            temp = upperbound(cur->data);
            cur->data = temp->data;
            cur->right = deletenode(cur->right, cur->data);
        }
        else
        {
            if(cur->left == NULL)
            {
            	cur = cur->right;
            }
            else if(cur->right == NULL)
        	{
        		cur = cur->left;
        	}
        	delete temp;
        }

		return cur;
	}



};

int main()
{
	printf("How many nodes in the tree: ");
	int n, x;
	scanf("%d", &n);
	BST tree;
	printf("Enter Data:\n");

	for(int i=0;i<n;i++)
	{
		scanf("%d", &x);
		tree.insert(x);
		// printf("%d ", tree.root->data);
	}

	while(1)
	{
		int cmd;
		printf("Enter Command\n");
		printf("1 - Print the tree.\n");
		printf("2 - Print Preorder Traversal.\n");
		printf("3 - Print Inorder Traversal.\n");
		printf("4 - Print Postorder Traversal.\n");
		printf("5 - Insert new node in the tree.\n");
		printf("6 - Search the tree for a value.\n");
		printf("7 - Delete a value from the tree.\n");
		printf("8 - Upper bound of a certain value.\n");
		printf("9 - Lower bound of a certain value.\n");
		printf("10 - Close the Application.\n");

		scanf("%d", &cmd);
		if(cmd == 1)
		{
			tree.print();
			printf("\n");
		}
		else if(cmd == 2)
		{
			tree.printPreorderTraversal();
			printf("\n");
		}
		else if(cmd == 3)
		{
			tree.printInorderTraversal();
			printf("\n");
		}
		else if(cmd == 4)
		{
			tree.printPostorderTraversal();
			printf("\n");
		}
		else if(cmd == 5)
		{
			printf("Enter the value to be inserted - ");
			scanf("%d", &x);
			tree.insert(x);
			printf("\n");
		}

		else if(cmd == 6)
		{
			int q;
			printf("Enter the value to search: ");
			scanf("%d", &q);

			Node *ans = tree.search(q);

			if(ans != NULL) printf("The value is found at %p\n", ans);
			else printf("The value is not in the Binary Search Tree\n");
			printf("\n");
		}


		else if(cmd == 7)
		{
			printf("Enter a value to delete from the tree: ");
			int q;
			scanf("%d", &q);

			tree.deletefromtree(q);

			printf("\n");
		}

		else if(cmd == 8)
		{
			int q;
			printf("Enter the value to find Upperbound of: ");
			scanf("%d", &q);

			Node *ans = tree.upperbound(q);

			if(ans != NULL)
			{
				if(q < ans->data)
				printf("The Upperbound is found at %p and its value is %d\n", ans, ans->data);
				else printf("Upperbound not found\n");
			}

			else printf("Upperbound not found\n");

			printf("\n");
		}

		else if(cmd == 9)
		{
			int q;
			printf("Enter the value to find Lowerbound of: ");
			scanf("%d", &q);

			Node *ans = tree.lowerbound(q);

			if(ans != NULL)
			{
				if(q <= ans->data)
				printf("The Lowerbound is found at %p and its value is %d\n", ans, ans->data);
				else printf("Lowerbound not found\n");
			}

			else printf("Lowerbound not found\n");

			printf("\n");
		}
		// printf("\n");
	}

	return 0;

	// tree.printright();

	// printf("\n");



	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	int frequency;
	int sizeOfSubtree;
    bool isActive;

	Node(int _data)
	{
		data = _data;
		left = NULL;
		right = NULL;
		frequency = 0;
		sizeOfSubtree = 0;
        isActive = false;
	}
	Node(int _data, Node *_left, Node *_right)
	{
		data = _data;
		left = _left;
		right = _right;
		frequency = 0;
		sizeOfSubtree = 0;
        isActive = false;
	}
};

class query{
public:
    char type;
    int data;

    query(char _type, int _data)
    {
        type = _type;
        data = _data;
    }
};

struct BST
{
	Node *root;
	int numberOfNodes;

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
				if(value < it->data )
				{
					// it->sizeOfSubtree++;

					if(it->left == NULL)
					{
						it->left = new Node(value);
						break;
					}
					else it = it->left;
				}

				else if(value > it->data )
				{
					// it->sizeOfSubtree++;

					if(it->right == NULL)
					{
						it->right = new Node(value);
						break;
					}
					else it = it->right;
				}
				else
				{
					//If the number is in the BST more than once, increment
					// it->frequency++;
					break;
				}
			}
		}
	}

    void activateNode(int value)
	{
		numberOfNodes++;
		Node *it = root;
		while(1)
		{

			if(value < it->data )
			{
                it->sizeOfSubtree++;
                it = it->left;

			}

			else if(value > it->data )
			{

                it->sizeOfSubtree++;
                it = it->right;
			}
			else
			{
				//If the number is in the BST more than once, increment
                if(! it->isActive )
                {

                    it->isActive = true;
                    it->frequency = 1;
                }
                else
                {
                    it->frequency++;
                }
				break;
			}
		}

	}

	int findSolve(Node *currentNode, int q)
	{
		if(currentNode == NULL)
		{
			return 0;
		}
		int ct = 0;

		if(currentNode->data > q)
		{
			ct += currentNode->frequency;

			if(currentNode->right != NULL)
			{
				ct += currentNode->right->frequency;
				ct += currentNode->right->sizeOfSubtree;
			}

			ct += findSolve(currentNode->left, q);
		}

		else if(currentNode->data < q)
		{
			ct += findSolve(currentNode->right, q);
		}

		else
		{
			if(currentNode->right != NULL)
			{
				ct += currentNode->right->frequency;
				ct += currentNode->right->sizeOfSubtree;
			}

		}

		return ct;
	}

	int findGreater(int data)
	{
		return findSolve(root, data);
	}

	int findLesser(int data)
	{
		/*
		We don't need a separate counter for the numbers less than X,
		we can use the same function if we only store a variable named numberOfNodes
		*/
		return numberOfNodes - findSolve(root, data);
	}


};



BST tree;

vector<int> toInsert;
vector <int> initInsert;
vector<query> listOfQueries;


// void makeBST(int size)
// {
//
//
// }


void runQueries()
{
	for(auto child: listOfQueries)
    {
        char command = child.type;
        int x = child.data;

		if(command == 'I')
		tree.activateNode(x);

		if(command == 'U')
		{
			int ans = tree.findGreater(x);
			printf("%d\n", ans);
		}

		else if(command == 'L')
		{
			int ans = tree.findLesser(x);
			printf("%d\n", ans);
		}

	}

	return;
}


void insertFromMid(int left, int right)
{
    if(left > right)
        return;

    if(left == right)
    {
        tree.insert(toInsert[left]);
        return;
    }

    int mid = (left + right) / 2;

    tree.insert(toInsert[mid]);

    insertFromMid(left, mid - 1);
    insertFromMid(mid + 1, right);
}

void insertInitials()
{
    for(auto child: initInsert)
    {
        tree.activateNode(child);
    }
}

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
    for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
        toInsert.push_back(x);
        initInsert.push_back(x);
	}

    for(int i=0; i<t; i++)
    {
        int x;
		char command;
		cin>>command>>x;
        if(command == 'I')
        toInsert.push_back(x);
        listOfQueries.push_back(query(command, x));
    }

    sort(toInsert.begin(), toInsert.end());

    insertFromMid(0, toInsert.size());

    insertInitials();
    runQueries();



    //
    // for(int child: toInsert)
    // {
    //     tree.insert(child);
    // }
    //
	// makeBST(n);
    //
	// runQueries(t);

	return 0;
}

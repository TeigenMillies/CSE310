#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

Node* create (int val) {
    Node *temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert (Node *root, int val) {
    if (root == NULL) {
        return create (val);
    }
    if (val < root->val) {
        root->left = insert (root->left, val);
    } else {
        root->right = insert (root->right, val);
    }
        return root;
    }
Node* deleteNode(Node* root, int k) {
    //base case
    if (root == NULL)
        return root;

    //finds ancesotrs of node to be deleted
    if (root->val > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->val < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    //root is now node to be deleted

    //has one child
    if (root->left == NULL) {
        Node* tempNode = root->right;
        delete root;
        return tempNode;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    //has two children
    else {
        Node* succParent = root;
 
        // Find successor
        Node* successor = root->right;
        while (successor->left != NULL) {
            succParent = successor;
            successor = successor->left;
        }
 
        
        if (succParent != root)
            succParent->left = successor->right;
        else
            succParent->right = successor->right;
 
        // Copy Successor Data to root
        root->val = successor->val;
 
        // Delete Successor and return root
        delete successor;
        return root;
    }

        
    

}

Node* search (Node *root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        search (root->left, val);
    } else {
        search (root->right, val);
    }
}

void inorder (Node *root) {
    if (root == NULL)
        return;
    inorder (root->left);
    cout << root->val << " ";
    inorder (root->right);
}

void preorder (Node *root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder (root->left);
    preorder (root->right);
}

void postorder (Node *root) {
    if (root == NULL)
        return;

    postorder (root->left);
    postorder (root->right);
    cout << root->val << " ";
}

void levelorder (Node *root, int curr, int level) {
    if (root == NULL)
        return;
    if (curr == level)
        cout << root->val << " ";

    levelorder (root->left, curr + 1, level);
    levelorder (root->right, curr + 1, level);
}

int main () {
    //initialize 
    Node *root = NULL;
    int key;

    //get commands
    int num_queries;
    cin >> num_queries;
    char commands [num_queries][20];
    char temp [20];
    int element [num_queries];
    int q = 0;
    for (int i = 0; i < num_queries; i++) {
        cin >> temp;
        if (strcmp(temp, "INSERT") == 0 || strcmp(temp, "DELETE") == 0 || strcmp(temp, "SEARCH") == 0) {
            cin >> element[q];
            q++;
        }
        strcpy(commands[i], temp);
           
    }
    
    //make two arrays
    //if command with key then get key and put in second array
    //keys are in the order the were input as well as commands

    q = 0;
    for (int i = 0; i < num_queries; i++) {
        //perform command
        if (strcmp(commands[i], "INSERT") == 0)
        {
            key = element[q];
            q++;

            root = insert(root, key);            
        }
        else if(strcmp(commands[i], "DELETE") == 0)
        {
            key = element[q];
            q++;
            
            root = deleteNode(root, key);
        }
        else if(strcmp(commands[i], "SEARCH") == 0) 
        {
            key = element[q];
            q++;
            
            if (search (root, key) == NULL) {
                cout << "False" << endl;
            } else {
                cout << "True" << endl;
            }
        }
        else if(strcmp(commands[i], "INORDER") == 0) 
        {
            if (root == NULL)
                cout << endl;
            else {
                inorder (root);
                cout << endl;
            }
        }
        else if(strcmp(commands[i], "PREORDER") == 0) 
        {
            if (root == NULL)
                cout << endl;
            else {
                preorder (root);
                cout << endl;
            }
        }
        else if(strcmp(commands[i], "POSTORDER") == 0) 
        {
            if (root == NULL)
                cout << endl;
            else {
                postorder (root);
                cout << endl;
            }
        }
        else if(strcmp(commands[i], "LEVELORDER") == 0) 
        {
            if (root == NULL)
                cout << endl;
            else {
                levelorder (root, 0, 0);
                cout << endl;
            }
        }
    }
    
    
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int item)
{
    Node* newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int item)
{
    if (root == nullptr)
        return createNode(item);

    if (item < root->data)
        root->left = insertNode(root->left, item);
    else if (item > root->data)
        root->right = insertNode(root->right, item);

    return root;
}

Node* findMinNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int item)
{
    if (root == nullptr)
        return root;

    if (item < root->data)
        root->left = deleteNode(root->left, item);
    else if (item > root->data)
        root->right = deleteNode(root->right, item);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* searchNode(Node* root, int item)
{
    if (root == nullptr || root->data == item)
        return root;

    if (item < root->data)
        return searchNode(root->left, item);

    return searchNode(root->right, item);
}

void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void printPreOrder(Node* root)
{
    if (root == NULL)
        return;
 
    // Visit Node
    cout << root->data << " ";
 
    // Traverse left subtree
    printPreOrder(root->left);
 
    // Traverse right subtree
    printPreOrder(root->right);
}
void printPostOrder(Node* root)
{
    if (root == NULL)
        return;
 
    // Traverse left subtree
    printPostOrder(root->left);
 
    // Traverse right subtree
    printPostOrder(root->right);
 
    // Visit node
    cout << root->data << " ";
}
int main()
{
    Node* root = nullptr;
    int choice, item;

    while (true) {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Search" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. preorder Traversal" << endl;
        cout << "6. postorder Traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> item;
            root = insertNode(root, item);
            break;
        case 2:
            cout << "Enter value to be deleted: ";
            cin >> item;
            root = deleteNode(root, item);
            break;
        case 3:
            cout << "Enter value to be searched: ";
            cin >> item;
            if (searchNode(root, item))
                cout << "Value found in the tree." << endl;
            else
                cout << "Value not found in the tree." << endl;
            break;
        case 4:
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Preorder Traversal: ";
            printPreOrder(root);
            cout << endl;
            break;
        case 6:
          cout << "Postorder Traversal: ";
            printPostOrder(root);
            cout << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}

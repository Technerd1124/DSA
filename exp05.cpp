#include <iostream>
#include <string>
using namespace std;

struct Node
{ int rollNo;   string name;
    Node *left; Node *right;
};
Node* createNode(int rollNo, string name)
{
    Node* newNode = new Node();
    newNode->rollNo = rollNo;   newNode->name = name;
    newNode->left = NULL;        newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int rollNo, string name)
{
if (root == NULL) return createNode(rollNo, name);
if (rollNo < root->rollNo)
        root->left = insert(root->left, rollNo, name);
else if (rollNo > root->rollNo)
        root->right = insert(root->right, rollNo, name);
else
        cout << "Roll number already exists!\n";
    return root;
}
// Search student by roll number
Node* search(Node* root, int rollNo)
{
 if (root == NULL || root->rollNo == rollNo) return root;
if (rollNo < root->rollNo)
        return search(root->left, rollNo);
    return search(root->right, rollNo);
}
// Display records using inorder traversal
void inorder(Node* root)
{
if (root == NULL) return;
inorder(root->left);
    cout << "Roll No: " << root->rollNo << "\tName: " << root->name << endl;
inorder(root->right);
}
int main()
{
Node* root = NULL;
    int choice, rollNo; string name;
 do
    { 
cout << "\n--- Student BST ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
switch (choice)
        {
case 1: cout << "Enter Roll Number: "; cin >> rollNo;
                cout << "Enter Student Name: "; cin.ignore();
                getline(cin, name);
                root = insert(root, rollNo, name);
                cout << "Student record inserted successfully.\n";
 break;
 case 2:{ cout << "Enter Roll Number to search: "; cin >> rollNo;
                Node* result = search(root, rollNo);
if (result != NULL)
                {
                    cout << "\nStudent Found!\n";
                    cout << "Roll No: " << result->rollNo << endl;
                    cout << "Name: " << result->name << endl;
                }
                else
                {
                    cout << "Student record not found.\n";
                }
break;
            }
case 3:cout << "\nStudent Records:\n";
                if (root == NULL)
                    cout << "Tree is empty.\n";
                else
                    inorder(root);
 break;
case 4: cout << "Exiting program...\n";
 break;
default:cout << "Invalid choice!\n";
        }
} while (choice != 4);
    return 0;
}
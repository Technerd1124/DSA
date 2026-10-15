#include <iostream> 
#include <string> 
using namespace std; 
  
// A tree node stores one student record 
struct Student { 
    int roll; 
    string name; 
    Student *left; 
    Student *right; 
}; 
  
Student *root = nullptr; 
  
// Function to create a new student node 
Student* createNode(int roll, const string &name) { 
    Student *newNode = new Student(); 
    newNode->roll = roll; 
    newNode->name = name; 
    newNode->left = nullptr; 
    newNode->right = nullptr; 
    return newNode; 
} 
  
// Function to insert a new student into the correct position in the BST 
Student* insert(Student *node, int roll, const string &name) { 
    if (node == nullptr) { 
        return createNode(roll, name); 
    } 
    if (roll < node->roll) { 
        node->left = insert(node->left, roll, name); 
    } else if (roll > node->roll) { 
        node->right = insert(node->right, roll, name); 
    } else { 
        cout << "Roll number already exists.\n"; 
    } 
    return node; 
} 
  
// Function to search for a student by roll number 
Student* search(Student *node, int roll) { 
    if (node == nullptr) { 
        return nullptr; 
    } 
    if (roll == node->roll) { 
        return node; 
    } else if (roll < node->roll) { 
        return search(node->left, roll); 
    } else { 
        return search(node->right, roll); 
    } 
} 
  
// Function to display all records in sorted order of roll number (inorder) 
void inorderDisplay(Student *node) { 
    if (node == nullptr) { 
        return; 
    } 
    inorderDisplay(node->left); 
    cout << "Roll No: " << node->roll << "\tName: " << node->name << "\n"; 
    inorderDisplay(node->right); 
} 
  
// Function to read a new student record from the user and insert it 
void addStudent() { 
    int roll; 
    string name; 
    cout << "Enter roll number: "; 
    cin >> roll; 
    cout << "Enter student name: "; 
    cin.ignore(); 
    getline(cin, name); 
    root = insert(root, roll, name); 
} 
  
// Function to search for a student and display the result 
void searchStudent() { 
    int roll; 
    cout << "Enter roll number to search: "; 
    cin >> roll; 
    Student *result = search(root, roll); 
    if (result != nullptr) { 
        cout << "Record found -> Roll No: " << result->roll << ", Name: " << result->name << "\n"; 
    } else { 
        cout << "Student record not found.\n"; 
    } 
} 
  
int main() { 
    int choice; 
    do { 
        cout << "\n----- STUDENT RECORD MENU (BST) -----\n"; 
        cout << "1. Add Student Record\n"; 
        cout << "2. Search Student by Roll Number\n"; 
        cout << "3. Display All Records (sorted by roll no.)\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
 
        cin >> choice; 
  
        switch (choice) { 
            case 1: addStudent(); break; 
            case 2: searchStudent(); break; 
            case 3: 
                if (root == nullptr) { 
                    cout << "No records available.\n"; 
                } else { 
                    inorderDisplay(root); 
                } 
                break; 
            case 4: cout << "Exiting...\n"; break; 
            default: cout << "Invalid choice. Please try again.\n"; 
        } 
    } while (choice != 4); 
  
    return 0; 
}
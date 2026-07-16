Design, Develop and Implement a menu driven Program in C++ for the following Array
operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements
c. Inserting an Element at a given valid Position
d. Deleting an Element at a given valid Position
e. Exit.

#include <iostream>

using namespace std;

// Maximum capacity constraint for the static array buffer
const int MAX_CAPACITY = 100;

// Function declarations to keep the architecture clean
void createArray(int arr[], int &n);
void displayArray(const int arr[], int n);
void insertElement(int arr[], int &n);
void deleteElement(int arr[], int &n);

int main() {
    int arr[MAX_CAPACITY];
    int n = 0; // Tracks the current active size of the array
    int choice;

    do {
        // Display Menu Structure
        cout << "\n================================" << endl;
        cout << "          ARRAY MENU            " << endl;
        cout << "================================" << endl;
        cout << "1. Create Array of N Elements" << endl;
        cout << "2. Display Array Elements" << endl;
        cout << "3. Insert an Element at Position" << endl;
        cout << "4. Delete an Element from Position" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                insertElement(arr, n);
                break;
            case 4:
                deleteElement(arr, n);
                break;
            case 5:
                cout << "\nExiting program. Goodbye!" << endl;
                break;
            default:
                cout << "\n[Error] Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

// a. Creating an Array of N Integer Elements
void createArray(int arr[], int &n) {
    cout << "\nEnter the number of elements (N): ";
    cin >> n;

    // Boundary check for allocated maximum buffer size
    if (n < 0 || n > MAX_CAPACITY) {
        cout << "[Error] Size must be between 0 and " << MAX_CAPACITY << "." << endl;
        n = 0; // Reset active tracking counter
        return;
    }

    cout << "Enter " << n << " integer elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout << "\n[Success] Array created successfully!" << endl;
}

// b. Display of Array Elements
void displayArray(const int arr[], int n) {
    if (n == 0) {
        cout << "\n[Warning] The array is empty. Nothing to display." << endl;
        return;
    }

    cout << "\n--- Current Array Elements ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n------------------------------" << endl;
}

// c. Inserting an Element at a given valid Position
void insertElement(int arr[], int &n) {
    // Check for memory overflow allocation constraints
    if (n >= MAX_CAPACITY) {
        cout << "\n[Error] Overflow! Array capacity is completely full." << endl;
        return;
    }

    int elem, pos;
    // Explaining positions as 0-indexed to match internal array indexing
    cout << "\nEnter the element to insert: ";
    cin >> elem;
    cout << "Enter the target index position (0 to " << n << "): ";
    cin >> pos;

    // Validate index boundaries
    if (pos < 0 || pos > n) {
        cout << "[Error] Invalid position! Index must be between 0 and " << n << "." << endl;
        return;
    }

    // Shift data blocks right to make space for target element
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Assign new value and bump the reference index tracker
    arr[pos] = elem;
    n++;
    cout << "\n[Success] Element inserted safely." << endl;
}

// d. Deleting an Element at a given valid Position
void deleteElement(int arr[], int &n) {
    // Check for structural underflow conditions
    if (n == 0) {
        cout << "\n[Error] Underflow! Array is empty. No elements to delete." << endl;
        return;
    }

    int pos;
    cout << "\nEnter the index position to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    // Validate active data array bounds
    if (pos < 0 || pos >= n) {
        cout << "[Error] Invalid position! Index must be between 0 and " << n - 1 << "." << endl;
        return;
    }

    int deletedValue = arr[pos];

    // Shift data elements left to fill the vacant index slot
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement programmatic boundaries
    n--;
    cout << "\n[Success] Deleted element '" << deletedValue << "' from index " << pos << "." << endl;
}

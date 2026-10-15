#include <iostream>
using namespace std;

const int SIZE = 10;

struct Student
{
    int rollNo;
    float marks;
    bool occupied;
};

Student hashTable[SIZE];

int hashFunction(int rollNo)
{
    return rollNo % SIZE;
}

void insertStudent(int rollNo, float marks)
{
    int index = hashFunction(rollNo);

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos].occupied == false)
        {
            hashTable[pos].rollNo = rollNo;
            hashTable[pos].marks = marks;
            hashTable[pos].occupied = true;

            cout << "Record inserted successfully.\n";
            return;
        }

        if (hashTable[pos].rollNo == rollNo)
        {
            cout << "Roll number already exists.\n";
            return;
        }
    }

    cout << "Hash table is full.\n";
}
void searchStudent(int rollNo)
{
    int index = hashFunction(rollNo);

    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos].occupied == false)
        {
            cout << "Record not found.\n";
            return;
        }
        if (hashTable[pos].rollNo == rollNo)
        {
            cout << "Roll Number: " << hashTable[pos].rollNo << endl;
            cout << "Marks: " << hashTable[pos].marks << endl;
            return;
        }
    }

    cout << "Record not found.\n";
}

void displayStudents()
{
    bool found = false;

    cout << "\nStudent Records:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i].occupied)
        {
            cout << "Roll Number: " << hashTable[i].rollNo
                 << ", Marks: " << hashTable[i].marks << endl;

            found = true;
        }
    }

    if (!found)
        cout << "No records available.\n";
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i].occupied = false;

    int choice, rollNo;
    float marks;

    do
    {
        cout << "\n1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter roll number: ";
                cin >> rollNo;

                cout << "Enter marks: ";
                cin >> marks;

                if (rollNo < 0 || marks < 0 || marks > 100)
                    cout << "Invalid input.\n";
                else
                    insertStudent(rollNo, marks);

                break;

            case 2:
                cout << "Enter roll number to search: ";
                cin >> rollNo;

                if (rollNo < 0)
                    cout << "Invalid roll number.\n";
                else
                    searchStudent(rollNo);

                break;

            case 3:
                displayStudents();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
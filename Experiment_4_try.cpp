#include <iostream>
#include <string>
#define MAX 10

using namespace std;

class BankQueue {
private:
    string queue[MAX];
    int front, rear;

public:
    BankQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add customer
    void enqueue(string customer) {
        if (isFull()) {
            cout << "\nQueue Overflow! Bank queue is full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = customer;

        cout << "Customer \"" << customer << "\" added to the queue.\n";
    }

    // Serve customer
    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow! No customers in the queue.\n";
            return;
        }

        cout << "Serving Customer: " << queue[front] << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }

        cout << "\nCustomers in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i] << endl;
        }
    }

    // Show front customer
    void frontCustomer() {
        if (isEmpty()) {
            cout << "\nNo customer in the queue.\n";
        } else {
            cout << "Customer at Front: " << queue[front] << endl;
        }
    }
};

int main() {
    BankQueue bank;
    int choice;
    string name;

    do {
        cout << "\n========== BANK QUEUE SYSTEM ==========\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. View Front Customer\n";
        cout << "5. Check Queue Status\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, name);
            bank.enqueue(name);
            break;

        case 2:
            bank.dequeue();
            break;

        case 3:
            bank.display();
            break;

        case 4:
            bank.frontCustomer();
            break;

        case 5:
            if (bank.isEmpty())
                cout << "Queue Status: EMPTY\n";
            else if (bank.isFull())
                cout << "Queue Status: FULL\n";
            else
                cout << "Queue Status: Customers Waiting\n";
            break;

        case 6:
            cout << "Exiting Bank Queue System...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

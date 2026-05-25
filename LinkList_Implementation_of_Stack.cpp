#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

Node* first = nullptr, *temp;

// Stack class using linked list

Node* push(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = first;
    return temp;
}

Node* pop() {
    if (first == nullptr) {
        cout << "Stack Underflow" << endl;
        return nullptr;
    }
    Node* temp = first;
    first = first->next;
    delete temp;
    return first;
}

void peek() {
    if (first == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top element is: " << first->data << endl;
}

void viewofStack() {
    temp = first;
    if (temp == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    char choice = '0';
    while (choice != '5') {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. View Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int item;
                cout << "Enter an integer to push: ";
                cin >> item;
                first = push(item);
                cout << item << " pushed to stack\n";
                break;
            }
            case '2': {
                if (first != nullptr) {
                    cout << first->data << " popped from stack\n";
                    first = pop();
                } else {
                    pop();
                }
                break;
            }
            case '3': {
                peek();
                break;
            }
            case '4': {
                viewofStack();
                break;
            }
            case '5':
                while (first != nullptr) {
                    cout << first->data << " popped from stack\n";
                    first = pop();
                }
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}   

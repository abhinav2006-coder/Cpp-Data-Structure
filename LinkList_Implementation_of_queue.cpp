#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *front = nullptr,*rear = nullptr;

void enqueue(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if (rear == nullptr) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue(){
    if (front == nullptr) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

void front_element(){
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Front element is: " << front->data << endl;
}

void rear_element(){
    if (rear == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Rear element is: " << rear->data << endl;
}

void viewofQueue(){
    Node *temp = front;
    if (temp == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int choice = 0;
    while (choice != 6) {
        cout << "\nChoose an operation:\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Front\n"
             << "4. Rear\n"
             << "5. View Queue\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                front_element();
                break;
            case 4  :
                rear_element();
                break;
            case 5:
                viewofQueue();
                break;
            case 6:
                while (front != nullptr) {
                    dequeue();
                }
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
#define NULL 0

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Node *first , *temp , *ttemp;

void first_node(){
    first = new Node;
    cout << "Enter data: ";
    cin >> first->data;
    first->next = NULL;
    first->prev = NULL;
}

void add_node(){
    temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    ttemp = new Node;
    cout << "Enter data: ";
    cin >> ttemp->data;
    ttemp->next = NULL;
    ttemp->prev = temp;
    temp->next = ttemp;
}

void add_before_node(int n){
    temp = first;
    while (temp->data != n) {
        ttemp = temp;
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp;
    new_node->prev = ttemp;
    ttemp->next = new_node;
    temp->prev = new_node;
}

void add_after_node(int n){
    temp = first;
    while (temp->data != n) {
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void add_nth_node(int pos) {
    temp = first;
    for (int i = 0; i < pos ; i++) {
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev = new_node;
    new_node->prev->next = new_node;
}

void delete_linked_list() {
    temp = first;
    while (temp != NULL) {
        ttemp = temp->next;
        delete temp;
        temp = ttemp;
    }
    first = NULL;
}

void delete_first_node(){
    temp = first;
    first = first->next;
    temp->next = NULL;
    delete temp;
}

void delete_last_node(){
    temp = first;
    while (temp->next != NULL) {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = NULL;
    delete temp;
}

void delete_before_node(int n){
    temp = first;
    while (temp->next->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    if (ttemp->next != NULL) {
        ttemp->next->prev = temp;
    }
    delete ttemp;
}

void delete_after_node(int n){
    temp = first;
    while (temp->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    if (ttemp->next != NULL) {
        ttemp->next->prev = temp;
    }
    delete ttemp;
}

void delete_nth_node(int n){
    temp = first;
    for (int i = 0; i < n ; i++) {
        temp = temp->next;
    }
    ttemp = temp->next;
    ttemp->prev = temp->prev;
    temp->prev->next = ttemp;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void display(){
    temp = first;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int n=0;
    while(n != -1) {
        cout << "1. Create doubly linked list\n"
                << "2. Add node in the linked list\n"
                << "3. Add node before a given node\n"
                << "4. Add node after a given node\n"
                << "5. Add node at a given position\n"
                << "6. Delete first node\n"
                << "7. Delete last node\n"
                << "8. Delete node before a given node\n"
                << "9. Delete node after a given node\n"
                << "10. Delete node at a given position\n"
                << "11. Display list\n"
                << "-1. Exit\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch(n) {
            case 1:
                first_node();
                break;
            case 2:
                add_node();
                break;
            case 3: {
                int val;
                cout << "Enter the value of the node to add before: ";
                cin >> val;
                add_before_node(val);
                break;
            }
            case 4: {
                int val;
                cout << "Enter the value of the node to add after: ";
                cin >> val;
                add_after_node(val);
                break;
            }
            case 5: {
                int pos;
                cout << "Enter the position to add the node at: ";
                cin >> pos;
                add_nth_node(pos);
                break;
            }
            case 6:
                delete_first_node();
                break;
            case 7:
                delete_last_node();
                break;
            case 8: {
                int val;
                cout << "Enter the value of the node to delete before: ";
                cin >> val;
                delete_before_node(val);
                break;
            }
            case 9: {
                int val;
                cout << "Enter the value of the node to delete after: ";
                cin >> val;
                delete_after_node(val);
                break;
            }
            case 10: {
                int pos;
                cout << "Enter the position of the node to delete: ";
                cin >> pos;
                delete_nth_node(pos);
                break;
            }
            case 11:
                display();
                break;
        }
    }
    cout << "Exiting program. Deleting linked list." << endl;
    cout << "Thank you!" << endl;
    delete_linked_list();
    return 0;
}
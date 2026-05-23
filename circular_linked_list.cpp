#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Node *first , *temp , *ttemp;

void create_node(){
    first = new Node;
    cout << "Enter data: ";
    cin >> first->data;
    first->next = first;
}

void add_node(){
    temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }
    ttemp = new Node;
    cout << "Enter data: ";
    cin >> ttemp->data;
    ttemp->next = first;
    temp->next = ttemp;
}

void add_after_node(int n){
    temp = first;
    while (temp->data != n) {
        ttemp = temp;
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp;
    ttemp->next = new_node;
}

void add_before_node(int n){
    temp = first;
    while (temp->next->data != n) {
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void add_nth_node(int pos) {
    temp = first;
    for (int i = 0; i < pos ; i++) {
        ttemp = temp;
        temp = temp->next;
    }
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp;
    ttemp->next = new_node;
}

void delete_first_node(){
    temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }
    ttemp = first;
    first = first->next;
    temp->next = first;
    ttemp->next = NULL;
    delete ttemp;
}

void delete_last_node(){
    temp = first;
    while (temp->next->next != first) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = first;
    ttemp->next = NULL;
    delete ttemp;
}

void delete_before_node(int n){
    temp = first;
    while (temp->next->next->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next = NULL;
    delete ttemp;
}

void delete_after_node(int n){
    temp = first;
    while (temp->data != n) {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void delete_nth_node(int pos){
    temp = first;
    for (int i = 0; i < pos ; i++) {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void delete_linked_list() {
    temp = first;
    do {
        ttemp = temp->next;
        delete temp;
        temp = ttemp;
    } while (temp != first);
    first = NULL;
}

void display(){
    temp = first;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != first);
}

int main() {
    int n=0;
    while(n != -1) {
        cout << "1. Create circular linked list\n"
                << "2. Add node in the circular linked list\n"
                << "3. Add node before a given node\n"
                << "4. Add node after a given node\n"
                << "5. Add node at a given position\n"
                << "6. Delete first node\n"
                << "7. Delete last node\n"
                << "8. Delete node at a given position\n"
                << "9. Delete node before a given node\n"
                << "10. Delete node after a given node\n"
                << "11. Display circular linked list\n"
                << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch(n) {
            case 1:
                create_node();
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
                int pos;
                cout << "Enter the position of the node to delete: ";
                cin >> pos;
                delete_nth_node(pos);
                break;
            }
            case 9: {
                int val;
                cout << "Enter the value of the node to delete before: ";
                cin >> val;
                delete_before_node(val);
                break;
            }
            case 10: {
                int val;
                cout << "Enter the value of the node to delete after: ";
                cin >> val;
                delete_after_node(val);
                break;
            }
            case 11: {
                display();
                break;
            }
            case 12: {
                delete_linked_list();
                cout << "Exiting..." << endl;
                cout << "Thank you!" << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
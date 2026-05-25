#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Node *first , *temp , *ttemp;

void create_node(){
    first = new Node;
    cout << "Enter data: ";
    cin >> first->data;
    first->next = first;
    first->prev = first;
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
    ttemp->prev = temp;
    temp->next = ttemp;
    first->prev = ttemp;
}

void add_before_node(int n){
    temp = first;
    while (temp->data != n) {
        temp = temp->next;
    }
    ttemp = temp->prev;
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = temp;
    new_node->prev = ttemp;
    temp->prev = new_node;
    ttemp->next = new_node;
}

void add_after_node(int n){
    temp = first;
    while (temp->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = ttemp;
    new_node->prev = temp;
    temp->next = new_node;
    ttemp->prev = new_node;
}

void add_nth_position(int n){
    temp = first;
    for (int i = 1; i < n-1; i++) {
        temp = temp->next;
    }
    ttemp = temp->next;
    Node *new_node = new Node;
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = ttemp;
    new_node->prev = temp;
    temp->next = new_node;
    ttemp->prev = new_node;
}

void delete_first_node(){
    temp = first;
    ttemp = first->prev;
    ttemp->next = first->next;
    first->next->prev = ttemp;
    first = first->next;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void delete_last_node(){
    temp = first;
    while (temp->next != first) {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = first;
    first->prev = ttemp;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void delete_before_node(int n){
    temp = first;
    while (temp->next->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = NULL;
    ttemp->prev = NULL;
    delete ttemp;
}

void delete_after_node(int n){
    temp = first;
    while (temp->data != n) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = NULL;
    ttemp->prev = NULL;
    delete ttemp;
}

void delete_nth_position(int n){
    temp = first;
    for (int i = 1; i < n-1; i++) {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = NULL;
    ttemp->prev = NULL;
    delete ttemp;
}

void delete_Linked_list(){
    temp = first;
    while (temp->next != first) {
        ttemp = temp->next;
        delete temp;
        temp = ttemp;
    }
    delete temp;
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
        cout << "1. Create Node" << endl;
        cout << "2. Add Node at the end" << endl;
        cout << "3. Add Node before a node" << endl;
        cout << "4. Add Node after a node" << endl;
        cout << "5. Add Node at nth position" << endl;
        cout << "6. Delete first node" << endl;
        cout << "7. Delete last node" << endl;
        cout << "8. Delete node before a node" << endl;
        cout << "9. Delete node after a node" << endl;
        cout << "10. Delete node at nth position" << endl;
        cout << "11. Display linked list" << endl;
        cout << "-1. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch(n) {
            case 1:
                create_node();
                break;
            case 2:
                add_node();
                break;
            case 3:
                int data;
                cout << "Enter data of the node before which you want to insert: ";
                cin >> data;
                add_before_node(data);
                break;
            case 4:
                cout << "Enter data of the node after which you want to insert: ";
                cin >> data;
                add_after_node(data);
                break;
            case 5:
                cout << "Enter position: ";
                cin >> data;
                add_nth_position(data);
                break;
            case 6:
                delete_first_node();
                break;
            case 7:
                delete_last_node();
                break;
            case 8:
                cout << "Enter data of the node before which you want to delete: ";
                cin >> data;
                delete_before_node(data);
                break;
            case 9:
                cout << "Enter data of the node after which you want to delete: ";
                cin >> data;
                delete_after_node(data);
                break;
            case 10:
                cout << "Enter position: ";
                cin >> data;
                delete_nth_position(data);
                break;
            case 11:
                display();
                break;
            case -1:
                delete_Linked_list();
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

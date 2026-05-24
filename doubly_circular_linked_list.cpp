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
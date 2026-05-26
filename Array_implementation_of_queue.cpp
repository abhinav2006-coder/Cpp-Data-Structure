#include <iostream>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
};

Queue* CreateQueue(int size) {
    Queue* q = new Queue;
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->queue = new int[q->capacity];
    return q;
}

bool isFull(Queue* q) {
    return q->rear == q->capacity - 1;
}

bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

void Enqueue(Queue* q, int value) {
    if (isFull(q)) {
        cout << "Queue is full\n";
        return;
    }
    q->queue[++q->rear] = value;
    cout << value << " enqueued to queue\n";
}

int Front(Queue* q) {
    if (isEmpty(q))
        return -1;
    return q->queue[q->front];
}

int Rear(Queue* q){
    if (isEmpty(q))
        return -1;
    return q->queue[q->rear];
}

int Dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->queue[q->front++];
}

void viewofQueue(Queue* q) {
    if (isEmpty(q)) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = q->front; i <= q->rear; i++) {
        cout << q->queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int NumberOfElement, choice = 0;
    cout << "Enter number of element: ";
    cin >> NumberOfElement;

    Queue* queue = CreateQueue(NumberOfElement);

    while(choice != 6){
        cout << "\nChoose an operation" << endl
             << "1. Enqueue" << endl
             << "2. Dequeue" << endl
             << "3. Front" << endl
             << "4. Rear" << endl
             << "5. View Queue" << endl
             << "6. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int item;
                cout << "Enter an integer to enqueue: ";
                cin >> item;
                Enqueue(queue, item);
                break;
            }
            case 2: {
                int poppedElement = Dequeue(queue);
                if (poppedElement != -1)
                    cout << poppedElement << " dequeued from queue\n";
                else
                    cout << "queue is empty. Cannot dequeue.\n";
                break;
            }
            case 3: {
                int frontElement = Front(queue);
                if (frontElement != -1)
                    cout << "Front element is: " << frontElement << endl;
                else
                    cout << "Queue is empty.\n";
                break;
            }
            case 4: {
                int RearElement = Rear(queue);
                if (RearElement != -1)
                    cout << "Rear element is: " << RearElement << endl;
                else
                    cout << "Queue is empty.\n";
                break;
            }
            case 5: {
                viewofQueue(queue);
                break;
            }
            case 6:
                cout << "Exiting...\n";
                while (isEmpty(queue) == 0){
                    Dequeue(queue);
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
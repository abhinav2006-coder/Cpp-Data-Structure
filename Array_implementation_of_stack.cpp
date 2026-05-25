#include <iostream>
using namespace std;


struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

Stack* createStack(unsigned capacity){
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[(stack->capacity * sizeof(int))];
    return stack;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item){
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    cout << item << " pushed to stack\n";
}

int pop(Stack* stack){
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void viewofStack(Stack* stack){
    if (isEmpty(stack)){
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= stack->top; i++){
        cout << stack->array[i] << " ";
    }
    cout << endl;
}

int main(){

    int numberOfElements;
    char choice = '0';
    cout << "Enter size of stack: ";
    cin >> numberOfElements;

    Stack* stack = createStack(numberOfElements);

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
                push(stack, item);
                break;
            }
            case '2': {
                int poppedElement = pop(stack);
                if (poppedElement != -1)
                    cout << poppedElement << " popped from stack\n";
                else
                    cout << "Stack is empty. Cannot pop.\n";
                break;
            }
            case '3': {
                int topElement = peek(stack);
                if (topElement != -1)
                    cout << "Top element is: " << topElement << "\n";
                else
                    cout << "Stack is empty.\n";
                break;
            }
            case '4': {
                viewofStack(stack);
                break;
            }
            case '5':
                cout << "Exiting...\n";
                while (isEmpty(stack) == 0){
                    pop(stack);
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
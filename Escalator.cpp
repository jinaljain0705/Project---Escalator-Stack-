#include <iostream>
using namespace std;

const int SIZE = 5; 

class StackBase {
public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual void display() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~StackBase() {}
};

class EscalatorStack : public StackBase {
private:
    int stack[SIZE];
    int top;

public:
    EscalatorStack() {
        top = -1;
    }

    void push(int val) override {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << val << "." << endl;
        } else {
            stack[++top] = val;
            cout << val << " pushed onto the escalator." << endl;
        }
    }

    void pop() override {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            cout << stack[top--] << " popped from the escalator." << endl;
        }
    }

    void display() override {
        if (isEmpty()) {
            cout << "Escalator is empty." << endl;
        } else {
            cout << "Elements on escalator: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty() override {
        return top == -1;
    }

    bool isFull() override {
        return top == SIZE - 1;
    }
};

int main() {
    StackBase* stack = new EscalatorStack(); 
    int choice, value;

    do {
        cout << "=== Escalator Menu ===" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: " << endl;
                cin >> value;
                stack->push(value);
                break;
            case 2:
                stack->pop();
                break;
            case 3:
                stack->display();
                break;
            case 4:
                cout << (stack->isEmpty() ? "Yes, it's empty." : "No, it's not empty.") << endl;
                break;
            case 5:
                cout << (stack->isFull() ? "Yes, it's full." : "No, it's not full.") << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    delete stack; 
    return 0;
}


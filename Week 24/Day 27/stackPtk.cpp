#include <iostream>
using namespace std;

#define MAX_SIZE 100

class TextEdit {
    char stack[MAX_SIZE];
    int top;
public:
    TextEdit() {
        top = -1;
    }
    
    void push(char ch) {
        stack[++top] = ch;
        cout << "Typed character: " << ch << endl;
    }
    
    void pop() {
        if(top == -1) {
            cout << "Text editor buffer is empty. Nothing to undo.\n";
            return;
        }
        cout << "Undo: Removed character " << stack[top--] << endl;
    }
    
    void display() {
        if(top == -1) {
            cout << "Text editor buffer is empty.\n";
            return;
        }
        
        cout << "Current text: ";
        for(int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
     }
};

int main() {
    TextEdit stack;
    int input;
    char c; //for taking the input
    
    while(true) {
        cin >> input;
        
        switch(input) {
        case 1:
            cin >> c;
            stack.push(c);
            break;
            
        case 2:
            stack.pop();
            break;
            
        case 3:
            stack.display();
            break;
            
        case 4:
            return 0;
        
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
    return 0;
}
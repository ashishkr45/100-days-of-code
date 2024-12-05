#include <iostream>
using namespace std;

#define MAX_SIZE 5

class queue {
    int front;
    int rear;
    int q[MAX_SIZE];
public:
    queue() {
        front = rear = -1;
    }
    
    void enqueue(int data) {
        if(rear == MAX_SIZE - 1) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        
        if(front == -1) front = 0;
        q[++rear] = data;
        cout << "Helpdesk Ticket ID " << data << " is enqueued.\n";
        return;
    }
    
    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        
        cout << "Dequeued Helpdesk Ticket ID: " << q[front++] << endl;
        if(front > rear) front = rear = -1;
    }
    
    void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Helpdesk Ticket IDs in the queue are: ";
    for (int i = front; i <= rear; i++) {
        cout << q[i];
        if (i < rear) cout << " "; // Add space only between IDs
    }
    cout << endl;
}

};


int main() {
    queue q;
    int choice, id;
    
    while(true) {
        cin >> choice;
        
        switch(choice) {
            case 1:
                cin >> id;
                q.enqueue(id);
                break;
            
            case 2:
                q.dequeue();
                break;
                
            case 3:
                q.display();
                break;
                
            case 4:
                cout << "Exiting the program\n";
                return 0;
            
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}
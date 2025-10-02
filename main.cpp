#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void createList(Node *&);
void deleteNode(Node *&);
void insertNode(Node *&);

int main() {
    Node *head = nullptr;
    int count = 0;

    createList(head);

    output(head);

    deleteNode(head);

    output(head);

    insertNode(head);

    /*
    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
    */

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void createList(Node * &hd){
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = hd;
            newVal->value = tmp_val;
            hd = newVal;
        }
    }

}

void deleteNode(Node *&hd){
    // deleting a node
    cout << "Which node to delete? " << endl;
    output(hd);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    Node * current = hd;

    // traverse that many times and delete that node
    current = hd;
    Node *prev = hd;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

}

void insertNode(Node *&hd){
    Node * current = hd;
    int count;
    // insert a node
    current = hd;
    Node *prev = hd;
    cout << "After which node to insert 10000? " << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = hd;
    prev = hd;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(hd);

}
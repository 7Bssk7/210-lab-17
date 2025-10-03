// COMSC 210 | Lab 17 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
void createList(Node *&);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;

    createList(head); // This function call creates a linked list of SIZE nodes with a random values in it

    output(head); // This function call outputs a linked list

    deleteNode(head); // This function call deletes a node at the position number entered by the user

    output(head); // This function call outputs a linked list

    insertNode(head); // This function call inserts a new node with value 10000 at the position number entered by the user 

    output(head); // This function call outputs a linked list

    deleteList(head); // This function call deletes all nodes in the linked list and frees memory 

    output(head); // This function call confirms list is empty 

    return 0;
}

// output() - outputs the contents of the linked list
// argument: hd - pointer to the head of the linked list
// return: returns nothing(void function)
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

// createList() creates a linked list of SIZE nodes with a random values in it
// argument: hd - reference to the head pointer of the linked list 
// return: returns nothing(void function) 
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

// deleteNode() deletes a node at the position number entered by the user 
// argument: hd - reference to the head pointer of the linked list
// return: returns nothing(void function)
void deleteNode(Node *&hd){
    // deleting a node
    cout << "Which node to delete? " << endl;
    output(hd);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    while((entry > SIZE  )  || (entry < 1)){
        cout << "Invalid input, please enter your choice again(1-7) --> ";
        cin >> entry;
    }

    Node * current = hd;

    // traverse that many times and delete that node
    current = hd;
    Node *prev = hd;
    if(entry == 1){
        hd = current -> next;
        delete current;
        current = nullptr;
    }
    else{
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

}

// insertNode() inserts a new node with value 10000 at the position number entered by the user 
// arguments: hd - reference to the head pointer of the linked list
// return: returns nothing(void function)
void insertNode(Node *&hd){
    Node * current = hd;
    // insert a node
    current = hd;
    Node *prev = hd;
    cout << "After which node to insert 10000? " << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    while((entry > SIZE -1 )  || (entry < 1)){
        cout << "Invalid input, please enter your choice again(1-6) --> ";
        cin >> entry;
    }

    output(hd);

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

}

// deleteList() deletes all nodes in the linked list and frees memory 
// argument: hd - reference to the head pointer of the linked list
// return: returns nothing(void function)
void deleteList(Node *& hd){
    // deleting the linked list
    Node * current = hd;
    current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}
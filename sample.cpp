#include <iostream>
#include <string>

using namespace std;

typedef int (*funcPt) (int, int);

typedef struct node {
    int val;
    struct node *next;
} node_t;

// linked list operation
void appendNode(node_t** head, node_t* newNode) {
    node_t* tmp;
    
    if (*head == NULL) {
        cout << "\t" << "head " << head << " " << *head << endl;
        cout << "\t" << "newNode " << newNode << endl;
        head = (node_t **) newNode;
        // cout << "\t" << "head " << head << " newNode " << newNode << endl;
    } else {
        /* tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode; */
    }
}

void printNodes(node_t* head) {
    node_t *tmp;

    tmp = head;
    while(tmp != NULL) {
        cout << "\t" << "node val is " << tmp->val << endl;
        tmp = tmp->next;
    }
}

// function pointers
int addition(int val1, int val2) {
    return val1 + val2;
}

int subtraction(int val1, int val2) {
    return val1 - val2;
}

int mathOperation(int val1, int val2, funcPt op) {
    return op(val1, val2);
}

void funcPter() {
    // playing with function pointer
    cout << "start of function pointer" << endl;
    cout << "\t" << "the value is " << mathOperation(1, 1, addition) << endl;
    cout << "\t" << "the value is " << mathOperation(1, 1, subtraction) << endl;
    funcPt minus = subtraction;
    cout << "\t" << "the value is " << mathOperation(1, 1, minus) << endl;
    cout << "end of function pointer" << endl << endl;
}

// pointer manipulation
void pterManip() {
    char *charVal = new char();
    int *val = new int();

    // playing with memory
    cout << "start of pterManip" << endl;
    // val = 0x41424344
    *val = 1094861636;
    cout << "\t" << "val is " << *val << " address is " << val << endl;
    cout << "\t" << "size of val " << sizeof(*val) << " size of charVal " << sizeof(*charVal) << endl;
    // intel is big endian encoding, less significant becomes most significant
    charVal = (char *) val + sizeof(*val) - 1;
    cout << "\t" << "address of val " << val << " address of charVal " << (void *) charVal << endl;
    cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    cout << "\t" << "address of val " << val << " address of charVal " << (void *) charVal << endl;
    cout << "end of pterManip" << endl << endl;
}

int main(int argc, char *argv[]) {
    // pterManip();
    // funcPter();

    node_t* head;
    node_t* tmp = (node_t *) malloc(sizeof(node_t));
    tmp->val = 5;
    tmp->next = NULL;
    cout << "head " << head << " " << &head << " tmp " << tmp << endl;
    appendNode(&head, tmp);
    // cout << "head " << head << " tmp " << tmp << endl;
    // head = tmp;
    printNodes(head);
    
    return 0;
}
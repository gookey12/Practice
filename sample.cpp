#include <iostream>
#include <string>

using namespace std;

typedef int (*funcPt) (int, int);

typedef struct node {
    int val;
    struct node *next;
} node_t;

// linked list operation
node_t* createNode(int val) {
    node_t* tmp = NULL;
    tmp = (node_t *) malloc(sizeof(node_t));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

void appendNode(node_t** head, node_t* newNode) {
    node_t* tmp;

    tmp = *head;

    if (tmp == NULL) {
        *head = newNode;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

void insertNode(node_t** head, int offset, node_t* newNode) {
    node_t *prev, *curr;
    prev = NULL;
    curr = *head;

    while (--offset > 0 && curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    if (offset == 0 && curr != NULL) {
        if (prev == NULL) {
            *head = newNode;
        } else {
            prev->next = newNode;
        }
        newNode->next = curr;
    }
}

void rmNode(node_t** head, int offset) {
    node_t *prev, *curr;
    prev = NULL;
    curr = *head;

    while (--offset > 0 && curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    if (offset == 0 && curr != NULL) {
        if (prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        curr = NULL;
    }
}

void rmAllNodes(node_t** head) {
    node_t *tmp;

    if (*head != NULL){
        while ((*head)->next != NULL) {
            tmp = *head;
            *head = (*head)->next;
            free(tmp);
            tmp = NULL;
        }
        free(*head);
        *head = NULL;
    }
}

void printNodes(node_t* head) {
    node_t *tmp;

    tmp = head;

    if (tmp == NULL) {
        cout << "\t" << "the linked list is empty" << endl;
    } else {
        cout << "\t" << "the linked list is " << tmp->val;
        tmp = tmp->next;
        while (tmp != NULL) {
            cout << "->" << tmp->val;
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void nodeManip() {
    node_t* head = NULL;
    node_t* tmp = createNode(5);
    
    appendNode(&head, tmp);
    tmp = createNode(10);
    appendNode(&head, tmp);
    tmp = createNode(15);
    appendNode(&head, tmp);

    printNodes(head);

    tmp = createNode(7);
    insertNode(&head, 2, tmp);
    printNodes(head);

    rmNode(&head, 2);
    printNodes(head);

    rmAllNodes(&head);
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
    nodeManip();
    
    
    return 0;
}
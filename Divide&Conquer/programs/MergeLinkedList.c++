#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to append node at end
void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// Merge two sorted linked lists
Node* mergeLists(Node* l1, Node* l2) {
    Node dummy(0); // dummy head
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    // attach remaining
    tail->next = (l1 ? l1 : l2);
    return dummy.next;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    Node* list1 = NULL;
    Node* list2 = NULL;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        append(list1, x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        append(list2, x);
    }

    Node* merged = mergeLists(list1, list2);
    printList(merged);

    return 0;
}

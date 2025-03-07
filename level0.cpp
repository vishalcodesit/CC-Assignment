#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

  
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};


class DoublyLinkedList {
private:
    Node* head;

public:
   
    DoublyLinkedList() {
        head = NULL;
    }

   
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

   
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

   
    void traverseForward() {
        Node* temp = head;
        cout << "Forward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

  
    void traverseBackward() {
        if (head == NULL) return;

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Backward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    dll.traverseForward();
    dll.traverseBackward();

    return 0;
}

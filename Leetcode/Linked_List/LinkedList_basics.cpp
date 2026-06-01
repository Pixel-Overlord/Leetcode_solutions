/*
 * In this program we gonna see how to declare linked list.
 * 
 * Insertion : 
 * 
 * push_back in linked list.
 * push_front in linked list.
 * 
 * Deletion :
 * 
 * pop_back in linked list.
 * pop_front in linked list. 
 * 
 */

 #include <iostream>
 using namespace std;

 class Node {
 public :
    int data;   // data in this node.
    Node* next; // stores address to another memeber.

    // create a constructor so that to assign new values to data.
    Node(int val) {
        data = val;
        next = NULL;
    }
 };

 class List {
    Node* head;
    Node* tail;
    
 public :
    List() {
        head = NULL;
        tail = NULL;
    }
    
    void push_front (int val){
        Node* newNode = new Node(val);
        
        // since it is adding in front.
        if (head == NULL) {
            head = newNode; // head points to newNode's memory address. newNode contains memory because it has been created using 'new' keyword.
            tail = newNode; // same goes for tail.
            return;
        }
        else {
            newNode -> next = head; // to create a connection of newNode to existing linked list.
            head = newNode; //now update head to newNode so that the new element get add to starting of linked list
            
            return;
        }
    }

    void push_back (int val){
        Node* newNode = new Node(val);
        
        // since it is adding in front.
        if (head == NULL) {
            head = newNode; // head points to newNode's memory address. newNode contains memory because it has been created using 'new' keyword.
            tail = newNode; // same goes for tail.
            return;
        }
        else {
            // traverse till the last.
            Node* temp = head;
            
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
            tail = newNode;
           
            return;
        }
    }

    void printLL(){
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
 };

 int main() {
    List li;

    li. push_back(1);
    li. push_back(2);
    li. push_back(3);

    li.printLL();
 }
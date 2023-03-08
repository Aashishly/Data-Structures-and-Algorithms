#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Contructor
    Node(){
        this -> prev = NULL;
        this -> next = NULL;
    }
};

Node* head = NULL, *tail, *temp, *node;

void CreateList(int d){

    temp = new Node();

    temp -> data = d;
    temp -> next = NULL;
    
    if(head == NULL){
        temp -> prev = NULL;
        head = temp;
        tail = temp;
    }
    else{

        temp -> prev = tail; 
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtHead(int d){
    temp = new Node();

    temp -> data = d;
    temp -> prev = NULL;
    temp -> next = head;
    head = temp;
}

void insertAtTail(int d){

    temp = new Node();

    temp -> data = d;
    temp -> next = NULL;
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(int position, int d){

    if(position == 1){
        insertAtHead(d);
        return;
    }

    temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(d);
        return;
    }

    Node* previous = temp;
    temp = temp -> next;

    Node* curr = new Node();
    curr -> data = d;

    curr -> next = previous -> next;
    temp -> prev = curr;

    previous -> next = curr;
    curr -> prev = previous;

}

void DeleteNode(int position){

    temp = head;
    int cnt = 1;

    if(position == 1){

        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;

    }

    Node* curr = NULL;
    while(cnt < position){
        curr = temp;
        temp = temp -> next;
        cnt++;
    }

    curr -> next = temp -> next;
    temp -> prev = NULL;
    temp -> next = NULL;
    delete temp;
}

void DisplayList(){
    temp = head;

    while(temp != NULL){
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main(){

    CreateList(10);
    CreateList(30);
    CreateList(50);
    CreateList(80);
    DisplayList();

    // insertAtPosition(5, 20);
    // DisplayList();

    DeleteNode(2);


    // insertAtHead(100);
    DisplayList();

    // insertAtTail(200);
    // DisplayList();


    return 0;
}
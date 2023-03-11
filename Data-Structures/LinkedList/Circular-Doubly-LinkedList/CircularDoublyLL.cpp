#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

int size = 0;
Node* head = NULL, *tail = NULL, *temp;

void CreateNode(int d){

    Node* newNode = new Node(d);

    if(head == NULL){
        newNode -> next = newNode -> prev;
        newNode -> prev = newNode -> next;
        head = newNode;
        tail = newNode;

        size++;

        return;
    }


    newNode -> prev = tail;
    tail -> next = newNode;
    newNode -> next = head;
    tail = newNode;

    size++;
}

void InsertAtHead(int d){

    if(head == NULL){
        CreateNode(d);
        return;
    }

    Node* newNode = new Node(d);
    newNode -> next = head;
    head -> prev = newNode;

    newNode -> prev = tail;
    tail -> next = newNode;

    head = newNode;

    size++;

}

void InsertAtLast(int d){

    CreateNode(d);
    return;

}

void InsertAtPosition(int pos, int d){

    if(size == -1){
        cout << "NO node to Insert" << endl;
    }
    else if(pos == 1){
        InsertAtHead(d);
        return;
    }
    else if(pos >= size){
        InsertAtLast(d);
        return;
    }

    Node* backward = head;
    Node* forward;

    Node* newNode = new Node(d);

    for(int i=0; i< pos - 2; i++){
        backward = backward -> next;
    }

    forward = backward -> next;

    newNode -> next = forward;
    forward -> prev = newNode;
    backward -> next = newNode;
    newNode -> prev = backward;

    size++;
}

void DeleteAtHead(){

    if(size == -1){
        cout << "No Node to delete" << endl;
        return;
    }

    temp = head;
    head = head -> next;
    temp -> next = NULL;
    temp -> prev = NULL;

    delete temp;

    size--;


}

void DeleteAtLast(){

    if(size == -1){
        cout << "No Node to delete" << endl;
        return;
    }

    temp = tail;
    tail = tail -> prev;
    tail -> next = head;

    temp -> prev = NULL;
    temp -> next = NULL;


    delete temp;

    size--;

}

void DeleteAtPosition(int pos){

    if(size == -1){
        cout << "No Node to delete" << endl;
        return;
    }
    else if(pos == 1){
        DeleteAtHead();
        return;
    }else if(pos == size){
        DeleteAtLast();
        return;
    }

    Node* temp = head;

    int cnt = 1; 

    while(cnt < pos-1){

        temp = temp -> next;
        cnt++;
    }

    Node* backward = temp;
    temp = temp -> next;
    Node* forward = temp -> next;

    backward -> next = forward;
    forward -> prev = backward;
    temp -> next = NULL;
    temp -> prev = NULL;

    delete temp;

    size--;

}

void DisplayNode(){

    temp = head;

    while(temp != tail){

        cout << temp -> data << " --> ";
        temp = temp -> next;
    }

    cout << temp -> data << endl;
}

int main(){

   
    CreateNode(23);
    CreateNode(26);
    InsertAtHead(20);
    InsertAtLast(34);
    InsertAtPosition(2, 42);

    DisplayNode();

    cout << size << endl;

    DeleteAtHead();
    DeleteAtLast();
    DisplayNode();

    DeleteAtPosition(4);
    

    DisplayNode();

    cout << size << endl;



    return 0;
}
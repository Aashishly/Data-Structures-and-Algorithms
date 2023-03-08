#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

};

Node *head = NULL, *tail, *temp;
string fl;

bool IsEmpty(){
    if(head == NULL)
    return true;

    return false;
}

int CountNodes(){
    int n = 0;
    temp = head;

    while(temp != NULL){
        n++;
        temp = temp -> next;
    }
    return n;
}

int SearchNode(int n){

    int c = 1, flag = 0;
    temp = head;

    while(temp != NULL){
        if(temp -> data == n){
            flag = 1;
            break;
        }
        temp = temp -> next;
        c++;
    }

    if(flag == 1)
    return c;

    return flag;
}

void CreateList(int d){
    temp = new Node();
    temp -> data = d;
    temp -> next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtHead(int d){
    temp = new Node();
    temp -> data = d;
    temp -> next = head;
    head = temp;
}

void insertAtTail(int d){
    temp = new Node();
    temp -> data = d;
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;  

}

void insertAtPosition(int position, int d){

    if(position == 1){
        insertAtHead(d);
        return;
    }

    temp = head;
    int cnt = 1;

    
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(d);
        return;
    }

    Node* nodeToInsert = new Node();
    nodeToInsert -> data = d;
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void DeleteNode(int position){

    if(position == 1){
        temp = head;
        head = head -> next;
        delete temp;
    }
    else{

        Node* current = head;
        int cnt = 1;

        while(cnt < position-1){

            current = current -> next;
            cnt++;
        }

        Node* previous = current;
        current = current -> next;

        previous -> next = current -> next;
        delete current;
        
    }


}

void DeleteVal(int val){

    if(IsEmpty())
    cout << "\nNothing to Delete!!" << endl;
    else{
        if(SearchNode(val)){
            DeleteNode(SearchNode(val));
        }
        else
            cout << "Element not found!!" << endl;
    }
}

void UpdateNode(int PreviousVal, int NewVal){
    temp = head;
    if(SearchNode(PreviousVal)){
        while(temp -> data != PreviousVal){
            temp = temp -> next;
        }

        temp -> data = NewVal;
    }
    else
    cout << "Invalid Input!!" << endl;
}

void DisplayList()
{

    if (IsEmpty())
        cout << "\nNothing to Display!!" << endl;
    else
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << endl;
    }
}


int main(){

   CreateList(10);
   CreateList(20);
   CreateList(30);
   CreateList(40);

   DisplayList();


    return 0;
}
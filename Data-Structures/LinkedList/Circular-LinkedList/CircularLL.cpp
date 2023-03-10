#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next  != NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory is free for Node and Data" << value << endl;
    }
};

int size = 0;
Node* head = NULL, *tail = NULL;


int CountList()
{
    return size;
}

void InsertNodeFirst(int d){
    Node* newNode = new Node(d);
    
    if(head == NULL){

        newNode-> next = newNode;
        head = newNode;
        tail = newNode;
        
    }
    else{

        newNode -> next = head;
        tail -> next = newNode;
        head = newNode;
    }


    size++;
}

void InsertNodeLast(int d){

    Node* newNode = new Node(d);

    if(tail == NULL){

        newNode-> next = newNode;
        tail = newNode;
        head = newNode;
    }
    else{

        newNode -> next = head;
        tail -> next = newNode;
        tail = newNode;
    }

    size++;
}

void InsertAtPosition(int position, int d){

    if(head == NULL){
        cout << "LL is already empty";
        return;
    }
    else if(position == 1){
        InsertNodeFirst(d);
        return;
    }
    else if(position == size + 1){
        InsertNodeLast(d);
        return;
    }
    else{

        Node* newNode = new Node(d);

        Node* temp = head;

        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }

        newNode -> next = temp -> next;
        temp ->next = newNode;
        size++;

    }
}

void DeleteFirstNode(){

    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    size--;

}

void DeleteLastNode(){

    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp -> next != tail)
    {
        temp = temp -> next;
    }

    temp -> next = head;
    tail = temp;
    size--;

}

void DeleteAtPosition(int position){

    if (tail == NULL || position > size || position < 1){
        cout << "Delete not possible";
        return;
    }
    else if (position == 1){
        DeleteFirstNode();
        return;
    }
    else if (position == size){
        DeleteLastNode();
        return;
    }

    Node* temp = head;

    for(int i=0; i < position - 2; i++){

        temp = temp -> next;
    }

    Node* ptr = temp;
    temp -> next = temp -> next -> next;
    size--;

}

void Display(){

    if(tail == NULL){
        cout << "No list to Display" << endl;
        return;
    }

    Node* temp = head;

    do{
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }
    while(temp != tail);

    cout << temp -> data << endl;;

}

void UpdateList(int position, int d){
    if (tail == NULL || position >size || position < 1)
    {
        cout << "Update not possible";
        return;
    }
    else
    {
        Node *ptr=head;
        for (int i = 0; i < position-1; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = d;
    }
}


int main(){

    int ch;
    int pos, val;
    do
    {
        cout << "\n *******MENU*******\n"<< endl;
        
        cout << "1______ Insert Node at First." << endl;
        cout << "2______Insert Node at the Last." << endl;
        cout << "3______Insert Node at any given position." << endl;
        cout << "4______Delete Node at first." << endl;
        cout << "5______Delete Node at last." << endl;
        cout << "6______Delete Node at any given position." << endl;
        cout << "7______Update a Node." << endl;
        cout << "8______Count the List." << endl;
        cout << "9______Display the List." << endl;
        cout << "10.....EXIT." << endl;
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nEnd of Program" << endl;
            break;
        case 1:
            cout << "Enter value: ";
            cin >> val;
            InsertNodeFirst(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            InsertNodeLast(val);
            break;
        case 3:
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            InsertAtPosition(pos, val);
            break;
        case 4:
            DeleteFirstNode();
            break;
        case 5:
            DeleteLastNode();
            break;
        case 6:
            cout << "Enter pos: ";
            cin >> pos;
            DeleteAtPosition(pos);
            break;
        case 7:
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter val: ";
            cin >> val;
            UpdateList(pos, val);
            break;
        case 8:
            cout <<CountList();
            break;
        case 9:
            Display();
            break;
        default:
            cout << "\nInvalid Input!!" << endl;
            break;
        }
    } while (ch != 0);

    


    return 0;
}
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class Circular_Link_list {
public:
    node *head;
    node *tail;
    Circular_Link_list() {
        head = NULL;
        tail = NULL;
    }
    void insert_head(int val) {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
        if (tail == NULL) {
             tail = temp;
        }
        tail->next = head;
    }

    void insert_tail(int val){
        node *temp =new node (val);
        if(head==NULL){
            tail=head= temp;
            temp->next=head;
        }
        else{
            temp->next = head;
            tail->next = temp;
            tail = temp;
        }
    }
    void insert_pos(int pos , int val){
        node *pos_node =new node(val);
        int L =len(head);
        if(pos==1){
            insert_head(val);
            return;
        }
        if(pos>=L){
            insert_tail(val);
            return;
        }
        int count =1;
        node *temp =head;
        while(count<pos-1){
            count++;
            temp=temp->next;
        }
        pos_node->next=temp->next;
        temp->next=pos_node;
    }
    void delete_head(){
        if (head == NULL) {
        cout << "EMPTY..." << endl;
        return;
    }
    node *temp = head;
    if (head->next == head) { // Only one node in the list
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    }
   
    void delete_tail() {
    if (head == NULL) {
        cout << "EMPTY..." << endl;
        return;
    }

    if (head->next == head) { // Only one node in the list
        delete head;
        head = tail = NULL;
        return;
    }

    node *temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = head;
}

    void delete_pos(int pos){
        node *prev =head;
        node *temp= head->next;
        int L=len(head);
        cout<<L<<"/// ";
        if(pos ==1){
            delete_head();
            return;
        }
        if(pos>=L){
            delete_tail();
            return;
        }
        int count =1;
        while(count>pos-1){
            count ++;
            prev=prev->next;
            temp=temp->next;       
        }
       prev->next=temp->next;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        node *temp = head;
        cout << temp->data << " ";
        temp = temp->next;
        while (temp != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout<<tail->next->data<< "...";
    }
    int len(node *head){
        if(head==NULL){
            return 0;
        }
        int n=0;
        node *temp =head;
        do {
            n++;
            temp = temp->next;
        } while (temp != head);
        return n;
    }
};

// main
int main() {
    Circular_Link_list l;
    int n,pos;
    char choice;

    do {
        cout << "\npress \n1=> insert at head || 2=>insert at tail || 3 => insert at position || 4 => delete at head || / => display || 0 => exit \n";
        cin >> choice;
        switch (choice) {
        case '0':
            cout << "EXIT";
            break;
        case '1':
            cout << "insert at head :  ";
            cin >> n;
            l.insert_head(n);
            break;
        case '2':
            cout << "insert at tail :  ";
            cin >> n;
            l.insert_tail(n);
            break;
       case '3':
            cout << "insert  position at :  ";
            cin >> pos;
            cout << "insert the number :  ";
            cin >> n;
            l.insert_pos(pos, n);
            break;
        case '4':
            l.delete_head();
            break;
        case '5':
            l.delete_tail();
            break;
        case '6':
            cout << "enter position  :  ";
            cin >> pos;
            l.delete_pos( pos);
            break;
        // case '7':
        // cout<<"length"
        case '/':
            l.display();
            break;
        }
    } while (choice != '0');

    return 0;
}

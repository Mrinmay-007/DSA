# include <iostream>

using namespace std;

class node {
public:
    int coefficient;
    int exponent;
    node *next;
    node(int coef,int exp){
        coefficient=coef;
        exponent=exp;
        next=NULL;
    }
};
node* insert (node* head,int coef,int exp){
    node *temp =new node(coef,exp);
    if(head==NULL || head->exponent > exp){
        temp->next =head;
        head =temp ;
    }
    else{
        node*prev =NULL;
        node*cur =head;
        while(cur !=NULL && cur->exponent < exp ){
            prev=cur ;
            cur=cur->next;
        }
        if(prev==NULL){
            temp->next =head;
            head=temp;
        }
        else if (cur != NULL && cur->exponent == exp) {
                // Add coefficients of the same exponent
            cur->coefficient += coef;
            delete temp;
        }
        else{
            prev->next=temp;
            temp->next=cur;
        }
    }
    return head;       
}
void display(node* head){
    node* temp =head;
    if(temp==NULL){
        cout<<" EMPTY .... ";
        return;
    }
    while(temp!=NULL){
        cout << temp->coefficient << "x^" << temp->exponent;
        temp=temp->next;
        if (temp != nullptr) {
                cout << " + ";
        }
    }
    cout<<endl;
}
void add( node *head1 ,node * head2){
    node *res_head=NULL;
    node* poly1 =head1;
    node* poly2 =head2;
    int res_coef, res_exp;
    


    while(poly1 !=NULL && poly2 != NULL){
        if(poly1 ->exponent == poly2 ->exponent ){
            res_coef = poly1->coefficient + poly2->coefficient; 
            res_exp = poly1->exponent; 
            res_head= insert(res_head, res_coef, res_exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->exponent > poly2->exponent){
            res_head =insert(res_head , poly2->coefficient , poly2->exponent);
            poly2 = poly2->next;
        }
        else if( poly1->exponent < poly2 -> exponent){
            res_head =insert(res_head , poly1->coefficient , poly1->exponent);
            poly1 = poly1->next;
        }
    }
    while (poly1 !=NULL){
        res_head =insert(res_head , poly1->coefficient , poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 !=NULL){
        res_head =insert(res_head , poly2->coefficient , poly2->exponent);
        poly2 = poly2->next;
    }
    cout<< "ADDED POLYNOMIAL :  ";
    display(res_head);
}
//main
int main(){
node * poly1 =NULL;
node *poly2 =NULL;
int co,exp;
 char choice;

    do {
        cout << "\nPress:\n"
             << "1 => Insert into Polynomial 1 ||"
             << "2 => Insert into Polynomial 2 ||"
             << "/ => Display Polynomials ||"
             << "+ => Add Polynomials ||"
             << "0 => Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '0':
                cout << "EXIT\n";
                break;
            case '1':
                cout<< "inerting poly 1 ...... "<<endl;
                cout<<"coefficient :  ";
                cin>>co;
                cout<<"exponent  : ";
                cin>>exp;
                poly1 = insert(poly1, co, exp);
                break;
            case '2':
                cout<< "inerting poly 2 ...... "<<endl;
                cout<<"coefficient :  ";
                cin>>co;
                cout<<"exponent  : ";
                cin>>exp;
                poly2 = insert(poly2, co, exp);
                break;
            case '/':
                cout<<" poly 1  : ";
                display(poly1);
                cout<<" poly 2  : ";
                display(poly2);
                break;
            case '+':
                add(poly1,poly2);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '0');
    while (poly1 != nullptr) {
        node *temp = poly1;
        poly1 = poly1->next;
        delete temp;
    }

    while (poly2 != nullptr) {
        node *temp = poly2;
        poly2 = poly2->next;
        delete temp;
    }

 return 0;
}
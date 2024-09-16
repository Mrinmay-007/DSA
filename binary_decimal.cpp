# include <iostream>
# include <cmath>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }    
};
class Stack {
    public:
    node *top;
    Stack(){
        top=NULL;
    }
    void push(int val){
        node *temp =new node(val);
        temp->next=top;
        top=temp;
    }
    void pop(){
        node *temp =top;
        if(top==NULL){
            cout<<"EMPTY  ...";
            return;
        }
        top= top->next;
        delete temp ;
    }
    void display(){
        node * temp=top;
        if(top==NULL){
            cout<< "EMPTY...";
            return;
        }
        while(temp!= NULL){
            cout<< temp->data;
            temp=temp->next;
        }
    }
        bool empty(){
        return top==NULL; 
    }
    int Top(){
        if(top != NULL ){
            return top->data;
        }
    return 0;
    }
};
string decimal_binary(int val){
    Stack st;
    int r;
    int temp;
    string res="";

    while(val != 0){
        r=val%2;
        st.push(r);
        val=val/2;
    }
    while(!st.empty()){
        res+= to_string(st.Top());
        st.pop();
    }
    return res;

}
int Binary_decimal(string s){
    int l =s.length();
    int res=0;
    int p=0;
    Stack st;
    for(int i=0 ;i< l; i++){
        st.push(s[i]-'0');    
    }
    while(!st.empty()){
        int c=st.Top();
        res+= c*pow(2,p);
        p++;
        st.pop();
    }
    return res;
}
//main
int main(){
    cout<<decimal_binary(3);
    cout<<Binary_decimal("1000");
 return 0;
}
# include <iostream>

using namespace std;

class node {
    public:
    char data ;
    node * next;
    node(char val){
        data=val;
        next=NULL;
    }    
};

class Stack{
    public:
    node *top ;
    Stack(){
        top =NULL;
    }

    void push(char val){
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
        top=top->next;
        delete temp;
    }
    bool empty(){
        return top==NULL; 
    }
    char Top(){
        if(top != NULL ){
            return top->data;
        }
    return '/0';
    }
};

string rev(string s){
    string res;
    Stack st;
    int l= s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='('){
        //st.pop();
        st.push(')');
        }else if(s[i]==')'){
        //st.pop();
        st.push('(');
        }else{

        st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.Top();
        st.pop();
    }
return res;
}
int prec (char  c){
    if(c== '+' || c== '-')
    return 1;
    else if(c== '*' || c=='/')
    return 2;
    else if (c== '^')
    return 3;
    else
    return -1;

}

string  infix_postfix(string s){
    Stack st;
    string res;
    int l= s.length();

    for(int i=0 ;i< l ;i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] ==')'){
            while(!st.empty() && st.Top()!='('){
                res+=st.Top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else {
            while(!st.empty() && prec(st.Top()) > prec(s[i]) ){
                res+= st.Top();
                st.pop();
            }
                st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.Top();
        st.pop();
    }
    return res;
}
string infix_prefix(string s){
    string res;
    res += rev(s);
    res= infix_postfix(res);
    res=rev(res);
    return res;
}
//main
int main(){
cout<< infix_postfix("(a-b/c)*(a/k-l)")<<endl;
//cout<< rev("(a-b/c)*(a/k-l)")<<endl;
cout<< "prefix: "<< infix_prefix("(a-b/c)*(a/k-l)");
 return 0;
}
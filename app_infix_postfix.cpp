# include <iostream>
# include<string>

using namespace std;

class Stack {
      

private:
    string stackString;

public:
    void push(char c) {
        stackString += c;
    }

    char pop() {
        if (!empty()) {
            char top = stackString.back();
            stackString.pop_back();
            return top;
        } else {
           // cerr << "Stack is empty." << endl;
            return '\0'; // Return null character for an empty stack
        }
    }

    bool empty() {
        return stackString.empty();
    }

    char Top() {
        if (!empty()) {
            return stackString.back();
        } else {
           // cerr << "Stack is empty." << endl;
            return '\0'; // Return null character for an empty stack
        }
    }
};

class Infix_postfix{
    public:
    Stack s;
    string infix;
    string  postfix;
  
    bool opr(char c){
        return (c=='+'||c=='-'||c=='*'||c=='/');
    }
    bool oprnd(char c){
        return (isalpha(c));
    }

    int prec (char c){  
        if(c=='+'||c=='-')
        return 1;
        if(c=='*'||c=='/')
        return 2;
        if (c=='^')
        return 3;
        
        return 0; 
    }

    string infixtopostfix(string input){
        infix=input;
        postfix ="";
        for(int i=0; i < infix.length();i++){
            char C=infix[i];

            if(oprnd(C)){
                postfix += C;
            }
             else if(C=='('){
                 s.push(C);
             }
            if(C==')'){
                if(s.Top()!='('){
                    postfix += s.Top();
                    s.pop();
                } 
            }   
                if(s.Top()=='(')
                    s.pop();
                
             
            else if(opr(C)){
                while(!s.empty() && prec(C)<=prec(s.Top())){
                    postfix += s.Top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
         while(!s.empty()){
            postfix += s.Top();
            s.pop();
        }
        
        return postfix;
     }
    
};
//main
int main(){
 Infix_postfix itop;
    string st;
    cout <<"enter the expression :  ";
    cin>> st;
    cout<<endl;
    cout<< "postfix :  "<<itop.infixtopostfix(st);

 return 0;
}
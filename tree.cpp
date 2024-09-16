# include <iostream>
# include <queue>

using namespace std;

class node  {
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node *creat(node *root){
    int val;
    cout<<"enter the data : "<<endl;
    cin>>val;
    root = new node(val);
    if(val==-1){
        return NULL;
    }
    cout<< "<---- insert left of : "<< val<< endl;
    root->left=creat(root->left);
    cout<< "----> insert right of: "<< val<< endl;
    root->right=creat(root->right);

    return root;
}
void creat_by_LOT(node * &root){
    queue<node*>q;
    cout<<"enter the root  ";
    int data ;
    cin>>data;
    root =new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter the left node of  "<<temp->data<<endl;
        int l;
        cin>>l;

        if (l!= -1){
            temp->left=new node(l);
            q.push(temp->left);
        }
                cout<<"enter the right node of  "<<temp->data<<endl;
        int r;
        cin>>r;

        if (r!= -1){
            temp->right=new node(r);
            q.push(temp->right);
        }
    }
}
//LEVEL ORDER TRAVERSAL
void level_order_traversal(node *root){ 
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp =q.front();
        q.pop();
    
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

void inorder(node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";
}

void preorder(node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}
//main
int main(){
    node* root=NULL;
    creat_by_LOT(root);
    //root=creat(root);
    level_order_traversal(root);
   // cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);


 return 0;
}
// 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

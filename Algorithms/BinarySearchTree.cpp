#include<bits/stdc++.h>
using namespace std;

/*Defining structure of the node*/
struct node
{
    int data;
    node* left;
    node* right;
};

/*Function to create a new node*/
node* create_node(int data)
{
    node* new_node=new node();
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

/*Function to check for a value in the tree*/
bool is_present(node* root,int data)
{
    if(root==NULL){
        return false;
    }

    if(root->data==data){
        return true;
    }
    else if(root->data<data){
        is_present(root->right,data);
    }
    else{
        is_present(root->left,data);
    }
}

/*Function to insert a new node into the tree*/
node* insert_node(node* root,int data)
{
    /*If tree is empty*/
    if(root==NULL){
        root = new node();
        root->data=data;
        root->left=NULL;
        root->right=NULL;

        cout<<"Root with "<<data<<" as value created successfully"<<endl;
        return root;
    }

    node* prev=NULL,*ptr=root;
    /*Check if given value is alraeady present,
    and also traverse to the position where 
    it is supposed to be inserted*/
    while(ptr!=NULL)
    {
        prev=ptr;
        if(ptr->data==data){
            cout<<"Cannot insert!!"<<data<<" is already present in the tree"<<endl;
            return ptr;
        }
        else if(ptr->data<data){
            ptr=ptr->right;
        }
        else if(ptr->data>data){
            ptr=ptr->left;
        }
    }

    /*Create a new node and add it to the tree*/
    node* new_node=create_node(data);
    if(data>prev->data){
        prev->right=new_node;
    }
    else{
        prev->left=new_node;
    }

    cout<<data<<" inserted successfully into the tree"<<endl;
    return root;
}

/*Function to get the leftmost node*/
node* min_value_node(node* root)
{
    node* ptr=root;
    while (ptr && ptr->left != NULL){
        ptr=ptr->left;
    }
    return ptr;
}
 
/* Function to delete a given value from BST */
struct node* delete_node(struct node* root, int data)
{
    /*If tree is empty*/
    if(root==NULL){
        cout<<"Element not found!!"<<endl;
        return root;
    }
 
    if (data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data){
        root->right = delete_node(root->right, data);
    }
    else {
        /*Node with only one child or no child*/
        if (root->left == NULL) {
            node* ptr=root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL) {
            node* ptr=root->left;
            free(root);
            return ptr;
        }
 
        struct node* temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right,temp->data);
    }
    return root;
}

/*Function for inorder traversal,
used to display the tree*/
void inorder_traversal(node* root)
{
    if(root!=NULL)
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

/*Function for menu*/
void menu(node* root){

    int option,element,n,*arr;
    while(1)            //Menu to be displayed to the users
    {
        cout<<"======================================"<<endl;
        cout<<"Choose from the following:"<<endl;
        cout<<"1.Insert an element into the BST"<<endl;
        cout<<"2.Delete an element from the BST"<<endl;
        cout<<"3.Search for an element in the BST"<<endl;
        cout<<"4.Display Inorder Traversal of the BST"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"->";
        cin>>option;
        
        switch(option)
        {
            case 1:
                cout<<"How many elements are going to be inserted?"<<endl;
                cout<<"->";
                cin>>n;

                arr=(int*)malloc(n*sizeof(int));
                cout<<"Give the list of elements to be inserted:";
                for(int i=0;i<n;i++)
                {
                    cin>>arr[i];
                    if(is_present(root,arr[i])){
                        cout<<"Cannot insert!! "<<arr[i]<<" already present in the BST"<<endl;
                    }
                    else{
                        root=insert_node(root,arr[i]);
                    }
                }

                break;
            case 2:
                cout<<"Give the element to the deleted:";
                cin>>element;
                if(!is_present(root,element)){
                    cout<<"Cannot delete!! "<<element<<" is not present in the tree"<<endl;
                }
                else{
                    root=delete_node(root,element);
                    cout<<element<<" deleted successfuly from the tree."<<endl;
                }
                break;
            case 3:
                cout<<"Give the value to be searched:";
                cin>>element;
                if(is_present(root,element)){
                    cout<<element<<" is present in the tree"<<endl;
                }
                else{
                    cout<<element<<" is NOT present in the tree"<<endl;
                }
                break;
            case 4:
                if(!root){
                    cout<<"Empty tree!!"<<endl;
                    break;
                }
                else{
                    cout<<"Inorder traversal of the AVL tree is:";
                    inorder_traversal(root);
                    cout<<endl;
                    break;
                }
            case 5:
                cout<<"Thank You!!"<<endl;
                return;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }

    }
    
}

int main(){

    node* root=NULL;
    menu(root);    
    return 0;
}



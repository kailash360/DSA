#include <bits/stdc++.h>
using namespace std;

/*Defining size of the array to be used as binary tree*/
#define MAXSIZE 100

/*Defining the structure of the binary tree made using array*/
struct tree
{
    int arr[MAXSIZE];
    bool isEmpty=true;
};

/*Initializing the tree*/
void initialise(tree &new_tree)
{
    for(int i=0;i<MAXSIZE;i++){
        new_tree.arr[i]=-1;
    }
}

/*Function to set left child of a node*/
void set_left_child(tree &new_tree, int parent, int data)
{
    /*Check for out of bounds*/
    if((2*parent + 1)>=MAXSIZE) {
        cout<<"Cannot insert as tree already full"<<endl;
        return;
    }

    /*Check if data already present in the left node*/
    if(new_tree.arr[2*parent + 1]!=-1) {
        cout<<"Data already present"<<endl;
        cout<<"Do you want to overwrite(Y/N):";
        fflush(stdin);
        if(getchar()=='Y'){
            cout<<"Data overwritten successfully"<<endl;
        }
        else{
            cout<<"Data insertion unsuccessful"<<endl;
            return;
        }
    }

    new_tree.arr[2*parent+1]=data;
    cout<<data<<" inserted successfully"<<endl;
}

/*Function to set right child of a node*/
void set_right_child(tree &new_tree, int parent, int data)
{
    /*Check for out of bounds*/
    if((2*parent + 2 )>=MAXSIZE) {
        cout<<"Cannot insert as tree already full"<<endl;
        return;
    }

    /*Check if data already present in the right node*/
    if(new_tree.arr[2*parent + 2]!=-1) {
        cout<<"Data already present"<<endl;
        cout<<"Do you want to overwrite (Y/N):";
        fflush(stdin);
        if(getchar()=='Y'){
            cout<<"Data overwritten successfully"<<endl;
        }
        else{
            cout<<"Data insertion unsuccessful"<<endl;
            return;
        }
    }

    new_tree.arr[2*parent+2] = data;
    cout<<data<<" inserted successfully"<<endl;
}

/*Function to insert data into the tree*/
void insert(tree &new_tree, int data)
{
    /*Check if root is empty*/
    if(new_tree.arr[0]==-1)
    {
        new_tree.arr[0] = data;
        new_tree.isEmpty=false;
        cout<<data<<" inserted successfully"<<endl;
    }
    /*If root exists then insert into children*/
    else
    {
        label3:
        int index=0,option;
        label2:
        if(index>=MAXSIZE)
        {
            cout<<"Array size exceeded. Index set to 0"<<endl;
            goto label3;
        }
        cout<<"//Current node info"<<endl;

        /*Display info of left child*/
        cout<<"Left child ";
        if(new_tree.arr[2*index+1]==-1){
            cout<<"does not exist"<<endl;
        }
        else{
            cout<<"exists"<<endl;
        }

        /*Display info of right child*/
        cout<<"Right child ";
        if(new_tree.arr[2*index+2]==-1){
            cout<<"does not exist"<<endl;
        }
        else{
            cout<<"exists"<<endl;
        }

        cout<<"Data present:"<<new_tree.arr[index]<<endl;
        label1:
        cout<<"1.Set Left Child"<<endl;
        cout<<"2.Set Right Child"<<endl;
        cout<<"3.Go to left"<<endl;
        cout<<"4.Go to right"<<endl;
        cout<<"Enter your choice:";
        cin>>option;
        switch(option)
        {
            case 1:
                set_left_child(new_tree, index, data);
                break;
            case 2:
                set_right_child(new_tree, index, data);
                break;
            case 3:
                if(new_tree.arr[2*index+1]==-1){
                    cout<<"Left child does not exist! Cannot go to left child"<<endl;
                }
                else{
                    index = 2*index+1;
                }
                goto label2;
            case 4:
                if(new_tree.arr[2*index+2]==-1){
                    cout<<"Right child does not exist! Cannot go to right child"<<endl;
                }
                else{
                    index = 2*index+2;
                }
                goto label2;

            default :
                cout<<"Invalid option Entered.";
                goto label1;
        }
    }
}

/*Function that gives left child of current node*/
int left_child(tree &new_tree, int index)
{
    if(!new_tree.isEmpty && (2*index+1)<MAXSIZE ){
        return 2*index+1;
    }
    return -1;
}

/*Function that gives right child of current node*/
int right_child(tree &new_tree, int index)
{
    if(!new_tree.isEmpty && (2*index+2)<MAXSIZE){
        return 2*index+2;
    }
    return -1;
}

/*Function for inorder traversal*/
void inorder_traversal(tree &new_tree, int index)
{
    if(new_tree.arr[index]!=-1)
    {
        inorder_traversal(new_tree, left_child(new_tree,index));
        cout<<new_tree.arr[index]<<" ";
        inorder_traversal(new_tree, right_child(new_tree,index));
    }
}

/*Function for preorder traversal*/
void preorder_traversal(tree &new_tree, int index)
{
    if(new_tree.arr[index]!=-1)
    {
        cout<<new_tree.arr[index]<<" ";
        preorder_traversal(new_tree, left_child(new_tree,index));
        preorder_traversal(new_tree, right_child(new_tree,index));
    }
}

/*Function for postorder traversal*/
void postorder_traversal(tree &new_tree, int index)
{
    if(new_tree.arr[index]!=-1)
    {
        postorder_traversal(new_tree, left_child(new_tree,index));
        postorder_traversal(new_tree, right_child(new_tree,index));
        cout<<new_tree.arr[index]<<" ";
    }
}

/*Function for menu*/
void menu()
{
    tree new_tree;
    initialise(new_tree);

    while(1)
    {
        int choice,data;
        cout<<"=================================="<<endl;
        cout<<"Choose from the following:"<<endl;
        cout<<"1.Insert Data"<<endl;
        cout<<"2.Inorder traversal"<<endl;
        cout<<"3.Preorder Traversal"<<endl;
        cout<<"4.Postorder traversal"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"->";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter your data into the tree: ";
                cin>>data;
                insert(new_tree,data);
                break;
            case 2:
                if(new_tree.isEmpty) {
                    cout<<"Empty tree!!"<<endl;
                    break;
                }
                cout<<"Inorder traversal is:";
                inorder_traversal(new_tree,0);
                cout<<endl;
                break;
            case 3:
                if(new_tree.isEmpty) {
                    cout<<"Empty tree!!"<<endl;
                    break;
                }
                cout<<"Preorder traversal is:";
                preorder_traversal(new_tree,0);
                cout<<endl;
                break;
            case 4:
                if(new_tree.isEmpty) {
                    cout<<"Empty tree!!"<<endl;
                    break;
                }
                cout<<"Postorder traversal is:";
                postorder_traversal(new_tree,0);
                cout<<endl;
                break;
            case 5:
                cout<<"Thank You"<<endl;
                return;
                break;
            default:
                cout<<"Invalid Choice!!"<<endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}

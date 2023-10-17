#include<iostream>
#include<string>

/*
	This includes the below functions in the singly linked list
	
	createNode
	insertfront
	insertback
	reverseLL 
	printlist 
	deletenthnode 
	deletenthnodeRev
	
*/
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node* createNode(int data)
{
    node *r = new(node);
    r->data = data;
    r->next = NULL;
    return r;
}

node* insertfront(node* root, int data)
{
    node *r = createNode(data);
    if(!root)
    {
        root = r;
    }
    else
    {
        r->next=root;
        root = r;
    }
    return root;
}
node* insertback(node* root, int data)
{
    node *r = createNode(data);
    if(!root)
    {
        root = r;
    }
    else
    {
        node *ptr = root;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = r;
    }
    return root;
}

node* reverseLL(node* root)
{
    node *p = root, *q=root->next, *a = NULL;
    while(q)
    {
        p->next = a;
        a = p;
        p=q;
        q=q->next;
    }
    p->next = a;
    cout<<"\n";
    return p;
}

void printlist(node *root)
{
    node *p = root;
    while(p)
    {
        cout<<p->data;
        p = p->next;
        if(p)
        {
            cout<<"->";
        }
        else
        {
            cout<<"-> NULL";
        }
    }
    
}

node *deletenthnode(node* root, int n)
{
    node *ptr = root, *prev = NULL;
    n -= 1;
    while(n--)
    {
        prev = ptr;
        ptr=ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return root;
}

node *deletenthnodeRev(node* root, int n)
{
    node *a=NULL, *b=root, *c=root;
    n -= 1;
    while(n--)
    {
        c=c->next;
    }
    while(c->next)
    {
        a = b;
        b = c;
        c = c->next;
    }
    if(a)
    {
        a->next = c;
    }
    if(root == b)
    {
        root = root->next;
    }
    free(b);
    return root;
}

int main()
{
    node *root = NULL;
    root = insertfront(root, 5);
    root = insertfront(root, 6);
    root = insertfront(root, 3);
    root = insertback(root, 7);
    root = insertback(root, 8);
    printlist(root);
    root = reverseLL(root);
    printlist(root);
    root = deletenthnode(root, 2);
    cout<<"\n";
    printlist(root);
    root = deletenthnodeRev(root, 2);
    cout<<"\n";
    printlist(root);
    return 0;
    
}

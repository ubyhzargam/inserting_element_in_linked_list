//
//  main.cpp
//  inserting_element_in_linked_list
//
//  Created by Uby H on 15/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}
*first=NULL;
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last= first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void insert(struct Node *p,int pos, int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    int c=0;
    if(pos==1)
    {
        t->data=x;
        t->next=first;
        first=t;
    }
    else
    {
        while(p!=NULL)
        {
            if(c++==pos-1)
            {
                t->data=x;
                t->next=p->next;
                p->next=t;
                break;
            }
            p=p->next;
        }
    }
}
int main()
{
    int n,pos,x;
    cout<<"Enter the number of elements in the linked list : "<<endl;
    cin>>n;
    cout<<"Enter the elements in the linked list : "<<endl;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    create(A,n);
    cout<<"Enter the position after which the element should be inserted : "<<endl;
    cin>>pos;
    cout<<"Enter the element to be inserted : "<<endl;
    cin>>x;
    cout<<"The original linked list is given by : "<<endl;
    display(first);
    cout<<endl;
    insert(first,pos,x);
    cout<<"The updated array is given by : "<<endl;
    display(first);
    cout<<endl;
    return 0;
}

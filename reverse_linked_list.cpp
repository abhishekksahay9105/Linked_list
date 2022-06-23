#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void push(Node** head,int val)
{    
     Node* new_node=new Node();

     new_node->data=val;
     new_node->next=*head;
     *head=new_node;
}

void print_list(Node* head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

void delete_node(Node** head,int key)
{
  if((*head)->data==key)
  {
     Node* temp=*head;
     *head=temp->next;
     free(temp);
     return;
  }
  
  Node* temp=NULL;
  temp=*head;
  
  while(temp->next->data!=key&&temp->next!=NULL)
  {
      temp=temp->next;
  }
  
  Node* temp1=temp->next;
  temp->next=temp->next->next;
  free(temp1);
}


void reverse_list(Node** head,Node* temp,Node* pre)
{
       if(temp->next==NULL)
       {
         temp->next=pre;
         *head=temp;
         return;
       }

       reverse_list(head,temp->next,temp);
       temp->next=pre;


}

int main()
{

     #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout);
  #endif

  Node* head=NULL;

  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  push(&head,6);
  push(&head,7);
  push(&head,8);

  Node* t=NULL;
  
  print_list(head);
  reverse_list(&head,head,t);
  print_list(head);

  delete_node(&head,8);
  delete_node(&head,7);
  delete_node(&head,1);
  delete_node(&head,4);

  
  print_list(head);
  reverse_list(&head,head,t);
  print_list(head);
}

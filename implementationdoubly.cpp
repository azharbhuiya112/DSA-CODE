#include<iostream>

using namespace std;


class node{
 public:
int info;
node *next;
node *prev;



};


void creation(node **head,int data)
{
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;

    if(*head==NULL)
    {
        *head=ptr;

    }
    else{
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
        temp->next=ptr;
        ptr->prev=temp;

    }




}

void printlist(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<"<->"<<temp->info;
        temp=temp->next;
    }
}

void firstinsert(node **head,int data)
{
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;
          ptr->next=temp;
          temp->prev=ptr;
          *head=ptr;

}

void lastinsert(node **head,int data)
{
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    ptr->prev=temp;
    temp->next=ptr;



}
void insertatpos(node **head,int data,int pos)
{
    int i=0;
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;
    while(i<pos-2)
    {
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
}
void inseraftetatpos(node **head,int data,int pos)
{
    int i=0;
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
}

void beforeinsertion(node **head,int data,int src)
{
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;
    if(temp->info==src)
    {
        firstinsert(head,data);
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->info==src)
            {
                node *str=temp->prev;
                ptr->next=temp;
                str->next=ptr;
                ptr->prev=str;
            }
            temp=temp->next;
        }
    }
}

void afterinsertion(node **head,int data,int src)
{
    node *ptr=new node();
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->info=data;
    node *temp=*head;

   while(temp!=NULL)
        {
           if(temp->info==src && temp->next==NULL)
            {
                temp->next=ptr;
                ptr->prev=temp;
                return;
            }
            else if(temp->info==src)
                {
                    node *str=temp->next;
                    str->prev=ptr;
                    ptr->next=str;
                    ptr->prev=temp;
                    temp->next=ptr;

                }
              temp=temp->next;
        }
}

void firstdeletion(node **head)
{
    node *temp=*head;
    *head=(*head)->next;
    //(*head)->next->prev=NULL;
        delete(temp);
}

void lastdeletion(node **head)
{
     node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->prev->next=NULL;
    delete(temp);

}
void givendelete(node **head,int src)
{

    node *temp=*head,*ptr,*str;
    while(temp!=NULL)
    {

        if(temp->info==src && temp==*head)
        {

              firstdeletion(head);
        }
        else if(temp->info==src)
          {
             ptr=temp->prev;
             str=temp->next;
            ptr->next=str;
            str->prev=ptr;
           }
         temp=temp->next;
    }
    delete(temp);

}

//   node* reversing(node *head)
//  {
//      node *current=head,*ptr=NULL;
//      if(current == NULL|current->next==NULL)
//        return head;
//      while(current->next!=NULL)
//
//          current=current->next;
//          head=current;
//
//
//      while(current!=NULL)
//      {
//          ptr=current->next;
//          current->next=current->prev;
//          current->prev=ptr;
//          current=ptr;
//      }
//          return head;
//
//  }
//
//
void reverseList(node *head)
{
    node *current=head;
    node *prev=NULL;
    while(current!=NULL)
    {
        current->prev=current->next; //line 1
        current->next=prev;          //line 2
        prev=current;                //line 3
        current=current->prev;       //line 4
    }
        head=prev;
}


int main()
{
    node *head=NULL;
    int n,a;
    cout<<"nmbr of eleemnts in doubly"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        creation(&head,a);
    }
    printlist(head);
    cout<<"WHICH VALUE YOU WANT TO INSERT FIRST:";

    int data;
    cin>>data;
    firstinsert(&head,data);
    printlist(head);
    cout<<"WHICH VALUE YOU WANT TO INSERT LAST:";
    cin>>data;
    lastinsert(&head,data);
    printlist(head);
    cout<<endl;
    insertatpos(&head,8,2);
    printlist(head);
    cout<<endl;

    beforeinsertion(&head,9,8);
    printlist(head);

     cout<<endl;
     afterinsertion(&head,10,8);
     printlist(head);

     cout<<endl;
     firstdeletion(&head);
     printlist(head);

     cout<<endl;
     lastdeletion(&head);
      printlist(head);

      cout<<endl;
      givendelete(&head,2);
      printlist(head);

       cout<<endl;
//      reversing(head);
//      printlist(head);
      reverseList(head);
       printlist(head);


    return 0;
 }

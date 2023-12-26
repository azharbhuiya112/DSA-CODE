#include<iostream>

using namespace std;


class node{

 public:
  int info;
  node *prev;
  node *next;

node()
{
    info=NULL;
    prev=NULL;
    next=NULL;
}

node(int x)
{
    info=x;
    prev=NULL;
    next=NULL;
}
};

void creation(node **Head,int data)
{
    node *ptr=new node(data);
    if(*Head==NULL)
    {
        *Head=ptr;

    }
else
    {

    node *temp=*Head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=ptr;
    ptr->prev=temp;
    }}


void firstinsertion(node **Head,int data)
{
    node *ptr=new node(data);
    (*Head)->prev=ptr;
    ptr->next=*Head;
    *Head=ptr;
}
void lastinsertion(node **Head,int data)
{

    node *temp=*Head;
    node *ptr=new node(data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     ptr->prev=temp;
     temp->next=ptr;

}

void beforeinsertion(node **Head,int data,int src)
{

    node *temp=*Head;
    node *str;
    node *ptr=new node(data);
    while(temp!=NULL)
    {
        if(temp->info==src)
        {
            str=temp->prev;
            if(*Head==NULL)
            {
                firstinsertion(Head,data);
            }
            else
            {
                str->next=ptr;
                ptr->prev=str;
                ptr->next=temp;
                temp->prev=ptr;
                return;
            }
        }
        else{

//            str=temp;
            temp=temp->next;
        }

    }

}

void afterinsertion(node **Head, int data , int src)
{
    node *temp=*Head,*str;
    node *ptr=new node(data);
    while(temp!=NULL)
    {
        if(temp->info==src)
        {
             str=temp->next;
            if(str==NULL)
            {
                temp->next=ptr;
                ptr->prev=temp;
                return;
            }
            else
            {
                temp->next=ptr;
                ptr->prev=temp;
                ptr->next=str;
                str->prev=ptr;
                return;

            }
        }
        else
        {
            temp=temp->next;

        }
    }

}

void firstdeletion(node **Head)
{
    node *temp=*Head;
    *Head=(*Head)->next;
    delete(temp);
}
void lastdeletion(node **Head)
{
 node *temp=*Head;
    while(temp->next!=NULL)
    {
     temp=temp->next;

    }

    temp->prev->next=NULL;
    delete(temp);
}

void givendeletion(node **Head, int src)
{
    node *temp=*Head,*str,*ptr;
    while(temp!=NULL)
    {
      if(temp->info==src)
      {
          if(temp==*Head)
          {
              firstdeletion(Head);
          }
          else{
              str=temp->next;
              ptr=temp->prev;
              ptr->next=str;
              str->prev=ptr;
           delete(temp);
           return;
      }


    }
    else{
        temp=temp->next;
    }
}}

void GivenDelete(node **Head, int src)
{
    node *temp=*Head;
    node *ptr,*str;
    while(temp!=NULL)
    {
        if(temp->info==src){
        if(temp==*Head)
        {
            firstdeletion(Head);
        }
        else{
            ptr=temp->next;
            str=temp->prev;
            str->next=ptr;
            ptr->prev=str;
            delete temp;
        }
        }
        else{
            temp=temp->next;
        }
    }
}

printlist(node *Head)
{
    node *temp=Head;

    while(temp->next!=NULL)
    {
        cout<<temp->info<<"<-->";
        temp=temp->next;
    }

    cout<<temp->info<<endl;
}


int main()
{
    node *Head=NULL;
    int data;
    for(int i=0;i<5;i++)
    {
        cin>>data;
        creation(&Head,data);
    }
    cout<<"the doubly"<<endl;
    printlist(Head);

    firstinsertion(&Head,4);
    cout<<"after first insertion"<<endl;;
     printlist(Head);

     lastinsertion(&Head,5);
     cout<<"after last insertion"<<endl;
      printlist(Head);

    beforeinsertion(&Head,7,1);
    cout<<" before insertion"<<endl;
    printlist(Head);

    afterinsertion(&Head, 105 ,1);
      cout<<" after insertion"<<endl;
      printlist(Head);

     firstdeletion(&Head);
     cout<<" after first deletion"<<endl;
     printlist(Head);

     lastdeletion(&Head);
     cout<<" after last deletion"<<endl;
     printlist(Head);
    GivenDelete(&Head,7);
      //givendeletion(&Head,5);
       printlist(Head);

}


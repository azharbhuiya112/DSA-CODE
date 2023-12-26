#include<iostream>


using namespace std;

class node{
    public:
           int info;
           node *link;
};

void creation(int data,node **head)
{
   node *ptr=new node();

   ptr->info=data;
   ptr->link=NULL;


 if(*head==NULL)
{
 *head=ptr;
}
else
{
node *temp;
temp=*head;
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=ptr;

}
}


void print(node *head)
{
node *temp=head;
while(temp!=NULL)
{
cout<<"->"<<temp->info;
temp=temp->link;
}
}


void firstinsert(int data,node **head)
{
    node *ptr=new node();
     ptr->link=NULL;
    ptr->info=data;
    ptr->link=*(head);
    *head=ptr;
}
void lastinsert(int data,node **head)
{
    node *ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    node *temp=*head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=ptr;
}


void aftergivenpos(int data,node **head)
{
    node *ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    int pos=2;
    int i;
    node *temp=*head;
    while(i<pos)
    {
        temp=temp->link;
        i++;
    }

    ptr->link=temp->link;
    temp->link=ptr;
}


void beforesearchitem(int data,node **head,int src)
{
    node *ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    node *temp=*head;
    while(temp->link->info!=src)
    {
        temp=temp->link;
    }
    ptr->link=temp->link;
    temp->link=ptr;

}

void firstdlt(node **head)
{
    node *temp=*head;
     *head=(*head)->link;
    delete(temp);
}



void lastdlt(node **head)
{
    node *temp=*head;
     while(temp->link->link!=NULL)
     {
         temp=temp->link;
     }
     temp->link=NULL;
    delete(temp->link);
}



void itemdlt(node **head,int item)
{
    node *str,*temp=*head;
    while(temp->link->info!=item)
    {
        temp=temp->link;
    }
      str=temp->link;
      temp->link=str->link;
     delete(str);
}

void get_nmbr_of_nodeorlength(node **head)
{
    int cnt=0;
    node *temp=*head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->link;
    }
    cout<<cnt<<endl;
}

void reversing(node **head)
{
    node *prev,*current,*next;
    prev=NULL;
    next=current=*head;
    while(next!=NULL)
    {
        next=next->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

int main()
{

cout<<"plz meem Enter link list size:";
int data,n;
cin>>n;
node *head=NULL;
node *temp=NULL;
cout<<"plz meem Enter the item:"<<endl;
for(int i=0;i<n;i++)
{
cin>>data;
creation(data,&head);
}
cout<<"meem your created link list:"<<endl;
print(head);

cout<<endl;
cout<<"meem plz enter item for 1st insert"<<endl;
cin>>data;
firstinsert(data,&head);
cout<<"after 1st insertion:"<<endl;
print(head);


cout<<endl;
cout<<"meem plz enter item for last insert"<<endl;
cin>>data;
lastinsert(data,&head);
cout<<"after last insertion:"<<endl;
print(head);


cout<<endl;
cout<<"which item meem you want to insert after given position 2:"<<endl;
cin>>data;
aftergivenpos(data,&head);
cout<<"inserting after given position 2:"<<endl;
print(head);

cout<<endl;
cout<<"which item meem you want to insert before an item"<<endl;
cin>>data;
cout<<"before which search item meem you want to insert"<<endl;
int src;
cin>>src;
beforesearchitem(data,&head,src);
cout<<" after inserting before search item:"<<endl;
print(head);


cout<<endl;
firstdlt(&head);
cout<<"after 1st dlt:"<<endl;
print(head);


cout<<endl;
lastdlt(&head);
cout<<"after last dlt:"<<endl;
print(head);


cout<<endl;
cout<<"which item you want to dlt meem!"<<endl;
int item;
cin>>item;
itemdlt(&head,item);
cout<<"after your requested  item deletion:"<<endl;
print(head);

cout<<endl;
cout<<"meem you are reversing the singly link list:"<<endl;
reversing(&head);
print(head);

cout<<endl<<"dear meem! after the operation your node nmbr is  ";
get_nmbr_of_nodeorlength(&head);
return 0;
}

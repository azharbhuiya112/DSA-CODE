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
while(temp!=NULL)
{
temp=temp->link;
}
temp->link=ptr;

}


}


void print(node **head)
{
    node *temp=*head;
    cout<<" "<<*head<<endl;
    while(temp!=NULL)
    {
         cout<<" "<<temp->info;
         cout<<"  "<<temp->next<<" "<<endl;//porer  node er address
         cout<<" "<<temp<<" "<<endl;//address
         temp=temp->next;
    }

}

int main()
{
  int n;
  int data;
  cin>>n;
node *head=NULL;
for(int i=0;i<n;i++)
{
cin>>data;
creation(data,&head);
}

print(&head);

return 0;

}

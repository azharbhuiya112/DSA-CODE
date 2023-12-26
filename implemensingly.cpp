#include<iostream>


using namespace std;


class node{
public:
  int info;
  node *next;


  node()
  {
      next=NULL;
      info=NULL;
  }

    node( int x)
  {
      next=NULL;
      info=x;
  }




};



void creation(int data,node **head)
{

    node *ptr=new node(data);

    if(*head==NULL)
    {
        *head=ptr;
    }

    else
    {
       node *temp;
       temp=*head;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }

        temp->next=ptr;
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
    cout<<"size of link list:";
    cin>>n;
    int data;
    node *head=NULL;
    //node *temp=NULL;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the" <<" "<<i<<" "<<"tomo value for creation:"<<endl;
        cin>>data;
        creation(data,&head);
    }

    cout<<"The created link list"<<endl;
    print(&head);
    return 0;




}

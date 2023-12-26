#include<iostream>


using namespace std;

class node{

public:
    int data;
    node link;


    node()
    {
        data=NULL;
        link=NULL;
    }

     node(int x)
    {
        data=x;
        link=NULL;
    }


void creation(int data, node **head)
{
    node *ptr=new node(data);

    if(*head=NULL)
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









};




int main()
{

















    return 0;
}

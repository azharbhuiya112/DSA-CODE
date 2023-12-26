#include<iostream>
using namespace std;

class node {
private:
    int data;
    node* next;

public:
    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    friend void creation(node** head, int data);
    friend void display(node** head);
};

void creation(node** head, int data) {
    node* ptr = new node(data);
    if (*head == NULL) {
        *head = ptr;
        (*head)->next = *head;
    }
    else {
        node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = ptr;
        ptr->next = *head;
    }
}

void display(node** head) {
    node* temp = *head;
    if (*head == NULL) {
        cout << "No nodes available" << endl;
        return;
    }

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != *head);
    cout << endl;
}

int main() {
    int n, info;
    cin >> n;
    node* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> info;
        creation(&head, info);
    }
    display(&head);

    return 0;
}



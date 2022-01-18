#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};
void print(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main(){
    //statically
    /*
    node n1(5);
    node n2(10);
    node n3(100);
    node *head=&n1;
    n1.next=&n2;
    n2.next=&n3;
    */
   //dynamically
   node* head=new node(25);
   node* n4=new node(50);
   node* n5=new node(10);
   node* n6=new node(100);
   node* n7=new node(1000);
    head->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n6;
    n6->next=n7;
    print(head);
    return 0;
}
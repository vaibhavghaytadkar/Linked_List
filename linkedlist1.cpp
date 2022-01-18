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
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data!=-1){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int numberofnodes(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
node* insertnode(node*head,int i,int data){
    
    node*temp=head;
    int count=0;
    node* newnode=new node(data);
    if(i==0){
       newnode->next=temp;
       head=newnode; 
       return head;
    }
    while(count<i-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
node* deletenode(node* head,int i){
    node* temp=head;
    int count=0;
    if(i==0){
        node* todelete=head;
        head=head->next;
        delete todelete;
        return head;
    }
    while(count<i-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    return head;
}
int findnode(node* head,int value){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        if(temp->data==value){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}
node* appendtolast(node* head,int m){
    node* temp=head;
    int n=numberofnodes(head)-m;
    int count=0;
    while(count<n-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    node* head1=temp->next;
    node* head2=temp->next;
    temp->next=NULL;
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=head;
    return head2;
}
void removeduplicates(node* head){
    
     if(head==NULL){
         return;
     }
     node* current=head;
     node* temp=head->next;
     while(temp!=NULL){
         if(current->data==temp->data){
             node* todelete=temp;
             temp=temp->next;
             delete todelete;
         }
         else{
             current->next=temp;
             current =temp;
             temp=temp->next;
         }

     }
      current->next=temp;

}
//Print revere linked list
void reversell(node* head){
    if(head==NULL){
        return;
    }
    reversell(head->next);
    cout<<head->data<<"->";
}


int main(){
    
   node* head=takeinput();
   
    print(head);
   /* cout<<numberofnodes(head)<<endl;
    head=insertnode(head,5,57778);
    print(head);
    print(deletenode(head,5));
    cout<<findnode(head,7)<<endl;
    */
    //node* head2=appendtolast(head,3);
  //  removeduplicates(head);
   // print(head);
   reversell(head);
    return 0;
}
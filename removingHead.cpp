#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};

//this function is returning head.
//because we cannot pass the entire linked list.
Node* convertArr2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
      Node* temp=new Node(arr[i]);
      mover->next=temp;
      mover=temp;
    }
    return head;
}


Node* removeHead(Node* head){
     if(head==NULL){
      return head;    //this is the edge case.    
     }
     Node* temp=head;
     head=head->next;
     free(temp);
     return head;
}

void print(Node* head){
     Node* temp=head;
     while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
     }
}
int main(){
vector<int>arr={22,5,8,7};
Node* head=convertArr2LL(arr);
head=removeHead(head);
print(head);
return 0;
}
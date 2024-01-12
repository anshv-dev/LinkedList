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

// Node* removeTail(Node* head){
//   if(head==NULL || head->next==NULL){
//     return NULL;
//   }
//   Node* temp=head;
//   while(temp->next->next!=NULL){
//     temp=temp->next;
//   }
//   free(temp->next);
//   temp->next=nullptr;
//   return head;
// }
Node* removeKposition(Node* head,int k){
  if(head==NULL){
    return head;
  }
  else if(k==1){
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
  }

  int count=0;
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    count++;
    if(count==k){
      prev->next=prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp=temp->next;
  }
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
// head=removeTail(head);
int k=2;
head=removeKposition(head,k);
print(head);
return 0;
}
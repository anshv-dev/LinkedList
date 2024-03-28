#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* back;

  public:
  Node(int data1,Node* next1,Node* back1){
    data=data1;
    next=next1;
    back=back1;
  }

  public:
  Node(int data1){
    data=data1;
    next=nullptr;
    back=nullptr;
  }
};

Node* convertArrtoLinked(vector<int> &v){
    Node* head=new Node(v[0]);
    Node* prev=head;
    for(int i=1;i<v.size();i++){
      Node* temp=new Node(v[i],nullptr,prev);
      prev->next=temp;
      prev=temp; 
    }
    return head;
}


void print(Node* head){
    while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
    }
}

void deleteNode(Node* temp){
  Node* prev=temp->back;
  Node* front=temp->next;

  if(front==NULL){
    prev->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return;
  }
  prev->next=front;
  front->back=prev;
  temp->next=nullptr;
  temp->back=nullptr;
  free(temp);
}
int main(){
vector<int>v={11,12,45,67,7,56};
Node* head=convertArrtoLinked(v);
deleteNode(head->next->next->next->next);
print(head);
return 0;
}
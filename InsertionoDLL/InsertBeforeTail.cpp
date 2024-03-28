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

Node* InsertBeforeTail(Node* head,int value){
    if(head->next==NULL){
      Node* newNode=new Node(value,head,nullptr);
      return newNode;
    }
    Node* tail=head;
    while(tail->next!=NULL){
      tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(value,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}
int main(){
vector<int>v={11,12,33,44};
Node* head=convertArrtoLinked(v);
head=InsertBeforeTail(head,0);
print(head);
return 0;
}
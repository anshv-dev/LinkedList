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

Node* DeleteHead(Node* head){
  if(head==NULL || head->next==nullptr){
      return NULL;
  } 
  Node* prev=head;
  head=head->next;
  head->back=nullptr;
  prev->next=nullptr;
  free(prev);
  return head;
}
void print(Node* head){
    while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
    }
}
int main(){
vector<int>v={11,12,45,67,7};
Node* head=convertArrtoLinked(v);
head=DeleteHead(head);
print(head);
return 0;
}
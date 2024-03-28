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

Node* DeleteTail(Node* head){
  if(head==NULL || head->next==nullptr){
      return NULL;
  } 
  Node* tail=head;
  while(tail->next!=NULL){
      tail=tail->next;
  }
  Node* prev=tail->back;
  tail->back=nullptr;
  prev->next=nullptr;
  free (tail);

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

Node* DeleteKth(Node* head,int k){
  Node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    if(count==k){
      break;
    }
    temp=temp->next;
  }
  Node* prev=temp->back;
  Node* front=temp->next;

  if(prev==NULL && front==NULL){
    delete temp;
    return head;
  }else if(prev==NULL){
        return DeleteHead(head);
        // return head;
  }else if(front==NULL){
    DeleteTail(head);
    return head;
  }else{
    prev->next=front;  
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;
  }
}
void print(Node* head){
    while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
    }
}
int main(){
vector<int>v={11,12,45,67,7,56};
Node* head=convertArrtoLinked(v);
head=DeleteKth(head,1);
print(head);
return 0;
}
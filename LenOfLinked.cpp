#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  // public:
  // Node(int data1,Node* next1){
  //    data=data1;
  //    next=next1;
  // }

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

int LengthofLinked(Node* head){
  int count=0;
  Node* temp=head;
  while(temp!=NULL){
    temp=temp->next;
    count++;
  }
  return count;
}
int main(){
vector<int>arr={22,5,8,7};
Node* head=convertArr2LL(arr);
cout<<LengthofLinked(head);
return 0;
}
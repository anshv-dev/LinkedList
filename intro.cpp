#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

   public:
   Node(int data1,Node* next1){
     data=data1;
     next=next1;
    }
  public:
  Node(int data1){
    data=data1;
    next=nullptr;
  }
  
};

int main(){
vector<int>arr={2,5,8,7};
Node* y=new Node(arr[0]);
Node* x=new Node(arr[1]);
Node* z=new Node(arr[2]);
Node* a=new Node(arr[3],nullptr);
cout<<y->data<<endl;
cout<<x->data<<endl;
cout<<z->data<<endl;
cout<<a->data;
return 0;
}
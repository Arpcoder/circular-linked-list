#include<bits/stdc++.h>
#include <numeric>
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define all(v) v.begin(),v.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fin(i,n1,n2);for(ll i=n1;i<n2;i++)
#define fde(i,n1,n2);for(ll i=n1;i>n2;i--)
#define M 1000000007
using ll=long long;
using ld=long double;
using namespace std;
//Arpcoder


bool comp(pair <ll,ll> &a,pair <ll,ll> &b)
{
    if(a.first!=b.first)
    return a.first>b.first;
    else return a.second<b.second;
}

class Node
{
   public:
   ll data;
   Node *next;
   
   Node(ll Data)
   {
       data=Data;
       next=NULL;
   }
};

void InsertNode(Node *&tail,ll element,ll d)
{
    if(tail==NULL)
    {
        Node *temp=new Node(d);
        tail=temp;
        temp->next=temp;
        return;
    }
    Node *temp=tail;
    while(temp->data!=element)
    {
        temp=temp->next;
    }
    Node *NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void print(Node *tail)
{
    if(tail==NULL)
    {cout<<"List is empty\n";
    return;}
    
    Node *temp=tail;
    do {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
    cout<<"\n";
}

void DeleteNode(Node *&tail,ll value)
{
    Node *p=tail;
    Node *q=tail->next;
    
    if(p->next==p)
    {
        free(p);
        return;
    }
    
    while(q->data!=value)
    {
        q=q->next;
    }
    p->next=q->next;
    //q->next=NULL;
    free(q);
    
}

int main()
{
    Node *node1=new Node(3);
    Node *tail=node1;  //creating circular ll
    tail->next=tail;
    print(tail);
    InsertNode(tail,3,4);
    print(tail);
    InsertNode(tail,4,5);
    print(tail);
    DeleteNode(tail,4);
    print(tail);
    DeleteNode(tail,5);
    print(tail);
}

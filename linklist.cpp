#include<bits/stdc++.h>
using namespace std;
class LinkedList
{
    public:
    class Node
    {
        public:    
        int data;
        Node *next=nullptr;    
        Node(int data)
        {
            this->data=data;
        }
    };
private:
Node *head=nullptr;
Node *tail=nullptr;
int size;
public:
~LinkedList()
{
    Node *temp=head;
    while(head!=nullptr)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
}
void addlast(int data)
{
    Node *rn= new Node(data);
    if(tail==nullptr)
    {
        head=rn;
        tail=rn;
    }
    else 
    {
        tail->next=rn;
        tail=rn;
    }
    size++;
}
Node *mid()
{
    Node *slow=head;
    Node *fast=head;
    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node *reverse(Node *gu)
{
    Node *pre=nullptr;
    Node *curr=gu;
    Node *forw=nullptr;
    while(curr!=nullptr)
    {
        forw=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forw;
    }
    return pre;
}
void reverse()
{
    Node *rn=reverse(head);
    head=rn;
    tail=head;
}
void display()
{
    Node *rn =head;
    while(rn!=nullptr)
    {
        cout<<rn->data<<" ";
        rn=rn->next;
    }
    cout<<endl;
}
int gett(Node *gn)
{
    return gn->data;
}
void fold()
{
    Node *midi=mid();
    // cout<<gett(midi)<<" ";
    Node *head1=midi->next;
    midi->next=nullptr;
    // cout<<gett(head1)<<" ";
    Node *head11=reverse(head1);
    // while(head11!=nullptr)
    // {
    //     cout<<head11->data<<" ";
    //     head11=head11->next;
    // }
    // cout<<endl;
    Node *fu=head;
    Node *fu1=head11;
    Node *fuu=nullptr;
    Node *fuu1=nullptr;
    while(fu1!=nullptr)
    {
        fuu=fu->next;
        fuu1=fu1->next;
        fu->next=fu1;
        fu1->next=fuu;
        fu=fuu;
        fu1=fuu1;
    }
    if (fu == nullptr)
            tail = head1;
        else
            tail = fu;
}
bool palindrome()
{
    Node *midi=mid();
    Node *head1=midi->next;
    midi->next=nullptr;
    Node *head11=reverse(head1);
    Node *ho=head;
    while(head11!=nullptr)
    {
        if(head11->data!=ho->data)
        {
            return false ;
        }
        head11=head11->next;
        ho=ho->next;
    }
    return true;
}
bool cycle()
{
    Node *slow=head;
    Node *fast=head;
    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
};
int main()
{
    LinkedList ll;
    for(int i=0; i<9; i++)
    {
        ll.addlast(i*2);
    }
    // ll.addlast(1);
    // ll.addlast(2);
    // ll.display();
    // cout<<ll.gett(ll.mid());
    // ll.reverse();
    // ll.display();
    // ll.fold();
    // cout<<ll.gett(ll.mid());
    ll.display();
    // cout<<ll.palindrome();
    cout<<ll.cycle();
}
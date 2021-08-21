#include<bits/stdc++.h>
using namespace std;
class LinkedList
{
    public:
    class Node 
    {
        public:
        int data=0;
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
    void AddfirstNode(Node *n)
    {
        if(head==nullptr)
        {
            head=n;
            tail=n;
        }
        else 
        {
            n->next=head;
            head=n;
        }
        size++;
    }
    void AddLastNode(Node *n)
    {
        if(tail==nullptr)
        {
            head=n;
            tail=n;
        }
        else 
        {
            tail->next=n;
            tail=n;
        }
        size++;
    }
    Node* Remove()
    {
        Node *rn=nullptr;
        if(head!=nullptr)
        {
            if(size==1)
            {
                head=nullptr;
            }
                rn=head;
                head=head->next;
        }
        size--;
        return rn;
    }
    void addData(int data)
    {
        Node *rn = new Node(data);
        AddfirstNode(rn);
    }
    void addLast(int data)
    {
        Node *rn= new Node(data);
        AddLastNode(rn);
    }
    int removeFirst()
    {
        Node *f=Remove();
        if(f==nullptr)
        {
            return -1;
        }
        else 
        {
            return f->data;
        }
    }
    Node *getNode(int idx)
    {
        Node *temp=head;
        if(idx==0)
        {
            return head;
        }
        else 
        {
            while(idx!=0)
            {
                temp=temp->next;
                idx--;
            }
        }
        return temp;
    }
    void addatidx(int data,int idx)
    {
        if(idx>size || idx<0)
        {
            return ;
        }
        else if(idx==0)
        {
            Node *rn=new Node(data);
            AddfirstNode(rn);
            size++;
        }
        else if(idx==size)
        {
            Node *rn=new Node(data);
            AddLastNode(rn);
            size++;
        }
        else 
        {
            Node *p=getNode(idx-1);
            Node *n=p->next;
            Node *ne =new Node(data);
            p->next=ne;
            ne->next=n;
            size++;
        }
    }
    Node *RemoveLast()
    {
        if(size==0)
        {
            return nullptr;
        }
        else if(size==1)
        {
            return head;
            size--;
        }
        else 
        {
            Node *rn=getNode(size-2);
            Node *what=rn->next;
            rn->next=nullptr;
            tail=rn;
            size--;
            return what;
        }
    }
    void removeAt(int idx)
    {
        if(idx<0 || idx > size)
        {
            return;
        }
        else if(idx==0)
        {
            Node *e=Remove();
        }
        else if(idx==size)
        {   
            Node *e=RemoveLast();
        }
        else 
        {
            Node *wo1=getNode(idx-1);
            Node *fr=wo1->next;
            wo1->next=fr->next;
            delete fr;
            size--;
        }   
    }
    Node *mid()
    {
        Node *slow=head;
        Node *fast=head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void display()
    {
        Node *curr =head;
        while(curr!=nullptr)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
    int gettt(Node *n)
    {
        return n->data;
    }
};
int main()
{
    LinkedList ll;
    for(int i=0; i<10 ; i++)
    {   
        ll.addLast(i*10);
    }
    // ll.display();
    ll.addatidx(100,5);
    ll.addData(101);
    ll.removeAt(2);
    ll.removeFirst();
    // cout<<ll.gettt(ll.mid());
    cout<<ll.gettt(ll.getNode(7));
    cout<<endl;
    ll.display();
}
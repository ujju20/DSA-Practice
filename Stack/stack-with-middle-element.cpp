#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class node{
    public:
    int data;
    node* prev;
    node* next;
};
class mstack{
    public:
    node* head;
    node* mid;
    int count;
};

    mstack* createStack()
    {
        mstack* ms=new mstack();
        ms->count=0;
        ms->head=NULL;
        ms->mid=NULL;
        return ms;
    }
    void push(mstack* ms,int data)
    {
        node* newNode=new node();
        newNode->prev=NULL;
        newNode->data=data;
        newNode->next=ms->head;

        ms->count+=1;
        if(ms->count==1)
        {
            ms->mid=newNode;

        }
        else
        {
            ms->head->prev=newNode;
        if(!(ms->count&1))
        {
           ms->mid=ms->mid->prev;
        }
        
        }
        ms->head=newNode;
    }
    int pop(mstack* ms)
    {
        if(ms->count==0)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        node* head=ms->head;
        int item=head->data;
        ms->head=ms->head->next;

        if(ms->head!=NULL)
        {
            ms->head->prev=NULL;
        }

        ms->count-=1;

        if(ms->count&1)
        {
            ms->mid=ms->mid->next;
        }
        return item;
    }

    int findMiddle(mstack* ms)
    {

    if (ms->count == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }
        return ms->mid->data;
    }
    int deleteMiddle(mstack* ms)
    {
        if (ms->count == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }

    node* mid=ms->mid;
    int item=mid->data;
    ms->count--;
    if(ms->count==1)
    {
        ms->head=ms->head->next;
        ms->mid=ms->head;

    }
    else if(ms->count>0)
    {
        ms->mid->prev->next=ms->mid->next;
		ms->mid->next->prev=ms->mid->prev;
		if(ms->count&1)
        {
             ms->mid=ms->mid->next;
        }
        else
        {
            ms->mid=ms->mid->prev;
        }

    }
    return item;

    }
    
int main() {
    mstack* ms = createStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
     push(ms, 66);
    push(ms, 77);
 
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
   cout << "Deleted Middle Element is "<<deleteMiddle(ms)<<endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class heap{
    vector<int> v;
    string heapType;
    bool compare(int i,int j)
    {
        if(heapType=="min")
        {
            if(v[i]<v[j])
            return true;
            return false;

        }
        else
        {
             if(v[i]>v[j])
            return true;
            return false;


        }

    }
    void heapify(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int minIdx=i;
        if(left<v.size() and compare(left,i))
        {
            minIdx=left;

        }
        if(right<v.size() and compare(right,minIdx))
        {
            minIdx=right;

        }
        if(minIdx!=i)
        {
            swap(v[i],v[minIdx]);
            heapify(minIdx);
        }
    }
    public:
    heap(int default_size=10,string s="min")
    {
        v.reserve(default_size);
        v.push_back(-1);
        heapType=s;
    }
    void push(int data)
    {
        v.push_back(data);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and !compare(parent,idx))
        {
            swap(v[parent],v[idx]);
            idx=parent;
            parent=parent/2;
        }
    }
    int top()
    {
        return v[1];
    }
    int pop()
    {
        int idx=v.size()-1;
        swap(v[1],v[idx]);
        int data=v[idx];
        v.pop_back();
        heapify(1);
        return data;

    }
};
int main() {
    heap h(20,"min");
    h.push(1);
    h.push(10);
    h.push(9);
    h.push(3);
    h.push(5);
    h.push(11);

    cout<<h.pop()<<" "<<h.pop()<<" "<<h.top();
    return 0;
}

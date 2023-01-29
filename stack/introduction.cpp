#include <iostream>
#include<vector>

using namespace std;

class stack{
    
    public:
        //properties
        int *arr;
        int top;
        int size;
        
        //behaviour
        stack(int size){
            this->size=size;
            arr=new int[size];
            top=-1;
        }
        
        void push(int data){
            if(top+1==size){
                cout<<"stack overflow\n";
                return;
            }
            
            top++;
            arr[top]=data;
        }
        
        void pop(){
            if(top==-1){
                cout<<"No element present to pop\n";
                return;
            }
            
            top--;
        }
        
        int peek(){
            if(top==-1){
                cout<<"stack is empty\n";
                cout<<"size:";
            }
            cout<<"top element:";
            return arr[top];
        }
        
        bool isEmpty(){
            if(top==-1)return true;
            else return false;
        }
    
};

int main()
{
    stack* st=new stack(2);
    st->push(5);
    st->push(4);
    st->push(3);
    cout<<st->peek()<<"\n";
    
    
    stack s(3);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<s.peek()<<"\n";
    
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<"\n";
    
    return 0;
}

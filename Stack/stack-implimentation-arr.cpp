#include <iostream>
using namespace std ;
class stack{
    private:
        int top;
        int capacity;
        int* arr;
    public:
        stack(int size){
            this->capacity =size;
            this->top = -1;
            this->arr = new int[capacity];
        }

        void push(int data){
            top++;
            if(top >capacity){
                cout<<"Stack Overflow";
                return;
            }
            arr[top] = data;
        }
        void pop(){
            if(top == -1){
                cout<<"Stack Underflow";
                return;
            }
            top --;
        }
        int peek(){
            if(top == -1){
                cout<<"Stack Underflow";
                return -1;
            }
            return arr[top];
        }
        int size(){
            return top+1;
        }
        bool isEmpty(){
            if(top >= 0){
                return 0;
            }
            return 1;
        }

};

int main()
{
    //Creation of stack
    stack s1(5);

    // Push operation
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    

    // Pop operation
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    //Peek element
    cout<<"Top element of stack is: "<<s1.peek()<<"\n";

    //Checking if stack is empty or not
    if(s1.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    // Size
    cout<<"size of stack is: "<<s1.size()<<endl;
    return 0;
}
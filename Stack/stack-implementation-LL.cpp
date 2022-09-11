#include<iostream>
using namespace std;
class stack{
    private:
        int data;
        stack* next;
    public:
        stack(int data){
            this->data = data;
            this->next = NULL;
        }
        void push(stack* &head, stack* &tail, int data){
            stack *n1 = new stack(data);
            if(head == NULL){
                head = n1;
                tail = n1;
                return;
            }
            tail->next = n1;
            tail = n1;
        }
        
        void pop(stack* &head, stack* &tail){
            if(head == NULL){
                cout << "stack Underflow";
                return;
            }
            stack* temp1 = head;
            stack* temp2 = NULL;
            while(temp1->next != NULL){
                temp2 = temp1;
                temp1 = temp1->next;
            }
            if(temp2){
                temp2->next = NULL;
                delete temp1;
                tail = temp2;
                return;
            }
            head = NULL;
            tail =NULL;
            delete temp1;
        }

        int peek(stack* head, stack* tail){
            if(head == NULL){
                cout<<"stack underflow";
                return -1;
            }
            return tail->data;
        }

        int size(stack* head, stack* tail){
            int size = 0;
            if(head ==  NULL){
                return size;
            }
            stack* temp = head;
            while(temp != NULL){
                size++;
                temp =temp->next;
            }
            return size;
        }

        bool isEmpty(stack* head, stack* tail){
            if(head == NULL){
                return 1;
            }
            return 0;
        }
};

int main()
{
    //Creation of stack
    stack* head = NULL;
    stack* tail = NULL;
    stack s1(5);

    //Push operation
    s1.push(head,tail,10);
    s1.push(head,tail,20);
    s1.push(head,tail,30);
    s1.push(head,tail,40);
    s1.push(head,tail,50);


    //Pop operation
    s1.pop(head,tail);
    s1.pop(head,tail);
    s1.pop(head,tail);


    //Peek 
    cout<<s1.peek(head,tail)<<endl;

    //SIZE
    cout<<s1.size(head,tail)<<endl;

    //Empty or not
    if(s1.isEmpty(head,tail)){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}

class TwoStack {
private:
    int top1;
    int top2;
    int *arr;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->top1 = -1;
        this->top2 = s;
        this->arr = new int[s];
        this->size = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        //Check if there is at least one space left in stack;
        if((top2 - top1) >1){
            top1++;
            arr[top1] = num;
        }
        else{
            //Stack overflow
        }
    }

    // Push in stack 2.
    void push2(int num) {
       if((top2 - top1) >1){
            top2--;
            arr[top2] = num;
        }
        else{
            //Stack overflow
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 > -1){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            //Underflow
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            //Underflow
            return -1;
        }
    }
};

#include <bits/stdc++.h>
using namespace std;
class ArrayADT
{
private:
    int capacity, lastindex;
    int *arr;

public:
    ArrayADT(int cap)
    {
        this->capacity = cap;
        this->lastindex = -1;
        this->arr = new int[cap];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }
    void append(int data)
    {
        if (this->lastindex == this->capacity - 1)
        {
            cout << "\n⚠️Overflow⚠️\n";
        }
        else
        {
            this->lastindex++;
            this->arr[this->lastindex] = data;
        }
    }
    void insert(int index, int data)
    {
        if (index < 0 || index > this->lastindex + 1)
        {
            cout << "\n⚠️Invalid index⚠️\n";
        }
        else if (this->lastindex == this->capacity - 1)
        {
            cout << "\n⚠️Overflow⚠️\n";
        }
        else
        {
            for (int i = this->lastindex; i >= index; --i)
            {
                this->arr[i + 1] = this->arr[i];
            }
            this->arr[index] = data;
            this->lastindex++;
        }
    }
    void display()
    {

        cout << "\nThis is your array\n";
        for (int i = 0; i < this->capacity; i++)
            cout <<"| "<<this->arr[i]<<" ";
        cout<<"|";
    }
    int count()
    {
        return (this->lastindex + 1);
    }
    void deletion(int index)
    {
        if (this->lastindex == -1)
        {
            cout << "\n⚠️Under flow cannot delete⚠️\n";
        }
        else
        {
            for (int i = index + 1; i < this->capacity; i++)
            {
                this->arr[i - 1] = this->arr[i];
            }
            this->lastindex--;
            this->arr[this->capacity - 1] = -1;
        }
    }
    int getdata(int index)
    {
        if (index > this->lastindex)
        {
            cout << "\n⚠️Invalid Index⚠️";
            return -1;
        }
        else
            return (this->arr[index]);
    }
    void edit(int index, int newvalue)
    {
        if (index > this->lastindex)
        {
            cout<<"\n⚠️Invalid Index⚠️";
        }
        else
        {
            this->arr[index] = newvalue;
        }
    }
};

int main()
{
    ArrayADT arr(5);
    // Append elements
    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);
    arr.append(50);
    arr.append(50);

    // Display whole array
    arr.display();
    cout<<arr.count()<<endl;

    //Delete element
    arr.deletion(1);
    arr.display();
    cout<<arr.count()<<endl;

    //Get data
    cout<<arr.getdata(2);

    // Edit
    arr.edit(2,100);
    arr.display();
    cout<<arr.count()<<endl;
}

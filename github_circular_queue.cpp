#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef class circular_queue
{
    int fornt;
    int rear;
    int capacity;
    int *arr;
public:
    void creat(int key)
    {
        fornt=0;
        rear=-1;
        capacity=key;
        arr= new int[capacity];
    }
    int isfull()
    {
        if(rear==capacity-1 && fornt==0)
            return 1;
        else
            return 0;
    }
    int isempty()
    {
       if(fornt==0  &&  rear==-1)
          return 1;
       else
          return 0; 
    }
    void enqueue(int data)
    {
        if(isfull())
        {
            cout<<"queue is full"<<endl;
            getch();
            return ;
        }
        rear=((rear%capacity)+1);
        arr[rear]=data;
    }
    void dequeue()
    {
       if(isempty())
    {
      cout<<"queue is empty ?"<<endl;
      getch();
      return ;
    }
        fornt=((fornt%capacity)+1);
    }
    void display() 
    {
        for(int i=fornt; i<=rear; i++)
        {
            cout<<" "<<arr[i];
        }
        getch();
    }
} queue_;
int main()
{
    int cmd,data,capacity;
    queue_ q1;
    while(1)
    {
        clrscr();
        cout<<"+---------------------------------+"<<endl;
        cout<<"|       [~circular queue~]        |"<<endl;        
        cout<<"+---------------------------------+"<<endl;
        cout<<"1.creat queue"<<endl;
        cout<<"2.insert the data"<<endl;
        cout<<"3.delete the data"<<endl;
        cout<<"4.display"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter the command ==>>"<<endl;
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            cout<<"enter the capacity=>>"<<endl;
            cin>>capacity;
            q1.creat(capacity);
            break;
        case 2:
            cout<<"enter the data=>"<<endl;
            cin>>data;
            q1.enqueue(data);
            break;
        case 3:
            q1.dequeue();
            break;
        case 4:
            q1.display();
            break;
        case 5:
            return 0;
            break;
        default:
            cout<<"command is not found ?"<<endl;
            break;
        }
        getch();
    }
    return 0;
}

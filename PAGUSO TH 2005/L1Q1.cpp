#include <iostream>

using namespace std;

class STACK{

    public:

    int top;
    int *stack;

    STACK(){
        top =0;
    }
    STACK(int size){
        top =0;
        stack = new int[size];
        
        for(int i=0; i<size;i++){
            stack[i]= 0;
        }
    }

    void insert(int n){
        stack[top] = n;
        top++;
    }

    int pop(){
        
        return stack[--top];
    }
    
    int print(){
        cout<<endl<<"PRINTING STACK:"<<endl<<endl;
        
        for(int i=0; i<top; i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }

    int operator[](int n){
        return(*(stack+n));
    }

    ~STACK(){
        delete[] stack;
    }
};



class QUEUE{

    public:

    int front;
    int rear;
    int size;
    int *queue;

    QUEUE(){
        front =0;
        rear =0; 
        size =0;
    }

    QUEUE(int n){
        front =0;
        rear =0;
        size=0;
        queue = new int[n];
    }
    

    void enqueue(int n){

        rear = front+size;
        queue[rear] = n;
        size++;
    }

    int dequeue(){
        int x=queue[front];
        front++;
        size--;
        return x;
    }

    int operator[](int n){
        return(*(queue+n));
    }
    
    int print(){
        cout<<endl<<"PRINTING QUEUE:"<<endl<<endl;
        
        for(int i=0; i<size; i++){
            cout<<queue[front+i]<<" ";
        }
        cout<<endl;
    }

    ~QUEUE(){
        delete[] queue;
    }
};



int main(){

    int cases =0;

    cin>>cases;

    for(int i=0; i<cases; i++){


        int operations = 0;

        cin>>operations;


        int del =0, insert =0,moves=0,numbers=0;

        bool stack = true, queue = true;
        
        STACK my_stack(operations);
        QUEUE my_queue(operations);
        
        for(int j=0; j<operations; j++){

            

            cin>>moves>>numbers;
            
            if(moves==1){

                my_stack.insert(numbers);
                my_queue.enqueue(numbers);
                
            }

            else if(moves==2){
                int a=0;
                if((a=my_stack.pop())!=numbers){
                    stack = false;
                    //cout<<a<<" popped "<<"number = "<<numbers<<endl;
                }
                //cout<<"queue before ="<<queue<<endl;
                if((a=my_queue.dequeue())!=numbers){
                    queue = false;
                    //cout<<a<<" dequeued "<<"number = "<<numbers<<endl;
                }
                
                //else{
                    //cout<<a<<" dequeued "<<"number = "<<numbers<<endl;
                //}
                //cout<<"queue later ="<<queue<<endl;
            }
            
            //my_stack.print();
            //my_queue.print();

        }

        cout<<"caso "<<(i+1)<<": ";

        if(stack && queue){
            cout<<"ambas"<<endl;
        }
        else if(stack && !queue){
            cout<<"pilha"<<endl;
        }
        else if(queue && !stack){
            cout<<"fila"<<endl;
        }
        else{
            cout<<"nenhuma"<<endl;
        }
        


    }

}
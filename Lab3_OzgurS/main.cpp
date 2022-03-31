#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node * next;

    Node(int x, Node * n){
        data = x;
        next = n;
    }
};

int elements;

class Stack {
    int maximum;

private:
    Node * top;

public:
    Stack(int x) {

        top = NULL;
        maximum = x;
    }

    void push(int data) {
        Node * temp = new Node(data, NULL);

        if (!top) {
            top = temp;

        } else{
            temp->data = data;
            temp->next = top;
            top = temp;
            elements += 1;
        }
    }

    bool isEmpty() {
        return false;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    void pop() {
        Node * temp;

        if (top == NULL) {

            cout << "\nStack Underflow" << endl;
            exit(1);
        } else{

            temp = top;
            top = top->next;
            cout<< "You Poped" << temp->data <<endl;
            free(temp);
        }
        elements -=1;
    }
    Node * getTop(){

        if(!top){
            cout << "\nStack Overflow";
            return NULL;
        }
        return top;
    }
    int size(){
        return elements;
    }
    void display(){

        Node * temp;
        if (top == NULL){

            cout << "\nStack Underflow";
            exit(1);
        } else{

            temp = top;
            while (temp != NULL){

                cout << temp->data << "-> ";
                temp = temp->next;
            }
        }
    }
};

int main(){

    Stack * stack = new Stack(7);
    stack->push(20);
    stack->push(44);
    stack->push(95);
    stack ->pop();
    stack->push(97);
    stack->display();

    cout << "\nTop element is "
         << stack->peek() << endl;
    return 0;
};
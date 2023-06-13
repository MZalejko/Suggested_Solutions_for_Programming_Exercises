#ifndef QUEUETP_HXX // samemu napisać
#define QUEUETP_HXX

#include "worker.hxx"
#include <cstdlib>
#define Q_SIZE 10

template <typename T>

class QueueTp{

    private:
        struct Node{T item; Node* next;};
        enum{sizeOfQ = Q_SIZE};
        Node* front;
        Node* rear;
        int numOfItems;
        const int queueSize;
        QueueTp(const QueueTp<T>& newQue) : numOfItems(DEFVALUE){};
        QueueTp<T>& operator=(const QueueTp<T>& newQue) {return *this;};
    
    public:
        explicit QueueTp(int qSize = sizeOfQ);
        ~QueueTp();
        bool isEmpty() const;
        bool isFull() const;
        int queueCount() const;
        bool enqueue(const T& item);
        bool dequeue(T& item);

};

template <typename T>

QueueTp<T>::QueueTp(int qSize) : queueSize(qSize){
    
    front = rear = nullptr;
    numOfItems = DEFVALUE;

}

template <typename T>

QueueTp<T>::~QueueTp(){
    
    Node* temp;
    
    while(front != nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>

bool QueueTp<T>::isEmpty() const{

    return numOfItems == DEFVALUE;
}

template <typename T>

bool QueueTp<T>::isFull() const{

    return numOfItems == queueSize;


}

template <typename T>

int QueueTp<T>::queueCount() const{
    
    return numOfItems;

}

template <typename T>

bool QueueTp<T>::enqueue(const T& item){

    if(isFull()) {return false;}

    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    numOfItems++;

    if(front == nullptr) {front = add;}
    else {rear->next = add;}
    rear = add;
    return true;

}

template <typename T>

bool QueueTp<T>::dequeue(T& item){

    if(front == nullptr) {return false;}
    
    item = front->item;
    numOfItems--;
    Node* temp = front;
    front = front->next;
    delete temp;

    if(isEmpty()){rear = nullptr;}
    return true;
}

#endif //QUEUETP_HXX
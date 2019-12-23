typedef struct {
    int* _a;
    int  _n;
    int _front;
    int _rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->_a = (int*)malloc(sizeof(int)*(k+1));
    cq->_n = k+1;
    cq->_front = cq->_rear = 0;

    return cq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    
    obj->_a[obj->_rear] = value;
    obj->_rear++;

    //obj->_rear %= obj->_n;
    if(obj->_rear == obj->_n)
        obj->_rear = 0;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    
    ++obj->_front;
    //obj->_rear %= obj->_n;
    if(obj->_rear == obj->_n)
        obj->_rear = 0;
    
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return obj->_a[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
      if(myCircularQueueIsEmpty(obj))
        return -1;
        
    int prevRear = obj->_rear-1;
    if(obj->_rear == 0)
        prevRear = obj->_n-1;

    return obj->_a[prevRear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->_front == obj->_rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int nextRear = obj->_rear+1;
    nextRear %= obj->_n;

    return nextRear == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
     free(obj->_a);
     free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

// ��ȯ ť �����.
class MyCircularQueue {
public:
    int head, tail;
    vector<int> q;
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0, tail = -1;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        tail = (tail + 1) % q.size();
        q[tail] = value;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail)    head = 0, tail = -1;
        else {
            head = (head + 1) % q.size();
        }
        return true;
    }

    int Front() {
        if (isEmpty())    return -1;
        return q[head];
    }

    int Rear() {
        if (isEmpty())    return -1;
        return q[tail];
    }

    bool isEmpty() {
        return tail == -1;
    }

    bool isFull() {
        return !isEmpty() && (tail + 1) % q.size() == head;

    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// ������ �迭�� ������ ũ�Ⱑ �־����� �����̵� �����쿡 �ִ� ��� ������ ����� ����Ѵ�.
class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {
        if (q.size() >= size) {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;
        }
        else {
            sum += val;
            q.push(val);
        }
        double result = 1.0 * sum / q.size();
        return result;
    }
private:
    queue<int> q;
    int size, sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// ���� ����
// ���� ������ �ּڰ� ã��
// �ð����⵵ O(1) �ȿ� ��� ��� �����ϱ�.
// �ּڰ��� �����ϴ� ������ �ϳ� �� ����
// �ּڰ��� ���� �ּڰ��� ������ �Բ� ����ϴ� ������� �ذ���
class MinStack {
public:
    MinStack() {
    }

    void push(int val) {

        if (main.empty() || val < min.top()[0]) {
            min.push({ val, 1 });
        }

        else if (val == min.top()[0]) {
            min.top()[1]++;
        }

        main.push(val);
    }

    void pop() {
        if (main.empty())   return;
        if (main.top() == min.top()[0])  min.top()[1]--;
        if (min.top()[1] <= 0)   min.pop();
        main.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return min.top()[0];
    }
private:
    stack<int> main;
    stack<vector<int>> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
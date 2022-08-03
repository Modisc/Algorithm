// 스택 구현
// 현재 스택의 최솟값 찾기
// 시간복잡도 O(1) 안에 모든 기능 구현하기.
// 최솟값을 추적하는 스택을 하나 더 만들어서
// 최솟값과 현재 최솟값의 개수를 함께 기록하는 방식으로 해결함
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
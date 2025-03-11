class MyStack {
public:
    MyStack() {
    }
    void push(int x) {
        temporaryQueue.push(x);
        while (!mainQueue.empty()) {
            temporaryQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        swap(mainQueue, temporaryQueue);
    }
    int pop() {
        int topElement = mainQueue.front(); 
        mainQueue.pop(); 
        return topElement;
    }
    int top() {
        return mainQueue.front(); 
    }
    bool empty() {
        return mainQueue.empty(); 
    }

private:
    queue<int> mainQueue;    
    queue<int> temporaryQueue;
};

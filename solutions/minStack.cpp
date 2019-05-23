#include "comm_header.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vec.clear();
        min.clear();
    }
    
    void push(int x) {
        vec.push_back(x);
        int x_idx = vec.size() - 1;
        if (min.size() == 0)
            min.push_back(x_idx);
        else
        {
            int min_idx = min[min.size() - 1];
            if (x < vec[min_idx])
                min.push_back(x_idx);
            else
                min.push_back(min_idx);
        }
    }
    
    void pop() {
        vec.pop_back();
        min.pop_back();
    }
    
    int top() {
        return vec[vec.size() - 1];
    }
    
    int getMin() {
        return vec[min[min.size() - 1]];
    }
    
private:
    vector<int> vec;
    vector<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    return 0;
}
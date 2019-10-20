/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/



#if 0

//方法一：用两个栈实现，一个存储数据，另一个栈存储最小值，
//当然，两个栈不必同步，只有当元素栈中出栈的值和最小值栈中的栈顶元素相等时，才出栈最小栈栈顶元素
//                    同理，只有当元素栈中将要入栈的元素小于最小值栈中的栈顶元素时，才对最小值栈进行入栈操作
class MinStack
{
public:
    MinStack()
    {}
    
    void push(int x)
    {
        index.push(x);
        if(min.empty() || x <= min.top())
        {
            min.push(x);
        }
    }
    void pop()
    {
        if(index.top() == min.top())
        {
            min.pop();
        }
        index.pop();
    }
    int top()
    {
        return index.top();
    }
    int getMin()
    {
        return min.top();
    }
    
private:
    std::stack<int> index;
    std::stack<int> min;
};

#endif


//方法二：用一个栈实现，每次入栈或出栈都为对两个元素的操作
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty())
        {
            s.push(x);
            s.push(x);
        }
        else
        {
            int min = s.top();
            s.push(x);
            if(min < x)
            {
                s.push(min);
            }
            else
            {
                s.push(x);
            }
        }
    }
    
    void pop() {
        if(!s.empty())
        {
            s.pop();
            s.pop();
        }
    }
    
    int top() {
            int min = s.top();
            s.pop();
            int top = s.top();
            s.push(min);
            return top;
    }
    
    int getMin() {
        return s.top();
    }
private:
    std::stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
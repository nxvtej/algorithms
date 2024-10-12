class MinStack
{
public:
    stack<int> st;
    stack<int> mins;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.size() == 0)
        {
            st.push(val);
            mins.push(val);
            return;
        }

        st.push(val);
        int temp = min(val, mins.top());
        mins.push(temp);
    }

    void pop()
    {
        st.pop();
        mins.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
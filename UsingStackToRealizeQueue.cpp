class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			temp.push(s.top());
			s.pop();
		}
		int ret = temp.top();
		temp.pop();
		for (int i = 0; i < len - 1; ++i)
		{
			s.push(temp.top());
			temp.pop();
		}
		return ret;
	}

	/** Get the front element. */
	int peek() {
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			temp.push(s.top());
			s.pop();
		}
		int ret = temp.top();
		for (int i = 0; i < len; ++i)
		{
			s.push(temp.top());
			temp.pop();
		}
		return ret;
	}


	/** Returns whether the queue is empty. */
	bool empty() {
		return s.empty();
	}

	std::stack<int> s;
	std::stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

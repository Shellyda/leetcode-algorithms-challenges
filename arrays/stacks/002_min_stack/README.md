# Min Stack

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/min-stack/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

```cpp
    stack minStk
    stack stkNormal

    push(val):
        stkNormal.push(val)
        if val < minStk.top() or minStk.isEmpty():
            minStk.push(val)

    pop():
      if minStk.top() == stkNormal.top():
          minStk.pop()

      stkNormal.pop()

    top():
      stkNormal.top()

    getMin():
        return minStk.top()
```

## ✅ Solution

```cpp
class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {}

    void push(int val) {
        stk.push(val);

        if(minStk.empty() || val <= minStk.top()){
            minStk.push(val);
        }
    }

    void pop() {
        if(stk.top() == minStk.top()){
            minStk.pop();
        }
        stk.pop();

    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
```

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack <NestedInteger> itr;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int s = nestedList.size();
        for (int i = s-1; i >= 0; --i) {
            itr.push(nestedList[i]);
        }
    }

    int next() {
        int r = itr.top().getInteger();
        itr.pop();
        return r;
    }
    
    bool hasNext() {
        while(!itr.empty()) {
            NestedInteger curr = itr.top();
            if (curr.isInteger()) {
                return true;
            }
            
            itr.pop();
            vector <NestedInteger> &list = curr.getList();
            int s = list.size();
            for (int i = s-1; i >= 0; --i) {
                itr.push(list[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
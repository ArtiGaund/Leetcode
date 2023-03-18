class BrowserHistory {
public:
    stack<string> history,future;
    string cur;
    BrowserHistory(string homepage) {
        cur=homepage;
    }
    
    void visit(string url) {
        history.push(cur);
        cur=url;
        future=stack<string>();
    }
    
    string back(int steps) {
        while(steps>0 and !history.empty())
        {
            future.push(cur);
            cur=history.top();
            history.pop();
            steps--;
        }
        return cur;
    }
    
    string forward(int steps) {
        while(steps>0 and !future.empty())
        {
            history.push(cur);
            cur=future.top();
            future.pop();
            steps--;
        }
        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
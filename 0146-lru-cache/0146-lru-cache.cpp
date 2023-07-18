class Node
{
    public:
    int key,val;
    Node *prev,*next;
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
    }
};
class LRUCache {
public:
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode)
    {
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *node)
    {
        Node *prevv=node->prev;
        Node *nextt=node->next;
        prevv->next=nextt;
        nextt->prev=prevv;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node *res=mp[key];
            int ans=res->val;
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *cur=mp[key];
            mp.erase(key);
            deleteNode(cur);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
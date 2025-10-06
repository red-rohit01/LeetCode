// head->next will always be pointing to the least Recently used key.
class LRUCache {
public:
    class list{
    public:
    int key;
    int val;
    list* next;
    list* prev;
    list(int k_val,int v_val)
    {
        key=k_val;
        val=v_val;
        next=NULL;
        prev=NULL;
    }
 };

    list* head=new list(-1,-1);
    list* tail=new list(-1,-1);
    unordered_map<int,list*>mp;
    int sz=0;

    void addnode(list* newnode) {
        list* temp=head->next;
        newnode->next=temp;
        newnode-> prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void deletenode(list* delnode) {
        list* delprev=delnode->prev;
        list* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        // delete(node);    // I should not use 'delete' here as in get and put function, first delete is getting called and for the same node
        // then addNode is getting called. so, If I delete it here, the 'node' will be lost.
    }

    LRUCache(int capacity) {
        sz=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        auto temp=mp[key];
        int res=temp->val;
        mp.erase(key);
        deletenode(temp);
        addnode(temp);
        mp[key]=head->next;    // update the address corresponding to the key
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) 
        {
            list* existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==sz) 
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new list(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
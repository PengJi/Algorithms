/**
 * 146. LRU缓存机制
 * 
 * https://leetcode-cn.com/problems/lru-cache/
 */

struct DListNode {
    int key, value;
    DListNode* prev;
    DListNode* next;
    DListNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DListNode(int k ,int v): key(k), value(v), prev(nullptr), next(nullptr) {}
}

class LRUCache {
private:
    unordered_map<int, DListNode*> cache;
    int size, cap;
    DListNode *head, *tail;

public:
    LRUCache(int capacity): cap(capacity), size(0) {
        // 创建链表
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // key不存在
        if(!cache.count(key)) return -1;

        // key存在
        DListNode* node = cache[key];
        moveToHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        DListNode* node;
        if(!cache.count(key)) {  // key不存在
            node = new DListNode(key, value);

            // 添加到哈希表和链表
            cache[key] = node;
            addToHead(node);
            size++;

            // 判断容量
            if(size > cap) {
                // 超出容量，则删除队尾节点
                node = removeTail();
                cache.erase(node->key);
                size--;
                delete node;
            }
        } else {  // key存在
            // 更新值
            node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DListNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DListNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DListNode* removeTail() {
        DListNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

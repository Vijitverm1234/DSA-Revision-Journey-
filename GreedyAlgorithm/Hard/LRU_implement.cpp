class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val): key(key),val(val),prev(NULL), next(NULL){}
};
class LRUCache {
private:
   void remove(Node* node){
      Node* prevnode=node->prev;
      Node* nextnode=node->next;
      prevnode->next=nextnode;
      nextnode->prev=prevnode;
   }
   void insert(Node* node){
    Node* temp=oldest->next;
    oldest->next=node;
    node->prev=oldest;
    node->next=temp;
    temp->prev=node;
   }
public:
   int cap;
   map<int,Node*>mapp;
   Node* oldest;
   Node* latest;
    LRUCache(int capacity) {
        cap=capacity;
        oldest=new Node(0,0);
        latest=new Node(0,0);
        oldest->next=latest;
        latest->prev=oldest;
    }
    
    int get(int key) {
       if(mapp.find(key)==mapp.end()){
        return -1;
       } 
       else{
        Node* curr=mapp[key];
        remove(curr);
        insert(curr);
        return curr->val;
       }
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            Node* curr=mapp[key];
            curr->val=value;
            remove(curr);
            insert(curr);
        }
        else{
            Node* newNode=new Node(key,value);
            if(mapp.size()==cap){
                Node* tnode=latest->prev;
                mapp.erase(tnode->key);
                remove(tnode);
                insert(newNode);
                mapp[key]=newNode;
                delete tnode;
            }
            else
            {
                insert(newNode);
                mapp[key]=newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
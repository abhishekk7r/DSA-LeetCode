class Node{
    int key;
    int value;
    Node next;
    Node prev;

    public Node(int key, int value){
        this.key = key;
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    private HashMap<Integer, Node> cache;
    private int size;
    private Node left;
    private Node right;

    public LRUCache(int capacity) {
        this.size = capacity;
        this.cache = new HashMap<>();
        this.left = new Node(0, 0);
        this.right = new Node(0, 0);
        this.left.next = right;
        this.right.prev = left;
    }
    
    public int get(int key) {
        if(cache.containsKey(key)){
            Node node = cache.get(key);
            remove(node);
            insert(node);
            return node.value;
        }

        return -1;
    }
    
    public void put(int key, int value) {
        Node node = new Node(key, value);

        if(cache.containsKey(key)){
            Node toRemove = cache.get(key);
            remove(toRemove);
        }

        cache.put(key, node);
        insert(node);

        if(cache.size() > size){
            Node lru = this.left.next;;
            remove(lru);
            cache.remove(lru.key);
        }
        
    }

    private void insert(Node node){
        Node prev = this.right.prev;
        prev.next = node;
        node.prev = prev;
        node.next = this.right;
        this.right.prev = node;
    }

    private void remove(Node node){
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev = prev;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T> class LinkList{
	
    public :
    template <typename N> class Node {
    public :
    	Node<N> *next;
    	N data;
    	Node(N t):data(t),next(nullptr){}
	};
    Node<T> *head;
    LinkList():head(nullptr){}
    LinkList(LinkList &ll){
        if (ll.head == nullptr){
            head = nullptr;
            return;
        }
        try{
            head = new Node<T>(ll.head ->data);
            
        }catch(std::bad_alloc ex){
            throw ex;
        }
        auto curr = ll.head -> next;
        auto tail = head;
        while(curr !=nullptr){
            tail->next = new Node<T>(curr->data);
            tail = tail -> next;
            curr = curr->next;
        }
    }
    ~LinkList(){
        auto curr = head;
        while (head != nullptr){
            head = head -> next;
            delete curr;
            curr = head;
        }
    }
    
    template<typename N> class iterator : public std::iterator<std::forward_iterator_tag, T>{
        Node<N>* node;
    public:
        iterator(Node<N>* head):node(head){}
        iterator operator=(const iterator &itr){
            node = itr.node;
            return *this;
        }
        iterator operator++(){
            node = node->next;
            return *this;
        }
        N& operator*(){
            return node->data;
        }
        bool operator!=(const iterator &ni){
            if (node == nullptr && ni.node == nullptr)
                return false;
            else
                return true;
        }
        bool operator==(const iterator &ni){
            if (node->data == ni.data)
                return true;
            else
                return false;
        }
    };
    
    void add_begin(T t){
        try{
            auto new_node = new Node<T>(t);
            new_node -> next = head;
            head = new_node;
        }
        catch(std::bad_alloc ex){
            throw ex;
        }
    }
    
    void add_end(T t){
        auto curr = head;
        while(curr -> next != nullptr)
            curr = curr-> next;
        try{
            auto new_node = new Node<T>(t);
            curr -> next = new_node;
        }
        catch(std::bad_alloc ex){
            throw ex;
        }
    }
    
    void traverse(){
        auto curr = head;
        while(curr != nullptr){
            try{
                std::cout << curr -> data << " ";
                curr = curr -> next;
            }
            catch(...){}
        }
        std::cout << std::endl;
    }
    
    void delete_begin(){
        if(head == nullptr)
            return;
        if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto curr = head;
        head = head -> next;
        delete curr;
    }
    
    void delete_end(){
        if(head == nullptr)
            return;
        if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto curr = head;
        auto prev = head;
        while(prev-> next != nullptr){
            if(curr -> next != nullptr)
                curr = curr -> next;
            if(curr -> next == nullptr){
                delete curr;
                prev -> next = nullptr;
                continue;
            }
            prev = prev -> next;
        }
    }
    
    void reverse(){
        if(head == nullptr || head -> next == nullptr)
            return;
        auto curr = head;
        Node<T>* prev = nullptr;
        Node<T>* ahead = nullptr;
        
        while(curr != nullptr){
            ahead = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr= ahead;
        }
        head = prev;
    }
    
    void operator+= (LinkList<T> &ll){
        if(ll.head == nullptr){
            return;
        }
        if(head == nullptr){
            head = (new LinkList(ll)) -> head;
        }
        auto curr = head;
        while(curr -> next != nullptr)
            curr = curr -> next;
        curr -> next = (new LinkList(ll)) -> head;
    }
    
    void concatenate(LinkList<T> &ll){
        operator+=(ll);
    }
    
    iterator<T> begin(){
        return iterator<T>(head);
    }
    
    iterator<T> end(){
        return iterator<T>(nullptr);
    }
};

int main() {
    LinkList<int> ll;
    for(int i = 100; i > 0; i --)
        ll.add_begin(i);
    for(int i = 100; i < 150; i ++)
        ll.add_end(i);
    ll.traverse();
    for(int i = 0; i < 149; i ++)
        ll.delete_end();
    ll.traverse();
    for(int i = 2; i < 100; i ++)
        ll.add_begin(i);
    ll.reverse();
    ll.traverse();
    LinkList<int> ll2;
    ll2.add_begin(100);
    ll2.add_begin(101);
    ll2.add_begin(102);
    ll2.add_begin(103);
    ll2.traverse();
    ll += ll2;
    for(auto i: ll)
        std::cout << i << " ";
    auto itr = std::find(ll.begin(), ll.end(), 28);
    auto found = ll.end();
    if(itr != found)
        std::cout << *itr;
    return 0;
}
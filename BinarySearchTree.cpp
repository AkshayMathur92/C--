#include <iostream>
#include <stack>
#include <queue>

template <typename T> class BinarySearchTree{
	template <typename N> class Node{
	public:
		Node<N>* left;
		Node<N>* right;
		Node<N>* parent;
		N key;
		Node(N key):key(key),left(nullptr),right(nullptr),parent(nullptr){}
	};
	Node<T>* root;
public:
	BinarySearchTree():root(nullptr){}
	~BinarySearchTree(){
		std::stack<Node<T>*> first;
		std::stack<Node<T>*> second;
		first.push(root);
		while(!first.empty()){
			auto itr = first.top();
			first.pop();
			second.push(itr);
			if(itr -> left != nullptr)
				first.push(itr -> left);
			if(itr -> right != nullptr)
				first.push(itr -> right);
		}
		while(!second.empty()){
			auto itr = second.top();
			second.pop();
			delete itr;
		}
	}
	static const Node<T>* inordersuccessor(const Node<T>* root){
		if(root == nullptr || (root -> parent == nullptr && root -> right == nullptr))
			return nullptr;
		if(root->right != nullptr){
			return BinarySearchTree::min_node(root->right);
		}
		else{
			auto parent = root -> parent;
			while(parent != nullptr && root == parent -> right){
				root = parent;
				parent = parent -> parent;
			}
			return parent;
		}
	}
	static const Node<T>* inorderpredecessor(const Node<T>* root){
		if(root == nullptr || (root -> parent == nullptr && root -> left == nullptr))
			return nullptr;
		if(root->left != nullptr){
			return BinarySearchTree::max_node(root->left);
		}
		else{
			auto parent = root -> parent;
			auto node = root;
			while(parent != nullptr && root == parent -> left){
				root = parent;
				parent = parent -> parent;
			}
			return parent;
		}
	}
	static const Node<T>* max_node(const Node<T>* root){
		auto curr = root;
		while(curr -> right != nullptr)
			curr = curr -> right;
		return curr;
	}
	static const Node<T>* min_node(const Node<T>* root){
		auto curr = root;
		while(curr -> left != nullptr)
			curr = curr -> left;
		return curr;
	}
	template <typename N> class inorderiterator{
		Node<N>* node;
	public:
		inorderiterator(Node<N>* node):node(node){}
		inorderiterator<T> operator++(){
			node = const_cast<Node<N>*>(BinarySearchTree::inordersuccessor(const_cast<const Node<N>*>(node)));
			return *this;
		}
		inorderiterator<T> operator++(int){
			return operator++();
		}
		inorderiterator<T> operator--(){
			node = const_cast<Node<N>*>(BinarySearchTree::inorderpredecessor(const_cast<const Node<N>*>(node)));
			return *this;
		}
		inorderiterator<T> operator--(int){
			return operator--();
		}
		N operator*(){
			return node->key;
		}
		bool operator!=(inorderiterator<N> &itr){
			if(itr.node == nullptr && node == nullptr)
				return false;
			return true;
		}
	};
	void insert(T key){
		auto new_node = root;
		try{
			new_node = new Node<T>(key);
		}
		catch(std::bad_alloc ex){
			throw ex;
		}
		if(root == nullptr){
			root = new_node;
			return;
		}
		rec_insert(new_node, root);

	}
	void rec_insert(Node<T> *new_node, Node<T> *root){
		if(new_node->key <= root->key){
			if(root -> left == nullptr){
				root -> left = new_node;
				new_node -> parent = root;
			}
			else
				rec_insert(new_node, root -> left);
		}
		else{
			if(root -> right == nullptr){
				root -> right = new_node;
				new_node -> parent = root;
			}
			else
				rec_insert(new_node, root -> right);
		}
	}
	void remove(T data){
		auto itr = search_node(data, root);
		if(itr == nullptr)
			return;
		if(itr == root && root -> left == nullptr && root -> right ==nullptr){
			delete root;
			root = nullptr;
		}
		else 
			remove(itr);

	}
	void remove(Node<T>* root){
		if(root -> left == nullptr && root -> right == nullptr){
			if(root == root -> parent -> right)
				root -> parent -> right = nullptr;
			else
				root -> parent -> left = nullptr;
			delete root;
			return;
		}
		if(root->left == nullptr){
			auto new_root = const_cast<Node<T>*>(min_node(root -> right));
			root->key = new_root -> key;
			if(new_root -> parent -> right == new_root)
				new_root -> parent -> right = nullptr;
			else
				new_root -> parent -> left = nullptr;
			new_root->parent = nullptr;
			delete new_root;
			return;
		}
		else if(root->right == nullptr){
			auto new_root = const_cast<Node<T>*>(max_node(root -> left));
			root->key = new_root-> key;
			if(new_root -> parent -> right == new_root)
				new_root -> parent -> right = nullptr;
			else
				new_root -> parent -> left = nullptr;
			delete new_root;
			return;
		}
		auto new_root = const_cast<Node<T>*>(max_node(root -> left));
			root->key = new_root-> key;
			if(new_root -> parent -> right == new_root)
				new_root -> parent -> right = nullptr;
			else
				new_root -> parent -> left = nullptr;
			delete new_root;
			return;
	}

	void inordertraversal(){
		inordertraversal(root);
	}
	void inordertraversal(Node<T>* root){
		if(root == nullptr)
			return;
		inordertraversal(root -> left);
		std::cout << root->key<< " ";
		inordertraversal(root -> right);
	}
	T max(){
		return max(root);
	}
	T max(const Node<T>* root){
		auto curr = root;
		while(curr -> right != nullptr)
			curr = curr -> right;
		return curr -> key;
	}
	T min(){
		return min(root);
	}
	T min(const Node<T>* root){
		auto curr = root;
		while(curr -> left != nullptr)
			curr = curr -> left;
		return curr -> key;
	}
	inorderiterator<T> begin(){
		return inorderiterator<T>(const_cast<Node<T>*>(BinarySearchTree::min_node(const_cast<const Node<T>*>(root))));
	}
	inorderiterator<T> end(){
		return inorderiterator<T>(nullptr);
	}
	bool search(T data){
		return search(data, root);
	}
	bool search(T data, Node<T>* root){
		if(root == nullptr)
			return false;
		if(root -> key == data)
			return true;
		if(root -> key > data)
			return search(data, root -> left);
		else 
			return search(data, root -> right);
	}
	static Node<T>* search_node(T data, Node<T>* root){
		if(root == nullptr)
			return nullptr;
		if(root -> key == data)
			return root;
		if(root -> key > data)
			return search_node(data, root -> left);
		else 
			return search_node(data, root -> right);
	}
	void levelordertraversal(){
		auto curr = root;
		if(curr == nullptr)
			return;
		std::queue<Node<T>*> q;
		q.push(curr);
		while(!q.empty()){
			curr = q.front();
			q.pop();
			std::cout << curr -> key<< " ";
			if(curr -> left != nullptr)
				q.push(curr -> left);
			if(curr -> right != nullptr)
				q.push(curr -> right);
		}
	}
	void levelorderzigzagtraversal(){
        auto curr = root;
        if(curr == nullptr)
            return;
        std::queue<Node<T>*> q;
        std::stack<Node<T>*> s;
        q.push(curr);
        q.push(nullptr);
        bool flip = false;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == nullptr){
                flip = !flip;
                if(!q.empty()){
                    q.push(nullptr);
                }
                continue;
            }
            if(flip){
                auto rev = s.top();
                s.pop();
                std::cout << rev -> key<< " ";
                if(curr -> left != nullptr)
                    q.push(curr -> left);
                if(curr -> right != nullptr)
                    q.push(curr -> right);
            }
            else{
                std::cout << curr -> key<< " ";
                if(curr -> left != nullptr){
                    q.push(curr -> left);
                    s.push(curr -> left);
                }
                if(curr -> right != nullptr){
                    q.push(curr -> right);
                    s.push(curr -> right);
                }
            }
        }
    }
    int height(){
    	return height(root);
    }
    int height(Node<T>* node){
    	if(node == nullptr)
    		return 0;
    	return std::max(height(node-> left), height(node-> right)) + 1;
    }
    int diameter(){
    	return diameter(root);
    }
    int diameter(Node<T>* node){
    	if(node == nullptr)
    		return 0;
    	auto ldia = diameter(node -> left);
    	auto rdia = diameter(node -> right);
    	return std::max((height(node->left) + height(node -> right) + 1),std::max(ldia,rdia));
    }
    const std::vector<T> allpaths(){
    	std::vector<T> path;
    	return allpaths(root, path);
    }
    const std::vector<T> allpaths(Node<T>* node, std::vector<T> vec){
    	if(node == nullptr)
    		return std::move(vec) ;
    	vec.push_back(node->key);
    	if(node->left == nullptr && node -> right == nullptr){
    		for(auto i : vec)
    			std::cout << i << " ";
    		std::cout << std::endl;
    		return std::move(vec);
    	}
    	auto left_path = allpaths(node -> left, vec);
    	auto right_path = allpaths(node -> right, vec);
    	return (left_path.size() > right_path.size())?std::move(left_path) : std::move(right_path);
    }

};
int main(){ 
	BinarySearchTree<int> bst;
	bst.insert(2);
	bst.insert(1);
	bst.insert(4);
	bst.insert(5);
	bst.insert(3);
	bst.inordertraversal();
	std::cout << std::endl;
	bst.levelordertraversal();
	std::cout << std::endl;
	bst.remove(3);  
	std::cout <<"MAX : " << bst.max() << std::endl;
	std::cout <<"MIN : " << bst.min() << std::endl;
	for(auto i: bst)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << bst.search(6) << std::endl;
	std::cout << bst.search(5) << std::endl;
	bst.insert(3);
	bst.insert(7);
	bst.insert(6);
	bst.insert(8);
	bst.insert(-2);
	bst.insert(-1);
	bst.insert(-3);
	bst.levelordertraversal();
	std::cout << std::endl;
	bst.levelorderzigzagtraversal();
	std::cout<<"height of tree : " << bst.height()<<std::endl;
	std::cout <<"diameter of tree : "<< bst.diameter() << std::endl;
	auto longest_path = bst.allpaths();
	std::cout << "longest path : ";
	for(auto i : longest_path){
		std::cout << i << " ";
	}
	std::cout << std::endl;

};
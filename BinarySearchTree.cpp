#include <iostream>
#include <stack>

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
};
int main(){
	BinarySearchTree<int> bst;
	bst.insert(2);
	bst.insert(1);
	bst.insert(3);
	bst.insert(5);
	bst.insert(4);
	bst.inordertraversal();
	std::cout <<"MAX : " << bst.max() << std::endl;
	std::cout <<"MIN : " << bst.min() << std::endl;
	for(auto i: bst){
		std::cout << i << " ";
	}
};
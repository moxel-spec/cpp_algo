#include <iostream>
#include <stack>
#include <algorithm> // std::swap
#include <type_traits> // std::is_same, std::enable_if, std::decay
#include <cstdint>

template <typename T>
class bst 
{
public:
    using value_type = T;
    using const_reference = const T&;
    using size_type = std::uint64_t;
private:
    struct node 
    {
        using node_ptr = node*;
        value_type value;    
        node_ptr parent = nullptr;  
        node_ptr left = nullptr;
        node_ptr right = nullptr;
        node(const_reference value, node_ptr parent): value(value), parent(parent) {}  
        ~node() { /*std::cout << "node destructor called\n";*/ }
        
        static node_ptr minimum(node_ptr root) {
            while (root && root->left)
                root = root->left;
            return root;
        }
        
        static node_ptr maximum(node_ptr root) {
            while (root && root->right)
                root = root->right;
            return root;
        }
                
        static void insert(node_ptr &root, const_reference value) { // thanks Croessmah for this :)
            node_ptr parent = nullptr;
            node_ptr *pos = &root;
            while (*pos) {
                parent = *pos;
                pos = (value < (*pos)->value)? &(*pos)->left: &(*pos)->right;
            }
            *pos = new node(value, parent);
        }
        
        static node_ptr find(node_ptr root, const_reference value) {
            while (root && root->value != value)
                if (value < root->value) root = root->left;
                else root = root->right;
            return root;
        }
        
        static node_ptr next(node_ptr pos) {
            if (pos->right)
                return node::minimum(pos->right);
            node_ptr child = pos;
            while (pos && pos->left != child) {
                child = pos;
                pos = pos->parent;
            }
            return pos;
        }
        
        static node_ptr prev(node_ptr pos) {
            if (pos->left)
                return node::maximum(pos->left);
            node_ptr child = pos;
            while (pos && pos->right != child) {
                child = pos;
                pos = pos->parent;
            }
            return pos;
        }
        
        static void erase(node_ptr &root, node_ptr pos) {
            auto parent = pos->parent;
            if (pos->left && pos->right) 
            {
                auto next = node::minimum(pos->right);
                std::swap(pos->value, next->value);
                pos = next; parent = pos->parent;
            }
            node_ptr z = pos->left ? pos->left : pos->right;
            if (parent)
                if (parent->left == pos) parent->left = z;
                else parent->right = z;
            else root = z; // UPDATE ROOT!
            if (z) z->parent = parent;
            delete pos;
        }
    };
    
    using node_ptr = node*;
    size_type count = 0;
    node_ptr root = nullptr;
    
public:
    class iterator 
    {
        friend class bst;
        private:
            node *pos;
            iterator(node *pos): pos(pos) {}
        public:
            iterator(): pos(nullptr) {}
            const_reference operator*() {
                return pos->value;
            }
            
            iterator& operator++() {
                pos = node::next(pos);
                return *this;
            }
            
            iterator operator++(int) {
                iterator copy(*this);
                ++*this;
                return copy;
            }
            
            iterator& operator--() {
                pos = node::prev(pos);
                return *this;
            }
            
            iterator operator--(int) {
                iterator copy(*this);
                --*this;
                return copy;
            }
            
            bool operator !=(const iterator& rhs) const { return pos != rhs.pos; }
            bool operator ==(const iterator& rhs) const { return pos == rhs.pos; }
    };
    
    class reverse_iterator {
        friend class bst;
        private:
            node *pos;
            reverse_iterator(node *pos): pos(pos) {}
        public:
            reverse_iterator(): pos(nullptr) {}
            const_reference operator*() {
                return pos->value;
            }
            
            reverse_iterator& operator++() {
                pos = node::prev(pos);
                return *this;
            }
            
            reverse_iterator operator++(int) {
                reverse_iterator copy(*this);
                ++*this;
                return copy;
            }
            
            reverse_iterator& operator--() {
                pos = node::next(pos);
                return *this;
            }
            
            reverse_iterator operator--(int) {
                reverse_iterator copy(*this);
                --*this;
                return copy;
            }
            
            bool operator !=(const reverse_iterator& rhs) const { return pos != rhs.pos; }
            bool operator ==(const reverse_iterator& rhs) const { return pos == rhs.pos; }
    };
    
    using const_iterator = iterator;
    using const_reverse_iterator = reverse_iterator;

    iterator begin() const {
        return iterator(node::minimum(root));
    }
    
    iterator end() const {
        return iterator();
    }
    
    iterator cbegin() const {
        return iterator(node::minimum(root));
    }
    
    iterator cend() const {
        return iterator();
    }
    
    reverse_iterator rbegin() const {
        return reverse_iterator(node::maximum(root));
    }
    reverse_iterator crbegin() const {
        return reverse_iterator(node::maximum(root));
    }
    
    reverse_iterator rend() const {
        return reverse_iterator();
    }
    reverse_iterator crend() const {
        return reverse_iterator();
    }
    
    iterator find(const_reference value) const {
        return iterator(node::find(root, value));
    }
    
    void insert(const_reference value) {
        node::insert(root, value);
        ++count;
    }
    
    size_type size() const {
        return count;
    }
    
    template <typename IterType,
              class = typename std::enable_if_t<std::is_same<IterType, std::decay_t<iterator>>::value>>
    void erase(IterType &&it) {
        if (it != end())
            --count, node::erase(root, it.pos);
    }
    
    void erase(const_reference value) {
        iterator it = find(value);
        if (it != end())
            --count, node::erase(root, it.pos);
    }
    
    void clear() {
        std::stack<node_ptr> st;
        st.push(root);
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            if (p) {
                st.push(p->left); 
                st.push(p->right);
                delete p;
            }
        }
        count = 0; root = nullptr;
    }
       
    ~bst() {
        clear();
    }
};

template <class ContType>
class reversedIter {
private:
    typename ContType::const_reverse_iterator b, e;
public:
    reversedIter() = delete;
    reversedIter(const ContType &c): b(c.crbegin()), e(c.crend()) {}
    auto begin() { return b; }
    auto end() { return e; }
};

int main() {
    bst<int> tree;
    for (int i: {2, 1, 3, 6, 9, 8, 5})
        tree.insert(i);
    for (int i: {6, 4, 5, 4})
        tree.insert(i);
    
    auto print_tree = [&tree]() {
        std::cout << "Size: " << tree.size();
        std::cout << "\nTree: "; 
        for (auto &num: tree) std::cout << num << ' ';
        std::cout << '\n';
    };
    
    auto reverse_print_tree = [&tree]() {
        std::cout << "Size: " << tree.size();
        std::cout << "\nTree: ";
        for (auto &num: reversedIter<bst<int>>(tree)) std::cout << num << ' ';
        std::cout << '\n';
    };
    
    print_tree(); std::cout << '\n';
    reverse_print_tree(); std::cout << '\n';
    
    auto erase_test = [&tree, &print_tree](const int x) {
        std::cout << x << " removed\n";
        tree.erase(x);
        print_tree();
        std::cout << '\n';
    };
    
    
    erase_test(9);
        
    erase_test(10); erase_test(15); erase_test(5);
    erase_test(4); erase_test(0); erase_test(1);
    
    
}

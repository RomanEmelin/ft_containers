/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once
#include "list.hpp"
#include <iterator>
#include <memory>
#include <utility>

namespace ft {

    /**
     * Why Red-Black Trees?
     * Sr. No.	Algorithm	Time Complexity
     * 1.	    Search	        O(log n)
     * 2.	    Insert	        O(log n)
     * 3.	    Delete	        O(log n)
     */
    template<class V>
    struct rbNode {
        V *data;
        rbNode *parent;
        rbNode *right;
        rbNode *left;
        int color;
    };
    template<class T>
    class MapIterator: public std::iterator<std::bidirectional_iterator_tag, T> {

    public:
        typedef rbNode<T> *pointer;
        typedef rbNode<T> &reference;
    private:
        pointer _ptr;
    public:
        explicit MapIterator(pointer ptr = nullptr) : _ptr(ptr) {};

        ~MapIterator() {};

        MapIterator(const MapIterator &x) {
            if (this == &x)
                return;
            *this = x;
        };

        MapIterator &operator=(const MapIterator &x) {
            _ptr = x._ptr;
            return *this;
        };

        MapIterator operator++() {
            getNext();
            return *this;
        };

        MapIterator operator++(int) {
            MapIterator tmp(*this);
            operator++();
            return tmp;
        };

        MapIterator operator--() {
            getPrev();
            return *this;
        };

        MapIterator operator--(int) {
            MapIterator tmp(*this);
            operator--();
            return tmp;
        };

        bool operator==(const MapIterator &x) const { return _ptr == x._ptr; };

        bool operator!=(const MapIterator &x) const { return _ptr != x._ptr; };

        T &operator*() const { return *(_ptr->data); };

        T *operator->() const { return _ptr->data; };

        pointer getNode() { return _ptr; };

    private:
        void getNext() {
            if (_ptr->right)
                for (_ptr = _ptr->right; _ptr->left; _ptr = _ptr->left);
            else {
                for (; _ptr->parent && _ptr->parent->right == _ptr; _ptr = _ptr->parent);
                _ptr = _ptr->parent;
            }
        };

        void getPrev() {
            if (_ptr->left)
                for (_ptr = _ptr->left; _ptr->right; _ptr = _ptr->right);
            else {
                for (; _ptr->parent && _ptr->parent->left == _ptr; _ptr =_ptr->parent);
                _ptr = _ptr->parent;
            }
        };
    };

    template<class V>
    class ReverseMapIterator: public std::iterator<std::bidirectional_iterator_tag, V> {

    public:
        typedef rbNode<V>* pointer;
    private:
        pointer _ptr;
    public:
        explicit ReverseMapIterator(pointer ptr = nullptr) : _ptr(ptr) {};

        virtual ~ReverseMapIterator() {};

        ReverseMapIterator(const ReverseMapIterator &x) {
            if (this == &x)
                return;
            *this = x;
        };

        ReverseMapIterator &operator=(const ReverseMapIterator &x) {
            _ptr = x._ptr;
            return *this;
        };

        ReverseMapIterator operator++() {
            getPrev();
            return *this;
        };

        ReverseMapIterator operator++(int) {
            ReverseMapIterator tmp(*this);
            operator++();
            return tmp;
        };

        ReverseMapIterator operator--() {
            getNext();
            return *this;
        };

        ReverseMapIterator operator--(int) {
            ReverseMapIterator tmp(*this);
            operator--();
            return tmp;
        };

        bool operator==(const ReverseMapIterator &x) const { return _ptr == x._ptr; };

        bool operator!=(const ReverseMapIterator &x) const { return _ptr != x._ptr; };

        V &operator*() const { return *(_ptr->data); };

        V *operator->() const { return _ptr->data; };

        pointer getNode() {return _ptr;};

    private:
         void getNext() {
            if (_ptr->right)
                for (_ptr = _ptr->right; _ptr->left; _ptr = _ptr->left);
            else {
                for (; _ptr->parent && _ptr->parent->right == _ptr; _ptr = _ptr->parent);
                _ptr = _ptr->parent;
            }
        };

        void getPrev() {
            if (_ptr->left)
                for (_ptr = _ptr->left; _ptr->right; _ptr = _ptr->right);
            else {
                for (; _ptr->parent && _ptr->parent->left == _ptr; _ptr =_ptr->parent);
                _ptr = _ptr->parent;
            }
        };


    };

    /**
     * Oh my gosh! This is the map key=value!
     * @tparam Key
     * @tparam T
     * @tparam Compare
     * @tparam Alloc
     */
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map {

    public:
        typedef Key                                                      key_type;
        typedef T                                                        mapped_type;
        typedef std::pair<const key_type, mapped_type>                   value_type;
        typedef Alloc                                                    allocator_type;
        typedef Compare                                                  key_compare;
        typedef value_type*                                              pointer;
        typedef value_type&                                              reference;
        typedef const value_type*                                        const_pointer;
        typedef const value_type&                                        const_reference;
        typedef size_t                                                   size_type;
        typedef MapIterator<value_type>                                  iterator;
        typedef MapIterator<const value_type>                            const_iterator;
        typedef ReverseMapIterator<value_type>                           reverse_iterator;
        typedef ReverseMapIterator<const value_type>                     const_reverse_iterator;
        typedef rbNode<value_type>                                       rbnode;
        typedef rbNode<value_type>*                                      node_pointer;
        typedef rbNode<value_type>&                                      node_reference;
        typedef typename allocator_type::template rebind<rbnode>::other  node_allocator;

    private:
        enum Color {
            _BLACK,
            _RED,
        };

        node_allocator _alloc_node;
        allocator_type _alloc_value;
        key_compare _comp;
        node_pointer _root;
        size_type _size;
        node_pointer _end;
        node_pointer _begin;

        /**
         * initializion empty node for tree end and begin
         */
        void initMap() {
            _end = _alloc_node.allocate(1);
            _end->parent = nullptr;
            _end->left = nullptr;
            _end->right = nullptr;
            _end->data = _alloc_value.allocate(0);
            _end->color = _BLACK;
            _begin = _alloc_node.allocate(1);
            _begin->parent = nullptr;
            _begin->left = nullptr;
            _begin->right = nullptr;
            _begin->data = _alloc_value.allocate(0);
            _begin->color = _BLACK;
        };

        /**
         * Create new node with allocation memory for node and data
         * @param val pair key-value for data
         * @param parent position of parent node
         * @param color color of node by default red
         * @return
         */
        node_pointer createNode(value_type val, node_pointer parent, int color = _RED){
            node_pointer newElem = _alloc_node.allocate(1);
            newElem->parent = parent;
            newElem->right = nullptr;
            newElem->left = nullptr;
            newElem->color = color;
            newElem->data = _alloc_value.allocate(1);
            _alloc_value.construct(newElem->data, val);
            _size++;
            return newElem;
        };

        void deleteNode(node_pointer node) {
            _alloc_value.destroy(node->data);
            _alloc_value.deallocate(node->data, 1);
            _alloc_node.deallocate(node, 1);
            _size--;
        };

        /**
         * return node with max key in a tree
         * @return node constrains maximal key
         */
        node_pointer getMaxFromIt(node_pointer node) {
            node_pointer tmp = node;
            for (;tmp && (tmp->right && tmp->right != _end); tmp = tmp->right);
            return tmp;
        };

        /**
         * return node with min key in a tree
         * @return node constrains minimal key
         */
        node_pointer getMinFromIt(node_pointer node) {
            node_pointer tmp = node;
            for (;tmp && (tmp->left && tmp->left != _begin); tmp = tmp->left);
            return tmp;
        };

        /**
         * The function takes a node and returns it uncle
         * @param node
         * @return uncle or NULL
         */
        node_pointer getUncle(node_pointer node) {
            node_pointer grandParent = getGrandParent(node);
            if (!grandParent)
                return nullptr;
            if (grandParent->right && grandParent->left) {
                if (node->parent == grandParent->right)
                    return grandParent->left;
                return grandParent->right;
            }
            return nullptr;
        };

        /**
         * The function takes a node and returns it brother
         * @param node
         * @return brother or NULL
         */
        node_pointer getBrother(node_pointer node) {
            if (node->parent && node->parent->left && node->parent->right) {
                if (node->parent->right == node)
                    return node->parent->left;
                return node->parent->right;
            }
            return nullptr;
        };

        /**
         * The function takes a node and returns it grandfather
         * @param node
         * @return grandfather
         */
        node_pointer getGrandParent(node_pointer node) {
            if (node->parent && node->parent->parent)
                return node->parent->parent;
            return nullptr;
        };

        /**
         * Relink begin and end of tree
         */
        void relinkTreeEnd() {
                node_pointer min = getMinFromIt(_root);
                node_pointer max = getMaxFromIt(_root);
                min->left = _begin;
                max->right = _end;
                _begin->parent = min;
                _end->parent = max;
        };

        /**
         * simple inserting in binary search tree
         * @param val pair key value
         * @return inserted node
         */
        node_pointer bstInsert(value_type val) {
            if (!_root) {
                _root = createNode(val, nullptr, _BLACK);
                return _root;
            }
            else {
                node_pointer tmp = _root;
                while (tmp) {
                    if (_comp(tmp->data->first, val.first)) {
                        if (tmp->right && tmp->right != _end)
                            tmp = tmp->right;
                        else {
                            tmp->right = createNode(val, tmp);
                            return tmp->right;
                        }
                    }
                    else {
                        if (tmp->left && tmp->left != _begin)
                            tmp = tmp->left;
                        else {
                            tmp->left = createNode(val, tmp);
                            return tmp->left;
                        }
                    }
                }
            }
            return nullptr;
        };

        /**
         * check what is case for balancing tree
         * @param node
         * @param parent node->parent
         * @param grandParent node->parent->parent
         * @return
         */
        bool isLeftLeftCase(node_pointer node, node_pointer parent, node_pointer grandParent) {
            return parent == grandParent->left && node == parent->left;
        };

        /**
         * check what is case for balancing tree
         * @param node
         * @param parent node->parent
         * @param grandParent node->parent->parent
         * @return
         */
        bool isLeftRightCase(node_pointer node, node_pointer parent, node_pointer grandParent) {
            return parent == grandParent->left && node == parent->right;
        };

        /**
         * check what is case for balancing tree
         * @param node
         * @param parent node->parent
         * @param grandParent node->parent->parent
         * @return
         */
        bool isRightRightCase(node_pointer node, node_pointer parent, node_pointer grandParent) {
            return !(isLeftLeftCase(node, parent, grandParent));
        };

        /**
         * check what is case for balancing tree
         * @param node
         * @param parent node->parent
         * @param grandParent node->parent->parent
         * @return
         */
        bool isRightLeftCase(node_pointer node, node_pointer parent, node_pointer grandParent) {
            return !(isLeftRightCase(node, parent, grandParent));
        };

        /**
         * recursively recolor the nodes to balance the tree
         * @param uncle node->parent->!parent
         * @param parent node->parent
         * @param grandParent node->parent->parent
         */
        void reColor(node_pointer uncle, node_pointer parent, node_pointer grandParent) {
            uncle->color = _BLACK;
            parent->color = _BLACK;
            grandParent->color = _RED;
            balanceRBTree(grandParent);
        };

        bool hasOneChild(node_pointer node) {
            return (node->right && !node->left) || (!node->right && node->left);
        };

        /**
         * Check node has red child or not
         * @param node
         * @return true if has red child, false if not
         */
        bool hasRedChild(node_pointer node) {
            return (node->right && node->right->color == _RED) ||
                    (node->left && node->left->color == _RED);
        };

        /**
         * find node that replaces a deleted node in BST
         * @param node
         * @return
         */
        node_pointer getReplacer(node_pointer node) {
            if (node && node->left && node->right)
                return getMinFromIt(node->right);
            if (!node->left && !node->right)
                return nullptr;
            if (node->left)
                return node->left;
            return node->right;
        };

        /**
         * Fixes the tree if there was a case when deleting an element
         * @param node
         */
        void fixDoubleBlack(node_pointer node) {
            if (node == _root)
                return;
            node_pointer brother = getBrother(node);
            node_pointer parent = node->parent;
            if (!brother)
                fixDoubleBlack(parent);
            else {
                if (brother->color == _RED) {
                    parent->color = _RED;
                    brother->color = _BLACK;
                    if (brother->parent->left == brother)
                        rightRotation(parent);
                    else
                        leftRotation(parent);
                    fixDoubleBlack(node);
                }
                else {
                    if (hasRedChild(brother)) {
                        if (brother->left && brother->left->color == _RED) {
                            if (brother->parent->left == brother) {
                                brother->left->color = brother->color;
                                brother->color = parent->color;
                                rightRotation(parent);
                            }
                            else {
                                brother->left->color = parent->color;
                                rightRotation(brother);
                                leftRotation(parent);
                            }
                        }
                        else {
                            if (brother->parent->left == brother) {
                                brother->right->color = parent->color;
                                leftRotation(brother);
                                rightRotation(parent);
                            }
                            else {
                                brother->right->color = brother->color;
                                brother->color = parent->color;
                                leftRotation(parent);
                            }
                        }
                        parent->color = _BLACK;
                    }
                    else {
                        brother->color = _RED;
                        if (parent->color == _BLACK)
                            fixDoubleBlack(parent);
                        else
                            parent->color = _BLACK;
                    }
                }
            }
        };

        bool areBlack(node_pointer node1, node_pointer node2) {
            return (!node1 || node1->color == _BLACK) && (!node2 || node2->color == _BLACK);
        };

        /**
         * Balancing the tree with turns additionally depending on the case
         * @param node rotation start point
         * @param parent node->parent
         * @param grandParent node->parent->parent
         */
        void rotation(node_pointer node, node_pointer parent, node_pointer grandParent) {
            if (isLeftLeftCase(node, parent, grandParent)) {
                rightRotation(grandParent);
                ft::swap(parent->color, grandParent->color);
            }
            else if (isLeftRightCase(node, parent, grandParent)) {
                leftRotation(parent);
                rightRotation(grandParent);
                ft::swap(parent->color, grandParent->color);
            }
            else if (isRightRightCase(node, parent, grandParent)) {
                leftRotation(grandParent);
                ft::swap(grandParent->color, parent->color);
            }
            else if (isRightLeftCase(node, parent, grandParent)) {
                rightRotation(parent);
                leftRotation(grandParent);
                ft::swap(grandParent->color, parent->color);
            }
        };

        /**
         * balance Red-Black Tree
         * @param node start for balancing tree
         */
        void balanceRBTree(node_pointer node) {
            if (node == _root) {
                node->color = _BLACK;
                return;
            }
            node_pointer grandParent = getGrandParent(node);
            node_pointer uncle = getUncle(node);
            node_pointer parent = node->parent;
            if (parent && parent->color == _RED && uncle && grandParent) {
                if (uncle && uncle->color == _RED)
                    reColor(uncle, parent, grandParent);
                else
                    rotation(node, parent, grandParent);
            }
        };

        void leftRotation(node_pointer node) {
            node_pointer rightNode = node->right;
            node->right = rightNode->left;
            if (node->right)
                node->right->parent = node;
            rightNode->parent = node->parent;
            if (!node->parent)
                _root = rightNode;
            else if (node == node->parent->left)
                node->parent->left = rightNode;
            else
                node->parent->right = rightNode;
            rightNode->left = node;
            node->parent = rightNode;
        };

        void rightRotation(node_pointer node) {
            node_pointer leftNode = node->left;
            node->left = leftNode->right;
            if (node->left)
                node->left->parent = node;
            leftNode->parent = node->parent;
            if (!node->parent)
                _root = leftNode;
            else if ( node == node->parent->left)
                node->parent->left = leftNode;
            else
                node->parent->right = leftNode;
            leftNode->right = node;
            node->parent = leftNode;
        };

        /**
         * Delete node from tree
         * @param delNode node to delete from tree
         */
        void deleteFromTree(node_pointer delNode) {
            node_pointer nodeForReplace = getReplacer(delNode);
            node_pointer parent = delNode->parent;
            if (!nodeForReplace) {
                if (delNode == _root)
                    _root =  nullptr;
                else {
                    if (areBlack(delNode, nodeForReplace))
                        fixDoubleBlack(delNode);
                    else {
                        node_pointer brother = getBrother(delNode);
                        if (brother)
                            brother->color = _RED;
                    }
                    if (delNode->parent->left == delNode)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                deleteNode(delNode);
                return;
            }
            if (!delNode->left || !delNode->right) {
                if (delNode == _root) {
                    delNode->data = nodeForReplace->data;
                    delNode->right = delNode->left = nullptr;
                    deleteNode(nodeForReplace);
                }
                else {
                    if (delNode->parent->left == delNode)
                        parent->left = nodeForReplace;
                    else
                        parent->right = nodeForReplace;
                    deleteNode(delNode);
                    nodeForReplace->parent = parent;
                    if (areBlack(delNode, nodeForReplace))
                        fixDoubleBlack(nodeForReplace);
                    else
                        nodeForReplace->color = _BLACK;
                }
                return;
            }
            ft::swap(nodeForReplace->data, delNode->data);
            deleteFromTree(nodeForReplace);
        };

    public:

        /**
         * Default constructor
         * @param comp Comparator for keys
         * @param alloc allocator for pair Key value
         */
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
            _alloc_value(alloc), _comp(comp), _root(nullptr), _size(0) {
            initMap();
        };

        /**
         * range constructor
         * @tparam InputIterator
         * @param first
         * @param last
         * @param comp
         * @param alloc
         */
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0):
                _alloc_value(alloc), _comp(comp), _root(nullptr), _size(0) {
                    initMap();
                    insert(first, last);
                };

        /**
         * copy constructor
         * @param x other map
         */
        map (const map& x):  _root(nullptr), _size(0) {
            if (this == &x)
                return ;
            *this = x;
        };

        map &operator=(const map& x) {
            clear();
            _alloc_value = x._alloc_value;
            _comp = x._comp;
            insert(x.begin(), x.end());
        };

        ~map() {
            clear();
           // _alloc_node.deallocate(_begin, 1);
           // _alloc_node.deallocate(_end, 1);
        };

        mapped_type &operator[](const key_type &key) {
            return insert(value_type(key, mapped_type())).first->second;
        };

        /**
         * Returns an iterator referring to the first element in the map container.
         * @return An iterator to the first element in the container.
         */
        iterator begin() {
            if (!_size)
                return iterator(_end);
            return iterator(_begin->parent);
        };

        const_iterator begin() const {
            if (!_size)
                return const_iterator(_end);
            return const_iterator(_begin->parent);};

        /**
         * Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
         * @return A reverse iterator to the reverse beginning of the sequence container.
         */
        reverse_iterator rbegin() {
            if (!_size)
                return reverse_iterator (_begin);
            return reverse_iterator (_end->parent);
        };

        /**
         * Returns a reverse const iterator pointing to the last element in the container (i.e., its reverse beginning).
         * @return A reverse const iterator to the reverse beginning of the sequence container.
         */
        const_reverse_iterator rbegin() const {
            if (!_size)
                return const_reverse_iterator (_begin);
            return const_reverse_iterator (_end->parent);};

        /**
         * Returns an iterator referring to the past-the-end element in the map container
         * @return An iterator to the past-the-end element in the container.
         */
        iterator end() {return iterator(_end);};

        /**
         * Returns an const iterator referring to the past-the-end element in the map container
         * @return An const iterator to the past-the-end element in the container.
         */
        const_iterator end() const {return const_iterator(_end);};

        /**
         * Returns a reverse iterator pointing to the theoretical element right before the first element in the map
         * container (which is considered its reverse end).
         * @return A reverse iterator to the reverse end of the sequence container.
         */
        reverse_iterator rend() {return reverse_iterator (_begin);};

        /**
         * Returns a reverse const iterator pointing to the theoretical element right before the first element in the map
         * container (which is considered its reverse end).
         * @return A reverse const iterator to the reverse end of the sequence container.
         */
        const_reverse_iterator rend() const {return const_reverse_iterator (_begin);};

        /**
         *
         * @param val pair key - value
         * @return it on new elem and true if insert success, and it on end and false if insert fail
         */

        /**
         * Insert new element in a map
         * @param val pair key-value
         * @return iterator on new element and true if insert success, or iterator with same key on old element and false
         */
        std::pair<iterator, bool> insert(const value_type& val) {
            iterator found = find(val.first);
            if (found != end())
                return std::pair<iterator, bool>(found, false);
            node_pointer tmp = bstInsert(val);
            relinkTreeEnd();
            balanceRBTree(tmp);
            return std::pair<iterator, bool>(iterator(tmp), true);
        };

        /**
         * Insert new element in a map between first and last
         * @tparam InputIterator
         * @param first
         * @param last
         */
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            for (; first != last; first++)
                insert(*first);
        };

        /**
         * Insert new element in a map
         * @param position
         * @param val
         * @return iterator on new element
         */
        iterator insert (iterator position, const value_type& val) {
            (void)position;
            return insert(val).first;
        };

        /**
         * Searches the container for an element with a key equivalent to k and returns an iterator to it if found,
         * otherwise it returns an iterator to end().
         * @param k it is a key
         * @return An iterator to the element, if an element with specified key is found, or end otherwise.
         */
        iterator find (const key_type& k) {
            iterator it = begin();
            for(iterator ite = end(); it != ite && it->first != k; it++);
            return it;
        };

        /**
         * Searches the container for an element with a key equivalent to k and returns an iterator to it if found,
         * otherwise it returns an iterator to end().
         * @param k it is a key
         * @return An iterator to the element, if an element with specified key is found, or end otherwise.
         */
        const_iterator find (const key_type& k) const {
            const_iterator it = begin();
            for(const_iterator ite = end(); it != ite && it->first != k; it++)
            return it;
        };

        /**
         * Returns the maximum number of elements that the map container can hold.
         * @return The maximum number of elements a map container can hold as content.
         */
        size_type max_size() const{return _alloc_value.max_size() / 2;};

        /**
         * Returns the number of elements in the map container.
         * @return number of elements in container
         */
        size_type size() const {return _size;};

        /**
         * Returns whether the map container is empty (i.e. whether its size is 0).
         * @return true if size 0, or false
         */
        bool empty() const {return _size == 0;};

        /**
         * Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
         */
        void clear() {
            erase(begin(), end());
        };
        void unlink() {
            _begin->parent->left = nullptr;
            _end->parent->right = nullptr;
        }
        /**
         * Removes from the map container either a single element by position
         * @param position
         */
        void erase (iterator position) {
            node_pointer delNode = position.getNode();
            unlink();
            deleteFromTree(delNode);
            relinkTreeEnd();
        };

        /**
         * Removes from the map container either a single element by key
         * @param k key
         * @return
         */
        size_type erase (const key_type& k) {
            iterator it = find(k);
            if (it == end())
                return 0;
            erase(it);
            return 1;
        };

        /**
         * Removes from the map container a range of elements ([first,last)).
         * @param first
         * @param last
         */
        void erase (iterator first, iterator last) {
            for (; first != last; first++)
                erase(first);
        };

        /**
         * Exchanges the content of the container by the content of x,
         * which is another map of the same type. Sizes may differ.
         * @param x Another map container of the same type as this
         */
        void swap (map& x) {
            ft::swap(_size, x._size);
            ft::swap(_root, x._root);
            ft::swap(_begin, x._begin);
            ft::swap(_end, x._end);
        };
    };
}
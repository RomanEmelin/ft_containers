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
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Alloc allocator_type;
        typedef Compare key_compare;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef const value_type *const_pointer;
        typedef const value_type &const_reference;
        typedef size_t size_type;
        typedef MapIterator<value_type> iterator;
        typedef MapIterator<const value_type> const_iterator;
        typedef ReverseMapIterator<value_type> reverse_iterator;
        typedef ReverseMapIterator<const value_type> const_reverse_iterator;
        typedef rbNode<value_type> rbnode;
        typedef rbNode<value_type> *node_pointer;
        typedef rbNode<value_type> &node_reference;
        typedef typename allocator_type::template rebind<rbnode>::other node_allocator;

    private:
        enum Direction {
            _RIGHT,
            _LEFT
        };
        enum Color {
            _BLACK,
            _RED
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
            for (; tmp && tmp->right; tmp = tmp->right);
            return tmp;
        };

        /**
         * return node with min key in a tree
         * @return node constrains minimal key
         */
        node_pointer getMinFromIt(node_pointer node) {
            node_pointer tmp = node;
            for (; tmp && tmp->left; tmp = tmp->left);
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
            if (isOnLeft(node->parent))
                return grandParent->right;
            else
                return grandParent->left;
        };

        /**
         * Create new node with allocation memory for node and data
         * @param val pair key-value for data
         * @param parent position of parent node
         * @param color color of node by default red
         * @return
         */
        node_pointer createNode(value_type val){
            node_pointer newElem = _alloc_node.allocate(1);
            newElem->parent = nullptr;
            newElem->right = nullptr;
            newElem->left = nullptr;
            newElem->color = _RED;
            newElem->data = _alloc_value.allocate(1);
            _alloc_value.construct(newElem->data, val);
            _size++;
            return newElem;
        };

        /**
         * The function takes a node and returns it grandfather
         * @param node
         * @return grandfather
         */
        node_pointer getGrandParent(node_pointer node) {
            if (node && node->parent)
                return node->parent->parent;
            return nullptr;
        };

        /**
         * Relink begin and end of tree
         */
        void relinkTreeEnd() {
            if (!_size)
                return;
            node_pointer min = getMinFromIt(_root);
            node_pointer max = getMaxFromIt(_root);
            min->left = _begin;
            max->right = _end;
            _begin->parent = min;
            _end->parent = max;
        };

        void rotation(node_pointer node, Direction direction) {
            if (direction == _LEFT) {
                node_pointer pivot = node->right;
                node->right = pivot->left;
                if (pivot->left)
                    pivot->left->parent = node;
                pivot->parent = node->parent;
                if (!node->parent)
                    _root = pivot;
                else if (node == node->parent->left)
                    node->parent->left = pivot;
                else
                    node->parent->right = pivot;
                pivot->left = node;
                node->parent = pivot;
            }
            else if (direction == _RIGHT) {
                node_pointer pivot = node->left;
                node->left = pivot->right;
                if (pivot->right)
                    pivot->right->parent = node;
                pivot->parent = node->parent;
                if (!node->parent)
                    _root = pivot;
                else if (node == node->parent->left)
                    node->parent->left = pivot;
                else
                    node->parent->right = pivot;
                pivot->right = node;
                node->parent = pivot;
            }
        };

        bool isOnLeft(node_pointer node) {
            return node == node->parent->left;
        };

    public:

        /**
         * Default constructor
         * @param comp Comparator for keys
         * @param alloc allocator for pair Key value
         */
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
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
        template<class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type(),
            typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0):
                _alloc_value(alloc), _comp(comp), _root(nullptr), _size(0) {
            initMap();
            insert(first, last);
        };

        /**
         * copy constructor
         * @param x other map
         */
        map(const map &x) : _root(nullptr), _size(0) {
            if (this == &x)
                return;
            *this = x;
        };

        map &operator=(const map &x) {
            clear();
            _alloc_value = x._alloc_value;
            _comp = x._comp;
            insert(x.begin(), x.end());
        };

        ~map() {
            clear();
            _alloc_node.destroy(_end);
            _alloc_node.destroy(_begin);
            _alloc_node.deallocate(_begin, 1);
            _alloc_node.deallocate(_end, 1);
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
            return const_iterator(_begin->parent);
        };

        /**
         * Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
         * @return A reverse iterator to the reverse beginning of the sequence container.
         */
        reverse_iterator rbegin() {
            if (!_size)
                return reverse_iterator(_begin);
            return reverse_iterator(_end->parent);
        };

        /**
         * Returns a reverse const iterator pointing to the last element in the container (i.e., its reverse beginning).
         * @return A reverse const iterator to the reverse beginning of the sequence container.
         */
        const_reverse_iterator rbegin() const {
            if (!_size)
                return const_reverse_iterator(_begin);
            return const_reverse_iterator(_end->parent);
        };

        /**
         * Returns an iterator referring to the past-the-end element in the map container
         * @return An iterator to the past-the-end element in the container.
         */
        iterator end() { return iterator(_end); };

        /**
         * Returns an const iterator referring to the past-the-end element in the map container
         * @return An const iterator to the past-the-end element in the container.
         */
        const_iterator end() const { return const_iterator(_end); };

        /**
         * Returns a reverse iterator pointing to the theoretical element right before the first element in the map
         * container (which is considered its reverse end).
         * @return A reverse iterator to the reverse end of the sequence container.
         */
        reverse_iterator rend() { return reverse_iterator(_begin); };

        /**
         * Returns a reverse const iterator pointing to the theoretical element right before the first element in the map
         * container (which is considered its reverse end).
         * @return A reverse const iterator to the reverse end of the sequence container.
         */
        const_reverse_iterator rend() const { return const_reverse_iterator(_begin); };


        /**
         * Insertion in standart binary search tree
         * @param val key-value
         * @return inserted node
         */

        void standartBstInsertion(value_type val) {
            node_pointer elem = createNode(val);
            node_pointer parent = nullptr;
            node_pointer tmp = _root;
            while (tmp) {
                parent = tmp;
                if (!_comp(val.first, tmp->data->first))
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            elem->parent = parent;
            if (!parent) {
                _root = elem;
                _root->color = _BLACK;
                return;
            }
            else if (_comp(parent->data->first, val.first))
                parent->right = elem;
            else
                parent->left = elem;
            if (!elem->parent->parent)
                return;
            rbInsertion(elem);
        };

        void rbInsertion(node_pointer tmp) {
            node_pointer uncle;
            while (tmp->parent && tmp->parent->color == _RED) {
                if (tmp->parent == tmp->parent->parent->right) {
                    uncle = tmp->parent->parent->left;
                    if (uncle && uncle->color == _RED) {
                        uncle->color = _BLACK;
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        tmp = tmp->parent->parent;
                    }
                    else {
                        if (tmp == tmp->parent->left) {
                            tmp = tmp->parent;
                            rotation(tmp, _RIGHT);
                        }
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        rotation(tmp->parent->parent, _LEFT);
                    }
                }
                else {
                    uncle = tmp->parent->parent->right;
                    if (uncle && uncle->color == _RED) {
                        uncle->color = _BLACK;
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        tmp = tmp->parent->parent;
                    }
                    else {
                        if (tmp == tmp->parent->right) {
                            tmp = tmp->parent;
                            rotation(tmp, _LEFT);
                        }
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        rotation(tmp->parent->parent, _RIGHT);
                    }
                }
                if (tmp == _root)
                    break;
            }
            _root->color = _BLACK;
        };

        /**
         * Insert new element in a map
         * @param val pair key-value
         * @return iterator on new element and true if insert success, or iterator with same key on old element and false
         */
        std::pair<iterator, bool> insert(const value_type &val) {
            iterator found = find(val.first);
            if (found != end()) {
                return std::pair<iterator, bool>(found, false);
            }
            unlink();
            standartBstInsertion(val);
            relinkTreeEnd();
            found = find(val.first);
            return std::pair<iterator, bool>(found, true);
        };

        /**
         * Insert new element in a map between first and last
         * @tparam InputIterator
         * @param first
         * @param last
         */
        template<class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0) {
            for (; first != last; first++)
                insert(*first);
        };

        /**
         * Insert new element in a map
         * @param position
         * @param val
         * @return iterator on new element
         */
        iterator insert(iterator position, const value_type &val) {
            (void) position;
            return insert(val).first;
        };

        /**
         * Searches the container for an element with a key equivalent to k and returns an iterator to it if found,
         * otherwise it returns an iterator to end().
         * @param k it is a key
         * @return An iterator to the element, if an element with specified key is found, or end otherwise.
         */
        iterator find(const key_type &k) {
            iterator it = begin();
            for (iterator ite = end(); it != ite && it->first != k; it++);
            return it;
        };

        /**
         * Searches the container for an element with a key equivalent to k and returns an iterator to it if found,
         * otherwise it returns an iterator to end().
         * @param k it is a key
         * @return An iterator to the element, if an element with specified key is found, or end otherwise.
         */
        const_iterator find(const key_type &k) const {
            const_iterator it = begin();
            for (const_iterator ite = end(); it != ite && it->first != k; it++);
            return it;
        };

        /**
         * Returns the maximum number of elements that the map container can hold.
         * @return The maximum number of elements a map container can hold as content.
         */
        size_type max_size() const { return _alloc_value.max_size() / 2; };

        /**
         * Returns the number of elements in the map container.
         * @return number of elements in container
         */
        size_type size() const { return _size; };

        /**
         * Returns whether the map container is empty (i.e. whether its size is 0).
         * @return true if size 0, or false
         */
        bool empty() const { return _size == 0; };

        /**
         * Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
         */
        void clear() {
            while (_size)
                erase(begin());
        };

        void unlink() {
            if (_begin->parent)
                _begin->parent->left = nullptr;
            if (_end->parent)
                _end->parent->right = nullptr;
        }

        void transplant(node_pointer u, node_pointer v) {
            if (u && !u->parent) // u is root
                _root = v;
            else if (isOnLeft(u))
                u->parent->left = v;
            else
                u->parent->right = v;
            if (v)
                v->parent = u->parent;
        };

        bool hasRedChild(node_pointer x) {
            return (x->left and x->left->color == _RED) or (x->right and x->right->color == _RED);
        };

        void fixTreeAfterDeletion(node_pointer x) {
            if (!x)
                return;
            while (x != _root and x->color == _BLACK) {
                if (x == x->parent->left) {
                    node_pointer w = x->parent->right;
                    if (w->color == _RED) {
                        w->color = _BLACK;
                        x->parent->color = _RED;
                        rotation(x->parent, _LEFT);
                        w = x->parent->right;
                    }
                    if (w->left->color == _BLACK and w->right->color == _BLACK) {
                        w->color = _RED;
                        x = x->parent;
                    }
                    else {
                        if (w->right->color == _BLACK) {
                            w->left->color = _BLACK;
                            w->color = _RED;
                            rotation(w, _RIGHT);
                            w = x->parent->right;
                        }
                        else {
                            w->color = x->parent->color;
                            w->parent->color = _BLACK;
                            w->right->color = _BLACK;
                            rotation(x->parent, _LEFT);
                            x = _root;
                        }
                    }
                }
                else {
                    node_pointer w = x->parent->left;
                    if (w->color == _RED) {
                        w->color = _BLACK;
                        x->parent->color = _RED;
                        rotation(x->parent, _RIGHT);
                        w = x->parent->left;
                    }
                    if (w->right->color == _BLACK and w->left->color == _BLACK) {
                        w->color = _RED;
                        x = x->parent;
                    }
                    else {
                         if (w->left->color == _BLACK) {
                             w->right->color = _BLACK;
                             w->color = _RED;
                             rotation(w, _LEFT);
                             w = x->parent->left;
                         }
                         else {
                             w->color = x->parent->color;
                             x->parent->color = _BLACK;
                             w->left->color = _BLACK;
                             rotation(x->parent, _RIGHT);
                             x = _root;
                         }
                    }
                }
            }
            x->color = _BLACK;
        };

        node_pointer replace(node_pointer v) {
            if (v->left and v->right) // when v have two children
                return getMaxFromIt(v->right);
            if (!v->left and !v->right) // when without children is leaf
                return nullptr;
            if (v->left) // when node have single child
                return v->left;
            return v->right;
        };



        void linkNodes(node_pointer parent, node_pointer child, Direction direction) {
            if (!parent)
                return;
            if (direction == _RIGHT)
                parent->right = child;
            else if (direction == _LEFT)
                parent->left = child;
            if (child)
                child->parent = parent;
        };

        node_pointer swapValues(node_pointer successor, node_pointer nodeToDel) {
            bool side;
            node_pointer left = successor->left;
            node_pointer right = successor->right;
            if (successor->parent == nodeToDel) {
                side = isOnLeft(successor);
                if (side)
                    linkNodes(successor, nodeToDel->right, _RIGHT);
                else
                    linkNodes(successor, nodeToDel->left, _LEFT);
                if (nodeToDel->parent) {
                    if (isOnLeft(nodeToDel))
                        linkNodes(nodeToDel->parent, successor, _LEFT);
                    else
                        linkNodes(nodeToDel->parent, successor, _RIGHT);
                }
                else
                    successor->parent = nullptr;
                if (side)
                    linkNodes(successor, nodeToDel, _LEFT);
                else
                    linkNodes(successor, nodeToDel, _RIGHT);
                linkNodes(nodeToDel, right, _RIGHT);
                linkNodes(nodeToDel, left, _LEFT);
            }
            else {
                node_pointer parent = successor->parent;
                side = isOnLeft(successor);
                linkNodes(successor, nodeToDel->right, _RIGHT);
                linkNodes(successor, nodeToDel->left, _LEFT);
                if (nodeToDel->parent and isOnLeft(nodeToDel))
                    linkNodes(nodeToDel->parent, successor, _LEFT);
                else
                    linkNodes(nodeToDel->parent, successor, _RIGHT);
                if (side)
                    linkNodes(parent, nodeToDel, _LEFT);
                else
                    linkNodes(parent,nodeToDel, _RIGHT);
                linkNodes(nodeToDel, left, _LEFT);
                linkNodes(nodeToDel, right, _RIGHT);
            }
            if (nodeToDel == _root)
                _root = successor;
            //std::cout << "tut" << std::endl;
            return nodeToDel;
        };

        void deleteFromTree(node_pointer node) { // node contains item to be deleted
            node_pointer y(node), x;
            int savedColor = y->color;
            if (!node->left) {
                x = node->right;
                transplant(node, node->right);
            }
            else if (!node->right) {
                x = node->left;
                transplant(node, node->left);
            }
            else {
                y = getMinFromIt(node->right);
                savedColor = y->color;
                x = y->right;
                if (node == y->parent) {
                    if (x)
                        x->parent = y;
                }
                else {
                    transplant(y, y->right);
                    y->right = node->right;
                    y->right->parent = y;
                }
                transplant(node, y);
                y->left = node->left;
                y->left->parent = y;
                y->color = node->color;
            }
            if (savedColor == _BLACK)
                fixTreeAfterDeletion(x);
            deleteNode(node);
        };

        /**
         * Removes from the map container either a single element by position
         * @param position
         */
        void erase(iterator position) {
            erase(position->first);
        };

        /**
         * Removes from the map container either a single element by key
         * @param k key
         * @return
         */
        size_type erase(const key_type &k) {
            node_pointer tmp = _root;
            unlink();
            while (tmp) {
                if (k == tmp->data->first) {
                    deleteFromTree(tmp);
                    relinkTreeEnd();
                    return 1;
                }
                if (_comp(k, tmp->data->first))
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            relinkTreeEnd();
            return 0;
        };

        /**
         * Removes from the map container a range of elements ([first,last)).
         * @param first
         * @param last
         */
        void erase(iterator first, iterator last) {
            for (; first != last; first++)
                erase(first->first);
        };

        /**
         * Exchanges the content of the container by the content of x,
         * which is another map of the same type. Sizes may differ.
         * @param x Another map container of the same type as this
         */
        void swap(map &x) {
            ft::swap(_size, x._size);
            ft::swap(_root, x._root);
            ft::swap(_begin, x._begin);
            ft::swap(_end, x._end);
        };

        node_pointer getRoot() {return _root;};
    };
}
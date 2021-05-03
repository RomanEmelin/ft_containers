/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

#include <memory>
#include <iostream>

namespace ft {

    template<class T>
    struct Node {
        T *content;
        Node *next;
        Node *prev;
    };

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    };

    /**
     * Class iterator for list
     * @tparam T
     */
    template<class T>
    class ListIterator {

    public:
        typedef T value_type;
        typedef T &reference;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ListIterator() : _ptr(nullptr) {};

        ListIterator(ListIterator const &other) {
            *this = other;
        }

        ListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ListIterator() {};

        pointer node() const { return _ptr; }

        ListIterator &operator=(ListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ListIterator &operator++() {
            _ptr = _ptr->next;
        }

        ListIterator operator++(int) {
            ListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        ListIterator &operator--() {
            _ptr = _ptr->prev;
        }

        ListIterator operator--(int) {
            ListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        bool operator==(ListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ListIterator const &other) const { return _ptr <= other._ptr; };

        value_type &operator*() { return *(_ptr->content); };
    };

    /**
     * Class constant iterator for list
     * @tparam T
     */
    template<class T>
    class ConstListIterator {

    public:
        typedef T value_type;
        typedef T &reference;
        typedef Node<T> *pointer;

    private:
        pointer _ptr;

    public:
        ConstListIterator() : _ptr(nullptr) {};

        ConstListIterator(ConstListIterator const &other) {
            *this = other;
        }

        ConstListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ConstListIterator() {};

        pointer node() const { return _ptr; }

        ConstListIterator &operator=(ConstListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ConstListIterator &operator++() {
            _ptr = _ptr->next;
        }

        ConstListIterator operator++(int) {
            ConstListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        ConstListIterator &operator--() {
            _ptr = _ptr->prev;
        }

        ConstListIterator operator--(int) {
            ConstListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        bool operator==(ConstListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ConstListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ConstListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ConstListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ConstListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ConstListIterator const &other) const { return _ptr <= other._ptr; };

        value_type &operator*() const { return *(_ptr->content); };
    };

    /**
     * Class reverse iterator for list
     * @tparam T
     */
    template<class T>
    class ReverseListIterator {

    public:
        typedef T value_type;
        typedef T &reference;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ReverseListIterator() {};

        ReverseListIterator(ReverseListIterator const &other) {
            *this = other;
        }

        ReverseListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ReverseListIterator() {};

        pointer node() const {
            return _ptr;
        }

        ReverseListIterator &operator=(ReverseListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ReverseListIterator &operator++() {
            _ptr = _ptr->prev;
        }

        ReverseListIterator operator++(int) {
            ReverseListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        ReverseListIterator &operator--() {
            _ptr = _ptr->next;
        }

        ReverseListIterator operator--(int) {
            ReverseListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        bool operator==(ReverseListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ReverseListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ReverseListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ReverseListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ReverseListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ReverseListIterator const &other) const { return _ptr <= other._ptr; };

        value_type &operator*() { return _ptr->content; };
    };

    template<class T>
    class ConstReverseListIterator {

    public:
        typedef T value_type;
        typedef T &reference;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ConstReverseListIterator() {};

        ConstReverseListIterator(ConstReverseListIterator const &other) {
            *this = other;
        }

        ConstReverseListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ConstReverseListIterator() {};

        pointer node() const {
            return _ptr;
        }

        ConstReverseListIterator &operator=(ConstReverseListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ConstReverseListIterator &operator++() {
            _ptr = _ptr->prev;
        }

        ConstReverseListIterator operator++(int) {
            ConstReverseListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        ConstReverseListIterator &operator--() {
            _ptr = _ptr->next;
        }

        ConstReverseListIterator operator--(int) {
            ConstReverseListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        bool operator==(ConstReverseListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ConstReverseListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ConstReverseListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ConstReverseListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ConstReverseListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ConstReverseListIterator const &other) const { return _ptr <= other._ptr; };

        value_type &operator*() const { return _ptr->content; };
    };

    template<class T, class Alloc = std::allocator<T> >
    class list {

    public:

        /**
         * Types definition
         */
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef Node<value_type>  node;
        typedef Node<value_type>* node_ptr;
        typedef Node<value_type>& node_ref;
        typedef typename allocator_type::template rebind<node>::other node_allocator;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename std::ptrdiff_t difference_type;
        typedef unsigned long size_type;

        /**
         * Iterators type definition
         */
        typedef ListIterator<value_type> iterator;
        typedef ConstListIterator<value_type> const_iterator;
        typedef ReverseListIterator<value_type> reverse_iterator;
        typedef ConstReverseListIterator<value_type> const_reverse_iterator;

    private:
        node_ptr _emptyNode;
        allocator_type _allocator;
        node_allocator _node_allocator;
        size_type _size;

        /**
         * list initialization
         */
        void initList() {
            _emptyNode = _node_allocator.allocate(1);
            _emptyNode->content = _allocator.allocate(1);
            _emptyNode->next = _emptyNode;
            _emptyNode->prev = _emptyNode;
        };


        /**
         * Creates a new node and links it to list elements
         * @param new element
         * @param pointer to next node
         * @param pointer to prev node
         * @return new node
         */
        node_ptr addNewNode(value_type const &val, node_ptr next, node_ptr prev) {
            node_ptr newNode = _node_allocator.allocate(1);
            newNode->content = _allocator.allocate(1);
            _allocator.construct(newNode->content, val);
            newNode->next = next;
            newNode->prev = prev;
            return newNode;
        };

        /**
         * Destroy node and relink pointers next and prev
         * @param node element of the list
         */
        void destroyNode(node_ptr node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            _allocator.destroy(node->content);
            _allocator.deallocate(node->content, 1);
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
            _size--;
        };

    public:

        /**
         * Default constructors
         */
        explicit list(allocator_type const &alloc = allocator_type()) :
                _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
        };

        /**
         * Fill constructor
         */
        explicit list(size_type n, value_type const &val = value_type(),
                      allocator_type const &alloc = allocator_type()) :
                _emptyNode(nullptr), _allocator(alloc), _size(n) {
            initList();
            assign(n, val);
        };

        /**
         * Range constructor
         */
        template<class InputIterator>
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type()):
             _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
            assign(first, last);
        };

        /**
         * Destructor
         */
        ~list() {
            clear();
            _node_allocator.destroy(_emptyNode);
            _node_allocator.deallocate(_emptyNode, 1);
        }

        iterator begin() const { return iterator(_emptyNode->next); };
        iterator end() { return iterator(_emptyNode); };
        const_iterator cbegin() const { return const_iterator(_emptyNode->next); };
        const_iterator cend() const { return const_iterator(_emptyNode); };
        reverse_iterator rbegin() { return _emptyNode->prev; };
        reverse_iterator rend() { return _emptyNode; };
        const_reverse_iterator crbegin() const { return _emptyNode->prev; };
        const_reverse_iterator crend() const { return _emptyNode; };

        /**
         * Range assign filling list from first to last
         * @tparam InputIterator
         * @param first first iterator
         * @param last end iterator
         */
        template<class InputIterator>
        void assign(InputIterator first, InputIterator last) {
            clear();
            while (first != last)
                push_back(*(first++));
        };

        /**
         * Fill assign
         * @param n number of elements
         * @param val element value
         */
        void assign(size_type n, value_type val) {
            clear();
            while (n--) {
                push_back(val);
            }
        };


        size_type size() const {
            return _size;
        };

        value_type &front() {
            return _emptyNode->next->content;
        };

        value_type &back() {
            return _emptyNode->prev->content;
        };

        void resize() {
            //TODO use resize
        }

        /**
         * Clear list
         */
        void clear() {
            node_ptr currentNode = _emptyNode->next;
            while (currentNode != _emptyNode) {
                node_ptr nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
            _emptyNode->next = _emptyNode;
            _emptyNode->prev = _emptyNode;
            _size = 0;
        }

        /**
         * Add element to the back of the list
         * @param element
         */
        void push_back(const value_type &val) {
            node_ptr element = addNewNode(val, _emptyNode, _emptyNode->prev);
            _emptyNode->prev->next = element;
            _emptyNode->prev = element;
            _size++;
        }

        /**
         * Add element to the front of the list
         * @param element
         */
        void push_front(const value_type &val) {
            node_ptr element = addNewNode(val, _emptyNode->next, _emptyNode);
            _emptyNode->next->prev = element;
            _emptyNode->next = element;
            _size++;
        }
        /**
         * Removes the first element in the list container, effectively reducing its size by one.
         * This destroys the removed element.
         */
        void pop_front(){
            destroyNode(_emptyNode->next);
        }
        /**
         * Removes the last element in the list container, effectively reducing the container size by one.
         * This destroys the removed element.
         */
        void pop_back() {
            destroyNode(_emptyNode->prev);
        }

        /**
         * Check empty list or not
         * @return true if list is empty, else false
         */
        bool empty() const {
            return _size == 0;
        };

        size_type max_size() const {
            return std::numeric_limits<size_type>::max() / sizeof(Node<value_type>);
        };

        void swap(list &other) {
            ft::swap(_size, other._size);
            ft::swap(_emptyNode, other._emptyNode);
        };

    };

    template<typename T>
    bool operator==(list<T> const &l, list<T> const &r) {
        if (l.size() != r.size())
            return false;
        typename list<T>::const_iterator lit = l.cbegin();
        typename list<T>::const_iterator rit = r.cbegin();
        for (; lit != l.cend(); lit++, rit++)
            if (*lit != *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator!=(list<T> const &l, list<T> const &r) {
        return !(l == r);
    };

    template<typename T>
    bool operator<(list<T> const &l, list<T> const &r) {
        if (l.size() >= r.size())
            return false;
        typename list<T>::const_iterator lit = l.cbegin();
        typename list<T>::const_iterator rit = r.cbegin();
        for (; lit != l.cend(); lit++, rit++)
            if (*lit >= *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator<=(list<T> const &l, list<T> const &r) {
        if (l.size() > r.size())
            return false;
        typename list<T>::const_iterator lit = l.cbegin();
        typename list<T>::const_iterator rit = r.cbegin();
        for (; lit != l.cend(); lit++, rit++)
            if (*lit > *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator>(list<T> const &l, list<T> const &r) {
        return !(l < r);
    };

    template<typename T>
    bool operator>=(list<T> const &l, list<T> const &r) {
        return !(l <= r);
    };

    template<class T, class Alloc>
    void swap(list<T, Alloc> &a, list<T, Alloc> &b) {
        a.swap(b);
    };
}


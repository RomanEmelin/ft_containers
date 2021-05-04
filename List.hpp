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
        typedef Node<value_type> *pointer;

    protected:
        pointer _ptr;

    public:
        ListIterator() : _ptr(nullptr) {};

        ListIterator(ListIterator const &other) {
            *this = other;
        }

        ListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ListIterator() {};

        pointer getNode() const { return _ptr; }

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

        pointer getNode() const { return _ptr; }

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

        pointer getNode() const {
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

        value_type &operator*() { return *(_ptr->content); };
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

        pointer getNode() const {
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

        value_type &operator*() const { return *(_ptr->content); };
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
            _size++;
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
                _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
            assign(n, val);
        };

        /**
         * Range constructor
         */
        template<class InputIterator>
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type(),
             typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0):
             _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
            assign(first, last);
        };

        /**
         * Copy constructor
         * @param x another list
         */
        list(const list &x) {
            initList();
            *this = x;
        };

        /**
         * Destructor
         */
        ~list() {
            clear();
            _allocator.destroy(_emptyNode->content);
            _allocator.deallocate(_emptyNode->content, 1);
            _node_allocator.destroy(_emptyNode);
            _node_allocator.deallocate(_emptyNode, 1);
        }

        list &operator=(const list &x) {
            if (this == &x)
                return (*this);
            clear();
            assign(x.begin(), x.end());
            return (*this);
        };

        iterator begin() { return iterator(_emptyNode->next); };
        iterator end() { return iterator(_emptyNode); };
        const_iterator begin() const { return const_iterator(_emptyNode->next); };
        const_iterator end() const { return const_iterator(_emptyNode); };
        reverse_iterator rbegin() { return _emptyNode->prev; };
        const_reverse_iterator rbegin() const { return const_reverse_iterator(_emptyNode->prev); };
        reverse_iterator rend() { return _emptyNode; };
        const_reverse_iterator rend() const { return const_reverse_iterator(_emptyNode); };

        //assign code block
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
                push_back(*first++);
        };

        /**
         * Fill assign
         * @param n number of elements
         * @param val element value
         */
        void assign(size_type n, const value_type &val) {
            clear();
            while (n--) {
                push_back(val);
            }
        };


        size_type size() const {
            return _size;
        };

        //Front and back code block

        reference front() { return *_emptyNode->next->content; };

        const_reference front() const { return *_emptyNode->next->content; };

        reference back() { return *_emptyNode->prev->content; };

        const_reference back() const { return *_emptyNode->prev->content; };

        void resize() {
            //TODO use resize
        }

        /**
         * Clear list
         */
        void clear() {
            while (_size > 0)
                pop_back();
        }

        /**
         * Add element to the back of the list
         * @param element
         */
        void push_back(const value_type &val) {
            node_ptr element = addNewNode(val, _emptyNode, _emptyNode->prev);
            _emptyNode->prev->next = element;
            _emptyNode->prev = element;
        }

        /**
         * Add element to the front of the list
         * @param element
         */
        void push_front(const value_type &val) {
            node_ptr element = addNewNode(val, _emptyNode->next, _emptyNode);
            _emptyNode->next->prev = element;
            _emptyNode->next = element;
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

        void swap(list &x) {
            ft::swap(_size, x._size);
            ft::swap(_emptyNode, x._emptyNode);
        };

        //Insert code block

        /**
         * Single element
         * The container is extended by inserting new element at the specified position
         * @param position of iterator
         * @param val element to insert
         * @return An iterator that points to the first of the newly inserted elements.
         */
        iterator insert(iterator position, const value_type& val) {
            node_ptr tmp = position.getNode();
            node_ptr newNode = addNewNode(val, tmp, tmp->prev);
            tmp->prev->next = newNode;
            tmp->prev = newNode;
            return iterator(newNode);

        };

        /**
         * filling insert
         * @param position of iterator
         * @param n Number of elements to insert. Each element is initialized to a copy of val.
         * @param val Value to be copied to the inserted elements.
         */
        void insert(iterator position, size_type n, const value_type &val) {
            while(n--)
                insert(position, val);
        };

        /**
         * filling list from position, elements from list2 first to list2 last
         * @tparam InputIterator
         * @param position
         * @param first Iterators specifying a range of elements
         * @param last
         */
        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last) {
                while (first != last)
                    insert(position, *first++);
        };

        //erase code block

        /**
         * Removes from the list container either a single element (position)
         * @param position to erase
         * @return iterator to position->next
         */
        iterator erase(iterator position) {
            node_ptr tmp = position.getNode();
            iterator it(tmp->next);
            destroyNode(tmp);
            return it;
        };

        /**
         * Removes from the list container either  a range of elements ([first,last)).
         * @param first
         * @param last
         * @return An iterator pointing to the element that followed the last element erased by the function call
         */
        iterator erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
            return iterator(last);
        };

        /**
         * Resizes the container so that it contains n elements.
         * @param n new size
         * @param val if n > size(), add new element - val
         */
        void resize(size_type n, value_type val = value_type()) {
            while (_size > n)
                pop_back();
            while (_size < n)
                push_back(val);
        };

        //splice code block

        /**
         * Transfers all the elements of x into the container.
         * @param position in destination list
         * @param x source list
         */
        void splice(iterator position, list& x) {
            insert(position, x.begin(), x.end());
            x.clear();
        };

        /**
         * Transfers only the element pointed by i from x into the container.
         * @param position in destination list
         * @param x source list
         * @param i source list position iterator
         */
        void splice (iterator position, list& x, iterator i) {
            insert(position, i ,x.end());
            x.erase(i, x.end());
        };

        /**
         * Transfers the range [first,last) from x into the container
         * @param position
         * @param x
         * @param first
         * @param last
         */
        void splice (iterator position, list& x, iterator first, iterator last) {
            insert(position, first, last);
            x.erase(first, last);
        };

        /**
         * Removes from the container all the elements that compare equal to val
         * @param val
         */
        void remove (const value_type& val) {
            for(iterator it = begin(); it != end(); it++)
                if (*it == val)
                    erase(it);
        };

        /**
         * Removes from the container all the elements for which Predicate pred returns true.
         * @tparam Predicate
         * @param pred Unary predicate that, taking a value of the same type as those contained in
         * the forward_list object, returns true for those values to be removed from the container,
         * and false for those remaining. This can either be a function pointer or a function object
         */
        template<class Predicate>
        void remove_if(Predicate pred) {
            for(iterator it = begin(); it != end(); it++)
                if (pred(*it))
                    erase(it);
        };

        //unique code block

        /**
         * Removes all but the first element from every consecutive group of equal elements in the container.
         */
        void unique() {
            iterator it = begin();
            for(; it != end(); it++) {
                iterator it2 = it;
                it2++;
                if (*it == *it2)
                    erase(it2);
            }
        };

        /**
         * Takes as argument a specific comparison function that determine the "uniqueness" of an element
         * @tparam BinaryPredicate
         * @param binary_pred Binary predicate that, taking two values of the same type than those contained
         * in the list, returns true to remove the element passed as first argument from the container,
         * and false otherwise. This shall be a function pointer or a function object.
         */
        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred) {
            iterator it = begin();
            for(; it != end(); it++) {
                iterator it2 = it;
                it2++;
                if (binary_pred(*it, *it2))
                    erase(it2);
            }
        };

        //Merge code block

        /**
         * Merges x into the list by transferring all of its elements at their respective ordered
         * positions into the container (both containers shall already be ordered)
         * @param x source list
         */
        void merge(list& x) {
            if (&x == this)
                return;
            splice(end(), x.begin(), x.end());
        };

        /**
         * Merge element is compare
         * @tparam Compare
         * @param x
         * @param comp some function to compare
         */
        template <class Compare>
        void merge (list& x, Compare comp) {
            if (&x == this)
                return;
            iterator itr = begin();
            iterator ite = end();
            iterator itrX = x.begin();
            iterator iteX = x.end();
            for (; itrX != iteX && itr != ite;) {
                for (; comp(*itr, *itrX) && itr != ite; itr++);
                splice(itr, x, itrX++);
            }
            while (!x.empty())
            {
                splice(ite, x, itrX++);
            }
        };

        //sort code block

        /**
         * Sort elements in container in order from min to max
         */
        void sort() {
            for(iterator it = begin(); it != end(); it++) {
                iterator it2 = it;
                it2++;
                for (; it2 != end(); it2++) {
                    if (*it > *it2)
                        ft::swap(*it, *it2);
                }
            }
        };

        /**
         * Sort elements in container by comparator
         * @tparam Compare
         * @param comp some function for compare elements
         */
        template <class Compare>
        void sort(Compare comp) {
            for(iterator it = begin(); it != end(); it++) {
                iterator it2 = it;
                it2++;
                for (; it2 != end(); it2++) {
                    if (comp(*it, it2))
                        ft::swap(*it, *it2);
                }
            }
        };
    };

    template<typename T>
    bool operator==(list<T> const &l, list<T> const &r) {
        if (l.size() != r.size())
            return false;
        typename list<T>::const_iterator lit = l.begin();
        typename list<T>::const_iterator rit = r.begin();
        for (; lit != l.end(); lit++, rit++)
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
        typename list<T>::const_iterator lit = l.begin();
        typename list<T>::const_iterator rit = r.begin();
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


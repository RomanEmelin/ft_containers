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

    template<class V>
    struct rbNode {
        V *data;
        rbNode *parent;
        rbNode *right;
        rbNode *left;
        int color;
    };
    template<class V>
    class MapIterator: public std::iterator<std::bidirectional_iterator_tag, V> {

    public:
        typedef rbNode<V>* pointer;
        typedef rbNode<V>& reference;
    private:
        pointer _ptr;
    public:
        explicit MapIterator(pointer ptr = nullptr) : _ptr(ptr) {};

        virtual ~MapIterator() {};

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
            _ptr = getNext(_ptr);
            return *this;
        };

        MapIterator operator++(int) {
            MapIterator tmp(*this);
            operator++();
            return tmp;
        };

        MapIterator operator--() {
            _ptr = getPrev(_ptr);
            return *this;
        };

        MapIterator operator--(int) {
            MapIterator tmp(*this);
            operator--();
            return tmp;
        };

        bool operator==(const MapIterator &x) const { return _ptr == x._ptr; };

        bool operator!=(const MapIterator &x) const { return _ptr != x._ptr; };

        V &operator*() const { return *(_ptr->data); };

        V *operator->() const { return _ptr->data; };

    private:
        pointer getNext(pointer ptr) {
            if (ptr->right)
                return getMinimalFromIt(ptr->right);
            else if (ptr->parent && ptr->parent->right == ptr) {
                ptr = ptr->parent;
                return ptr->parent;
            }
            pointer tmp = ptr;
            for (; tmp->parent->right == tmp; tmp = tmp->parent)
                if (!tmp)
                    return ptr->right;
            return tmp->parent;
        };

        pointer getPrev(pointer ptr) {
            if (ptr->left)
                return getMaximalFromIt(ptr->left);
            else if (ptr->parent && ptr->parent->right == ptr)
                return ptr->parent;
            pointer tmp = ptr;
            for (; tmp->parent->left == tmp; tmp = tmp->parent)
                if (!tmp)
                    return ptr->left;
            return tmp->parent;
        };

        pointer getMaximalFromIt(pointer ptr) {
            if (ptr && ptr->right)
                while (ptr->right)
                    ptr = ptr->right;
            return ptr;
        };

        pointer getMinimalFromIt(pointer ptr) {
            if (ptr && ptr->left)
                while (ptr->left)
                    ptr = ptr->left;
            return ptr;
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
            _ptr = getPrev(_ptr);
            return *this;
        };

        ReverseMapIterator operator++(int) {
            ReverseMapIterator tmp(*this);
            operator++();
            return tmp;
        };

        ReverseMapIterator operator--() {
            _ptr = getNext(_ptr);
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

    private:
        pointer getNext(pointer ptr) {
            if (ptr->right)
                return getMinimalFromIt(ptr->right);
            else if (ptr->parent && ptr->parent->right == ptr) {
                ptr = ptr->parent;
                return ptr->parent;
            }
            pointer tmp = ptr;
            for (; tmp->parent->right == tmp; tmp = tmp->parent)
                if (!tmp)
                    return ptr->right;
            return tmp->parent;
        };

        pointer getPrev(pointer ptr) {
            if (ptr->left)
                return getMaximalFromIt(ptr->left);
            else if (ptr->parent && ptr->parent->right == ptr)
                return ptr->parent;
            pointer tmp = ptr;
            for (; tmp->parent->left == tmp; tmp = tmp->parent)
                if (!tmp)
                    return ptr->left;
            return tmp->parent;
        };

        pointer getMaximalFromIt(pointer ptr) {
            if (ptr && ptr->right)
                while (ptr->right)
                    ptr = ptr->right;
            return ptr;
        };

        pointer getMinimalFromIt(pointer ptr) {
            if (ptr && ptr->left)
                while (ptr->left)
                    ptr = ptr->left;
            return ptr;
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
        typedef rbNode<value_type>                                       node;
        typedef rbNode<value_type>*                                      node_pointer;
        typedef rbNode<value_type>&                                      node_reference;
        typedef typename allocator_type::template rebind<node>::other  node_allocator;

    private:
        enum Color {
            _BLACK,
            _RED
        };

        node_allocator _alloc_node;
        allocator_type _alloc_value;
        key_compare _comp;
        node_pointer _root;
        node_pointer _end;
        size_type _size;

        void initMap() {
            _end = _alloc_node.allocate(1);
            _end->parent = _end;
            _end->left = _end;
            _end->right = _end;
            _end->data = _alloc_value.allocate(0);
            _end->color = _BLACK;
        };

        node_pointer createNode(value_type val, node_pointer parent, int color = _RED){
            node_pointer newElem = _alloc_node.allocate(1);
            newElem->parent = parent;
            newElem->right = nullptr;
            newElem->left = nullptr;
            newElem->color = color;
            newElem->data = _alloc_value.allocate(1);
            _alloc_value.construct(newElem->data, val);
            return newElem;
        };

    public:

        /**
         * Default constructor
         * @param comp Comparator for keys
         * @param alloc allocator for pair Key value
         */
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
            _alloc_value(alloc), _comp(comp), _root(nullptr), _end(nullptr), _size(0) {
            initMap();
        };

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0):
                _alloc_value(alloc), _comp(comp), _root(nullptr), _end(nullptr), _size(0) {
                    initMap();
            (void)first, last;
                   // insert(first, last);
                };

        /**
         * Returns an iterator referring to the first element in the map container.
         * @return An iterator to the first element in the container.
         */
        iterator begin() {return iterator(_end->right);};
        const_iterator begin() const {return const_iterator(_end->right);};

        /**
         * Returns an iterator referring to the past-the-end element in the map container
         * @return An iterator to the past-the-end element in the container.
         */
        iterator end() {return iterator(_end);};
        const_iterator end() const {return const_iterator(_end);};

        /**
         *
         * @param val pair key - value
         * @return it on new elem and true if insert success, and it on end and false if insert fail
         */
        std::pair<iterator, bool> insert(const value_type& val) {
            if (_root) {
                _root = createNode(val, nullptr, _BLACK);
                _root->right = _end;
                _end->parent = _root;
                _end->left = _end;
            }
            else if (find(val.first) == end())
                return std::pair<iterator, bool>(iterator(_end), false);
            return std::pair<iterator, bool>(iterator(_root), true);
        };

        /**
         * Searches the container for an element with a key equivalent to k and returns an iterator to it if found,
         * otherwise it returns an iterator to end().
         * @param k it is a key
         * @return An iterator to the element, if an element with specified key is found, or end otherwise.
         */
        iterator find (const key_type& k) {
            iterator it = begin();
            for(iterator ite = end(); it != end() && it->first != k; it++);
            return it;
        };

        const_iterator find (const key_type& k) const {
            const_iterator it = begin();
            for(const_iterator ite = end(); it != end() && it->first != k; it++);
            return it;
        };
    };
}
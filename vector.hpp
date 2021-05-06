/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

#include <memory>
#include <iostream>

namespace ft {

    template<class T>
    class vector_iterator: public std::iterator<std::random_access_iterator_tag, T> {

    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::ptrdiff_t difference_type;

    protected:
        pointer _ptr;

    public:
        vector_iterator(): _ptr(nullptr) {};

        vector_iterator(const vector_iterator& a) {
            if (this == &a)
                return;
            *this = a;
        };

        vector_iterator &operator=(const vector_iterator& a) {
            _ptr = a._ptr;
            return *this;
        };

        ~vector_iterator();

        //bool operation
        bool operator==(const vector_iterator& a) {return _ptr == a._ptr;};
        bool operator!=(const vector_iterator& a) {return _ptr != a._ptr;};
        bool operator<(const vector_iterator& a) {return _ptr < a._tr;};
        bool operator<=(const vector_iterator& a) {return _ptr <= a._ptr;};
        bool operator>(const vector_iterator& a) {return _ptr > a._ptr;};
        bool operator>=(const vector_iterator& a) {return _ptr >= a._ptr;};
        //arithmetic operations
        vector_iterator operator+(difference_type ptr) const {return iterator(_ptr + ptr);};
        difference_type operator+(vector_iterator& a) {return _ptr + a._ptr;}
        vector_iterator operator-(difference_type ptr) const {return iterator(_ptr - ptr);};
        difference_type operator-(vector_iterator& a) {return _ptr - a._ptr;}
        vector_iterator &operator+=(difference_type &ptr) {_ptr += ptr; return *this;};
        vector_iterator &operator-=(difference_type &ptr) {_ptr -= ptr; return *this;};
        vector_iterator &operator++() {++_ptr; return *this;};
        vector_iterator operator++(int) {vector_iterator tmp(*this); ++(*this); return tmp;};
        vector_iterator &operator--() {--_ptr; return *this;};
        vector_iterator operator--(int) {vector_iterator tmp(*this); --(*this); return tmp;};

        reference operator[](difference_type val) const {return _ptr[val];};
        reference operator*() {return *_ptr;};
        pointer operator->() {return _ptr;};
    };

    template<class T>
    class reverse_vector_iterator: public std::iterator<std::random_access_iterator_tag, T> {

    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::ptrdiff_t difference_type;

    protected:
        pointer _ptr;

    public:
        reverse_vector_iterator(): _ptr(nullptr) {};

        reverse_vector_iterator(const reverse_vector_iterator& a) {
            if (this == &a)
                return;
            *this = a;
        };

        reverse_vector_iterator &operator=(const reverse_vector_iterator& a) {
            _ptr = a._ptr;
            return *this;
        };

        ~reverse_vector_iterator();

        //bool operation
        bool operator==(const reverse_vector_iterator& a) {return _ptr == a._ptr;};
        bool operator!=(const reverse_vector_iterator& a) {return _ptr != a._ptr;};
        bool operator<(const reverse_vector_iterator& a) {return _ptr < a._tr;};
        bool operator<=(const reverse_vector_iterator& a) {return _ptr <= a._ptr;};
        bool operator>(const reverse_vector_iterator& a) {return _ptr > a._ptr;};
        bool operator>=(const reverse_vector_iterator& a) {return _ptr >= a._ptr;};
        //arithmetic operations
        reverse_vector_iterator operator+(difference_type ptr) const {return iterator(_ptr + ptr);};
        difference_type operator+(reverse_vector_iterator& a) {return _ptr + a._ptr;}
        reverse_vector_iterator operator-(difference_type ptr) const {return iterator(_ptr - ptr);};
        difference_type operator-(reverse_vector_iterator& a) {return _ptr - a._ptr;}
        reverse_vector_iterator &operator+=(difference_type &ptr) {_ptr += ptr; return *this;};
        reverse_vector_iterator &operator-=(difference_type &ptr) {_ptr -= ptr; return *this;};
        reverse_vector_iterator &operator++() {++_ptr; return *this;};
        reverse_vector_iterator operator++(int) {reverse_vector_iterator tmp(*this); ++(*this); return tmp;};
        reverse_vector_iterator &operator--() {--_ptr; return *this;};
        reverse_vector_iterator operator--(int) {reverse_vector_iterator tmp(*this); --(*this); return tmp;};

        reference operator[](difference_type val) const {return _ptr[val];};
        reference operator*() {return *_ptr;};
        pointer operator->() {return _ptr;};
    };

    /**
     * Vector
     * @tparam T
     * @tparam Alloc
     */
    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:

        typedef T value_type;
        typedef Alloc allocator_type;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef vector_iterator<value_type> iterator;
        typedef vector_iterator<const value_type> const_iterator;
        typedef reverse_vector_iterator<value_type> reverse_iterator;
        typedef reverse_vector_iterator<const value_type> const_reverse_iterator;
        typedef typename std::iterator_traits<iterator>::difference_type difference_type;
        typedef size_t size_type;

    private:
        pointer _array;
        allocator_type _allocator;
        size_type _size;
        size_type _capacity;

    public:

        /**
         * default constructor
         * @param alloc
         */
        explicit vector(const allocator_type& alloc = allocator_type()):
        _array(nullptr), _allocator(alloc), _size(0), _capacity(0) {};

        /**
         * Filling constructor
         * @param n Number of elements
         * @param val element
         * @param alloc
         */
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()):
                _array(nullptr), _allocator(alloc), _size(0), _capacity(0) {
            _array = _allocator.allocate(0);
            assign(n, val);
        };

        /**
         * Range constructor
         * @tparam InputIterator
         * @param first
         * @param last
         * @param alloc
         */
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _allocator(alloc) {
            _array = _allocator.allocate(0);
            assign(first, last);
        };

        /**
         * Removes all elements from the list container (which are destroyed),
         * and leaving the container with a size of 0.
         */
        void clear() {
            while(_size--)
                pop_back();
        };

        /**
         * This is the number of actual objects held in the vector,
         * which is not necessarily equal to its storage capacity.
         * @return _size
         */
        size_type size() const {return _size;};

        //assign code block

        /**
         * Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
         * @param n Number of elements
         * @param val element
         */
        void assign(size_type n, const value_type& val) {
            clear();
            while (n--)
                push_back(val);
        }

        /**
         * Assign the new contents are n elements, each initialized to a copy of val.
         * @tparam InputIterator
         * @param first
         * @param last
         */
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last) {
            clear();

        };

        /**
         * Removes the last element in the vector, effectively reducing the container size by one.
         */
        void pop_back() {_allocator.destroy(_array + (--_size));};

        /**
         * Requests that the vector capacity be at least enough to contain n elements.
         * @param n Minimum capacity for the vector. Note that the resulting vector capacity
         * may be equal or greater than n. Member type size_type is an unsigned integral type.
         */
        void reserve(size_type n) {
            if (n > max_size())
                throw std::length_error("The requested storage space is too large");
            if (n > _capacity) {
                pointer tmp = _allocator.allocate(n);
                for (size_type i = 0; i < _size; i++) {
                    _allocator.construct(tmp + i, *(_array + i));
                    _allocator.destroy(_array + i);
                }
                _allocator.deallocate(_array, _capacity);
                _capacity = n;
                _array = tmp;
            }
        }

        /**
         * Adds a new element at the end of the vector, after its current last element.
         */
        void push_back(const value_type& val) {
            if (_size + 1 > _capacity)
                reserve(_size + 1);
            _array[_size++] = val;
        };

        /**
         * Returns the maximum number of elements that the vector can hold.
         * @return The maximum number of elements a vector container can hold as content.
         */
        size_type max_size()  const {return allocator_type().max_size();};

        size_type capacity() const {return _capacity;};

        //insert code block


        iterator insert(iterator position, const value_type& val) {
            if (_size + 1 > _capacity)
                reserve(_size + 1);
            size_type pos = position.operator->() - _array;

        };

        void insert(iterator position, size_type n, const value_type& val) {
            while (n--)
                position = insert(position, val);
        };

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last) {
            for (; first != last; first++, position++)
                insert(position, *first);
        }

        reference operator[](size_type n) const{return _array[n];};
    };
}

/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

#include <memory>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <math.h>


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

        vector_iterator(pointer ptr): _ptr(ptr) {};

        vector_iterator(const vector_iterator& a) {
            if (this == &a)
                return;
            *this = a;
        };

        vector_iterator &operator=(const vector_iterator& a) {
            _ptr = a._ptr;
            return *this;
        };

        ~vector_iterator() {};

        //bool operation
        bool operator==(const vector_iterator& a) {return _ptr == a._ptr;};
        bool operator!=(const vector_iterator& a) {return _ptr != a._ptr;};
        bool operator<(const vector_iterator& a) {return _ptr < a._tr;};
        bool operator<=(const vector_iterator& a) {return _ptr <= a._ptr;};
        bool operator>(const vector_iterator& a) {return _ptr > a._ptr;};
        bool operator>=(const vector_iterator& a) {return _ptr >= a._ptr;};
        //arithmetic operations
        vector_iterator operator+(difference_type ptr) const {return vector_iterator(_ptr + ptr);};
        vector_iterator operator+(size_t n) const {return  vector_iterator(_ptr + n);};
        difference_type operator+(vector_iterator& a) {return _ptr + a._ptr;}
        vector_iterator operator-(difference_type ptr) const {return vector_iterator(_ptr - ptr);};
        difference_type operator-(vector_iterator& a) {return _ptr - a._ptr;}
        vector_iterator &operator+=(difference_type &ptr) {_ptr += ptr; return *this;};
        vector_iterator &operator-=(difference_type &ptr) {_ptr -= ptr; return *this;};
        vector_iterator &operator++() {++_ptr; return *this;};
        vector_iterator operator++(int) {vector_iterator tmp(_ptr); ++_ptr; return tmp;};
        vector_iterator &operator--() {--_ptr; return *this;};
        vector_iterator operator--(int) {vector_iterator tmp(_ptr); --_ptr; return tmp;};

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

        reverse_vector_iterator(pointer ptr): _ptr(ptr) {};

        reverse_vector_iterator(const reverse_vector_iterator& a) {
            if (this == &a)
                return;
            *this = a;
        };

        reverse_vector_iterator &operator=(const reverse_vector_iterator& a) {
            _ptr = a._ptr;
            return *this;
        };

        ~reverse_vector_iterator() {};

        //bool operation
        bool operator==(const reverse_vector_iterator& a) {return _ptr == a._ptr;};
        bool operator!=(const reverse_vector_iterator& a) {return _ptr != a._ptr;};
        bool operator<(const reverse_vector_iterator& a) {return _ptr < a._tr;};
        bool operator<=(const reverse_vector_iterator& a) {return _ptr <= a._ptr;};
        bool operator>(const reverse_vector_iterator& a) {return _ptr > a._ptr;};
        bool operator>=(const reverse_vector_iterator& a) {return _ptr >= a._ptr;};
        //arithmetic operations
        reverse_vector_iterator operator+(difference_type ptr) const {return reverse_vector_iterator(_ptr - ptr);};
        difference_type operator+(reverse_vector_iterator& a) {return _ptr - a._ptr;}
        reverse_vector_iterator operator-(difference_type ptr) const {return reverse_vector_iterator(_ptr + ptr);};
        difference_type operator-(reverse_vector_iterator& a) {return _ptr + a._ptr;}
        reverse_vector_iterator &operator+=(difference_type &ptr) {_ptr -= ptr; return *this;};
        reverse_vector_iterator &operator-=(difference_type &ptr) {_ptr += ptr; return *this;};
        reverse_vector_iterator &operator++() {--_ptr; return *this;};
        reverse_vector_iterator operator++(int) {reverse_vector_iterator tmp(_ptr); --_ptr; return tmp;};
        reverse_vector_iterator &operator--() {++_ptr; return *this;};
        reverse_vector_iterator operator--(int) {reverse_vector_iterator tmp(_ptr); ++_ptr; return tmp;};

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

        size_type distance(iterator first, iterator last) {
            size_type dst = 0;
            for (;first != last; first++, dst++);
            return dst;
        };

    public:

        /**
         * default constructor
         * @param alloc
         */
        explicit vector(const allocator_type& alloc = allocator_type()):
        _array(nullptr), _allocator(alloc), _size(0), _capacity(0) {
            _array = _allocator.allocate(0);
        };

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
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
               typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0):
               _array(nullptr), _allocator(alloc), _size(0), _capacity(0) {
            _array = _allocator.allocate(0);
            assign(first, last);
        };

        vector(const vector& x){
            if (this == &x)
                return ;
            *this = x;
        }

        virtual ~vector() {
          if (_array)
               clear();
          _allocator.deallocate(_array, _capacity);
          _capacity = 0;
          _size = 0;
        };

        vector &operator=(const vector& x) {
            _allocator.deallocate(_array, _capacity);
            _allocator = x._allocator;
            _array = _allocator.allocate(0);
            assign(x.begin(), x.end());
            return *this;
        }

        /**
         * Returns an iterator pointing to the first element in the vector
         * @return An iterator to the beginning of the sequence container.
         */
        iterator begin() {return iterator(_array);};
        const_iterator begin() const {return const_iterator(_array);};
        iterator end() {return iterator(_array + _size);};
        const_iterator end() const {return const_iterator(_array + _size);};
        reverse_iterator rbegin() {return reverse_iterator (end());};
        const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
        reverse_iterator rend() {return reverse_iterator(begin());};
        const_reverse_iterator rend() const {return const_reverse_iterator(begin());};

        /**
         * Removes all elements from the list container (which are destroyed),
         * and leaving the container with a size of 0.
         */
        void clear() {
            while(_size)
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
            insert(begin(), n, val);
        }

        /**
         * Assign the new contents are n elements, each initialized to a copy of val.
         * @tparam InputIterator
         * @param first
         * @param last
         */
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                     typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            clear();
            insert(begin(), first, last);
        };

        /**
         * Removes the last element in the vector, effectively reducing the container size by one.
         */
        void pop_back() {_allocator.destroy(_array + --_size);};

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
            insert(end(), 1, val);
        };

        /**
         * Returns the maximum number of elements that the vector can hold.
         * @return The maximum number of elements a vector container can hold as content.
         */
        size_type max_size()  const {return allocator_type().max_size();};

        size_type capacity() const {return _capacity;};

        //insert code block

        /**
         * The vector is extended by inserting new elements before the element at the specified position,
         * effectively increasing the container size by the number of elements inserted.
         * @param position Position in the vector where the new elements are inserted.
         * @param val Value to be copied (or moved) to the inserted elements
         * @return An iterator that points to the first of the newly inserted elements.
         */
        iterator insert(iterator position, const value_type& val) {
            size_type pos = distance(begin(), position);
            if (_size + 1  > _capacity)
                reserve(_size >= 0 && _size + 1 <= 8 ? _size + 1 : _size * 2);
            _size++;
            for (size_type j = _size - 1; j > pos; j--)
                _array[j] = _array[j - 1];
            _array[pos] = val;
            return iterator(_array + pos);
        };

        /**
         * The vector is extended by inserting new elements before the element at the specified position,
         * effectively increasing the container size by the number of elements inserted.
         * @param position Position in the vector where the new elements are inserted.
         * @param n val Value to be copied (or moved) to the inserted elements
         * @param val Value to be copied (or moved) to the inserted elements.
         */
        void insert(iterator position, size_type n, const value_type& val) {
            while(n--)
                position = insert(position, val);
        };

        /**
         * Iterators specifying a range of elements. Copies of the elements in the range [first,last)
         * are inserted at position (in the same order).
         * @tparam InputIterator
         * @param position Position in the vector where the new elements are inserted.
         * @param first
         * @param last
         */
        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
            for (; first != last; first++, position++)
                position = insert(position, *first);
        }

        /**
         * Returns whether the vector is empty (i.e. whether its size is 0).
         * @return True if size is 0
         */
        bool empty() const {return 0 == _size;};

        /**
         *
         * @param n New container size, expressed in number of elements.
         * @param val Object whose content is copied to the added elements
         */
        void resize(size_type n, value_type val = value_type()) {
            while (_size > n)
                pop_back();
            while (_size < n)
                push_back(val);
        }

        // at code block

        /**
         * Returns a reference to the element at position n in the vector.
         * @param n index
         * @return
         */
        reference at(size_type n) {
            if (n >= _size)
                throw std::out_of_range("Index out of range");
            return _array[n];
        };

        /**
         * Returns a reference to the element at position n in the vector.
         * @param n index
         * @return
         */
        const_reference at(size_type n) const {
            if (n >= _size)
                throw std::out_of_range("Index out of range");
            return _array[n];
        };

        //erase code block

        /**
         * Removes from the vector either a single element (position)
         * @param position Iterator pointing to a single element to be removed from the vector.
         * @return An iterator pointing to the new location of the element that followed the last element erased by the function call
         */
        iterator erase(iterator position) {
            iterator ret(position);
            while (position != end() - 1)
                *position = *(++position);
            _size--;
            return ret;
        };

        /**
         *Removes from the vector either a range of elements ([first,last)).
         * @param first
         * @param last
         * @return
         */
        iterator erase(iterator first, iterator last) {
            while (first != last)
                erase(--last);
            return last;
        };

        /**
         * Exchanges the content of the container by the content of x,
         * which is another vector object of the same type. Sizes may differ.
         * @param x Another vector container of the same type
         */
        void swap (vector& x) {
            ft::swap(_array, x._array);
            ft::swap(_size, x._size);
            ft::swap(_capacity, x._capacity);
        };

        reference front() {return _array[0];};
        const_reference front() const {return _array[0];};
        reference back() {return _array[_size - 1];};
        const_reference back() const {return _array[_size - 1];}

        reference operator[](size_type n) {return _array[n];};
        const_reference operator[](size_type n) const {return _array[n];};
    };
    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs == rhs;};

    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs != rhs;};
    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs < rhs;};
    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs <= rhs;};
    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs > rhs;};
    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return lhs >= rhs;};

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {x.swap(y);};
}

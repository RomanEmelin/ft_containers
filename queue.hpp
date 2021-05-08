/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once
#include "list.hpp"

namespace ft {

    template<class T, class Container = ft::list<T> >
    class queue {

    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        container_type _cntr;

    public:
        /**
         * Constructs a queue container adaptor object.
         * @param ctnr Container object.
         */
        explicit queue(const container_type& cntr = container_type()): _cntr(cntr) {};

        queue(const queue<value_type, container_type> &x): _cntr(x._cntr) {};

        queue &operator=(const queue<value_type, container_type> &x) {
            if (this == &x)
                return ;
            _cntr = x._cntr;
            return *this;
        };

        virtual ~queue() {};
        /**
         * Returns whether the queue is empty: i.e. whether its size is zero.
         * @return true if size is 0 and false if not
         */
        bool empty() const {return _cntr.empty();};

        /**
         * Returns the number of elements in the queue.
         * @return the number of elements in the queue.
         */
        size_type size() const {return _cntr.size();};

        /**
         * Returns a reference to the next element in the queue.
         * @return A reference to the next element in the queue.
         */
        value_type& front() {return _cntr.front();};
        const value_type& front() const {return _cntr.front();};

        /**
         * Returns a reference to the last element in the queue.
         * @return A reference to the last element in the queue.
         */
        value_type& back() {return _cntr.back();};
        const value_type& back() const {return _cntr.back();};

        /**
         * Inserts a new element at the end of the queue, after its current last element
         * @param val Value to which the inserted element is initialized.
         */
        void push (const value_type& val) {_cntr.push_back(val);};

        /**
         * Removes the next element in the queue, effectively reducing its size by one.
         */
        void pop() {_cntr.pop_front();};
    };

    template <class T, class Container>
    bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr == rhs._cntr;};
    template <class T, class Container>
    bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr != rhs._cntr;};
    template <class T, class Container>
    bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr < rhs._cntr;};
    template <class T, class Container>
    bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr <= rhs._cntr;};
    template <class T, class Container>
    bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr > rhs._cntr;};
    template <class T, class Container>
    bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {return lhs._cntr >= rhs._cntr;};
}
/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

namespace ft {

    template<class T, class Container = ft::list<T> >
    class stack {

    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        container_type _cntr;

    public:
        /**
         * Constructs a stack container adaptor object.
         * @param ctnr Container object.
         */
        explicit stack(const container_type& cntr = container_type()): _cntr(cntr) {};

        stack(const stack<value_type, container_type> &x): _cntr(x._cntr) {};

        stack &operator=(const stack<value_type, container_type> &x) {
            if (this == &x)
                return ;
            _cntr = x._cntr;
            return *this;
        };

        virtual ~stack() {};
        /**
         * Returns whether the stack is empty: i.e. whether its size is zero.
         * @return true if size is 0 and false if not
         */
        bool empty() const {return _cntr.empty();};

        /**
         * Returns a reference to the top element in the stack.
         * @return A reference to the top element in the stack.
         */
        value_type& top() {return _cntr.back();};
        const value_type& top() const{return _cntr.back();};

        /**
         * Returns the number of elements in the stack.
         * @return the number of elements in the stack.
         */
        size_type size() const {return _cntr.size();};

        /**
         * Inserts a new element at the end of the stack, after its current last element
         * @param val Value to which the inserted element is initialized.
         */
        void push(const value_type& val) {_cntr.push_back(val);};

        /**
         * Removes the next element in the stack, effectively reducing its size by one.
         */
        void pop() {_cntr.pop_back();};
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr == rhs._cntr;};
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr != rhs._cntr;};
    template <class T, class Container>
    bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr < rhs._cntr;};
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr <= rhs._cntr;};
    template <class T, class Container>
    bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr > rhs._cntr;};
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr >= rhs._cntr;};
}
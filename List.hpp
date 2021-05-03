/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

#include <memory>

namespace ft {

	template<class T>
	struct Node {
		T content;
		Node *next;
		Node *prev;
	};

	template<class T>
	class listIterator {

	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;

	protected:
		pointer _ptr;

	public:
		listIterator(): _ptr(nullptr) {};
		listIterator(listIterator const &other) {
			*this = other;
		}

		listIterator(pointer ptr): _ptr(ptr) {};

		virtual ~listIterator() {};

		pointer node() const {
			return _ptr;
		}

		listIterator &operator=(listIterator const &other) {
			_ptr = other._ptr;
			return *this;
		}

		listIterator &operator++() {
			_ptr = _ptr->next;
		}

		listIterator operator++(int) {
			listIterator tmp(*this);
			_ptr = _ptr->next;
			return (tmp);
		}

		listIterator &operator--() {
			_ptr = _ptr->prev;
		}

		listIterator operator--(int) {
			listIterator tmp(*this);
			_ptr = _ptr->prev;
			return (tmp);
		}

		bool operator==(listIterator const &other) {
			return _ptr == other._ptr;
		}

		bool operator!=(listIterator const &other) {
			return _ptr != other._ptr;
		}

		value_type &operator*() {
			return _ptr->content;
		}
	};

	template<class T>
	class ReverselistIterator {

	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;

	protected:
		pointer _ptr;

	public:
		ReverselistIterator() {};
		ReverselistIterator(ReverselistIterator const &other) {
			*this = other;
		}

		ReverselistIterator(pointer ptr): _ptr(ptr) {};

		virtual ~ReverselistIterator() {};

		pointer node() const {
			return _ptr;
		}

		ReverselistIterator &operator=(ReverselistIterator const &other) {
			_ptr = other._ptr;
			return *this;
		}

		ReverselistIterator &operator++() {
			_ptr = _ptr->prev;
		}

		ReverselistIterator operator++(int) {
			ReverselistIterator tmp(*this);
			_ptr = _ptr->prev;
			return (tmp);
		}

		ReverselistIterator &operator--() {
			_ptr = _ptr->next;
		}

		ReverselistIterator operator--(int) {
			ReverselistIterator tmp(*this);
			_ptr = _ptr->next;
			return (tmp);
		}

		bool operator==(ReverselistIterator const &other) {
			return _ptr == other._ptr;
		}

		bool operator!=(ReverselistIterator const &other) {
			return _ptr != other._ptr;
		}

		value_type &operator*() {
			return _ptr->content;
		}
	};

	template <class T, class Alloc = std::allocator<T> >
	class list {
		public:

			/**
			 * Types definition
			 */
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef Node<value_type>* node_ptr;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename std::ptrdiff_t difference_type;
			typedef unsigned long size_type;
			/**
			 * Iterators
			 */
			typedef listIterator<value_type> iterator;
			typedef const listIterator<value_type> const_iterator;
			typedef ReverselistIterator<value_type> reverse_iterator;
			typedef const  ReverselistIterator<value_type> const_reverse_iterator;

		private:
			node_ptr _emptyNode;
			allocator_type _allocator;
			size_type _size;

			/**
			 * list initialization
			 */
			void initList() {
				_emptyNode = new Node<value_type>();
				_emptyNode->next = _emptyNode;
				_emptyNode->prev = _emptyNode;
			};

			void assign(size_type n, value_type val) {
				node_ptr currNode;
				while (n--) {
					currNode = Node<value_type>(val);
					_emptyNode->next = currNode;
					currNode->prev = _emptyNode;
				}
			};
		public:

			/**
			 * Default constructors
			 */
			explicit list(allocator_type const &alloc = allocator_type()):
				_emptyNode(nullptr), _allocator(alloc), _size(0){
				initList();
			};

			/**
			 * Fill constructor
			 */
			explicit list(size_type n, value_type &val = value_type(),
				 allocator_type const &alloc = allocator_type()):
					_emptyNode(nullptr), _allocator(alloc), _size(n){
				initList();
				assign(n, val);
			}

			iterator begin() const {
				return iterator(_emptyNode->next);
			};

			bool empty() const {
				return _size == 0;
			};

			iterator end() const {
				return iterator(_emptyNode);
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

	};
}


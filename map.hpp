/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once
#include "list.hpp"
#include <iterator>

namespace ft {

    
    /**
     * Red-black tree node
     * @tparam Key
     * @tparam T
     */
    template <class Key, class T>
    struct rbNode {
        std::pair<Key, T> content;
        rbNode *parent;
        rbNode *right;
        rbNode *left;
        bool    color;
    };

    /**
     * @tparam Key map::key_type
     * @tparam T map::mapped_type
     * @tparam Compare map::key_compare
     * @tparam Alloc map::allocator_type
     */
    template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> >
    class map {

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef map_iterator<value_type> iterator;
        typedef map_iterator<const value_type> const_iterator;
        typedef reverse_map_iterator<value_type> reverse_iterator;
        typedef reverse_map_iterator<const value_type> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef rbNode<value_type>* node_ptr;
        typedef rbNode<value_type>& node_ref;

        //TODO binary search trees
    private:

        bool _black = true, _red = false;
        allocator_type _allocator;
        rbNode          _root;
        size_type _size;

    public:

    };

}
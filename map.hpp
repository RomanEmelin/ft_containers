/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

namespace ft {

    /**
     * @tparam Key map::key_type
     * @tparam T map::mapped_type
     * @tparam Compare map::key_compare
     * @tparam Alloc map::allocator_type
     */
    template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> >
    class map {

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::reference reference;

        //TODO binary search trees
    };

}
/**####################################################
*###				  Create by 		            ###
*###		Roman Emelin aka Magnemite Winter       ###
*######################################################*/

#pragma once

namespace ft {

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    };
}
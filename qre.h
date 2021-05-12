//
// Created by Magnemite Winter on 5/12/21.
//

#ifndef FT_CONTAINERS_QRE_H
#define FT_CONTAINERS_QRE_H
template<class V>
class  ReverseMapIterator {

private:
    struct rbNode {
        V* data;
        rbNode *parent;
        rbNode *right;
        rbNode *left;
        int     color;
    };

    rbNode* _ptr;
public:
    explicit ReverseMapIterator(rbNode ptr = nullptr): _ptr(ptr) {};
    virtual ~ReverseMapIterator() {};
    ReverseMapIterator(const ReverseMapIterator& x) {
        if (this == &x)
            return ;
        *this = x;
    };

    ReverseMapIterator &operator=(const ReverseMapIterator& x) {
        _ptr = x._ptr;
        return *this;
    };

    ReverseMapIterator operator++() {
        _ptr = getNext();
        return *this;
    };

    ReverseMapIterator operator++(int) {
        ReverseMapIterator tmp(*this);
        operator++();
        return tmp;
    };

    ReverseMapIterator operator--() {
        _ptr = getPrev();
        return *this;
    };

    ReverseMapIterator operator--(int) {
        ReverseMapIterator tmp(*this);
        operator--();
        return tmp;
    };

    bool operator==(const ReverseMapIterator &x) const {return _ptr == x._ptr;};
    bool operator!=(const ReverseMapIterator &x) const {return _ptr != x._ptr;};
    V &operator*() const {return *(_ptr->data);};
    V *operator->() const {return _ptr->data;};

private:
    rbNode *getNext(rbNode *ptr) {
        if (ptr->right)
            return getMinimalFromIt(ptr->right);
        else if (ptr->parent && ptr->parent->right == ptr) {
            ptr = ptr->parent;
            return ptr->parent;
        }
        rbNode *tmp = ptr;
        for (;tmp->parent->right == tmp; tmp = tmp->parent)
            if (!tmp)
                return ptr->right;
        return tmp->parent;
    };

    rbNode *getPrev(rbNode *ptr) {
        if (ptr->left)
            return getMaximalFromIt(ptr->left);
        else if (ptr->parent && ptr->parent->right == ptr)
            return ptr->parent;
        rbNode *tmp = ptr;
        for (;tmp->parent->left == tmp; tmp = tmp->parent)
            if (!tmp)
                return ptr->left;
        return tmp->parent;
    };

    rbNode *getMaximalFromIt(rbNode *ptr) {
        if(ptr && ptr->right)
            while(ptr->right)
                ptr = ptr->right;
        return ptr;
    };

    rbNode *getMinimalFromIt(rbNode *ptr) {
        if (ptr && ptr->left)
            while(ptr->left)
                ptr = ptr->left;
        return ptr;
    };
};

rbNode *getMinimalFromIt(rbNode *ptr) {
    if (ptr && ptr->left)
        while(ptr->left)
            ptr = ptr->left;
    return ptr;
};
};
#endif //FT_CONTAINERS_QRE_H

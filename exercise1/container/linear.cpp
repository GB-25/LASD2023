
#include <stdexcept>
#include "container.hpp"
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool LinearContainer<Data>:: operator ==(const LinearContainer<Data>& lc)const noexcept{
    if (dimensione==lc.dimensione){
        for (ulong i=0; i<dimensione; i++) {
            if (operator[](i)!=lc[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

template <typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& lc)const noexcept{
    return !(*this==lc);
}

template <typename Data>
Data& LinearContainer<Data>::Front()const {
    if(dimensione == 0)
            throw std::length_error("Array vuoto.");
    else return operator[](0);
}

template <typename Data>
Data& LinearContainer<Data>::Front() {
    if(dimensione == 0)
            throw std::length_error("Array vuoto.");
    else return operator[](0);
}

template <typename Data>
Data& LinearContainer<Data>::Back() const {
    if(dimensione == 0)
            throw std::length_error("Array vuoto.");
    else{
        return operator[](dimensione - 1);
    } 
}

template <typename Data>
Data& LinearContainer<Data>::Back() {
    if(dimensione == 0)
            throw std::length_error("Array vuoto.");
    else{
        return operator[](dimensione - 1);
    } 
}



template <typename Data>
void LinearContainer<Data>::Fold(FoldFunctor fun, void* acc) const{
    PreOrderFold(fun, acc);
}

template <typename Data>
void LinearContainer<Data>::PreOrderFold(FoldFunctor fun, void* acc) const{
    for(ulong i=0; i<dimensione; i++){
        fun(LinearContainer<Data>& operator[](i), acc);
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderFold(FoldFunctor fun, void* acc) const{
    ulong i=dimensione;
    while(i>=0){
        fun(LinearContainer<Data>& operator[](i), acc);
        i--;
    };
}

template <typename Data>
void LinearContainer<Data>::Map(MapFunctor fun) const{
    PreOrderMap(fun);
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor fun) const{
    for(ulong i=0; i<dimensione; i++){
        fun(LinearContainer<Data>& operator[](i));
    }
}
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor fun) const{
    ulong i=dimensione;
    while(i>=0){
        fun(LinearContainer<Data>& operator[](i));
        i--;
    }
}

template <typename Data>
void LinearContainer<Data>::Map(MutableMapFunctor fun){
    PreOrderMap(fun);
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor fun){
    for(ulong i=0; i<dimensione; i++){
        fun(LinearContainer<Data>& operator[](i));
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor fun){
    ulong i=dimensione;
    while(i>=0){
        fun(LinearContainer<Data>& operator[](i));
        i--;
    }
}
/* ************************************************************************** */

}

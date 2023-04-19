
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
void MappableContainer<Data>::Fold(FoldFunctor fun, void* acc) const{
    Map({
        [&fun, &acc](const Data& dat){
            fun(dat, acc);
        }
});
}

template<typename Data>
void PreOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* acc)const{
    PreOrderMap({
        [&fun, &acc](const Data& dat){
            fun(dat, acc);
        }
    });
}

template<typename Data>
void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* acc)const{
    PostOrderMap({
        [&fun, &acc](const Data& dat){
            fun(dat, acc);
        }
    });
}


/* ************************************************************************** */

}

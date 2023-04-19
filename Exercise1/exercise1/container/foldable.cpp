
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept{
    bool exists = false;
    Fold({
        [this, &data](const Data& newdato, void* ext){
            if(newdato==data){
                *(bool*)ext=true;
            }
        }
    }, &exists);
    return exists;
}

template<typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* acc) const{
    FoldableContainer<Data>::Fold(fun, acc);
}

template<typename Data>
void FoldableContainer<Data>::Fold(FoldFunctor fun, void* acc) const{
    
}
/* ************************************************************************** */

}

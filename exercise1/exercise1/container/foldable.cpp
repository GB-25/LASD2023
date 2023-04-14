
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept{
    bool exists = false;
    Data compare= data;
    Fold({
        [this, &compare](const Data& newdato, void* ext){
            if(newdato==compare){(bool*)ext=true;}
        }
    }, &exists);
    return exists;
}



/* ************************************************************************** */

}

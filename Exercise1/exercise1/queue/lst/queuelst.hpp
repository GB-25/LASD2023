
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual public List<Data>{
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::dimensione;

  // ...

public:

  // Default constructor
  QueueLst();

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueLst(const MutableMappableContainer<Data>&); // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst&);

  // Move constructor
  QueueLst(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator = (const QueueLst&);

  // Move assignment
  QueueLst& operator = (QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst&) const noexcept;
  bool operator!=(const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() const override; // Override Queue member (mutable version; must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif

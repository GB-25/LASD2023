
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual public Vector<Data> {
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::dimensione;

  // ...

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueVec(const MutableMappableContainer<Data>&); // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec&);

  // Move constructor
  QueueVec(QueueVec&&);

  /* ************************************************************************ */

  // Destructor
  ~QueueVec() noexcept=default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  QueueVec& operator = (QueueVec&&) noexcept;;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>&) const noexcept;
  bool operator!=(const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() const override; // Override Queue member (mutable version; must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() noexcept override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();
  void SwapVectors(ulong newdimensione);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif

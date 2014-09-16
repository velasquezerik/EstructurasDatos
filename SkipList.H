/**
	@file SkipList.H
	@brief Clase Lista por Saltos. 
	Implementada mediante el uso de Skips List.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 8/2014

*/

#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include "ManejoExcepciones.H"
#include "VectorUtils.H"

using namespace std;

template <class Comparable>
class SkipList
{
private:
  // embedded node
  class SkipListNode
  {
  public:
    void setDatum(const Comparable & datum);
    void setForward(int i, SkipListNode * f);
    void setSize(int sz);
    SkipListNode(); // 16 levels, Comparable() for datum
    SkipListNode(const Comparable & datum, int levels);
    SkipListNode(const SkipListNode &);
    ~SkipListNode();

    const Comparable & getDatum() const;
    int getSize() const;
    SkipListNode * getForward(int level);
  private:
    int _levels;  // number of levels in this node
    Vector<SkipListNode *> _forward;  // forward pointers
    Comparable _datum;  // datum stored at this node
  }; // SkipListNode
public:
  SkipList(); // use max_node_size of 16, prob of 0.25
  SkipList(int max_node_size, double probab);
  SkipList(const SkipList &);
  ~SkipList();

  int getHighNodeSize() const; // size of the node with most levels
  int getMaxNodeSize() const; // max node size allowed in this list
  double getProbability() const; // prob for this list

  // insert item into this skiplist.
  void insert(const Comparable & item);

  // Search for item in skiplist.  If found, return the item with
  // success equal true.  Otherwise, return a dummy item with
  // success equal false.
  const Comparable & find(const Comparable & item, bool & success);

  // remove the first occurrence of the specified item
  void remove(const Comparable & item);  
private:
  // Search for item in this skiplist, starting at startnode
  // startnode will usually be the header.  If item is found, 
  // return the node at which it is found with success equal true.
  // Otherwise, return the preceding node with success equal false.
  // Precondition:  startnode is not NULL
  SkipListNode * find(const Comparable & item, 
		      SkipListNode * startnode);

  // Accessor for _head
  SkipListNode * getHeader() const; // return the header node

  // Finds the point at which item would be inserted using a node
  // of the given size.
  // Returns a "lookback" node that has each of its forward 
  // pointers set to the closest node (toward the header) at that level.
  SkipListNode * findInsertPoint(const Comparable & item, 
				 int nodesize);

  // insert item into this skiplist, using a node of the 
  // specified size. success returned true if insertion succeeds
  void insert(const Comparable & item, int nodesize, bool & success);

  int _high_node_size;  // highest-level node now in this list
  int _max_node_size;  // highest-level node allowed in this list
  double _prob;  // probability associated with this list
  SkipListNode * _head;  // header node of this list
};  // SkipList


template<class T>
void 
SkipList<T>::insert(const T & item)
{
  int nodesize = randomNodeSize(getProbability(), getMaxNodeSize());
  insert(item, nodesize);
}

template<class T>
void 
SkipList<T>::insert(const T & item, int nodesize)
{
  SkipList<T>::SkipListNode * backLook = findInsertPoint(item, nodesize);
  SkipList<T>::SkipListNode * newnode = 
    new SkipList<T>::SkipListNode(item, nodesize);

  // newnode may have more levels than are currently in list
  // If so, adjust high_node_size of list.
  if (nodesize > getHighNodeSize())
    setHighNodeSize(nodesize);

  //  Rearrange the relevant previous pointers using information
  //  in the backLook node.
  for (int i = 0; i < nodesize; i++)
    {
      SkipList<T>::SkipListNode * prev = backLook->getForward(i);
      SkipList<T>::SkipListNode * next = prev->getForward(i);
      newnode->setForward(i, next);
      prev->setForward(i, newnode);
    }

  incrementListSize();
}

#endif

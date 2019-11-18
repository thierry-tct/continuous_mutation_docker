/*
 * Bijection.h
 *
 *  Created on: 28 Jun 2012
 *      Author: hpalikar
 */

#ifndef BIJECTION_H_
#define BIJECTION_H_


#include "assert.h"
#include <map>


namespace llvm {
class BranchInst;
}

template <class S, class T>
class Bijection {
public:
  Bijection() {};
  virtual ~Bijection() {};

  void add(const S& first, const T& second) {
    assert(!exists_first(first));
    assert(!exists_second(second));

    _first_2_second[first] = second;
    _second_2_first[second] = first;
  };

  const S& get_first(const T& second) {
    assert(exists_second(second));
    return(_second_2_first[second]);
  };

  const T& get_second(const S& first) {
    assert(exists_first(first));
    return(_first_2_second[first]);
  };

  bool exists_first(const S& first) const {
    typename std::map<S, T>::const_iterator it = _first_2_second.find(first);
    return(it != _first_2_second.end());
  };

  bool exists_second(const T& second) const {
    typename std::map<T, S>::const_iterator it = _second_2_first.find(second);
    return(it != _second_2_first.end());
  };

  unsigned int size() const {
    assert(_first_2_second.size() == _second_2_first.size());
    return(_first_2_second.size());
  };

private:
  std::map<S, T>   _first_2_second;
  std::map<T, S>   _second_2_first;
};



#endif /* BIJECTION_H_ */

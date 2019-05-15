#pragma once

class cont_t
{
  int con_;

public:
  cont_t() : con_(1){};
  ~cont_t(){};
  void operator++() { ++con_;};
  void reset() {con_=1;};
  int get_cont()const {return con_;};
  void set_cont(int x) {con_=x;};


};

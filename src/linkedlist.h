
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// #include "./boolean.h"
#include "stdbool.h"

struct lln {
  void * value;
  //the first node in the list (may be the same as current)
  struct lln * start;
  //the next node in the list
  struct lln * next;
};

//Typing "struct lln *" is annoying
#define llnp struct lln *

llnp lln_create ();

void lln_add (llnp parent, llnp child);

llnp lln_get_tail (llnp parent);

llnp lln_add_value (llnp parent, void * value);

bool lln_has (llnp list, llnp search);

bool lln_has_value (llnp list, void * value);

void lln_destroy (llnp list, bool freeValue);

llnp lln_get_at (llnp list, int index);

void lln_trim_end (llnp list, int index, bool freeValue);

int lln_get_size (llnp list);

int lln_iterate ( llnp node, void (*cb)() );

#endif
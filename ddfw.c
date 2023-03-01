#include "yals.h" 

struct DDFW {
  LitClauses* lit_clauses_map;
 
  /** Whole neighborhood for all the clauses **/
  ClauseNeighboursDups* clause_neighbourhood_map_dups; // Array of STACKs to accumulate neighbors for clauses (may contain duplicate neighbors)
  ClauseNeighboursDupRemoved * clause_neighbourhood_map; // Array of arrays holds distinct neighbors for clauses (does not contain duplicate neighbors)
  int * neighbors_size; // each element contains size of the neighborhood for each clause

  /** On demand neighborhood for a clause **/
  STACK (int)  clause_neighbors; 
  int neighborhood_size;

  int prev_nunsat;
  int prev_unsat_weights;
  int rand_choices;
 
 
  int * clause_weights;
  int * unsat_weights, * sat1_weights;
  int init_weight_done;
  STACK (int) satisfied_clauses;
 

  int last_flipped;


  int sideways;

  // max_weighted_neighbour: initial weights are equal for all the clauses. just initialize the first neighbor of a clause as the max_weight neighbor
  // max_weighted_neighbour: needs to be updated after each weight transfers between a clause and its max neighbors
  int * max_weighted_neighbour;

  int * clauses_unsat;
  int * clasues_sat_one_lit;


  int break_weight, break_weight_temp;
  int * uwrvs;
  int uwrvs_size;
  int * non_increasing;
  int non_increasing_size; 
  int * helper_hash;
  STACK (int) helper_hash_changed_idx;
  int minw_var;
  int minw;
  int * sat_count_in_clause;
  STACK (int) sat_clauses;
  int local_minima;
} DDFW;
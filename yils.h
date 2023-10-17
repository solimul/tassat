/*-------------------------------------------------------------------------*/
/* TaSSAT is an SLS solver that implements an weight transferring algorithm. 
It is based on Yalsat (by Armin Biere)
Copyright (C) 2023-2029  Md Solimul Chowdhury, Cayden Codel, and Marijn Heule, Carnegie Mellon University, Pittsburgh, PA, USA. */
/*-------------------------------------------------------------------------*/

#ifndef YILS_H_INCLUDED
#define YILS_H_INCLUDED

#ifndef YALSINTERNAL
#error "this file is internal to 'libyals'"
#endif

/*------------------------------------------------------------------------*/

#include "yals.h"

/*------------------------------------------------------------------------*/

#include <stdlib.h>

/*------------------------------------------------------------------------*/

#ifndef NDEBUG
void yals_logging (Yals *, int logging);
void yals_checking (Yals *, int checking);
#endif

/*------------------------------------------------------------------------*/

void yals_abort (Yals *, const char * fmt, ...);
void yals_exit (Yals *, int exit_code, const char * fmt, ...);
void yals_msg (Yals *, int level, const char * fmt, ...);

const char * yals_default_prefix (void);
const char * yals_version ();
void yals_banner (const char * prefix);

/*------------------------------------------------------------------------*/

double yals_process_time ();				// process time

double yals_sec (Yals *);				// time in 'yals_sat'
size_t yals_max_allocated (Yals *);		// max allocated bytes

/*------------------------------------------------------------------------*/

void * yals_malloc (Yals *, size_t);
void yals_free (Yals *, void*, size_t);
void * yals_realloc (Yals *, void*, size_t, size_t);

/*------------------------------------------------------------------------*/

void yals_srand (Yals *, unsigned long long);

/* ddfw non-static methods */
int get_pos (int lit);
void yals_ddfw_update_lit_weights_on_make (Yals * yals, int cidx, int lit);
void yals_ddfw_update_lit_weights_at_start (Yals * yals, int cidx, int satcnt, int crit);
void yals_ddfw_update_lit_weights_at_restart (Yals *yals);
void yals_ddfw_compute_neighborhood_for_clause (Yals *yals, int cidx);
void yals_ddfw_compute_uwrvs (Yals * yals);
int yals_pick_literal_ddfw (Yals * yals);
int yals_pick_non_increasing (Yals * yals);
void yals_ddfw_init_build (Yals *yals);
void compute_neighborhood_for_clause_init (Yals *yals, int cidx);
int yals_pick_literals_random (Yals * yals);
void yals_ddfw_update_lit_weights_on_break (Yals * yals, int cidx, int lit);
void yals_add_vars_to_uvars (Yals* yals, int cidx);
int yals_var_in_unsat (Yals *yals, int v);
void yals_delete_vars_from_uvars (Yals* yals, int cidx);
void yals_ddfw_update_var_unsat_count (Yals *yals, int cidx);
int yals_needs_ddfw (Yals *yals); 
void yals_print_stats (Yals * yals); 
void yals_ddfw_update_uvars (Yals *yals, int cidx);
void set_options (Yals * yals);
void yals_outer_loop_maxtries (Yals * yals);
void yals_set_wid (Yals * yals, int widx);
int yals_inner_loop_max_tries (Yals * yals);
double set_cspt (Yals * yals);
void yals_set_threadspecvals (Yals * yals, int widx, int nthreads);


#endif

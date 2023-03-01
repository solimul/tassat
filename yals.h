/*-------------------------------------------------------------------------*/
/* Copyright 2013-2019 Armin Biere Johannes Kepler University Linz Austria */
/*-------------------------------------------------------------------------*/

#ifndef LIBYALS_H_INCLUDED
#define LIBYALS_H_INCLUDED

/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------*/

typedef struct Yals Yals;

/*------------------------------------------------------------------------*/

Yals * yals_new ();
void yals_del (Yals *);

/*------------------------------------------------------------------------*/

typedef void * (*YalsMalloc)(void*,size_t);
typedef void * (*YalsRealloc)(void*,void*,size_t,size_t);
typedef void (*YalsFree)(void*,void*,size_t);

Yals * yals_new_with_mem_mgr (void*, YalsMalloc, YalsRealloc, YalsFree);

/*------------------------------------------------------------------------*/

void yals_srand (Yals *, unsigned long long seed);
int yals_setopt (Yals *, const char * name, int val);
void yals_setprefix (Yals *, const char *);
void yals_setout (Yals *, FILE *);
void yals_setphase (Yals *, int lit);
void yals_setflipslimit (Yals *, long long);
void yals_setmemslimit (Yals *, long long);

int yals_getopt (Yals *, const char * name);
void yals_usage (Yals *);
void yals_showopts (Yals *);

/*------------------------------------------------------------------------*/

void yals_add (Yals *, int lit);

int yals_sat (Yals *);

/*------------------------------------------------------------------------*/

long long yals_flips (Yals *);
long long yals_mems (Yals *);

int yals_minimum (Yals *);
int yals_lkhd (Yals *);
int yals_deref (Yals *, int lit);

const int * yals_minlits (Yals *);


int yals_flip_count (Yals *yals);

int yals_nunsat_external (Yals *yals);

/*------------------------------------------------------------------------*/

void yals_stats (Yals *);
int yals_sat_palsat (Yals *, int);


/*------------------------------------------------------------------------*/

void yals_seterm (Yals *, int (*term)(void*), void*);

void yals_setime (Yals *, double (*time)(void));

void yals_setmsglock (Yals *,
       void (*lock)(void*), void (*unlock)(void*), void*);

/*------------------------------------------------------------------------*/

int init_done (Yals *yals);
int * cdb_top (Yals *yals);
int * cdb_start (Yals *yals);
int * cdb_end (Yals *yals);
int * occs (Yals *yals);
int noccs (Yals *yals);
int * refs (Yals *yals);
int * lits (Yals *yals);
int num_vars (Yals *yals);
void set_tid (Yals *yals, int tid);
int * preprocessed_trail (Yals *yals);
int  preprocessed_trail_size (Yals *yals);

void yals_fnpointers (Yals *yals, 
                            int * (*get_cdb_start)( ),
                            int * (*get_cdb_end)( ),
                            int * (*get_cdb_top)( ),
                            int * (*get_occs) (),
                            int  (*get_noccs) (),
                            int * (*get_refs) (),
                            int * (*get_lits) (),
                            int (*get_numvars) (),
                            int * (*get_preprocessed_trail) (),
                            int (*get_preprocessed_trail_size) (),
                            void (*set_preprocessed_trail) ()
                            );
void set_shared_structures (Yals *yals);

#endif

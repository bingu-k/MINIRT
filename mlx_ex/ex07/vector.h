#ifndef VECTOR_H
# define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  s_vec
{
    double  x;
    double  y;
    double  z;
}   t_vec;

t_vec   make_vec(double x, double y, double z);
t_vec   add_vec(t_vec vec1, t_vec vec2);
t_vec   sub_vec(t_vec vec1, t_vec vec2);
t_vec   mul_vec(t_vec vec1, t_vec vec2);
t_vec   mul_vec_(t_vec vec1, double t);
t_vec   div_vec(t_vec vec1, double t);
double  dot_vec(t_vec vec1, t_vec vec2);
t_vec   cross_vec(t_vec vec1, t_vec vec2);
t_vec   unit_vec(t_vec vec);

#endif
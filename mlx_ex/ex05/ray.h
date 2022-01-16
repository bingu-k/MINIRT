#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct  s_ray
{
    t_vec   origin;
    t_vec   direction;
}   t_ray;

typedef struct  s_cam
{
    double  viewport_w;
    double  viewport_h;
    double  aspect_ratio;
    double  focal_length;
    t_vec   origin;
    t_vec   horizontal;
    t_vec   vertical;
    t_vec   left_bottom_corner;
}   t_cam;

typedef struct  s_sphere
{
    t_vec   centor;
    double  radius;
}   t_sphere;


t_ray       make_ray(t_vec origin, t_vec direction);
t_vec       at_ray(t_ray ray, double t);
t_cam       make_cam(t_vec origin, double viewport_w, double viewport_h, double focal_length);
t_sphere    make_sphere(t_vec centor, double radius);
int         hit_sphere(t_sphere sp, t_ray ray);

#endif
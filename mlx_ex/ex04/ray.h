#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_ray
{
    t_vec   origin;
    t_vec   direction;
}   t_ray;

typedef struct s_cam
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


t_ray   make_ray(t_vec origin, t_vec direction);
t_vec   at_ray(t_ray ray, double t);
t_cam   make_cam(t_vec origin, double viewport_w, double viewport_h, double focal_length);

#endif
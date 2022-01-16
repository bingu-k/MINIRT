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

typedef struct  s_rec
{
    t_vec   p;
    t_vec   normal;
    double  tmin;
    double  tmax;
    double  t;
    int     front_face;
    t_vec   ambient;
    t_vec   albedo;
}   t_rec;

typedef struct  s_sphere
{
    t_vec   centor;
    double  radius;
    t_vec   albedo;
}   t_sphere;

typedef struct s_light
{
    t_vec   origin;
    t_vec   light_color;
    double  bright_ratio;
}   t_light;



t_ray       make_ray(t_vec origin, t_vec direction);
t_vec       at_ray(t_ray ray, double t);
t_cam       make_cam(t_vec origin, double viewport_w, double viewport_h, double focal_length);
t_sphere    make_sphere(t_vec centor, double radius, t_vec albedo);
void        set_face_normal(t_ray ray, t_rec **rec);
int         hit_sphere(t_sphere sp, t_ray ray, t_rec *rec);
int         is_hit_sphere(t_sphere *sp, t_ray ray, t_rec *rec, double tmax);
t_light     make_light(t_vec origin, t_vec light_color, double bright_color);

#endif
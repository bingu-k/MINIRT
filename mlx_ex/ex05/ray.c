#include "ray.h"

t_ray   make_ray(t_vec origin, t_vec direction)
{
    t_ray   new;

    new.origin = origin;
    new.direction = direction;
    return (new);
}

t_vec   at_ray(t_ray ray, double t)
{
    return (add_vec(ray.origin, mul_vec_(ray.direction, t)));
}

t_cam   make_cam(t_vec origin, double viewport_w, double viewport_h, double focal_length)
{
    t_cam   new;

    new.viewport_w = viewport_w;
    new.viewport_h = viewport_h;
    new.aspect_ratio = viewport_w / viewport_h;
    new.focal_length = focal_length;
    new.origin = origin;
    new.horizontal = make_vec(viewport_w, 0, 0);
    new.vertical = make_vec(0, viewport_h, 0);
    new.left_bottom_corner = sub_vec(origin, \
                                add_vec(div_vec(new.horizontal, 2.0), \
                                add_vec(div_vec(new.vertical, 2.0), \
                                make_vec(0, 0, focal_length))));
    return (new);
}

t_sphere    make_sphere(t_vec centor, double radius)
{
    t_sphere    new;

    new.centor = centor;
    new.radius = radius;
    return (new);
}

int         hit_sphere(t_sphere sp, t_ray ray)
{
    t_vec   oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;

    oc = sub_vec(ray.origin, sp.centor);
    a = dot_vec(ray.direction, ray.direction);
    b = dot_vec(oc, ray.direction);
    c = dot_vec(oc, oc) - (sp.radius * sp.radius);
    discriminant = b * b - a * c; // 점화식
    if (discriminant >= 0)
        return (1);
    else
        return (0);
}
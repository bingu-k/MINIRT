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

t_sphere    make_sphere(t_vec centor, double radius, t_vec albedo)
{
    t_sphere    new;

    new.centor = centor;
    new.radius = radius;
    new.albedo = albedo;
    return (new);
}

void    set_face_normal(t_ray ray, t_rec **rec)
{
    if (dot_vec(ray.direction, (*rec)->normal) > 0.0)
    {
        (*rec)->front_face = 0;
        (*rec)->normal = mul_vec_((*rec)->normal, -1);
    }
    else
        (*rec)->front_face = 1;
}

int hit_sphere(t_sphere sp, t_ray ray, t_rec *rec)
{
    t_vec   oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;
    double  temp;

    oc = sub_vec(ray.origin, sp.centor);
    a = dot_vec(ray.direction, ray.direction);
    b = dot_vec(oc, ray.direction);
    c = dot_vec(oc, oc) - (sp.radius * sp.radius);
    discriminant = (b * b) - (a * c); // 점화식
    if (discriminant < 0)
        return (0);
    temp = (-b - sqrt(discriminant)) / a;
    if (temp > rec->tmax || rec->tmin > temp)
    {
        temp = (-b + sqrt(discriminant)) / a;
        if (temp > rec->tmax || rec->tmin > temp)
            return (0);
    }
    rec->albedo = sp.albedo; // rec->albedo 최신화
    rec->t = temp;
    rec->p = at_ray(ray, temp);
    rec->normal = div_vec(sub_vec(rec->p, sp.centor), sp.radius);
    set_face_normal(ray, &rec);
    return (1);
}

int is_hit_sphere(t_sphere *sp, t_ray ray, t_rec *rec, double tmax)
{
    int hit_anything;
    int i;

    hit_anything = 0;
    rec->tmin = 0;
    i = -1;
    while (++i < 3)
    {
        rec->tmax = tmax;
        if (hit_sphere(sp[i], ray, rec))
        {
            tmax = rec->t;
            hit_anything = 1;
        }
    }
    return (hit_anything);
}

t_light     make_light(t_vec origin, t_vec light_color, double bright_color)
{
    t_light light;

    light.origin = origin;
    light.light_color = light_color;
    light.bright_ratio = bright_color;
    return (light);
}
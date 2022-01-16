#include "vector.h"

t_vec   make_vec(double x, double y, double z)
{
    t_vec   new;

    new.x = x;
    new.y = y;
    new.z = z;
    return (new);
}

t_vec   add_vec(t_vec vec1, t_vec vec2)
{
    return (make_vec(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_vec   sub_vec(t_vec vec1, t_vec vec2)
{
    return (make_vec(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_vec   mul_vec(t_vec vec1, t_vec vec2)
{
    return (make_vec(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z));
}

t_vec   mul_vec_(t_vec vec1, double t)
{
    return (make_vec(vec1.x * t, vec1.y * t, vec1.z * t));
}

t_vec   div_vec(t_vec vec1, double t)
{
    return (make_vec(vec1.x * (1 / t), vec1.y * (1 / t), vec1.z * (1 / t)));
}

double  dot_vec(t_vec vec1, t_vec vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec  cross_vec(t_vec vec1, t_vec vec2)
{
    t_vec   new;

    new.x = vec1.y * vec2.z - vec1.z * vec2.y;
    new.y = vec1.z * vec2.x - vec1.x * vec2.z;
    new.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return (new);
}

t_vec   unit_vec(t_vec vec)
{
    t_vec   new;
    double  len;

    len = sqrt(dot_vec(vec, vec));
    new = div_vec(vec, len);
    return (new);
}

t_vec   min_vec(t_vec vec1, t_vec vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}
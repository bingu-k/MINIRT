#include <stdio.h>
#include <stdlib.h>
#include "../../mlx/mlx.h"
#include "vector.h"
#include "ray.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 800
# define IMG_HEIGHT 600

typedef struct  s_img
{
    void        *img_ptr;
    char        *data;
    int         size_l;
    int         bpp;
    int         endian;
    t_sphere    *sp;
}   t_img;

typedef struct s_mlx
{
    void        *mlx_ptr;
    void        *win;
}   t_mlx;

t_vec   phong_lighting(t_light light, t_rec rec)
{
    t_vec   light_color;

    light_color = make_vec(0, 0, 0);
    light_color = add_vec(light_color, rec.ambient);
    return (min_vec(mul_vec(light_color, rec.albedo), make_vec(1, 1, 1)));
}

void	my_mlx_pixel_put(t_img *img, t_cam cam, int x, int y)
{
	char	*dst;
    double  u;
    double  v;
    double  t;
    int     rgb_color;
    t_ray   ray;
    t_vec   color;
    t_vec   tmp;
    t_rec   rec;
    t_light light;

    u = (double)x / (double)(IMG_WIDTH - 1);
    v = (double)y / (double)(IMG_HEIGHT - 1);
    ray = make_ray(cam.origin, sub_vec(add_vec(add_vec(cam.left_bottom_corner, \
                                                mul_vec_(cam.horizontal, u)), \
                                                mul_vec_(cam.vertical, v)), \
                                                cam.origin));
    rec.ambient = mul_vec_(make_vec(1, 1, 1), 0.1); // ambient set
    if (is_hit_sphere(img->sp, ray, &rec, 9999))
    {// color of phong model
        light = make_light(make_vec(0, 5, 0), make_vec(1, 1, 1), 0.5);
        tmp = phong_lighting(light, rec);
        color = mul_vec_(tmp, 255.999);
    }
    else
    {
        t = 0.5 * (unit_vec(ray.direction).y + 1.0);
        color = mul_vec_(add_vec(mul_vec_(make_vec(1.0, 1.0, 1.0), (1.0 - t)), \
                        mul_vec_(make_vec(0.5, 0.7, 1.0), t)), 255.999);
    }
    rgb_color = ((int)color.x << 16) | ((int)color.y << 8) | (int)color.z;
	dst = img->data + (x * img->bpp / 8) + ((IMG_HEIGHT - y - 1) * img->size_l);
	*(unsigned int *)dst = rgb_color;
}

int main(void)
{
    t_mlx   *mlx;
    t_img   img;
    t_cam   cam;
    int     count_w;
    int     count_h;

    mlx = malloc(sizeof(t_mlx));
    mlx->mlx_ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Phong Model");
    img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
    img.sp = malloc(sizeof(t_sphere) * 3);
    img.sp[0] = make_sphere(make_vec(-1, 0, -5), 2, make_vec(0.5, 0, 0));
    img.sp[1] = make_sphere(make_vec(1, 0, -5), 2, make_vec(0, 0.5, 0));
    img.sp[2] = make_sphere(make_vec(0, -1000, -100), 999, make_vec(1, 1, 1));
    cam = make_cam(make_vec(0, 0, 0), 2.0 * 8.0 / 6.0, 2.0, 1.0);
    count_h = IMG_HEIGHT;
    while (--count_h >= 0)
    {
        count_w = -1;
        while (++count_w < IMG_WIDTH)
            my_mlx_pixel_put(&img, cam, count_w, count_h);
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
    mlx_loop(mlx->mlx_ptr);
    free(img.sp);
    free(mlx);
    return (0);
}
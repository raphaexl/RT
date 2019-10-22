/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 10:47:27 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/22 01:32:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "camera.h"
# include "col3.h"
# include "defines.h"
# include "libft/libft.h"

typedef enum	e_type
{
	NO_OBJECT = 0, SPHERE, CONE, CYLINDER, BOX, PLANE, DISK, TORUS, CUBE,
	TRIANGLE, PARALLELOGRAM, RING, PARABOLOID, ELLIPSOID, MESH
}				t_type;

typedef t_type	t_otype;

typedef enum	e_ltype
{
	NO_LIGHT, DEFAULT_LIGHT, DISTANT_LIGHT, POINT_LIGHT, SPOT_LIGHT
}				t_ltype;

typedef enum	e_ftype
{
	NO_FILTER, GAUSSIAN_BLUR, MOTION_BLUR, SHARPEN, EMBOSS, SOBEL, GREY,
	NEGATIVE, SEPIA
}				t_ftype;

typedef	enum	e_mtype
{
	NO_PROPERTY, PROCEDURAL, TEXTURE, PERLIN, MARBLE, TURBULENCE, CHESS
}				t_mtype;

typedef enum	e_ctype
{
	CUBE_UP, CUBE_DOWN, CUBE_RIGHT, CUBE_LEFT, CUBE_FORWARD, CUBE_BACKWARD
}				t_ctype;

typedef	enum	e_itype
{
	DEFAULT, EDITING
}				t_itype;

typedef enum	e_btype
{
	NO_BACKGROUND, ENVMAP
}				t_btype;

typedef struct	s_ray
{
	t_vec3		start;
	t_vec3		dir;
}				t_ray;

typedef struct	s_d_light
{
	t_vec3		dir;
}				t_direct_light;

typedef struct	s_def_light
{
	t_vec3		pos;
}				t_default_light;

typedef struct	s_p_light
{
	t_vec3		pos;
	float		constant;
	float		linear;
	float		quadratic;
}				t_point_light;

typedef struct	s_s_light
{
	t_vec3		pos;
	t_vec3		dir;
	float		constant;
	float		linear;
	float		quadratic;
	float		cut_off;
	float		outer_cut_off;
}				t_spot_light;

typedef union	u_light
{
	t_default_light	def;
	t_spot_light	spot;
	t_point_light	point;
	t_direct_light	direct;
}				t_union_light;

typedef	struct	s_l
{
	t_union_light	u;
	t_col3			diffuse;
	int				id;
	t_ltype			type;
	struct s_l		*next;
}				t_light;

typedef struct	s_texture
{
	int		w;
	int		h;
	t_col3	*data;
}				t_texture;

typedef struct	s_cubemap
{
	t_col3		*texture;
	int			w;
	int			h;
	float		exposure;
	int			exposed;
	int			srgb;
}				t_cubemap;

typedef	struct	s_convolution
{
	int			size;
	int			den;
	Uint32		*img;
	Uint32		*aux;
	double		*filter;
	t_point		pix;
}				t_convolution;

typedef struct	s_pixel
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				col;
}				t_pixel;

typedef struct	s_material
{
	t_col3		diffuse;
	t_col3		diffuse1;
	t_col3		diffuse2;
	t_col3		specular;
	float		albedo[2];
	float		reflection;
	float		refraction;
	float		spec_pow;
	float		bump;
	float		u_sc;
	float		v_sc;
	t_texture	*texture;
	t_mtype		type;
}				t_material;

typedef struct	s_sphere
{
	float		radius;
	float		radius2;
}				t_sphere;

typedef struct	s_cylinder
{
	float		radius;
	float		radius2;
	float		height;
	t_vec3		v;
}				t_cylinder;

typedef struct	s_disk
{
	float		radius;
	float		radius2;
	t_vec3		normal;
}				t_disk;

typedef struct	s_cone
{
	float		angle;
	float		height;
	t_vec3		v;
}				t_cone;

typedef struct	s_plane
{
	t_vec3		normal;
}				t_plane;

typedef struct	s_box
{
	t_vec3		bounds[2];
}				t_box;

typedef struct	s_torus
{
	float		radius1;
	float		radius2;
}				t_torus;

typedef struct	s_cube
{
	float		radius;
}				t_cube;

typedef struct	s_triangle
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
}				t_triangle;

typedef struct	s_ring
{
	float		radius;
	float		radius2;
	float		height;
	t_vec3		v;
}				t_ring;

typedef struct	s_ellipsoid
{
	float		k;
	float		radius;
	float		radius2;
	t_vec3		v;
	t_vec3		c;
}				t_ellipsoid;

typedef struct	s_paraboloid
{
	float		k;
	t_vec3		v;
	t_vec3		c;
}				t_paraboloid;

typedef struct	s_normal
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
}				t_normal;

typedef struct	s_texel
{
	t_vec2		a;
	t_vec2		b;
	t_vec2		c;
}				t_texel;

typedef struct	s_mesh
{
	char		*name;
	t_triangle	*triangles;
	int			size;
}				t_mesh;

typedef struct	s_obj
{
	t_vector	vertices;
	t_vector	uvs;
	t_vector	normals;
	t_vector	v_indices;
	t_vector	uv_indices;
	t_vector	n_indices;
}				t_obj;

typedef struct	s_aux_obj
{
	t_vector	v_list;
	t_vector	uv_list;
	t_vector	n_list;
}				t_aux_obj;

typedef struct	s_aux_sphere
{
	t_vec3		vn;
	t_vec3		ve;
	t_vec3		vc;
	float		phi;
	float		theta;
}				t_aux_sphere;

typedef struct	s_aux_triangle
{
	float		det;
	float		invdet;
	t_vec3		h;
	t_vec3		s;
	t_vec3		q;
	t_vec3		edge1;
	t_vec3		edge2;
	float		t1;
	float		u;
	float		v;
}				t_aux_triangles;

typedef struct	s_parallelogram
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
	t_vec3		d;
}				t_parallelogram;

typedef struct	s_aux_parallelogram
{
	t_vec3	e01;
	t_vec3	e03;
	t_vec3	e23;
	t_vec3	e21;
	t_vec3	p;
	t_vec3	p2;
	t_vec3	t;
	t_vec3	t2;
	t_vec3	q;
	t_vec3	q2;
	t_vec3	n;
	float	det;
	float	det2;
	float	invdet;
	float	invdet2;
	float	t1;
	float	a;
	float	b;
	float	a2;
	float	b2;
}				t_aux_parallelogram;

typedef struct	s_aux_cone
{
	t_delta	d;
	t_vec3	pa;
	t_vec3	va;
	t_vec3	x;
	t_vec3	a;
	t_vec3	b;
	float	anglesin;
	float	t1;
	float	t2;
	float	m;
	float	anglecos;
}				t_aux_cone;

typedef struct	s_aux_cylinder
{
	t_delta	d;
	t_vec3	x;
	float	m0;
	float	m1;
	float	t0;
	float	t1;
}				t_aux_cylinder;

typedef struct	s_aux_readfile
{
	size_t	used;
	size_t	n;
	size_t	size;
	char	*data;
	char	*temp;
}				t_aux_read_file;

typedef union	u_union
{
	t_sphere		sphere;
	t_cylinder		cylinder;
	t_disk			disk;
	t_cone			cone;
	t_plane			plane;
	t_box			box;
	t_torus			torus;
	t_cube			cube;
	t_triangle		triangle;
	t_parallelogram	para;
	t_ring			ring;
	t_paraboloid	parab;
	t_ellipsoid		ellipse;
	t_mesh			mesh;
}				t_union;

typedef	struct	s_o
{
	t_material	material;
	t_vec3		pos;
	t_vec3		translate;
	t_vec3		rotate;
	t_vec3		scale;
	t_union		e;
	int			id;
	int			emissive;
	t_type		type;
	char		*name;
	struct s_o	*next;
}				t_object;

typedef struct	s_iterm
{
	t_vec3		pos;
	t_col3		color;
}				t_iterm;

typedef struct	s_intersect
{
	t_ray		ray;
	t_ray		ray_light;
	t_vec3		n;
	t_vec3		p;
	float		t;
	t_object	*current;
}				t_intersect;

typedef t_intersect	t_hit;

typedef	struct	s_scene
{
	t_camera	cam;
	t_col3		c;
	t_col3		bg_color;
	t_col3		ambiant;
	int			nb_samples;
	uint32_t	nb_depth;
	int			a;
	t_object	*obj;
	t_light		*light;
	t_cubemap	*cmap;
	t_col3		(*ft_rtv1)(struct s_scene *, t_intersect *, int);
	t_col3		(*ft_bg_color)(struct s_scene *, t_intersect *, int);
	t_ftype		filter;
	t_btype		background;
}				t_scene;
#endif

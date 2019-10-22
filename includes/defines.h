/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:55:38 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 21:17:09 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <math.h>
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define VIDEO_SIZE 360
# define MAX_DEPTH 5
# define N_SAMPLES 16
# define NB_OPTIONS 23
# define N_PROPERTIES 10
# define JPG_QUALITY 10
# define N_VIEW1 5
# define N_VIEW4 1
# define DEFAULT_W1 100
# define DEFAULT_W 50
# define DEFAULT_H 25
# define DEFAULT_FSIZE 10
# define DEFAULT_NSIZE 5
# define N_TEXTURES 10
# define DEFAULT_FONT ("data/fonts/Roboto-Condensed.ttf")
# define ANGELINA_FONT ("data/fonts/angelina.TTF")
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define GRAY	0x707070FF
# define BLUE   0x0000FFFF
# define YELLOW	0x00000FF
# define BUTB_COLOR	0x000000FF
# define BUTT_COLOR	0xF0FFFFFF
# define ENTB_COLOR	0x707070FF
# define ENTT_COLOR	0xF0FFFFFF
# define NB_INSPECT 2
# define DELTA_TRANS 1.5
# define DELTA_SCALE 1.0
# define DELTA_ANGLE 2
# define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
# define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))
# define MAX(a, b) ((a) < (b) ? (b) : (a))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define EQN_EPS 1e-9
# define IS_ZERO(x) ((x) > -EQN_EPS && (x) < EQN_EPS)
# ifndef CBRT
#  define POW1(x) (pow((double)(x), 1.0 / 3.0))
#  define POW2(x) (pow((double)-(x), 1.0 / 3.0))
#  define CBRT(x) ((x) > 0.0 ? POW1(x) : ((x) < 0.0 ? -POW2(x) : 0.0))
# endif
# ifndef READALL_CHUNK
#  define READALL_CHUNK  262144
# endif
# define READALL_OK          0
# define READALL_INVALID    -1
# define READALL_ERROR      -2
# define READALL_TOOMUCH    -3
# define READALL_NOMEM      -4
# define OBJECT_DESCRIPTION		2
# define LIGHT_DESCRIPTION			3
# define BACKGROUND_DESCRIPTION	4
# define CAMERA_DESCRIPTION		5
# define ENVMAP_DESCRIPTION		6
# define SCENE_DESCRIPTION			7
# define OBJECT_NAME      15
# define LIGHT_NAME      5
# define BACKGROUND_NAME      10
# define ENVMAP_NAME      10
# define CAMERA_NAME      6
# define SCENE_NAME      5

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_delta
{
	float	a;
	float	b;
	float	c;
	float	delta;
}				t_delta;

typedef struct	s_cubic
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	sq_a;
	double	p;
	double	q;
	double	cb_p;
}				t_cubic;

typedef struct	s_quartic
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	z;
	double	u;
	double	v;
	double	sub;
	double	sq_a;
	double	p;
	double	q;
	double	r;
}				t_quartic;

typedef struct	s_perlin
{
	int						x;
	int						y;
	int						z;
	int						a;
	int						b;
	int						aa;
	int						ab;
	int						ba;
	int						bb;
	double					fx;
	double					fy;
	double					fz;
}				t_perlin;

typedef struct	s_aux_texel
{
	float	fu;
	float	fv;
	float	fracu;
	float	fracv;
	float	w1;
	float	w2;
	float	w3;
	float	w4;
	int		u1;
	int		v1;
	int		u2;
	int		v2;
}				t_aux_textel;

typedef struct	s_aux_readtexture
{
	int		umin;
	int		vmin;
	int		umax;
	int		vmax;
	float	ucoef;
	float	vcoef;
}				t_aux_read_texture;

typedef struct	s_split
{
	int						min;
	int						max;
	char					**tab;
}				t_rtsplit;

typedef	enum	e_opt
{
	NNE = 0, NEW_SPHERE, NEW_CONE, NEW_CYLINDRE, NEW_BOX, NEW_PLANE, NEW_DISK,
	NEW_TORUS, NEW_CUBE, NEW_TRIANGLE, NEW_PARALLELOGRAM, NEW_RING,
	NEW_PARABOLOID, NEW_ELLIPSOID, NEW_MESH, DELETE, EDIT_TRACE, RAY_TRACE,
	S_VIDEO, S_PPM, S_BMP, S_PNG, S_JPG
}				t_options;

typedef	struct	s_font
{
	char		*mes;
	char		*file;
	int			size;
}				t_font;
#endif

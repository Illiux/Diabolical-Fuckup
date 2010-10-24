/***************************************************
FILE: glmain.h
AUTHOR: gem, loosely based on hwa random skel
DATE: 02/13/08
DOES: header file for cs1566 Assignment 3 -- transformer
***************************************************/

#ifndef __CS1566_GLOBALS
#define __CS1566_GLOBALS


#ifndef min //In VC++ 2008, Ryan got a warning about min redefinition, so let's not redefine it if something else already did; sigh
#define min(a,b) ((a) < (b)? a:b)
#endif

#define PI		3.1415927
#define FALSE 0 
#define TRUE  1

class vertex{
public:
	GLfloat x,y,z,w;
	GLfloat cx,cy,cz,cw;
};

/* define index constants into the colors array */
#define BLACK   0
#define RED     1
#define YELLOW  2
#define MAGENTA 3
#define GREEN   4
#define CYAN    5
#define BLUE    6
#define GREY    7
#define WHITE   8


#define HOUSE    0
#define CUBE     1
#define TESCUBE  2
#define CYLINDER 3
#define SPHERE   4
#define TORUS    5
#define MESH     6
#define GEODESIC 7
#define CONE	 8


#define TRANSLATION_MODE 0
#define SCALING_MODE 1
#define ROTATION_MODE 2
#define NONE_MODE 3
#define AXIS_ROTATION_MODE 4
#define REAL_TRANSLATION_MODE 5
#define REAL_SCALING_MODE 6
#define REAL_ROTATION_MODE 7

#define SPIN_ENABLED 1
#define SPIN_DISABLED 0


typedef GLfloat (*ObjectArray)[50][50][4];
/*note to cs1566 staff:
colors and vertices below shd actually be in some .c file*/

GLfloat colors [][3] = {
  {0.0, 0.0, 0.0},  /* black   */
  {1.0, 0.0, 0.0},  /* red     */
  {1.0, 1.0, 0.0},  /* yellow  */
  {1.0, 0.0, 1.0},  /* magenta */
  {0.0, 1.0, 0.0},  /* green   */
  {0.0, 1.0, 1.0},  /* cyan    */
  {0.0, 0.0, 1.0},  /* blue    */
  {0.5, 0.5, 0.5},  /* 50%grey */
  {1.0, 1.0, 1.0}   /* white   */
};

/*note the 4 (!) coordinates per vertex below; 
homogeneous coords with w = 1 (see the lecture notes);*/
GLfloat vertices_house[][4] = {
  {0,2,0,1}, 
  {-1,1,1,1}, {1,1,1,1}, {1,1,-1,1}, {-1,1,-1,1},
  {-1,-1,1,1}, {1,-1,1,1}, {1,-1,-1,1}, {-1,-1,-1,1}
};


GLfloat vertices_cube_brute[][4] = {
  {-1,1,1,1}, {1,1,1,1}, {1,1,-1,1}, {-1,1,-1,1},
  {-1,-1,1,1}, {1,-1,1,1}, {1,-1,-1,1}, {-1,-1,-1,1}
  };

vertex vertices_cube_smart[4][4];


// a suggestion; you don't have to use this data structure
vertex vertices_cyl[50][50];


// a suggestion; you don't have to use this data structure
vertex vertices_sph[50][50];

vertex vertices_cone[50][50];
vertex vertices_torus[50][50];


GLfloat vertices_axes[][4] = {
	{0.0, 0.0, 0.0, 1.0},  /* origin */ 
	{5.0, 0.0, 0.0, 1.0},  /* maxx */ 
	{0.0, 5.0, 0.0, 1.0}, /* maxy */ 
	{0.0, 0.0, 5.0, 1.0}  /* maxz */ 

};


void glut_setup(void) ;
void gl_setup(void) ;
void my_setup(void);
void my_display(void) ; 
void my_mouse(int button, int state, int mousex, int mousey) ;
void my_reshape(int w, int h) ;
void my_keyboard_up( unsigned char key, int x, int y ) ;
void my_keyboard( unsigned char key, int x, int y ) ;
void my_idle(void) ;
void my_TimeOut(int id) ;

void make_stuff(int shape);
void draw_object(int shape);
vertex (*(t_translate)(int shape))[50];
void translate (unsigned char key, int shape);
void draw_cube_smart();
void draw_cylinder(int rs, int vs);
void draw_sphere(int rs, int vs);
void draw_torus(int rs, int vs);
GLfloat** matrix_mult (GLfloat** matrix, GLfloat** obj, int arow,int acol, int brow, int bcol);
void make_cube_smart( double size );
void make_cylinder( double height, double ray, int rs, int vs );
void make_sphere( double ray, int rs, int vs );
void make_cone(double radius, double height,int rs, int vs);
void make_torus( double r1,double r2, int rs, int vs);



#endif

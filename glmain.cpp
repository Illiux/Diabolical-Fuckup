//WHERE I LEFT OFF
// Scale in the Shift+'X' direction isnt working.
// next step is rotation.

//need to readjust camera.  set to look at one point to verify rotation etc :)


/*******************************************************
FILE: glmain.c
AUTHOR: gem, loosely based on some hwa
DATE: 02/09/08
DOES: skeleton for hmkw3
********************************************************/

/**********
notes:
VS users: include gl/glut.h below instead of glut.h
OSX users: include glut/glut.h below instead of glut.j
**********/

//VisS will not let through math.h constants such as M_PI w/out the line below
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glut.h>

//#include "cs1566globals.h"
//#include "stitcher.h"
//#include "transformer.h"
#include "glheader.h"

double cyl_height=1;
double cyl_ray=1;
double sph_ray=1;
double x_camera = 0, y_camera = 5, z_camera = 30;
double lookat_x =0.0, lookat_y = 0.0,lookat_z = 0.0;
vertex ** p;
vertex (*ptr)[50]; 
int crt_render_mode;
int crt_shape, crt_rs, crt_vs;
int crt_transform;
int spin_val = SPIN_DISABLED;
double torusr1 = 1.2;
double torusr2 = .2;
GLfloat matrix  [4][4];		//may need some tinkerin'
GLfloat mmatrix [4][4];		//col by row matrix

 




/*******************************************************
FUNCTION: main
ARGS: argc, argv
RETURN: 0
DOES: main function (duh!); starts GL, GLU, GLUT, then loops 
********************************************************/
int main(int argc, char** argv)

{	
	//intialize ptr

  glutInit(&argc, argv);
  glut_setup();
  gl_setup();
  my_setup();

  glutMainLoop();

  return(0);

}




/*******************************************************
FUNCTION: glut_setup
ARGS: none
RETURN: none
DOES: sets up GLUT; done here because we like our 'main's tidy
********************************************************/
/* This function sets up the windowing related glut calls */
void glut_setup (){

  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(700,700);
  glutInitWindowPosition(20,20);
  glutCreateWindow("Transformer");


  /* set up callback functions */
  glutDisplayFunc(my_display);
  glutReshapeFunc(my_reshape);
  glutMouseFunc(my_mouse);
  glutKeyboardFunc(my_keyboard);
  glutKeyboardUpFunc( my_keyboard_up );	
  glutTimerFunc( 20, my_TimeOut, 0 );/* schedule a my_TimeOut call with the ID 0 in 20 seconds from now */
  return;

}


/*******************************************************
FUNCTION: gl_setup
ARGS: none
RETURN: none
DOES: sets up OpenGL (name starts with gl but not followed by capital letter, so it's ours)
********************************************************/
void gl_setup(void) {
  // enable depth handling (z-buffer)
  glEnable(GL_DEPTH_TEST);

  // define the background color 
  glClearColor(0,0,0,1);

  glMatrixMode(GL_PROJECTION) ;
  
  glLoadIdentity() ;

  gluPerspective( 20, 1.0, 15, 100.0);

  glMatrixMode(GL_MODELVIEW) ;

  glLoadIdentity() ;  // init modelview to identity

  return ;

}


/*******************************************************
FUNCTION: my_setup
ARGS: 
RETURN:
DOES: pre-computes staff and presets some values
********************************************************/
/*TODO if you did EC for hmwk2: add make_torus etc.   */
void my_setup(){
  crt_render_mode = GL_POLYGON;//GL_LINE_LOOP;
  crt_shape = HOUSE;
  crt_transform = NONE_MODE;
  crt_rs = 20;
  crt_vs = 10;
  make_cube_smart(1);
  make_cylinder(cyl_height,cyl_ray,crt_rs,crt_vs);
  make_sphere(sph_ray,crt_rs,crt_vs);
  make_cone(sph_ray,cyl_height,crt_rs,crt_vs);
  make_torus(torusr1,torusr2,crt_rs,crt_vs);
  return;

}



/*******************************************************
FUNCTION: my_reshape
ARGS: new window width and height 
RETURN:
DOES: remaps viewport to the Window Manager's window
********************************************************/
void my_reshape(int w, int h) {
  // ensure a square view port
  glViewport(0,0,min(w,h),min(w,h)) ;
  return ;

}

/*******************************************************
FUNCTION: renderer_rev
ARGS: angle and axis x, y, z 
RETURN:
DOES: makes shape spin around its vertical axis when rendered
Note: 'vertical' axis means house keeps revolving around its roof-top
base-center axis, torus spins around axis passing through hole, 
sphere spins around North-South axis etc *at all times*.
********************************************************/
/*TODO */
void renderer_rev(GLfloat deg, GLfloat x, GLfloat y, GLfloat z) {
	//[T*][M#][R][M][T]v
	//* refers to translating by the saved coords of translation from the first [T] == vertex pts in space.
	//# refers to translating by the inverse of M, to shift back into its origional location.


}


/*******************************************************
FUNCTION: renderer_translation
ARGS: translation amount along x, y, z
RETURN:
DOES: translates shape during rendering
********************************************************/
/*TODO */
void renderer_translation(GLfloat x, GLfloat y, GLfloat z) {
	int j,k,m;
	GLfloat ux,uy,uz;
	for (j = 0;j < 4;j++){
		for(k=0;k<4;k++){
			mmatrix[j][k] = 0;
		}
	}
	ux = 1;
	uy = 1;
	uz =1;
	GLfloat theta;
	mmatrix[0][0] = ux*ux+cos(theta)*(1-ux*ux);
	mmatrix[0][1] =	ux*uy*(1-cos(theta))-uz*sin(theta);
	mmatrix[0][2] = uz*ux*(1-cos(theta))-uy*sin(theta);
	mmatrix[0][3] = 0;
	mmatrix[1][0] = ux*uy*(1-cos(theta))+uz*sin(theta);
	mmatrix[1][1] = uy*uy + cos(theta)*(1-uy*uy);
	mmatrix[1][2] = uy*uz*(1-cos(theta)) - ux*sin(theta);
	mmatrix[1][3] = 0;
	mmatrix[2][0] = x;
	mmatrix[2][1] = y;
	mmatrix[2][2] = z;
	mmatrix[2][3] = 0;
	mmatrix[3][0] = x;
	mmatrix[3][1] = y;
	mmatrix[3][2] = z;
	mmatrix[3][3] = 1;
	


//	for (j=0;j<50;j++){
//		for (k=0;k<50;k++){
//			for (m = 0;m<4;m++){
//				point[m][0] = p[j][k][m];
//			}
//				point = matrix_mult(*matrix,point,4,4,4,1);
//				//matrix needs to be adjusted as does point.
//		}
//	}
}


/*******************************************************
FUNCTION: renderer_scaling
ARGS: scaling amount along x, y, z
RETURN:
DOES: scales shape during rendering
********************************************************/
/*TODO*/
void renderer_scaling(GLfloat sx, GLfloat sy, GLfloat sz) {
	//[t*][s][t]v
}

/*******************************************************
FUNCTION: renderer_rotation
ARGS: angle and axis
RETURN:
DOES: rotates shape, for real
********************************************************/
/*TODO*/
void renderer_rotation(GLfloat deg, GLfloat x, GLfloat y, GLfloat z) {
}

/*******************************************************
FUNCTION: real_translation
ARGS: translation amount along x, y, z
RETURN:
DOES: translates shape for real
********************************************************/
/*TODO. Note: Absolutely no gl calls */
/*can assume model-matrix stack contains at this point nothing but viewing transform*/
void real_translation(GLfloat x, GLfloat y, GLfloat z) {
	//[t]v
	int j,k;
	//vertex ** ptr;
	//reset matrix
	for (j = 0;j<4;j++){
		for (k=0;k<4;k++){
			matrix[j][k] = 0;
		}
	}
	//set matrix values
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
	matrix[3][0] = x;
	matrix[3][1] = y;
	matrix[3][2] = z;

	// shift every vertex of an object in the X,Y,Z direction.
	//2 for loops through pointer, adjusting the values accordingly

	ptr = t_translate(crt_shape);
	//print matrix pre- adjust
	for (j = 0;j< 50;j++){
		for(k=0;k<50;k++){
			printf("%f %f %f %f--",ptr[j][k].x,ptr[j][k].y,ptr[j][k].z,ptr[j][k].w);
		}
		printf("\n");
	}
	for (j =0;j<50;j++){
		for (k=0;k<50;k++){
			//add approperate information here...
			ptr[j][k].x= matrix[0][0]*ptr[j][k].x + ptr[j][k].w*matrix[3][0];
			ptr[j][k].y= matrix[1][1]*ptr[j][k].y + ptr[j][k].w*matrix[3][1];
			ptr[j][k].z= matrix[2][2]*ptr[j][k].z + ptr[j][k].w*matrix[3][2];
			ptr[j][k].w=1;
		}
	}
	ptr[0][0].cx += x;
	ptr[0][0].cy += y;
	ptr[0][0].cz += z;
	/*
	for (j = 0;j< 50;j++){
		for(k=0;k<50;k++){
			printf("%f %f %f %f--",ptr[j][k].x,ptr[j][k].y,ptr[j][k].z,ptr[j][k].w);
		}
		printf("\n");
	}*/
	glutPostRedisplay();
}


/*******************************************************
FUNCTION: renderer_scaling
ARGS: scaling amount along x, y, z
RETURN:
DOES: scales shape, for real
********************************************************/
/*TODO */
/*can assume model-matrix stack contains at this point nothing but viewing transform*/
void real_scaling(GLfloat sx, GLfloat sy, GLfloat sz) {
	int i,j;
	ptr = t_translate(crt_shape);
	real_translation(-1*ptr[0][0].cx,-1*ptr[0][0].cy,-1*ptr[0][0].cz);
	for (i = 0;i<50;i++){
		for (j=0;j<50;j++){
			ptr[i][j].x *= sx;
			ptr[i][j].y *= sy;
			ptr[i][j].z *= sz;
		}
	}
	real_translation(ptr[0][0].cx,ptr[0][0].cy,ptr[0][0].cz);
}

/*******************************************************
FUNCTION: real_rotation
ARGS: angle and axis
RETURN:
DOES: rotates shape, for real 
********************************************************/
/*TODO. Note: Absolutely no gl calls*/
/*can assume model-matrix stack contains at this point nothing but viewing transform */
void real_rotation(GLfloat deg, GLfloat x, GLfloat y, GLfloat z) {
	/*
xaxis rotate
--------------
x
ycos(theta)-zsin(theta)
ysin(theta)+zcos(theta)

yaxis rotate
--------------
xcos(theta)+zsin(theta)
y
-xsin(theta)+zcos(theta)

zaxis rotate
--------------
xcos(theta)-ysin(theta)
xsin(theta)+ycos(theta)
z
*/
	int i,j;
	ptr = t_translate(crt_shape);

	for (i = 0;i<50;i++){
		for (j = 0;j<50;j++){
			printf("%f %f %f --",ptr[i][j].x,ptr[i][j].y,ptr[i][j].z);
		}
		printf("\n");
	}
	//real_translation(-1*ptr[0][0].cx,-1*ptr[0][0].cy,-1*ptr[0][0].cz);
	for (i = 0; i<50;i++){
		for (j = 0;j <50;j++){
			if (x ==1){
				ptr[i][j].y = ptr[i][j].y*cos(deg)-ptr[i][j].z*sin(deg);
				ptr[i][j].z = ptr[i][j].y*sin(deg)+ptr[i][j].z*cos(deg);
			}
			if (y==1){
				ptr[i][j].x = ptr[i][j].x*cos(deg)+ptr[i][j].z*sin(deg);
				ptr[i][j].z = ptr[i][j].z*cos(deg)-ptr[i][j].x*sin(deg);
			}
			if (z ==1){
				ptr[i][j].x = ptr[i][j].x*cos(deg)-ptr[i][j].y*sin(deg);
				ptr[i][j].y = ptr[i][j].x*sin(deg)+ptr[i][j].y*cos(deg);
			}
		}
	}
	for (i = 0;i<50;i++){
		for (j = 0;j<50;j++){
			printf("%f %f %f --",ptr[i][j].x,ptr[i][j].y,ptr[i][j].z);
		}
		printf("\n");
	}
	//real_translation(ptr[0][0].cx,ptr[0][0].cy,ptr[0][0].cz);
}


/*******************************************************
FUNCTION: reset
ARGS: 
RETURN:
DOES: resets shape and camera
********************************************************/
/*TODO reset shape post real transformations, as well etc*/
void reset()
{
  glMatrixMode(GL_MODELVIEW) ;
  glLoadIdentity() ;
  x_camera = 0; y_camera = 5; z_camera =30;
  lookat_x = 0;
  lookat_y = 0;
  lookat_z = 0;
  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
  make_stuff(crt_shape);
  draw_object(crt_shape);
}


/*******************************************************
FUNCTION: my_keyboard
ARGS: key id, x, y
RETURN:
DOES: handles keyboard events
********************************************************/
/*TODO: expand to add hmwk 3 keyboard events */
void my_keyboard( unsigned char key, int x, int y ) {
  switch( key ) {
  case 'O':
  case 'o': {
    reset();
    glutPostRedisplay(); 
  }; break;


  case 'y': {
	switch( crt_transform) {
	case ROTATION_MODE: real_rotation(-2,0,1,0); break;
	case TRANSLATION_MODE: real_translation(0,-1,0); break;
	case SCALING_MODE: real_scaling(1,.95,1);break;
	//... etc: handle scaling, real-translation, rotation, scaling
	}
    glutPostRedisplay(); 
  }; break;
  case 'Y': {
	switch( crt_transform) {
	case ROTATION_MODE: real_rotation(2,0,1,0); break;
	case TRANSLATION_MODE: real_translation(0,1,0); break;
	case SCALING_MODE: real_scaling(1,1.05,1);break;
	//... etc: handle scaling, real-translation, rotation, scaling
	}
    glutPostRedisplay(); 
  }; break;
	  case 'x':{
		//printf("T(t) AND x has been pressed\n");
		//translate along the neg. x axis
		  switch( crt_transform) {
			case ROTATION_MODE: real_rotation(-2,1,0,0); break;
			case TRANSLATION_MODE: real_translation(-1,0,0); break;
			case SCALING_MODE: real_scaling(.95,1,1);break;
			//... etc: handle scaling, real-translation, rotation, scaling
		}
		glutPostRedisplay();
	}; break;
  case 'X':{
		//translate along the pos. x axis
	  switch( crt_transform) {
		case ROTATION_MODE: real_rotation(2,1,0,0); break;
		case TRANSLATION_MODE: real_translation(1,0,0); break;
		case SCALING_MODE: real_scaling(1.05,1,1);break;
		//... etc: handle scaling, real-translation, rotation, scaling
	}
		glutPostRedisplay();
	};break;
  case 'z':{
		//translate along the neg. z axis
	  switch( crt_transform) {
		case ROTATION_MODE: real_rotation(-2,0,0,1); break;
		case TRANSLATION_MODE: real_translation(0,0,-1); break;
		case SCALING_MODE: real_scaling(1,1,.95);break;
		//... etc: handle scaling, real-translation, rotation, scaling
	}
		glutPostRedisplay();
	};break;
  case 'Z':{
		//translate along the pos. z axis
	  switch( crt_transform) {
		case ROTATION_MODE: real_rotation(2,0,0,1); break;
		case TRANSLATION_MODE: real_translation(0,0,1); break;
		case SCALING_MODE: real_scaling(1,1,1.05);break;
		//... etc: handle scaling, real-translation, rotation, scaling
	}
		glutPostRedisplay();
	};break;

  //etc...

  case '1': {
    crt_shape = CUBE;
    glutPostRedisplay();
  }; break;
  case '0': {
    crt_shape = HOUSE;
    glutPostRedisplay();
  }; break;
  case '3':{
    crt_shape = CYLINDER;
    glutPostRedisplay();
  }; break;
  case '4': {
    crt_shape = SPHERE;
    glutPostRedisplay();
  }; break;
  case '6': {
    crt_shape = MESH;
    glutPostRedisplay();
  }; break; 
  case '5': {
	  crt_shape = TORUS;
	  glutPostRedisplay();
			};break;

  //etc ... your EC shapes from hmwk2

  case 'S':
  case 's': {
    crt_transform = SCALING_MODE;
  }; break;

  case 'T':
  case 't': {
	  //printf("T or t has been pressed\n");
    crt_transform = TRANSLATION_MODE;
			};break;

  case 'R':
  case 'r': {
    crt_transform = ROTATION_MODE;
  }; break;


  case 'G':
  case 'g': {
    crt_transform = REAL_SCALING_MODE;
  }; break;

  case 'D':
  case 'd': {
    crt_transform = REAL_TRANSLATION_MODE;
  }; break;

  case 'F':
  case 'f': {

    crt_transform = REAL_ROTATION_MODE;
  }; break;

  //add camera controls...
  case 'N':{
	  //move camera along pos. Z world axis
	  z_camera++;
	  lookat_z++;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;
  case 'n':{
	  //move camera along neg. Z world axis
	  z_camera--;
	  lookat_z--;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;
  case 'P':{
	  //move camera along pos. X world axis
	  x_camera++;
	  lookat_x++;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;
  case 'p':{
	  //move camera along neg. X world axis
	  x_camera--;
	  lookat_x--;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;
  case 'V':{
	  //move camera along pos. Y world axis
	  y_camera++;
	  lookat_y++;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;
  case 'v':{
	  //move camera along neg. Y world axis
	  y_camera--;
	  lookat_y--;
	  gluLookAt(x_camera, y_camera,z_camera,lookat_x,lookat_y,lookat_z,0,1,0);
	  glutPostRedisplay();
		   }; break;


  //add your tesselation code from hmwk2
  case '+': {
	  crt_rs++;
	if (crt_rs>49)crt_rs = 49;
	make_stuff(crt_shape);
	glutPostRedisplay();
  }; break;

  case '-': {
	crt_rs--;
	if(crt_rs <= 0) crt_rs = 1;
	make_stuff(crt_shape);
	glutPostRedisplay();
  }; break;

  case '>': {
	  crt_vs++;
	if (crt_vs >49) crt_vs = 49;
	make_stuff(crt_shape);
	glutPostRedisplay();
  }; break;

  case '<': {
	  crt_vs--;
	if (crt_vs <=1)crt_vs = 1;
	make_stuff(crt_shape);
	glutPostRedisplay();
  }; break;

  case 'q': 
  case 'Q':

    exit(0) ;

    break ;	

  default: break;

  }

  

  return ;

}

/*******************************************************
FUNCTION: my_keyboard_up
ARGS: key id, x, y
RETURN:
DOES: handles keyboard up events
********************************************************/
void my_keyboard_up( unsigned char key, int x, int y ) {
	switch( key ) {
	case 'S'://break;
	case 's'://break; 
	case 'T'://break;
	case 't'://break;
	case 'R'://break;
	case 'r': //break;
	//case 'e':	{
	{
		crt_transform = NONE_MODE; break;
		}
	}
}




/*******************************************************
FUNCTION: my_mouse
ARGS: button, state, x, y
RETURN:
DOES: handles mouse events
********************************************************/

void my_mouse(int button, int state, int mousex, int mousey) {
  switch( button ) {	
  case GLUT_LEFT_BUTTON:
    if( state == GLUT_DOWN ) {
 	 if(spin_val == SPIN_ENABLED) spin_val = SPIN_DISABLED;
	  else spin_val = SPIN_ENABLED;
	  glutPostRedisplay();
    }

    if( state == GLUT_UP ) {
    }
    break ;

  case GLUT_RIGHT_BUTTON:
    if( state == GLUT_DOWN ) {
	if(crt_render_mode == GL_LINE_LOOP) crt_render_mode = GL_POLYGON;
	else crt_render_mode = GL_LINE_LOOP;
      glutPostRedisplay();
    }
    if( state == GLUT_UP ) {
    }
    break ;
  }
  
  return ;

}



/***********************************
  FUNCTION: draw_quad 
  ARGS: - a vertex array
        - 4 indices into the vertex array defining a quad face
        - an index into the color array.
  RETURN: none
  DOES:  helper drawing function; draws one quad. 
   For the normal to work out, follow left-hand-rule (i.e., counter clock
   wise) 
*************************************/
void draw_quad(GLfloat vertices[][4], int iv1, int iv2, int iv3, int iv4, int ic) {
  glBegin(crt_render_mode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(vertices[iv1]);
    glVertex4fv(vertices[iv2]);
    glVertex4fv(vertices[iv3]);
    glVertex4fv(vertices[iv4]);
  }
  glEnd();
}

/***********************************
  FUNCTION: draw_param_quad 
  ARGS: - a 50 by 50 by 4 vertex array
        - 2 indices into the vertex array defining the top left of a quad face
        - an index into the color array.
  RETURN: none
  DOES:  helper drawing function; draws one quad. 
*************************************/
void draw_param_quad(GLfloat vertices[][50][4], int line, int col, int ic) {
  glBegin(crt_render_mode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(vertices[line][col]);
    glVertex4fv(vertices[line+1][col]);
    glVertex4fv(vertices[line+1][col+1]);
    glVertex4fv(vertices[line][col+1]);
  }
  glEnd();
}



/***********************************
  FUNCTION: draw_triangle 
  ARGS: - a vertex array
        - 3 indices into the vertex array defining a triangular face
        - an index into the color array.
  RETURN: none
  DOES:  helper drawing function; draws one triangle. 
   For the normal to work out, follow left-hand-rule (i.e., ccw)
*************************************/
void draw_triangle(GLfloat vertices[][4], int iv1, int iv2, int iv3, int ic) {
  glBegin(crt_render_mode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(vertices[iv1]);
    glVertex4fv(vertices[iv2]);
    glVertex4fv(vertices[iv3]);
  }
  glEnd();
}


/***********************************
  FUNCTION: draw_house 
  ARGS: none
  RETURN: none
  DOES: helper build function; 
        defines a hollow cube with a bottomless pyramid as rooftop
************************************/
void draw_house()
{
  draw_triangle(vertices_house,0,1,2,RED);
  draw_triangle(vertices_house,0,2,3,GREEN);
  draw_triangle(vertices_house,0,3,4,WHITE);
  draw_triangle(vertices_house,0,4,1,GREY);


  draw_quad(vertices_house,2,1,5,6, BLUE);
  draw_triangle(vertices_house,2,6,3, CYAN);
  draw_triangle(vertices_house,3,6,7, CYAN);
  draw_triangle(vertices_house,3,7,8, YELLOW);
  draw_triangle(vertices_house,8,3,4, YELLOW);
  draw_triangle(vertices_house,4,8,1, MAGENTA);
  draw_triangle(vertices_house,1,8,5, MAGENTA);

}



/***********************************
  FUNCTION: draw_axes
  ARGS: none
  RETURN: none
  DOES: draws main X, Y, Z axes
************************************/
void draw_axes( void ) {
    glLineWidth( 5.0 );
    glBegin(GL_LINES); 
  {
    glColor3fv(colors[1]);
    glVertex4fv(vertices_axes[0]);
    glVertex4fv(vertices_axes[1]);

    glColor3fv(colors[4]);
    glVertex4fv(vertices_axes[0]);
    glVertex4fv(vertices_axes[2]);

    glColor3fv(colors[6]);
    glVertex4fv(vertices_axes[0]);
    glVertex4fv(vertices_axes[3]);
  }
	glEnd();
	glLineWidth( 1.0 );

}




/***********************************
  FUNCTION: my_display
  ARGS: none
  RETURN: none
  DOES: main drawing function
************************************/
/*TODO add on to make sure we're not losing the crt transform*/
void my_display() {

  // clear all pixels, reset depth 
  glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT );
  
   // init to identity 

   glLoadIdentity() ;

   gluLookAt(x_camera, y_camera, z_camera,  // x,y,z coord of the camera 
	    lookat_x, lookat_y, lookat_z,  // x,y,z LookAt
	    0.0, 1.0, 0.0); // the direction of Up (default is y-axis)

   draw_axes();


   draw_object(crt_shape);

  // this buffer is ready

  glutSwapBuffers();

}

/***********************************
  FUNCTION: my_TimeOut
  ARGS: timer id
  RETURN: none
  DOES: handles "timer" events
************************************/
void my_TimeOut(int id) {
  /* spin counter-clockwise*/
  /* schedule next timer event, 0.2 secs from now */ 
  if(spin_val == SPIN_ENABLED){
    renderer_rev(3,0,1,0);
    
	glutPostRedisplay();
	
  };
  glutTimerFunc(20, my_TimeOut, 0);

  return ;
}


/***********************************
  FUNCTION: my_idle
  ARGS: none
  RETURN: none
  DOES: handles the "idle" event
************************************/
void my_idle(void) {
}


/***********************************
  FUNCTION: make_cube_smart 
  ARGS: size (the edge length)
  RETURN: none
  DOES: helper build function; 
        defines a hollow cube centered at the origin, with edge length 'size'
        the cube has no bottom nor a top
************************************/
/*TODO: compute cube vertices*/
void make_cube_smart(double size)
{
	double height = size;
	double ray = sqrt(3*size*size);
	int rs = 4;
	int vs = 2;
  /*hint: top-face vertices lie on a circle (same for bottom); 
    if need be, generate top-face vertices by cutting the circle in pie slices*/
	int i;
	int j;
	for(i = 0; i <= vs;i++){
		for (j = 0; j <= rs; j++){
			vertices_cube_smart[i][j].x= ray * cos(2*PI*j/rs);
			vertices_cube_smart[i][j].y= i*height/vs - height/2;
			vertices_cube_smart[i][j].z= ray * sin(2*PI* j/rs);
			vertices_cube_smart[i][j].w= 1;
		}//end j for
	}//end i for
}


/***********************************
  FUNCTION: draw_cube_smart 
  ARGS: none
  RETURN: none
  DOES: helper drawing function; constructs cube faces given cube vertices
************************************/
/*TODO: use precomputed vertices,
        stitch vertices together to make faces
        don't bother about color*/
void draw_cube_smart(){
	int i;
	int j;
	int vs = 2;
	int rs = 4;
	for ( i = 0; i < vs;i++){
		for(j = 0; j < rs;j++){
			glBegin(crt_render_mode); 
			{
				glVertex4f(vertices_cube_smart[i][j].x,vertices_cube_smart[i][j].y,vertices_cube_smart[i][j].z,vertices_cube_smart[i][j].w);
				glVertex4f(vertices_cube_smart[i][j+1].x,vertices_cube_smart[i][j+1].y,vertices_cube_smart[i][j+1].z,vertices_cube_smart[i][j+1].w);
				glVertex4f(vertices_cube_smart[i+1][j+1].x,vertices_cube_smart[i+1][j+1].y,vertices_cube_smart[i+1][j+1].z,vertices_cube_smart[i+1][j+1].w);
				glVertex4f(vertices_cube_smart[i+1][j].x,vertices_cube_smart[i+1][j].y,vertices_cube_smart[i+1][j].z,vertices_cube_smart[i+1][j].w);
			}
			glEnd();
		}
	}
	//make the top and bottom for the cylinder, doesnt seem to be rendering it though... 
	//glBegin(crt_render_mode); 
	//	{
	//		for (i=0;i<rs;i++){
	//			glVertex4f(vertices_cube_smart[0][i][0],vertices_cube_smart[0][i][1],vertices_cube_smart[0][i][2],vertices_cube_smart[0][i][3]);
	//		}
	//		
	//	}
	//	glEnd();
	//	glBegin(crt_render_mode); 
	//		{
	//			for (i=0;i<rs;i++){
	//				glVertex4f(vertices_cube_smart[vs-1][i][0],vertices_cube_smart[vs-1][i][1],vertices_cube_smart[vs-1][i][2],vertices_cube_smart[vs-1][i][3]);
	//			}
	//		}
	//		glEnd();
}




/***********************************
  FUNCTION: make_cylinder 
  ARGS: height (along the Y axis), ray, and tesselation parameter (how many side faces) 
  RETURN: none
  DOES: helper build function; 
        defines a cylinder centered at the origin, 
        of height 'height' along the Y axis,
        and ray 'ray' in the XOZ plane
************************************/
/*TODO: compute cylinder vertices*/
void make_cylinder(double height, double ray, int rs, int vs)
{
  /*hint: top-face vertices lie on a circle (same for bottom); 
    if need be, generate top-face vertices by cutting the circle in pie slices*/
	int i;
	int j;
	for(i = 0; i <= vs;i++){
		for (j = 0; j <= rs; j++){
			vertices_cyl[i][j].x= ray * cos(2*PI*j/rs);
			vertices_cyl[i][j].y= i*height/vs - height/2;
			vertices_cyl[i][j].z= ray * sin(2*PI* j/rs);
			vertices_cyl[i][j].w= 1;
		}//end j for
	}//end i for
	
	vertices_cyl[0][0].cx = 0;
	vertices_cyl[0][0].cy = 0;
	vertices_cyl[0][0].cz = 0;
	vertices_cyl[0][0].cw = 1;
}

/***********************************
	FUNCTION: make_cone
	ARGS: Radius, height, radial sections, and vertical sections
	RETURN: none
	DOES: Builds a cone from the ground up....
************************************/
void make_cone(double radius, double height,int rs, int vs){
	int i;
	int j;
	for (i = 0;i<=vs;i++){
		for (j=0;j<=rs;j++){
			vertices_cone[i][j].x = (radius*(vs-i)/vs)*cos(2*PI*j/rs);
			vertices_cone[i][j].y = i*height/vs - height/2;
			vertices_cone[i][j].z = (radius*(vs-i)/vs)*sin(2*PI*j/rs);
			vertices_cone[i][j].w = 1;
		}
	}
	vertices_cone[0][0].cx = 0;
	vertices_cone[0][0].cy = 0;
	vertices_cone[0][0].cz = 0;
	vertices_cone[0][0].cw = 1;
	
}
/***********************************
	FUNCTION: draw_cone()
	ARGS: none
	RETURN: none
	DOES: draws a cone
************************************/
void draw_cone(int rs,int vs){
	int i;
	int j;
	for (i=0;i<vs;i++){
		for(j=0;j<rs;j++){
			glBegin(crt_render_mode); 
			{
				glVertex4f(vertices_cone[i][j].x,vertices_cone[i][j].y,vertices_cone[i][j].z,vertices_cone[i][j].w);
				glVertex4f(vertices_cone[i][j+1].x,vertices_cone[i][j+1].y,vertices_cone[i][j+1].z,vertices_cone[i][j+1].w);
				glVertex4f(vertices_cone[i+1][j+1].x,vertices_cone[i+1][j+1].y,vertices_cone[i+1][j+1].z,vertices_cone[i+1][j+1].w);
				glVertex4f(vertices_cone[i+1][j].x,vertices_cone[i+1][j].y,vertices_cone[i+1][j].z,vertices_cone[i+1][j].w);
			}
			glEnd();
		}
	}
}
/***********************************
  FUNCTION: make_sphere 
  ARGS: ray, and tessellation parameters (how many meridians, respectively parallels) 
  RETURN: none
  DOES: helper build function; 
        defines a sphere centered at the origin and of ray 'ray'
************************************/
/*TODO: compute sphere vertices, 
        don't bother about color*/


void make_sphere(double ray, int rs, int vs)
{
  int i;
  int j;
  for (i = 0; i <= vs; i++){
	  for (j = 0; j <= rs; j++){
		vertices_sph[i][j].x = ray * sin(-PI/2+i*2*PI/vs) * cos(PI*j/rs);
		vertices_sph[i][j].y = ray * cos(-PI/2+i*2*PI/vs);
		vertices_sph[i][j].z = ray* sin(-PI/2+i*2*PI/vs) * sin(PI*j/rs);
		vertices_sph[i][j].w = 1;
	  }//end j
  }//end i
  
	vertices_sph[0][0].cx = 0;
	vertices_sph[0][0].cy = 0;
	vertices_sph[0][0].cz = 0;
	vertices_sph[0][0].cw = 1;
}

/***********************************
	FUNCTION: make_torus()
	ARGS: Innter radius, thickness radius, radial slices, and avertical slices
	RETURN: none
	DOES: makes a torus
************************************/
void make_torus( double r1,double r2, int rs, int vs){
	int i;
	int j;
	double phi,theta,x,y,z;

	for (i=0;i<=rs;i++){
		theta = 2*PI*i/rs;
		x = r1+r2*cos(theta);
		y = r2*sin(theta);
		z=0;
		for(j=0;j<=vs;j++){
			phi = 2*PI*j/vs;
			vertices_torus[i][j].x = x*cos(phi)+z*sin(phi);
			vertices_torus[i][j].y = y;
			vertices_torus[i][j].z = -1*x*sin(phi)+ z*cos(phi);
			vertices_torus[i][j].w = 1;
		}
	}
	vertices_torus[0][0].cx = 0;
	vertices_torus[0][0].cy = 0;
	vertices_torus[0][0].cz = 0;
	vertices_torus[0][0].cw = 1;
}

/***********************************
	FUNCTION: draw_torus()
	ARGS: none
	RETURN: none
	DOES: draws a torus
************************************/
void draw_torus(int rs, int vs){
	int i;
	int j;
	for (i = 0; i <rs;i++){
		for (j = 0;j<vs;j++){
			glBegin(crt_render_mode); 
			{
				glVertex4f(vertices_torus[i][j].x,vertices_torus[i][j].y,vertices_torus[i][j].z,vertices_torus[i][j].w);
				glVertex4f(vertices_torus[i][j+1].x,vertices_torus[i][j+1].y,vertices_torus[i][j+1].z,vertices_torus[i][j+1].w);
				glVertex4f(vertices_torus[i+1][j+1].x,vertices_torus[i+1][j+1].y,vertices_torus[i+1][j+1].z,vertices_torus[i+1][j+1].w);
				glVertex4f(vertices_torus[i+1][j].x,vertices_torus[i+1][j].y,vertices_torus[i+1][j].z,vertices_torus[i+1][j].w);
			}
			glEnd();
		}
	}
}

/***********************************
  FUNCTION: draw_cylinder() 
  ARGS: none
  RETURN: none
  DOES: draws a cylinder from triangles
************************************/
/*TODO: stitch cylinder vertices together to make faces
don't call gl directly, use my_draw_triangle and my_draw_quad instead*/
void draw_cylinder(int rs, int vs)
{
	int i;
	int j;
	for ( i = 0; i < vs;i++){
		for(j = 0; j < rs;j++){
			glBegin(crt_render_mode); 
			{
				glVertex4f(vertices_cyl[i][j].x,vertices_cyl[i][j].y,vertices_cyl[i][j].z,vertices_cyl[i][j].w);
				glVertex4f(vertices_cyl[i][j+1].x,vertices_cyl[i][j+1].y,vertices_cyl[i][j+1].z,vertices_cyl[i][j+1].w);
				glVertex4f(vertices_cyl[i+1][j+1].x,vertices_cyl[i+1][j+1].y,vertices_cyl[i+1][j+1].z,vertices_cyl[i+1][j+1].w);
				glVertex4f(vertices_cyl[i+1][j].x,vertices_cyl[i+1][j].y,vertices_cyl[i+1][j].z,vertices_cyl[i+1][j].w);
			}
			glEnd();
		}
	}
	//make the top and bottom for the cylinder, doesnt seem to be rendering it though... 
	glBegin(crt_render_mode); 
		{
			for (i=0;i<rs;i++){
				glVertex4f(vertices_cyl[0][i].x,vertices_cyl[0][i].y,vertices_cyl[0][i].z,vertices_cyl[0][i].w);
			}
			
		}
		glEnd();	
		glBegin(crt_render_mode); 
			{
				for (i=0;i<rs;i++){
					glVertex4f(vertices_cyl[vs-1][i].x,vertices_cyl[vs-1][i].y,vertices_cyl[vs-1][i].z,vertices_cyl[vs-1][i].w);
				}
			}
			glEnd();
}

/***********************************
  FUNCTION: draw_sphere() 
  ARGS: none
  RETURN: none
  DOES: draws a sphere from triangles
************************************/
/*TODO: stitch sphere vertices together to make faces
don't call gl directly, use make_triangle and make_quad instead*/
void draw_sphere(int rs, int vs)
{
	int i;
	int j;
	for ( i = 0; i < vs;i++){
		for(j = 0; j < rs;j++){
			glBegin(crt_render_mode); 
			{
				glVertex4f(vertices_sph[i][j].x,vertices_sph[i][j].y,vertices_sph[i][j].z,vertices_sph[i][j].w);
				glVertex4f(vertices_sph[i][j+1].x,vertices_sph[i][j+1].y,vertices_sph[i][j+1].z,vertices_sph[i][j+1].w);
				glVertex4f(vertices_sph[i+1][j+1].x,vertices_sph[i+1][j+1].y,vertices_sph[i+1][j+1].z,vertices_sph[i+1][j+1].w);
				glVertex4f(vertices_sph[i+1][j].x,vertices_sph[i+1][j].y,vertices_sph[i+1][j].z,vertices_sph[i+1][j].w);
			}
			glEnd();
		}
	}
}


/***********************************
  FUNCTION: draw_object 
  ARGS: shape to create (HOUSE, CUBE, CYLINDER, etc)
  RETURN: none
  DOES: draws an object from triangles
************************************/
/*TODO: expand according to assignment 2 specs*/
void draw_object(int shape) {

  switch(shape){
  case HOUSE: draw_house(); break;
  case CUBE: draw_cube_smart(); break; /*TODO: replace with draw_cube_smart*/
  case CYLINDER: draw_cylinder(crt_rs, crt_vs);  break;
  case SPHERE: draw_sphere(crt_rs, crt_vs);  break;
  //case CONE: draw_cone(crt_rs,crt_vs);  break;
  case TORUS: draw_torus(crt_rs,crt_vs); break;
  case MESH: /*TODO EC: call your function here*/ ; break;

  default: break;
  }

}

/***********************************
	FUNCTION: make_stuff()
	ARGS: target shape
	RETURN: none
	DOES: remake objects.
************************************/
  
void make_stuff(int shape){
	switch(shape){
		case HOUSE: break;
		case CUBE:make_cube_smart(1);break;
		case CYLINDER:make_cylinder(cyl_height,cyl_ray,crt_rs,crt_vs);break;
		case SPHERE:make_sphere(sph_ray,crt_rs,crt_vs);break;
		case CONE:make_cone(sph_ray,cyl_height,crt_rs,crt_vs);break;
		case TORUS:make_torus(torusr1,torusr2,crt_rs,crt_vs);break;
		case MESH:/*insert mesh code here*/break;

		default: break;
	}
}
vertex (*(t_translate)(int shape))[50]{
	
	//ObjectArray ptr = (ObjectArray) new GLfloat[50][50][4];
	//ObjectArray ptrcube = (ObjectArray) new GLfloat[4][4][4];
	switch (shape){
	case HOUSE:{
		//ptr points to house.
			   };break;
	//case CUBE: {
	//	return vertices_cube_smart;
	//		   };break;
	case CYLINDER: {
		return vertices_cyl;
				   }; break;
	case SPHERE: {
		return vertices_sph;
				 }; break;
	case CONE: {
		return vertices_cone;
			   }; break;
	case TORUS: {
		return vertices_torus;
				}; break;
	case MESH: {
		//need to put something in here if i am to do a mesh.
			   }; break;
	default: break;
	}
	return 0;

}

GLfloat** matrix_mult (GLfloat** matrix, GLfloat** obj, int arow,int acol, int brow, int bcol){
	//what... cant we... have our cake... and eat it to..?
	if (arow != bcol)return 0; //if they dont match.
	int j, k, m;
	GLfloat ans;
	GLfloat **result = new GLfloat*[arow];
	for (j =0;j<arow;j++){
		result[j] = new GLfloat[acol];
	}
	//matrix cross-product obj
	for(j = 0;j < arow;j++){
		for(k = 0;k<bcol;k++){
			ans = 0;
			for (m=0;m<arow;m++){
				ans += matrix[j][m]*obj[m][k];
			}
			result[j][k] = ans;
		}
	}
	return result;
}
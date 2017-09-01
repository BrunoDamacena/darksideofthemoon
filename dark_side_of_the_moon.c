/*
    Pink Floyd - Dark Side of the Moon Cover
    By Bruno Damacena, Computer Engineering Student
*/

#include <GL/glew.h>
#include <GL/freeglut.h>

void darkSide(double a, double b,double c, double d,double e, double f,double g, double h){
    glBegin(GL_POLYGON);
        glVertex3f(a, b, 0);
        glVertex3f(c, d, 0);
        glVertex3f(e, f, 0);
        glVertex3f(g, h, 0);
    glEnd();
}

void desenhaCena(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //set color as white
    glColor3f(1, 1, 1);

    // draw the main triangle
    glBegin(GL_LINE_LOOP);
        glVertex3f(-40, -40, 0);
        glVertex3f(40, -40, 0);
        glVertex3f(0, 40, 0);
    glEnd();
    
    // draw the line going to the main triangle
    glBegin(GL_LINE_STRIP);
        glVertex3f(-200, -50, 0);
        glVertex3f(-20, 0, 0);
        //glVertex3f(0, 40, 0);
    glEnd();
    // draw the triangle inside the main triangle
    glColor3f(.9, .9, .9);
    glBegin(GL_TRIANGLES);
        glVertex3f(-20, 0, 0);
        glVertex3f(25, -10, 0);
        glVertex3f(15, 10, 0);
    glEnd();
    // set color as red 
    glColor3f(1, 0, 0);
    darkSide(15,10,(51/3),(20/3),200,-(65/3),200,-15);
    // set color as orange    
    glColor3f(1, 0.5, 0);
    darkSide((51/3),(20/3),(55/3),(10/3),200,-(85/3),200,-(65/3));
    // set color as yellow 
    glColor3f(1, 1, 0);
    darkSide((55/3),(10/3),20,0,200,-35,200,-(85/3));
    // set color as green   
    glColor3f(0, 1, 0);
    darkSide(20,0,(65/3),-(10/3),200,-(125/3),200,-35);
    // set color as light blue    
    glColor3f(0, 1, 1);
    darkSide((65/3),-(10/3),(70/3),-(20/3),200,-(145/3),200,-(125/3));
    // set color as purple    
    glColor3f(1, 0, 1);
    darkSide((70/3),-(20/3),25,-10,200,-55,200,-(145/3)); 


    // show the drawing on screen using OpenGL
    glFlush();
}

void inicializa(void)
{
    // background color - black
    glClearColor(0, 0, 0, 0);
}

// auto-rezise callback
void redimensiona(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-200, 200, -100, 100, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// keyboard event callback
void teclado(unsigned char key, int x, int y)
{
   switch(key)
   {
      // ESC
      case 27:
         exit(0); // quit
         break;
      default:
         break;
   }
}

int main(int argc, char **argv)
{
    // start Glut
    glutInit(&argc, argv);

    // set OpenGL version
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Start Glut Window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);

    // create and open the window
    glutCreateWindow("Dark Side of the Moon");

    // register the callbacks
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    inicializa();

    // start glut loop
    glutMainLoop();
    return 0;
}


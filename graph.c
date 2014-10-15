#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

GLdouble vertex[][3] = {
    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 0.5, 0.0},
    {0.0, 0.5, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 0.5, 1.0},
    {0.0, 0.5, 1.0}
};

int edge[][2] = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 4},
    {0, 4},
    {1, 5},
    {2, 6},
    {3, 7}
};

void idle()
{
    glutPostRedisplay();
}

void display()
{
    int i;
    static double rev = 0.0;

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0 ,1.0, 0.0);

    glRotated((double)rev, 0.0, 1.0, 0.0);

    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for(i = 0; i < 12; i++){
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();

    glFlush();

    rev += 0.1;
    if(rev >= 360.0)rev = 0.0;
}

void resize(int w, int h){
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'q':
        case 'Q':
        case '\033':
            exit(0);

        case 's':
            glutIdleFunc(idle);
            break;

        case 'd':
            glutIdleFunc(0);
            break;

        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}

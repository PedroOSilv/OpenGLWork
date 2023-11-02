from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

window = 0                                             # glut window number

def init():
   glClearColor(0.0, 0.0, 0.0, 1.0); # Black and opaque

def display():
   #Draw a Red 1x1 Square centered at origin
   glClear(GL_COLOR_BUFFER_BIT) # clear the screen
   glColor3f(1.0, 0.0, 0.0) # Red
   
   glBegin(GL_QUADS)          # Each set of 4 vertices form a quad
   glVertex2f(-0.5, -0.5)    # x, y
   glVertex2f( 0.5, -0.5)
   glVertex2f( 0.5,  0.5)
   glVertex2f(-0.5,  0.5)
   glEnd()
   
   glFlush()

# initialization
glutInit()                                             # initialize glut

glutInitDisplayMode(GLUT_RGBA)
glutInitWindowSize(480, 480)                      # set window size
glutInitWindowPosition(50, 50)                           # set window position
window = glutCreateWindow(b'Hello')              	# create window with title

glutDisplayFunc(display)                                  # set draw function callback
glutIdleFunc(display)                                     # draw all the time

init()
glutMainLoop()      

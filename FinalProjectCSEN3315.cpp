// Created by: Leo Martinez III in Fall 2022
#include <windows.h>
#include <GL/glut.h>
#include <stdbool.h>

char title[] = "UserControlled_LiveDemo" ; // Title that will be used for the window we create
int refreshMills = 1;        // Refresh interval in milliseconds
int windowWidth  = 640;     // Windowed mode's width
int windowHeight = 480;     // Windowed mode's height
int windowPosX   = 50;      // Windowed mode's top-left corner x
int windowPosY   = 50;      // Windowed mode's top-left corner y
bool paused = false;         // Movement paused or resumed
bool fullScreenMode = true; // Full-screen or windowed mode

GLfloat xMov = - 1.5f;      // 1st 3d shape's movement in x direction
GLfloat yMov = - 1.5f;     // 1st 3d shape's movement in y direction
GLfloat zMov = - 7.0f;     // 1st 3d shape's movement in z direction
GLfloat xMov2 = 1.5f;      // 2nd 3d shape's movement in x direction
GLfloat yMov2 = 1.5f;     // 2nd 3d shape's movement in y direction
GLfloat zMov2 = - 7.0f;     // 2nd 3d shape's movement in z direction
GLfloat xMov3 = -2.5f;		// 3rd 2d shape's movement in x direction
GLfloat yMov3 = 1.5f;		// 3rd 2d shape's movement in y direction
GLfloat zMov3 = -10.0f;		// 3rd 2d shape's movement in z direction

GLfloat angleCube = 0.0f;  // Rotational angle for Cube
GLfloat angleRectangular_Prism = 0.0f;     // Rotational angle for Rectangular Prism
GLfloat angleTriangle = 0.0f;	// Rotstional angle for Triangle

GLfloat angleCubeRot = 0.2f;  // angle of rotation of the Cube
GLfloat angleRectangular_PrismRot = 0.15f;    // angle of rotation of the Rectangular Prism
GLfloat angleTriangleRot = 0.25f;	// angle of rotation of the Triangle
GLfloat angleCubeRotSaved = 0; // variable for angle of rotation of the Cube saved when paused
GLfloat angleRectangular_PrismRotSaved = 0;    // variable for angle of rotation of the Rectangular Prism saved when paused
GLfloat angleTriangleRotSaved = 0;	// variable for angle of rotation of the Triangle saved when paused

GLfloat redcv = 1.0f;   // red color value initial
GLfloat bluecv = 0.0f;  // blue color value initial
GLfloat greencv = 1.0f; // green color value initial
GLfloat clearcolor_red = 0.0f; // red color value initial for background
GLfloat clearcolor_blue = 0.0f; // blue color value initial for background
GLfloat clearcolor_green = 0.0f; // green color value initial for background

// Initialize OpenGL Graphics
void initGL() {
    glClearDepth ( 1.0f );        // Set background depth to farthest
    glEnable ( GL_DEPTH_TEST );   // Enable depth testing for z-culling
    glDepthFunc ( GL_LEQUAL );    // Set the type of depth-test
    glShadeModel ( GL_SMOOTH );   // Enable smooth shading
    glHint (GL_PERSPECTIVE_CORRECTION_HINT , GL_NICEST );  // Nice perspective corrections
}
void display() {
	glClearColor ( clearcolor_red , clearcolor_blue , clearcolor_green , 1.0f ); //Set initial background color black and opaque
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Clear color and depth buffers
    glMatrixMode ( GL_MODELVIEW );     // To operate on model-view matrix
    
    glLoadIdentity ();                                          // Reset the model-view matrix
    glTranslatef ( xMov , yMov , zMov );                        // translate the 1st 3D shape by its defined x, y, and z movements
    glRotatef ( angleRectangular_Prism , 1.0f , 1.0f , 1.0f );  // Rotate about (1,1,1)-axis
    
    glBegin ( GL_QUADS ); // Begin drawing the color Rectangular Prism with 6 quads
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f (redcv + 0.1f , greencv + 0.2f , bluecv + 0.3f );
    glVertex3f( 1.0f, 1.0f, - 1.0f);
    glVertex3f(- 1.0f, 1.0f, - 1.0f);
    glVertex3f(- 1.0f, 1.0f,   1.0f);
    glVertex3f( 1.0f, 1.0f,   1.0f);
    
    glColor3f (redcv + 0.4f , greencv + 0.5f , bluecv + 0.6f );
    glVertex3f( 1.0f, - 2.3f,   1.0f);
    glVertex3f(- 1.0f, - 2.3f,   1.0f);
    glVertex3f(- 1.0f, - 2.3f, - 1.0f);
    glVertex3f( 1.0f, - 2.3f, - 1.0f);
    
    glColor3f (redcv + 0.3f , greencv + 0.4f , bluecv + 0.5f );
    glVertex3f( 1.0f,   1.0f, 1.0f);
    glVertex3f(- 1.0f,   1.0f, 1.0f);
    glVertex3f(- 1.0f, - 2.3f, 1.0f);
    glVertex3f( 1.0f, - 2.3f, 1.0f);
    
    glColor3f (redcv + 0.55f , greencv + 0.65f , bluecv + 0.75f );
    glVertex3f( 1.0f, - 2.3f, - 1.0f);
    glVertex3f(- 1.0f, - 2.3f, - 1.0f);
    glVertex3f(- 1.0f,   1.0f, - 1.0f);
    glVertex3f( 1.0f,   1.0f, - 1.0f);
    
    glColor3f (redcv + 0.35f , greencv + 0.45f , bluecv + 0.55f );
    glVertex3f(- 1.0f,   1.0f,   1.0f);
    glVertex3f(- 1.0f,   1.0f, - 1.0f);
    glVertex3f(- 1.0f, - 2.3f, - 1.0f);
    glVertex3f(- 1.0f, - 2.3f,   1.0f);
    
    glColor3f (redcv + 0.45f , greencv + 0.55f , bluecv + 0.65f );
    glVertex3f( 1.0f,   1.0f, - 1.0f);
    glVertex3f( 1.0f,   1.0f,   1.0f);
    glVertex3f( 1.0f, - 2.3f,   1.0f);
    glVertex3f( 1.0f, - 2.3f, - 1.0f);
    glEnd ();  // End of drawing Rectangular Prism
    
    glLoadIdentity ();                  	   	   // Reset the model-view matrix
    glTranslatef ( xMov2 , yMov2 , zMov2 );        // translate the 2nd 3D shape by its defined x, y, and z movements
    glRotatef ( angleCube , 1.0f , 1.0f , 0.0f );  // Rotate about the (1,1,0)-axis
    
    glBegin ( GL_QUADS ); // Begin drawing the color Cube with 6 quads
    glColor3f (redcv + 0.2f , greencv + 0.3f , bluecv + 0.4f );
    glVertex3f( 1.0f, 1.0f, - 1.0f);
    glVertex3f(- 1.0f, 1.0f, - 1.0f);
    glVertex3f(- 1.0f, 1.0f,   1.0f);
    glVertex3f( 1.0f, 1.0f,   1.0f);
    
    glColor3f (redcv + 0.4f , greencv + 0.5f , bluecv + 0.6f );
    glVertex3f( 1.0f, - 1.0f,   1.0f);
    glVertex3f(- 1.0f, - 1.0f,   1.0f);
    glVertex3f(- 1.0f, - 1.0f, - 1.0f);
    glVertex3f( 1.0f, - 1.0f, - 1.0f);
    
    glColor3f (redcv + 0.4f , greencv + 0.5f , bluecv + 0.6f );
    glVertex3f( 1.0f,   1.0f, 1.0f);
    glVertex3f(- 1.0f,   1.0f, 1.0f);
    glVertex3f(- 1.0f, - 1.0f, 1.0f);
    glVertex3f( 1.0f, - 1.0f, 1.0f);
    
    glColor3f (redcv + 0.15f , greencv + 0.25f , bluecv + 0.35f );
    glVertex3f( 1.0f, - 1.0f, - 1.0f);
    glVertex3f(- 1.0f, - 1.0f, - 1.0f);
    glVertex3f(- 1.0f,   1.0f, - 1.0f);
    glVertex3f( 1.0f,   1.0f, - 1.0f);
    
    glColor3f (redcv + 0.35f , greencv + 0.45f , bluecv + 0.55f );
    glVertex3f(- 1.0f,   1.0f,   1.0f);
    glVertex3f(- 1.0f,   1.0f, - 1.0f);
    glVertex3f(- 1.0f, - 1.0f, - 1.0f);
    glVertex3f(- 1.0f, - 1.0f,   1.0f);
    
    glColor3f (redcv + 0.35f , greencv + 0.45f , bluecv + 0.55f );
    glVertex3f( 1.0f,   1.0f, - 1.0f);
    glVertex3f( 1.0f,   1.0f,   1.0f);
    glVertex3f( 1.0f, - 1.0f,   1.0f);
    glVertex3f( 1.0f, - 1.0f, - 1.0f);
    glEnd ();  // End of drawing Cube
    
    glLoadIdentity ();                      		   // Reset the model-view matrix
    glTranslatef ( xMov3 , yMov3 , zMov3 ); 		   // translate the 2nd 3D shape by its defined x, y, and z movements
    glRotatef ( angleTriangle , 1.0f , 1.0f , 0.0f );  // Rotate about the (1,1,0)-axis
   
    glBegin ( GL_TRIANGLES );
    glColor3f (redcv + 0.1f , greencv + 0.2f , bluecv + 0.3f );
    glVertex3f ( 0.0f , 1.0f , 0.0f );
    glColor3f (redcv + 0.4f , greencv + 0.5f , bluecv + 0.6f );
    glVertex3f(- 1.0f, - 1.0f, 1.0f);
    glColor3f (redcv + 0.7f , greencv + 0.8f , bluecv + 0.9f );
    glVertex3f (1.0f , -1.0f , 1.0f );
    glEnd(); // End of drawing Triangle
    
    glutSwapBuffers ();  // Swap the front and back frame buffers (double buffering)
    
    // Update the rotational angles for all 3 shapes after each refresh
    angleCube -= angleCubeRot ;
    angleRectangular_Prism += angleRectangular_PrismRot ;
    angleTriangle += angleTriangleRot;
}
// Called back when timer expired
void timer( int value) {
    glutPostRedisplay ();      					// Post re-paint request to activate display()
    glutTimerFunc ( refreshMills , timer , 0 ); // next timer call milliseconds later
}
void reshape( GLsizei width, GLsizei height) {
    if (height == 0) height = 1;                			  // To prevent divide by 0
    GLfloat aspect = ( GLfloat )width / ( GLfloat )height;    // Compute aspect ratio of the new window
    
    glViewport ( 0 , 0 , width, height);   // Set the viewport to cover the new window
    
    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode ( GL_PROJECTION );  // To operate on the Projection matrix
    glLoadIdentity();             	 // Reset
    gluPerspective ( 55.0f , aspect, 0.1f , 100.0f );    // Enable perspective projection with fovy, aspect, zNear and zFar
}
void mouse( int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
        paused = ! paused;        							// Toggle state
        if ( paused) {
            angleCubeRotSaved = angleCubeRot ; // save the angle of rotation for the Cube
            angleRectangular_PrismRotSaved = angleRectangular_PrismRot ; // save the angle of rotation for the Rectangular Prism
            angleTriangleRotSaved = angleTriangleRot ; // save the angle of rotation for the Triangle
            angleCubeRot = 0 ; // Stop angular rotation movement for the pyramid
            angleRectangular_PrismRot = 0 ; // Stop angular rotation movement for the Rectangular Prism
            angleTriangleRot = 0; // Stop angular rotation movement for the Triangle
        } else {
            angleCubeRot = angleCubeRotSaved ;  // Restore angle of rotation for the Cube
            angleRectangular_PrismRot = angleRectangular_PrismRotSaved ; // Restore angle of rotation for the Rectangular Prism
            angleTriangleRot = angleTriangleRotSaved ; // Restor angle of rotation for the Triangle
        }
    }
}
void keyboard( unsigned char key, int x, int y) {
    switch (key) {
        case 27:     // ESC key to exit the program
            exit(0);
            break;
        case 8:		 // Backspace key to revert shapes back to their initial color
        	redcv = 1.0f;  
			bluecv = 0.0f;  
			greencv = 1.0f;
			break;
            
        //keys used for changing shape colors
        case 'p':		// Turn the shapes Purple
            redcv = 0.4f;
            bluecv = 0.8f;
            greencv = 0.0f;
            break;
        case 'r':		// Turn the shapes Red
            redcv = 1.0f;
            bluecv = 0.0f;
            greencv = 0.0f;
            break;
        case 'g':		// Turn the shapes Green
            redcv = 0.0f;
            bluecv = 0.0f;
            greencv = 1.0f;
            break;
        case 'b':		// Turn the shapes Blue
            redcv = 0.0f;
            bluecv = 1.0f;
            greencv = 0.0f;
            break;
        case 'v':  // Turn the shapes Brown
            redcv = 0.6f;
            greencv = 0.3f;
            bluecv = 0.0f;
            break;
        case '1':	// Turn the background White
        	clearcolor_red = 1.0f;
        	clearcolor_blue = 1.0f;
        	clearcolor_green = 1.0f; 
        	break;
        case '2':	// Turn the background Black
        	clearcolor_red = 0.0f;
        	clearcolor_blue = 0.0f;
        	clearcolor_green = 0.0f; 
        	break;
        case '3':	// Turn the background Red
        	clearcolor_red = 1.0f;
        	clearcolor_blue = 0.0f;
        	clearcolor_green = 0.0f; 
        	break;
        case '4':	// Turn the background Blue
        	clearcolor_red = 0.0f;
        	clearcolor_blue = 1.0f;
        	clearcolor_green = 0.0f; 
        	break;
        case '5':	// Turn the background Green
        	clearcolor_red = 0.0f;
        	clearcolor_blue = 0.0f;
        	clearcolor_green = 1.0f; 
        	break;
        	
        // keys used for moving shapes
    	case 'w':	// Move the Cube UP
            yMov2 = yMov2 + 0.25f;
            break;
        case 's':	// Move the Cube DOWN
            yMov2 = yMov2 - 0.25f;
            break;
        case 'a':	// Move the Cube LEFT
            xMov2 = xMov2 - 0.25f;
            break;
        case 'd':	// Move the Cube RIGHT
            xMov2 = xMov2 + 0.25f;
            break;
        case 'z':	// Move the Cube FORWARD
            zMov2 = zMov2 + 0.25f;
            break;
        case 'x':	// Move the Cube BACKWARD
            zMov2 = zMov2 - 0.25f;
            break;
        case 'u':	// Move the Triangle UP
      		yMov3 = yMov3 + 0.25f;
      		break;
        case 'j':	// Move the Triangle DOWN
        	yMov3 = yMov3 - 0.25f;
        	break;
        case 'h':	// Move the Triangle LEFT
        	xMov3 = xMov3 - 0.25f;
        	break;
        case 'k':	// Move the Triangle RIGHT
        	xMov3 = xMov3 + 0.25f;
        	break;
        case 't':	// Move the Triangle FORWARD
        	zMov3 = zMov3 + 0.25f;
        	break;
        case 'y':	// Move the Triangle BACKWARD
        	zMov3 = zMov3 - 0.25f; 
        	break;
    }    
}
void specialKeys( int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_INSERT :    // Insert key: toggle between full-screen and windowed mode
            fullScreenMode = !fullScreenMode ;         // Toggle state
            if ( fullScreenMode){                     // Full-screen mode
                windowPosX   = glutGet ( GLUT_WINDOW_X ); // Save parameters for restoring later
                windowPosY   = glutGet( GLUT_WINDOW_Y);
                windowWidth   = glutGet( GLUT_WINDOW_WIDTH);
                windowHeight = glutGet( GLUT_WINDOW_HEIGHT);
                glutFullScreen();                       // Switch into full screen
            }
            else {                                         // Windowed mode
                glutReshapeWindow ( windowWidth , windowHeight ); // Switch into windowed mode
                glutPositionWindow ( windowPosX , windowPosX );   // Position top-left corner
            }
            break;
        case GLUT_KEY_RIGHT :    // Move the Rectangular Prism RIGHT
            xMov = xMov + 0.25f;
            break;
        case GLUT_KEY_LEFT:     // Move the Rectangular Prism LEFT
            xMov = xMov - 0.25f;
            break;
        case GLUT_KEY_UP:       // Move the Rectangular Prism UP
            yMov = yMov + 0.25f;
            break;
        case GLUT_KEY_DOWN:     // Move the Rectangular Prism DOWN
            yMov = yMov - 0.25f;
            break;
        case GLUT_KEY_PAGE_UP :  // Move the Rectangular Prism FORWARD
            zMov = zMov + 0.25f;
            break;
        case GLUT_KEY_PAGE_DOWN : // Move the Rectangular Prism BACK
            zMov = zMov - 0.25f;
            break;
    }
}
// Main function: GLUT runs as a console application starting at main()
int main( int argc, char** argv) {
    glutInit(&argc, argv);             // Initialize GLUT
    glutInitDisplayMode ( GLUT_DOUBLE ); // Enable double buffered mode
    glutInitWindowSize ( windowWidth , windowHeight );  // Initial window width and height
    glutInitWindowPosition ( windowPosX , windowPosY ); // Initial window top-left corner (x, y)
    glutCreateWindow ( title );          // Create window with the given title
    glutDisplayFunc ( display );       // Register callback handler for window re-paint event
    glutReshapeFunc ( reshape );       // Register callback handler for window re-size event
    glutMouseFunc ( mouse );   // Register callback handler for mouse event
    glutSpecialFunc ( specialKeys ); // Register callback handler for special-key event
    glutKeyboardFunc ( keyboard );   // Register callback handler for keyboard event
    initGL ();                       // Our own OpenGL initialization
    glutTimerFunc ( 0 , timer , 0 );     // First timer call immediately
    glutMainLoop ();                 // Enter the infinite event-processing loop
    return 0;
}

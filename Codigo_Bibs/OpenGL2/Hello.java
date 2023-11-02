package tests.OGL2.basics;

import javax.swing.JFrame;

import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.awt.GLJPanel;

public class Hello implements GLEventListener {
	@Override
	public void init(GLAutoDrawable drawable) {
		System.err.println("Init: " + drawable);
		GL2 gl = drawable.getGL().getGL2();
		// Set the current clear color to black and the current drawing color to
		// white.
		gl.glClearColor(0f, 0f, 0f, 1f);
	}

	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
		System.err.println("Reshape " + x + "/" + y + " " + width + "x" + height);
		GL2 gl = drawable.getGL().getGL2();
		// Just the glViewport for this sample
		gl.glViewport(x, y, width, height);
	}

	@Override
	public void dispose(GLAutoDrawable drawable) {
		System.err.println("Dispose");
	}

	@Override
	public void display(GLAutoDrawable drawable) {
		System.err.println("Init: " + drawable);
		GL2 gl = drawable.getGL().getGL2();
		// Set every pixel in the frame buffer to the current clear color.
		gl.glClear(GL2.GL_COLOR_BUFFER_BIT);
		gl.glColor3f(1.0f, 0.0f, 0.0f);//red

		// call your draw code here
		gl.glBegin(GL2.GL_QUADS);
		gl.glVertex2f(-0.5f, -0.5f);
		gl.glVertex2f( 0.5f, -0.5f);
		gl.glVertex2f( 0.5f,  0.5f);
		gl.glVertex2f(-0.5f,  0.5f);
		gl.glEnd();

		// Flush drawing command buffer to make drawing happen as soon as
		// possible.
		gl.glFlush();

	}

	public static void main(String[] args) {
		GLProfile profile = GLProfile.get(GLProfile.GL2);
		GLJPanel canvas = new GLJPanel(new GLCapabilities(profile));
		canvas.addGLEventListener(new Hello());

		JFrame app = new JFrame("Hello");
		app.setSize(480, 480);
		app.setLocationRelativeTo(null);
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.getContentPane().add(canvas);
		app.setVisible(true);
	}
}

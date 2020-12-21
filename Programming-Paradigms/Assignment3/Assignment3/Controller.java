/*
/ Name: Riley Nadwodny
/ Date: 9/11/2020
/ Description: Controller class use to control the turtle for movement.
/ This listens to the moust and keyboard for events and updates the model 
/ destination as necessary.
*/

import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

class Controller implements ActionListener, MouseListener, KeyListener
{
    View view;
    Model model;
    Json ob = Json.newObject();
    boolean keyLeft;
    boolean keyRight;
    boolean keyUp;
    boolean keyDown;
    
	Controller(Model m)
	{
            model = m;
	}

	public void actionPerformed(ActionEvent e)
	{
	}
        
        void setView(View v)
        {
            view = v;
        }
        
        public void mousePressed(MouseEvent e)
	{
            //Add Tube model
		model.addTube(e.getX() + view.scrollPos, e.getY());
	}

	public void mouseReleased(MouseEvent e) {    }
	public void mouseEntered(MouseEvent e) {    }
	public void mouseExited(MouseEvent e) {    }
	public void mouseClicked(MouseEvent e) {    }
        
        public void keyPressed(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: keyRight = true; break;
			case KeyEvent.VK_LEFT: keyLeft = true; break;
			case KeyEvent.VK_UP: keyUp = true; break;
			case KeyEvent.VK_DOWN: keyDown = true; break;
		}
	}

	public void keyReleased(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: keyRight = false; break;
			case KeyEvent.VK_LEFT: keyLeft = false; break;
			case KeyEvent.VK_UP: keyUp = false; break;
			case KeyEvent.VK_DOWN: keyDown = false; break;
		}
                char c = e.getKeyChar();
                if (c == 's')
                {
                    model.marshal().save("map.json");
                    System.out.println("map.json saved!");
                }
                if (c == 'l')
                {
                    Json j = Json.load("map.json");
                    model.unmarshal(j);
                    System.out.println("map.json loaded!");
                }
	}

	public void keyTyped(KeyEvent e)
	{
	}

	void update(View v)
	{
            view = v;
		if(keyRight) v.scrollPos += 4;
		if(keyLeft) v.scrollPos -= 4;
//		if(keyDown) model.dest_y++;
//		if(keyUp) model.dest_y--;
	}
}

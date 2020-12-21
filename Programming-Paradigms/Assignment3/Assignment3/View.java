/*
/ Name: Riley Nadwodny
/ Date: 9/11/2020
/ Description: Creates the view for the game. Creates a button and a function to
/ remove the button upon click. The view paints the game.
*/

import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.IOException;
import java.io.File;
import javax.swing.JButton;
import java.awt.Color;

class View extends JPanel
{
        BufferedImage tube_image;
        Model model;
        int scrollPos;

	View(Controller c, Model m)
	{
                model = m;
                try
		{
			this.tube_image =
				ImageIO.read(new File("tube.png"));
		} catch(Exception e) {
			e.printStackTrace(System.err);
			System.exit(1);
		}
	}
        
        
        public void paintComponent(Graphics g)
	{
            g.setColor(new Color(128, 255, 255));
            g.fillRect(0, 0, this.getWidth(), this.getHeight());
            for(int i = 0; i < model.tubes.size(); i++)
		{
			Tube t = model.tubes.get(i);
			g.drawImage(tube_image, t.x - scrollPos, t.y, null);
		}
	}
}

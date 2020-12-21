/*
/ Name: Riley Nadwodny
/ Date: 9/21/2020
/ Description: Tube class that contains an (x,y) for where the tube is on the screen.
/ Contains the width and height of tube.png
*/

public class Tube {
    int x, y;
    //width and height of tube.png
    int width = 55;
    int height = 400;

    public Tube(int tube_x, int tube_y) 
    {
        this.x = tube_x;
        this.y = tube_y;
    }
    
    Tube(Json obj)
    {
        x = (int)obj.getLong("tube_x");
        y = (int)obj.getLong("tube_y");
    }
    
    boolean tubeClicked(int mouse_x, int mouse_y) 
    {
        if (mouse_x < this.x)
           return false;
        if (mouse_x > this.x + width)
            return false;
        if (mouse_y < this.y)
            return false;
        if (mouse_y > this.y + height)
            return false;
        return true;
    }
    
    Json marshal()
    {
        Json obj = Json.newObject();
        obj.add("tube_x", x);
        obj.add("tube_y", y);
        return obj;
    }
}

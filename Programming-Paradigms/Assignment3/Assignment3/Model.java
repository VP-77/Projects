/*
/ Name: Riley Nadwodny
/ Date: 9/11/2020
/ Description: Model class that creates the turtle model, current coordinates for
/ the turtle as well as destination coordinates. Updates the location of
/ the turtle model and sets the destination on click.
*/

import java.util.ArrayList;
import java.util.Comparator;

class Model
{
        int x, y;
	int dest_x;
	int dest_y;
        ArrayList<Tube> tubes;

	Model()
	{
            tubes = new ArrayList<Tube>();
	}

	public void update()
	{
	}
          
        public void addTube(int mouse_x, int mouse_y)
        {
            Tube t = null;
            for(int i = 0; i < tubes.size(); i++) 
            {
                if (tubes.get(i).tubeClicked(mouse_x, mouse_y) == true)
                {
                    t = tubes.get(i);
                    tubes.remove(t);
                    return;
                }
            }
            if (t == null)
            {
                tubes.add(new Tube(mouse_x, mouse_y));
            }
        }
        
        Json marshal()
        {
            Json obj = Json.newObject();
            Json tmpList = Json.newList();
            obj.add("tubes", tmpList);
            for (int i = 0; i < tubes.size(); i++)
                tmpList.add(tubes.get(i).marshal());
            
            return obj;
        }
        
        void unmarshal(Json obj)
        {
            tubes = new ArrayList<Tube>();
            Json tmpList = obj.get("tubes");
            for(int i = 0; i < tmpList.size(); i++)
                tubes.add(new Tube(tmpList.get(i)));
        }
        

class TubeComparator implements Comparator<Tube>
{
	public int compare(Tube a, Tube b)
	{
		if(a.x < b.x)
			return -1;
		else if(a.x > b.x)
			return 1;
		else
			return 0;
	}

	public boolean equals(Object obj)
	{
		return false;
	}
}
}
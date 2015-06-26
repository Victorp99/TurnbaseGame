//Class that makes our person and the monsters. Derive from this class to make a monster class
//it should have coordinates x and y or player, direction, player attacks, health 

public class Character {
	
	public Character() {
	
		health = 100;
		direction = "East";
		x = 0;
		y = 0;
	}
	private int x;
	private int y;
	private int health;
	private string direction;
	
	
	public void setX(int xCoor)
    {
    	x =xCoor;
    }
    public void setY(int yCoor)
    {
    	y = yCoor;
    }
	
	public int getX()
    {
    	return x;
    }
    public int getY()
    {
    	return y;
    }
	
	public void setDirection(string direct)
	{
		direction = direct;
	}
	public string getDirection()
	{
		return direction;
	}
	
	public int getHealth()
	{
		return health;
	}
	public void setHealth(int hp)
	{
		health = hp;
	}
	
	// overloaded prefix ++ operator
      Character operator++ ()  
      {
         health = health + 20;
         return Character(health);
      }
	
	
	
}

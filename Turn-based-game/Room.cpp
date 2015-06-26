//sees if there is a monster in the room, or health, or 
public class Room {
	private boolean monsterHere;
	private boolean foodHealth;
	//private boolean 
	public Room() {
		monsterHere = false;
		foodHealth = false;
	}
	public boolean setMonster()
	{
		monsterHere = true;
	}
	public boolean setFood()
	{
		foodHealth = true;
	}
	
	public void getMonster()
	{
		return monsterHere;
	}
	public void getFood()
	{
		return foodHealth;
	}
	
}
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//#define inFile "loadMap.txt"

using namespace std;
//Class that makes our person and the monsters. Derive from this class to make a monster class
//it should have coordinates x and y or player, direction, player attacks, health 

class Character {
private:
	 int x;
	 int y;
	 int health;
	 string direction;
public: 
	
	 Character() {
	
		//health = 100;
		direction = "East";
		x = 0;
		y = 0;
	}
	 
	
	
	void setX(int xCoor)
    {
    	x =xCoor;
    }
    void setY(int yCoor)
    {
    	y = yCoor;
    }
	
	int getX()
    {
    	return x;
    }
    int getY()
    {
    	return y;
    }
	
	void setDirection(string direct)
	{
		direction = direct;
	}
	string getDirection()
	{
		return direction;
	}
	
	int getHealth()
	{
		return health;
	}
	void setHealth(int hp)
	{
		health = hp;
	}
	
	// overloaded prefix ++ operator
      Character operator++()  
      {
         health = health + 20;
         setHealth(health);
      }
	
	
	
};




//derived Monster class
class Monster: public Character {
public:
// used when he dies
	string screech()
	{
		return "eeeeeeeeeeeeee\n The monster screams\n.";
	}
	
	
};

//sees if there is a monster in the room, or health, or 
class Room {
	private:
	bool monsterHere;
	bool foodHealth;
	//private boolean 
	public:
	 Room() {
		monsterHere = false;
		foodHealth = false;
	}
	 bool setMonster()
	{
		monsterHere = true;
	}
	bool setFood()
	{
		foodHealth = true;
	}
	
	bool getMonster()
	{
		return monsterHere;
	}
	bool getFood()
	{
		return foodHealth;
	}
	
};

void BattleScene(Character player, Monster monster, int totalScore);
void Currentpostion(int tempx, int tempy, string direction);
void printboard(char array[][10]);
string getMove();
int checksize();
//remember to add prototypes of functions and overloading operator - 
int main()
{
	int totalScore = 0; // score over whole game
	string move= "";
	char Board[6][10] = {{'X','X','X','X','X','X','X','X','X','X'},
						{'X','X','X','X','X','X','X','X','X','X'},
						{'X','X','X','X','X','X','X','X','X','X'},
						{'X','X','X','X','X','X','X','X','X','X'},
						{'X','X','X','X','X','X','X','X','X','X'},
						{'X','X','X','X','X','X','X','X','X','X'}};
	Room map[6][10];
	cout << "You saw a cave and were curious so you decided to check inside. Once you enter in, the entrance closes with bolders and you are trapped. It is dark.\n";
	
	//ifstream ins;
	//const int N = checksize();
	printboard(Board);
	char test = ',';
	int i;
	int j;
		for ( i = 0; i < 6; i++)    //This loops on the rows.
		{
			for (j = 0; j < 10; j++) //This loops on the columns
			{
				int v1 = rand() % 100; 
				//cout << Board[i][j] << " ";
				if (v1 < 20)
				{

					map[i][j].setFood();

				}
				else if(v1 < 60)
				{
				
					map[i][j].setMonster();
					
				}
			
			}
		}
	
	Character player; // makes character
	player.setHealth(100);

	//turn right moves
	 while(player.getHealth() > 0)
	 {
		Currentpostion(player.getX(), player.getY(), player.getDirection());
		move = getMove();
		
		if(map[player.getX()][player.getY()].getFood()== true)
       	{
			if(player.getHealth() >= 81)
			{
				player.setHealth(100);
				cout << "You happened to stumble across food! You gained 20 hp. \n";
			}
			else
			{
				cout << "You happened to stumble across food! You gained 20 hp. \n";
				//++ = health  + 20 health
				++player;
				//player.setHealth(player.getHealth() + 20);
			}
       	}
		if(map[player.getX()][player.getY()].getMonster()== true)
       	{	
			//creater monster here, set health of monster to be 30
			Monster monster;
			monster.setHealth(30);
			//call battle scene
			BattleScene(player, monster, totalScore);
			
       	}
	 
        if(move == "R" && player.getDirection() == "East")
        {
        	player.setDirection("South");
        }
        else if(move =="R" && player.getDirection() == "North")
        {
        	player.setDirection("East");
        }
       else if(move == "R" && player.getDirection() == "West")
        {
        	player.setDirection("North");
        }
       else if(move == "R" && player.getDirection() == "South")
        {
        	player.setDirection("West");
        }
       	//turn left moves
       else	if(move == "L" && player.getDirection() == "East")
        {
        	player.setDirection("North");
        }
       else if(move == "L" && player.getDirection() == "North")
        {
        	player.setDirection("West");
        }
       else if(move == "L" && player.getDirection() == "West")
        {
        	player.setDirection("South");
        }
      else  if(move == "L" && player.getDirection() == "South")
        {
        	player.setDirection("East");
        }
        //moving forward
        else if(move == "F" && player.getDirection() == "East")
        {
        	if(player.getY() == (i-1))
        		cout << "BUMP!!! You hit a wall!\n";
        	else
        	{
        		
        		int temp = player.getY();
        		player.setY(++temp);
        		
        		
        	}
        }
        else if(move == "F" && player.getDirection() == "West")
        {
        	if(player.getY() == 0)
        		cout << "BUMP!!! You hit a wall!\n";
        	else
        	{
        		
        		
        		int temp = player.getY();
        		player.setY(--temp);
        		

        	}
        }
        else if(move == "F" && player.getDirection() == "North")
        {
        	int sup = 0;
        	if(player.getX()== sup)
        		cout << "BUMP!!! You hit a wall!\n";
        	else if(player.getX() !=sup)
        	{
        	
        	
        		
        		int temp = player.getX();
        		player.setX(--temp);
        		
        		
        	}
        }
        else if(move == "F" && player.getDirection() == "South")
        {
        	cout << j << "\n";
        	int sup = j-1;
        	if(player.getX() == sup)
        		cout << "BUMP!!! You hit a wall!\n";
        	else if(player.getX() != sup)
        	{
        		
        		
        		int temp = player.getX();
        		player.setX(++temp);
        		
        		
        	}
        }
		//starts other move
		Currentpostion(player.getX(), player.getY(), player.getDirection());
		move = getMove();
	}
	cout << "You died. Your score was " << totalScore << "\n";
	return 0;
}


///////////////////////////set prototypes/////////////////////////////////
void printboard(char array[][10])
{
cout << "\n";
for (int i = 0; i <6; i++)
{

for (int j = 0; j <10; j++)
{
if (array[i][j] != 0)
{
cout << array[i][j] << " ";
}
else
cout << "  ";
}
cout << "\n";
}
cout << "\n";

}

// second character is going to be replaced with inherited Character class for monster, check to see if monster is in room then, if he is, 
//create monster and then pass them into the battle scene

void BattleScene(Character player, Monster monster, int totalScore)
{
	cout << "A monster jumps out of the darkness toward you!\n";
	//battle loop
	int attack; // your attack: 1 = punch, 2 = elbow, 3 = kick, 4 = tackle

	while(player.getHealth() > 0 && monster.getHealth() > 0)
	{	
	cout << "What are you going to do now?\n";
	cout << "Enter in a number to pick your move:\n"; 
	cout << "-----------------------\n";
	cout << "1 = punch 2 = elbow\n";
	cout <<	"3 = kick 4 = tackle \n";
	cout << "-----------------------\n";
	cin >> attack;
		if(attack == 1)
		{
			int hit = rand() % 100;
			if(hit > 10)
			{
				monster.setHealth(monster.getHealth() - 5);
				cout << "You punched the monster!\n";
				cout << "Your Health: " <<player.getHealth() << "   Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "You missed.\n";
			}
			
		}
		else if(attack == 2)
		{
			int hit = rand() % 100;
			if(hit > 30)
			{
				monster.setHealth(monster.getHealth() - 10);
				cout << "You elbowed the monster!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "You missed.\n";
			}
			
		}
		else if(attack == 3)
		{
			int hit = rand() % 100;
			if(hit > 50)
			{
				monster.setHealth(monster.getHealth() - 20);
				cout << "You kicked the monster!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "You missed.\n";
			}
			
		}
		else if(attack == 4)
		{
			int hit = rand() % 100;
			if(hit > 85)
			{
				monster.setHealth(monster.getHealth() - 20);
				cout << "You tackled the monster to the floor!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "You missed.\n";
			}
			
		}
		//monster attacks now
		int mHit = (rand() % 4) + 1; // 1 = scratch 2 = bite 3 = kick 4 = tackle 
		cout << " The monster retaliated!!\n";
		if(mHit == 1)
		{
			int hit = rand() % 100;
			if(hit > 10)
			{
				player.setHealth(player.getHealth() - 5);
				cout << "The monster swung and scratched you!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "The monster went for a scratch but missed.\n";
			}
			
		}
		else if(mHit == 2)
		{
			int hit = rand() % 100;
			if(hit > 30)
			{
				player.setHealth(player.getHealth() - 10);
				cout << "The monster came in close and bite you!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "The monster went in for a bite but missed.\n";
			}
			
		}
		else if(mHit == 3)
		{
			int hit = rand() % 100;
			if(hit > 50)
			{
				player.setHealth(player.getHealth() - 20);
				cout << "The monster lifted its leg and kicked you!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "The monster attempted to kick you but missed.\n";
			}
			
		}
		else if(mHit == 4)
		{
			int hit = rand() % 100;
			if(hit > 80)
			{
				player.setHealth(player.getHealth() - 30);
				cout << "The monster ran at you and tackled you to the floor!\n";
				cout << "Your Health: " <<player.getHealth() << "  Monster Health: " << monster.getHealth() << "\n";
			}
			else
			{
				cout << "The monster ran at you to tackle you but you moves out of the way.\n";
			}
		/*
			cout << "What are you going to do now?\n";
			cout << "Enter in a number to pick your move:\n 1 = punch 2 = elbow\n 3 = kick 4 = tackle \n";
			cin >> attack;
	*/
		}
		
		
		if(monster.getHealth() <=0)
		{
			monster.screech();
			totalScore += 10;
		}
		if(player.getHealth() <= 0)
		{
			cout << "You have been defeated by the monster!\n";
		}
		
	}
	
}
void Currentpostion(int tempx, int tempy, string direction)
{

	cout << "You are in room [" << tempx << "," << tempy << "] of the cave. Facing " << direction;
	cout << "\n";
}
string getMove()
{
	string command = "";
	cout << "What would you like to do? Please enter command [R,L,F,S]:\n>";
	cin >> command;
	return command;
}

package Aliens;

public class Alien {
	private String alienName;
	private int hp;
	
	public Alien() {
		alienName = "N/A";
		hp = 0;
	}
	public Alien(String name,int hp) {
		alienName = name;
		this.hp = hp;
	}
	
	public void setName(String name) {
		this.alienName = name;
	}
	public String getName() {
		return this.alienName;
	}
	
	public void setHP(int hp) {
		this.hp = hp;
	}
	public int getHP() {
		return hp;
	}
	
	public int getDamage() {
		return 0;
	}
	
	public String toString() {
		return "Name: " + this.alienName + " Health: " + this.hp; 
	}
}

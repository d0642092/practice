package Aliens;

public class Ogre extends Alien {
	public Ogre() {
		super();
	}
	public Ogre(String name,int hp) {
		super(name,hp);
	}
	public int getDamage() {
		return 6;
	}
}

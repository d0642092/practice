package Aliens;

public class Snake extends Alien {
	public Snake() {
		super();
	}
	public Snake(String name,int hp) {
		super(name,hp);
	}
	public int getDamage() {
		return 10;
	}
}

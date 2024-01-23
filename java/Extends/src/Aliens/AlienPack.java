package Aliens;
import Aliens.Alien;
public class AlienPack{
	private Alien[] aliens ;
	
	public AlienPack() {
		return;
	}
	public AlienPack (int num) {
		aliens = new Alien[num];
	}
	public void addAlien (Alien kind,int num) {
		aliens[num] = kind; 
	}
	public Alien[] getAlien() {
		return aliens;
	}

	public int calculateDamage() {
		int sum=0;
		for(int i=0; i<aliens.length; i++) {
			if(aliens[i] == null) {
				continue;
			}
			else {
				sum += aliens[i].getDamage();
			}
		}
		return sum;
	}
}

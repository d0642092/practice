import Aliens.Alien;
import Aliens.AlienPack;
import Aliens.Marshmallow;
import Aliens.Ogre;
import Aliens.Snake;

public class D0642092_homework3_Q3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Marshmallow alien1 = new Marshmallow("MarshmallowMonster",10);
		Ogre alien2 = new Ogre("OgreMonster",50);
		Snake alien3 = new Snake("SnakeMonster",90);
		AlienPack store = new AlienPack(3);
		Alien[] aliens = new Alien[3];

		store.addAlien(alien1, 0);
		store.addAlien(alien2, 1);
		store.addAlien(alien3, 2);

		aliens = store.getAlien();
		System.out.println("The aliens in this park are:");
		for(int i=0;i<aliens.length;i++) {
			if(aliens[i] == null) {
				continue;
			}
			else {
				System.out.printf("Name:%-20s Health:%3d \t Damage: %d\n",aliens[i].getName(),aliens[i].getHP(),aliens[i].getDamage());
			}
		}
		System.out.println();
		System.out.println("The total damage from this AlienPack is: " + store.calculateDamage());
	}

}

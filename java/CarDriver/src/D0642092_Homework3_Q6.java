import Driver.Truck;
import Driver.Person;

public class D0642092_Homework3_Q6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person owner1 = new Person("Jack");
		Person owner2 = new Person(owner1);
		Person owner3 = new Person("John");
		Truck car1 = new Truck(owner1,"Audi",5,20.2,4);
		Truck car2 = new Truck(owner2,"Audi",5,20.2,4);
		Truck car3 = new Truck(owner3,"Audi",5,16.7,6);
		
		System.out.println(car1);
		System.out.println(car2);
		System.out.println(car3);
		
		System.out.println();
		System.out.println("IS Truck[0] equals to Truck[1]?" + car1.equals(car2));
		System.out.println("IS Truck[1] equals to Truck[2]?" + car2.equals(car3));
	}

}

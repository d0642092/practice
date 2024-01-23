package Driver;
import Driver.Person;
public class Vehicle {
	private String manufacturer;
	private int cylinders;
	protected Person owner;
	
	public Vehicle() {
		this.manufacturer = "N/A";
		this.cylinders =0;
		this.owner = new Person();
	}
	public Vehicle(Person own,String manufacture,int cylinders) {
		this.manufacturer = manufacture;
		this.cylinders = cylinders;
		this.owner = new Person(own);
	}
	
	public void setManufacture(String name) {
		this.manufacturer = name;
	}
	public void setCylinders(int cylinders) {
		this.cylinders = cylinders;
	}
	public String getManufacture() {
		return this.manufacturer;
	}
	public int getCylinders() {
		return this.cylinders;
	}
	
	public String toString() {
		return "PersonName: " + this.owner.getName() + "\tManufacture: " + this.manufacturer + "\tCylinders: " + this.cylinders;
	}
	public boolean equals(Object other) {
		if(other == null) {
			return false;
		}
		else if(this.getClass() != other.getClass()){
			return false;
		}
		else {
			Vehicle others = (Vehicle)other;
			return this.owner.getName().equals(others.owner.getName())
							&& this.manufacturer.equals(others.manufacturer)
							&& this.cylinders == others.cylinders;
		}
		
	}
}

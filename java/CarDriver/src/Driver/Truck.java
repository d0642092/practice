package Driver;

public class Truck extends Vehicle {
	private double load;
	private int towing;
	
	public Truck() {
		super();
		load = 0;
		towing = 0;
	}
	public Truck(Person own,String manufacturer,int cylinders,double load,int towing) {
		super(own,manufacturer,cylinders);
		this.load = load;
		this.towing = towing;
	}
	
	public void setManufacture(double load) {
		this.load = load;
	}
	public void setTowing(int towing) {
		this.towing = towing;
	}
	public double getLoad() {
		return this.load;
	}
	public int getTowing() {
		return this.towing;
	}
	
	public String toString() {
		return super.toString() + "\tLoad: " + this.load + "\tTowing: " + this.towing;
	}
	public boolean equals(Object other) {
		if(other == null) {
			return false;
		}
		else if(this.getClass() != other.getClass()){
			return false;
		}
		else {
			Truck others = (Truck)other;
			return super.equals(others) && this.load == others.load && this.towing == others.towing;
		}
		
	}
}

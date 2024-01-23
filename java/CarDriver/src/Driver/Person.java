package Driver;

public class Person {
	private String owner;
	
	public Person() {
		this.owner = "N/A";
	}
	public Person(String name) {
		this.owner = name;
	}
	public Person(Person other) {
		this.owner = other.owner;
	}
	
	public void setName(String name) {
		this.owner = name;
	}
	public String getName() {
		return this.owner;
	}
	
	public String toString() {
		return "PersonName: " + this.owner;
	}
	public boolean equals(Object other) {
		if(other == null) {
			return false;
		}
		else if(this.getClass() != other.getClass()){
			return false;
		}
		else {
			Person others = (Person)other;
			return this.owner.equals(others.owner);
		}
		
	}
}

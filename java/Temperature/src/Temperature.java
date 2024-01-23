import java.text.DecimalFormat;
public class Temperature {

	private float degree;
	private char scale;
	private DecimalFormat degreeFormat =new DecimalFormat("0.0");

	/*constructor*/
	public Temperature() {
		this.degree = 0;
		this.scale = 'C';
	}
	public Temperature(float degree) {
		this.degree = degree;
		this.scale = 'C';
	}
	public Temperature(char scale) {
		this.scale = scale;
		this.degree = 0;
	}
	public Temperature(float degree, char scale) {
		this.degree = degree;
		this.scale = scale;
	}
	
	/*get*/
	public String getDegreeC() {
		if (this.scale == 'F') {
			return degreeFormat.format((5*(this.degree-32)/9));
		}
		else {
			return "false";
		}
		
	}
	public String getDegreeF() {
		if (this.scale == 'C') {
			return degreeFormat.format((9*(this.degree/5)+32));
		}
		else {
			return "false";
		}
		
	}
	private float getDegree(char otherScale) {
		if (this.scale == otherScale) {
			return (float)this.degree;
		}
		else if(otherScale == 'C') {
			return (float)(5*(this.degree-32)/9);
		}
		else {
			return (float)(9*(this.degree/5)+32);
		}
	}
	/*set*/
	public void setDegree(float degree) {
		this.degree = degree;
	}
	public void setScale(char scale) {
		this.scale = scale;
	}
	public void setAll(float degree,char scale) {
		this.degree = degree;
		this.scale = scale;
	}
	
	/*equals*/
	public boolean equals(Temperature others) {
		return this.degree == others.getDegree(this.scale);
	}
	public boolean moreThen(Temperature others) {
		return this.degree >= others.getDegree(this.scale);
	}
	public boolean lessThen(Temperature others) {
		return this.degree <= others.getDegree(this.scale);
	}

	public String toString() {
		if (this.scale == 'C') {
			return this.degree +" degrees C";
		}
		else {
			return this.degree +" degrees F";
		}
	}
}


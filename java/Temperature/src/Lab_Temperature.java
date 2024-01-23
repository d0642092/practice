
public class Lab_Temperature {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Temperature t_One = new Temperature((float)-40.0,'C');
		Temperature t_Two = new Temperature((float)-40.0,'F');
		Temperature t_Three = new Temperature((float)100.0,'C');
		Temperature t_Four = new Temperature((float)212.0, 'F');
		Temperature t_Five = new Temperature((float)-30.0,'C');
		Temperature t_Six = new Temperature((float)100.0,'C');
		Temperature t_Seven = new Temperature((float)50.0,'C');
		Temperature t_Eight = new Temperature((float)100.0, 'F');
		/*t_One.setAll((float)100.0, 'C');
		t_Two.setScale('F');
		t_Three.setDegree((float)-40.0);*/
		
		/*System.out.println("constructor: ");
		System.out.println();
		System.out.println(t_One);
		System.out.println(t_Two);
		System.out.println(t_Three);
		System.out.println(t_Four);
		System.out.println();*/
		
		
		
		/*get Degree C/F*/
		/*System.out.println("Get Degree: ");
		System.out.println();
		//one
		if(t_One.getDegreeC() != "false") {
			System.out.println("From: " + t_One);
			System.out.println("To " + t_One.getDegreeC() + " degree C");
		}
		else {
			System.out.println("Not from C to C");
		}
		//Two
		if(t_Two.getDegreeF() != "false") {
			System.out.println("From: " + t_Two);
			System.out.println("To " + t_Two.getDegreeF() + " degree F");
		}
		else {
			System.out.println("Not from F to F");
		}
		//three
		if(t_Three.getDegreeF() != "false") {
			System.out.println("From: " + t_Three);
			System.out.println("To " + t_Three.getDegreeF() + " degree F");
		}
		else {
			System.out.println("Not from F to F");
		}
		//four
		if(t_Four.getDegreeC() != "false") {
			System.out.println("From: " + t_Four);
			System.out.println("To " + t_Four.getDegreeC()+ " degree C");
		}
		else {
			System.out.println("Not from C to C");
		}
		
		System.out.println();
		*/
		/*equal more less*/
		if(t_One.equals(t_Two)) {
			System.out.println(t_One+" = "+ t_Two);
		}
		else {
			System.out.println(t_One+" != "+ t_Two);
		}
		if(t_Three.equals(t_Four)) {
			System.out.println(t_Three+" = "+ t_Four);
		}
		else {
			System.out.println(t_Three+" = "+ t_Four);
		}
		
		
		if(t_Five.lessThen(t_Six)) {
			System.out.println(t_Five+" < "+ t_Six);
		}
		else {
			System.out.println(t_Five+" > "+ t_Six);
		}
		if(t_Seven.moreThen(t_Eight)) {
			System.out.println(t_Seven+" > "+ t_Eight);
		}
		else {
			System.out.println(t_Seven+" < "+ t_Eight);
		}
	}

}

import java.util.Scanner;
public class StudentScore {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner keyboard = new Scanner(System.in);
		StudentRecord student = new StudentRecord();
		int i=0;
		boolean check = false;
		
		/*Quiz Score*/
		for(i=0;i<3;i++) {
			System.out.println("Input quizzes " + (i+1));
			do {
				check = student.setQuizzes(keyboard.nextInt(), i);
				if(check == false) {
					System.out.println("Input again 0~10 for quizzes " + (i+1));
				}
			}while(!check);
			check = false;
		}
		
		/*MidTerm Score*/
		System.out.println("Input midScore:");
		do {
			check = student.setMidTerm(keyboard.nextInt());
			if(check == false) {
				System.out.println("Input again 0~100 for midScore");
			}
		}while(!check);
		check =false;
		
		/*FinalTerm Score*/
		System.out.println("Input finalScore:");
		do {
			check = student.setFinalTerm(keyboard.nextInt());
			if(check == false) {
				System.out.println("Input again 0~100 for finalScore");
			}
		}while(!check);
		
		student.totalScore();
		
		System.out.println(student);
		keyboard.close();
	}

}

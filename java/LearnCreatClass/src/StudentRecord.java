
public class StudentRecord {
	 private int[] quizzes = new int[3];
	 private int midTerm;
	 private int finalTerm;
	 private double numericScore=0.0;
	 private char finalLatter='F';
	 
	 public StudentRecord (){
		 this.quizzes[0] = 0;
		 this.quizzes[1] = 0;
		 this.quizzes[2] = 0;
		 this.midTerm = 0;
		 this.finalTerm = 0;
	 }
	
	 /*set*/
	 public boolean setQuizzes(int score,int times) {
		 if(score>=0 && score <=10) {
			 this.quizzes[times] = score;
			 return true;
		 }
		 else {
			 return false;
		 }
	 }
	
	 public boolean setMidTerm(int score) {
		 if(score>=0 && score <=100) {
			 this.midTerm = score;
			 return true;
		 }
		 else {
			 return false;
		 }
	 }
 
	 public boolean setFinalTerm(int score) {
		 if(score>=0 && score <=100) {
			 this.finalTerm = score;
			 return true;
		 }
		 else {
			 return false;
		 }
		 
	 }
	 
	 /*get*/
	 public int getQuizzes(int times) {
		 return this.quizzes[times];
	 }
	 
	 public int getMidTerm() {
		 return this.midTerm;
	 }
	 
	 public int getFinalTerm() {
		 return this.finalTerm;
	 }
	 
	 public double getNumericScore() {
		 return this.numericScore;
	 }
	 
	 public char getFinalLatter() {
		 return this.finalLatter;
	 }
	
	 /*­pºâ*/
	 public void totalScore(){
		 int i=0,sum=0;
		 for(i=0;i<3;i++) {
			 sum += this.quizzes[i];
		 }
		 this.numericScore = (sum*25)/30+this.midTerm*0.35+this.finalTerm*0.4;
		 setFinalLatter(this.numericScore);
	 }
	 
	 /*equals toString*/
	 private void setFinalLatter(double numericScore) {
		 if(this.numericScore>=90) {
			 this.finalLatter ='A';
		 }
		 else if(this.numericScore>=80 && this.numericScore<90) {
			 this.finalLatter = 'B';
		 }
		 else if(this.numericScore>=70 && this.numericScore<80) {
			 this.finalLatter = 'C';
		 }
		 else if(this.numericScore>=60 && this.numericScore<70) {
			 this.finalLatter = 'D';
		 }
		 else {
			 this.finalLatter = 'F';
		 }
	 }
	 
	 public boolean equals(StudentRecord others) {
		 return this.numericScore == others.numericScore;
	 }
	 
	 public String toString() {
		 return "Quiz 1 : " + this.quizzes[0] +" Quiz 2 : " + this.quizzes[1] +
				 " Quiz 3 : " + this.quizzes[2] +"\n"+ "midScore : " + this.midTerm +
				 " finalScore : " + this.finalTerm + "\n" +"numericScore : " + this.numericScore +
				 " finalLatter : " + this.finalLatter;
	 }
}

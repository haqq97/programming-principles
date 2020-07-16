#include <iostream>
#include <cmath>

using namespace std;

//function prototypes
double examAverageCalculator();
double zybookAverageCalculator();
int TotalClassParticipation();
double homeworkAverageCalculator(int& homeworkMissing);
double labworkAverageCalculator();
double totalExtraCredit();
double numericGradeCalculator(double totalExamScore, double totalZybookScore, 
							 int classParticipation, double totalHomeworkScore, 
							 double totalLabworkScore, double extraPoints);
void letterGradeCalculator(double overallGrade, double totalExamScore, 
							int homeworkMissing);
void printResult(double totalExamScore, double totalZybookScore, 
				 int classParticipation, double totalHomeworkScore, 
				 double totalLabworkScore, double extraPoints, double overallGrade);

int main() 
{	double totalExamScore = 0;
	double totalZybookScore = 0;
	int classParticipation = 0;
	double totalHomeworkScore = 0;
	double totalLabworkScore = 0;
	double extraPoints = 0;
	double overallGrade = 0;
	int homeworkMissing = 0;

	char syllabusQuiz;
	cout << "did you get 100% on the syllabus quiz [y/n]?";
	cin >> syllabusQuiz;
	
	if (syllabusQuiz == 'n') {
		cout << " letter grade:  F" << endl;
		return 0;
	}
	totalExamScore = examAverageCalculator();
	totalZybookScore = zybookAverageCalculator();
	classParticipation = TotalClassParticipation();
	totalHomeworkScore =  homeworkAverageCalculator(homeworkMissing);
	totalLabworkScore = labworkAverageCalculator();
	extraPoints = totalExtraCredit();
	overallGrade =  numericGradeCalculator(totalExamScore, totalZybookScore, 
			classParticipation, totalHomeworkScore, totalLabworkScore, extraPoints);
	printResult(totalExamScore, totalZybookScore,  classParticipation,  
				totalHomeworkScore,  totalLabworkScore,  extraPoints,  overallGrade);
	letterGradeCalculator(overallGrade, totalExamScore, homeworkMissing);

	return 0;
}

//calculates the exam average by taking in exam 1, exam 2 and final exam score (if taken)
double examAverageCalculator() {	
	double examOne = 0;
	double examTwo = 0;
	double finalExam = 0;
	double examTotal = 0;

	cout << " exam 1 grade [0-100]: ";
	cin >> examOne;

	cout << "exam 2 grade [0-100]: ";
	cin >> examTwo;

	cout << "final exam grade [0-100, -1 to skip]: " ;
	cin >> finalExam;

	if (finalExam == -1) {
		//exam average is 40% of exam 1 and 60% exam 2
		examTotal = examOne*(40.0/100) + examTwo*(60.0/100); 
	} else {
		double averageWithFinal = (examOne + examTwo + finalExam)/3; 

		//if the final exam score is higher than the average of exam1 and exam2
		if (finalExam >= averageWithFinal){ 
			examTotal =  finalExam;
		}else{
			examTotal = averageWithFinal;
		}	
	}
	return examTotal; 
}



//calculates the zybook average by taking in zybook particpation and challenge scores
double zybookAverageCalculator(){
	int zybookParticipation = 0;
	int zybookChallenge = 0;
	double zybookTotal = 0;

	cout << "zybook participation (%): " ; 
	cin >> zybookParticipation;

	//score limited to 100 if higher or equal to 85
	if (zybookParticipation > 85) 
		zybookParticipation = 100;

	if (zybookChallenge > 85) 
		zybookChallenge = 100;

	//add 15 if score is less than 85
	if (zybookParticipation > 0 && zybookParticipation < 85) 
		zybookParticipation += 15;

	cout << "zybook challenge (%): "; 
	cin >> zybookChallenge;
	if (zybookChallenge > 0 && zybookChallenge < 85)
		zybookChallenge+=15;

	//zybook 7% = 4% participation + 3% challenge
	zybookTotal = ((4.0/7)*zybookParticipation) + ((3.0/7)*zybookChallenge);  
	if (zybookTotal > 100)
		zybookTotal = 100;

	return zybookTotal;
}


//returns the final class participation score 
int TotalClassParticipation(){	
	int participationScore = 0;
	cout << "class participation (%): ";
	cin >> participationScore;

	if (participationScore > 0 && participationScore < 85) 
		participationScore += 15; 

	if (participationScore >= 85) //limit score to 100 
		participationScore = 100;

	return participationScore;

}


//calculates the homework average by taking in all the homework scores 
double homeworkAverageCalculator(int& homeworkMissing){
	double sum = 0;
	int i = 0;
	double homeworkAverage = 0;
	double homeworkScore = 0;
	int homeworkCounter = 0;
	homeworkMissing = 0;

	while (homeworkScore!= - 1){ //end storing homework values if user inputs -1
		cout << "homework " << i + 1 << " [0-100, -1 to end]: ";
		cin >> homeworkScore;

		if (homeworkScore == 0){
			homeworkMissing++;} //counts number of totalHomeworkScore with score 0
			++i;
			++homeworkCounter; //counts number of totalHomeworkScore
			sum = sum + homeworkScore; //adds all totalHomeworkScore 
	}
	//subtract 1 for the last while loop execution
	homeworkCounter+= -1; 

	//if no totalHomeworkScore are entered
	if (homeworkCounter <= 0) 
			homeworkAverage = 0;
	else
	//add 1 to sum for the -1 added to homework score on last execution
	homeworkAverage = (sum+1)/(homeworkCounter); 

	return homeworkAverage;
}


//calculates the lab average by taking in lab scores and adds 15% if final average is less than 85%
double labworkAverageCalculator(){	
	double sum = 0;
	int i = 0;
	double labworkScore = 0;
	int labworkCounter = 0;
	double labworkAverage = 0;
	while (labworkScore != - 1) //end storing labwork values if user inputs -1
	{
		cout << "labwork " << i + 1 << " [0-100, -1 to end]: ";
		cin >> labworkScore;

		++i;
		++labworkCounter; //counts number of totalLabworkScore
		sum = sum + labworkScore; //adds all labwork scores
	}		
	if (labworkCounter <= 1)
		labworkAverage = 0;
	else{
		labworkAverage = (sum + 1)/(labworkCounter - 1); 
		if (labworkAverage >= 85) //limit labwork average to 100
			labworkAverage = 100;

		else 
			labworkAverage+=15;  //add 15 if labwork average is less than 85
		}
	return labworkAverage;
}


//returns the total extra credit points earned	
double totalExtraCredit(){
	double extra = 0;
	cout << "extra credit points [0-1]: ";
	cin >> extra;
	if (extra == -1) // if no extra credit points were scored
		extra = 0;

	return extra;
}


//calculates the numeric grade by taking in all the components of the syllabus
double numericGradeCalculator(double totalExamScore, double totalZybookScore, int classParticipation,
				    double totalHomeworkScore, double totalLabworkScore, double extraPoints){
	//total grade is 50% totalExamScore, 7% totalZybookScore, 3% class participation, 35% totalHomeworkScore, 5% totalLabworkScore, and extra points(0% / 0.5% / 1%)
	double numericGrade = 0;
	numericGrade = (0.5 * totalExamScore) + (0.07 * totalZybookScore) + (0.03 * classParticipation) +
	 (0.35 * totalHomeworkScore) + (0.05 * totalLabworkScore) + extraPoints;

	return numericGrade;
}


//returns the final letter grade using the numeric grade, total exam score and hws missing
void letterGradeCalculator(double overallGrade, double totalExamScore, int homeworkMissing){
	char letterGrade = ' ';
	if (totalExamScore < 60) //automatic D if exam average is less than 60
		letterGrade = 'D';
	else if (homeworkMissing > 2) //automatic F for more than two hws missing
		letterGrade = 'F';
	else{
		if (overallGrade >= 90)
			letterGrade = 'A';
		else if (overallGrade >= 80 &&  overallGrade < 90)
			letterGrade = 'B';
		else if (overallGrade >= 70 && overallGrade < 80)
			letterGrade = 'C';
		else if (overallGrade >= 60 && overallGrade < 70)
			letterGrade = 'D';
		else
			letterGrade = 'F';
	}
		cout << "letter grade:  " << letterGrade << endl;
}


//prints the result according to the required format
void printResult(double totalExamScore, double totalZybookScore, int classParticipation, double totalHomeworkScore, 
				double totalLabworkScore, double extraPoints, double overallGrade){

	cout << "exams:               " << totalExamScore <<	endl;
	cout << "zybook activities:   " << totalZybookScore << endl;
	cout << "class participation: " << classParticipation << endl;
	cout << "homework:            " << totalHomeworkScore << endl;
	cout << "labwork:             " << totalLabworkScore << endl;
	cout << "extra credit:        " << extraPoints << endl;

	cout << endl;
	cout << "numeric grade: " << overallGrade << endl;
}


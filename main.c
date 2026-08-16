/*
 * main.c
 *
 *  Created on: 14-Aug-2026
 *      Author: Alastair
 *  Practical 36- Student Mark Analyzer
 *
 *  Accepts Marks of 20 students stores them in array and generates a report showing all marks highest lowest average and
 *  pass count and fail count pass marks=40
 */
#include<stdio.h>
#define TOTAL_STUDENTS 20
#define PASS_MARK 40

int main(){
	int marks[TOTAL_STUDENTS]; //array to store marks of all students
	int highest,lowest;
	int passCount=0,failCount=0;
	float total=0,average=0;

	//step1: accept marks of 20 students and store them in array
	for(int i=0;i<TOTAL_STUDENTS;i++){
		printf("enter marks of student %d:",i+1);
		scanf("%d",&marks[i]);
	}
	//step 2:Initialize highest and lowest using the first student marks
	highest=marks[0];
	lowest=marks[0];
	//steo 3: single pass through array to compute all statistics
	for(int i=0;i<TOTAL_STUDENTS;i++){
		//track the highest marks seen so far
		if(marks[i]>highest){
			highest=marks[i];
		}
		//track the lowest marks of students
		if(marks[i]<lowest){
			lowest=marks[i];
		}
		//running total,used later to calculate average
		total+=marks[i];

		//count pas/fail based on the PASS_MARK threshold
		if(marks[i]>=40){
			passCount++;
		}else{
			failCount++;
		}
	}
//STep 4: calculate average marks
	average= total/ TOTAL_STUDENTS;
	//step 5: Display the complete report
	printf("\n--STUDENT RESULT SUMMARY--\n\n");
	printf("All marks Entered:");
	for(int i=0;i<TOTAL_STUDENTS;i++){
		printf("%d",marks[i]);
	}
	printf("\n\n");
	printf("highest marks:%d\n\n",highest);
	printf("Lowest marks:%d\n\n",lowest);
	printf("Average marks:%2f\n\n",average);
	printf("passed student:%d\n\n",passCount);
	printf("Failed student:%d\n\n",failCount);
	printf("-------\n");
	return 0;
}





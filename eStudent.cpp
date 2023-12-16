#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


struct grades{
	int passGrade;
	int sGrade;
};

struct lectures{
	
	std::string name;
	grades Grade; };




struct students{
	
	std::string name;
	
	std::vector<lectures> sLectures;
};

void welcomeScreen(){
	
	std::cout << "+---------------------+" << std::endl;
	std::cout << "  eStudent  " << std::endl;
	std::cout << "+---------------------+\n" << std::endl;
	std::cout << "1. Add Lecture" << std::endl;
	std::cout << "2. Add Student" << std::endl;
	std::cout << "3. See Grades" << std::endl;
	std::cout << "4. Calculate Avarage" << std::endl;
	std::cout << "5. See Highest and Lowest Grade" << std::endl;
	std::cout << "6. Exit\n" << std::endl;

}

void addStudent(students*& stdnt, lectures* list, int& nStudent, int nLecture) {
    students* newArrayStudent = new students[nStudent + 1];

    for (int i = 0; i < nStudent; i++) {
        newArrayStudent[i] = stdnt[i];
    }

    delete[] stdnt;
    stdnt = newArrayStudent;
    std::cout << "Name: ";
    getline(std::cin, stdnt[nStudent].name);
    std::cout << "Lecture: " << std::endl;
    for (int i = 0; i < nLecture; i++) {
        std::cout << i+1 << "-" << list[i].name << std::endl;
        std::cout << "Grade(0-100pt.): ";
        int value;
        std::cin >> value;
        stdnt[nStudent].sLectures.push_back({list[i].name,{list[i].Grade.passGrade,{value}}});
    }
    

    std::cout << "Student added successfully." << std::endl;
    nStudent++;
}

void addLecture(lectures*& ptr, int& nLecture) {
    lectures* newArrayLecture = new lectures[nLecture + 1];

    for (int i = 0; i < nLecture; i++) {
        newArrayLecture[i] = ptr[i];
    }

    delete[] ptr;
    ptr = newArrayLecture;
    std::cout << "Name of Lecture: ";
    getline(std::cin, ptr[nLecture].name);
    std::cout << "Pass Grade of Lecture(0-100pt.): ";
    int value;
    std::cin >> value;
    ptr[nLecture].Grade.passGrade = value;


    std::cout << "Lecture added successfully." << std::endl;
    nLecture++;
}

void seeGrades(students* ptr,int nStudent,int nLecture){


	std::cout << "+---Grades---+" << std::endl;
	
	for(int i = 0; i < nStudent ;i++){
		for(int j = 0; j < nLecture ;j++){
		std::cout << "Student: " << ptr[i].name << " | Lecture: " << ptr[i].sLectures[j].name << "("  << ptr[i].sLectures[j].Grade.passGrade << "pt.)"<< " | Grade: " << ptr[i].sLectures[j].Grade.sGrade << "pt. | ";
		if((ptr[i].sLectures[j].Grade.sGrade) >= (ptr[i].sLectures[j].Grade.passGrade))
			std::cout << "PASSED"<< std::endl;
		else
		    std::cout << "FAILED"<< std::endl;    }  
			std::cout << std::endl; 
	}
	
	
}

void calculateAvarage(students* ptr,lectures* ptr1,int nStudent,int nLectures){
	
	std::cout << "+--Avarage--+" << std::endl;
	double avarage[nStudent-1]; int j;
	for(int i =0; i <nLectures; i++){
		
		avarage[i] = 0;
		
		for(j =0; j <nStudent; j++){
		
		
		avarage[i] += ptr[j].sLectures[i].Grade.sGrade;
		
	}
	
	avarage[i] = avarage[i] / nStudent;
	std::cout << ptr1[i].name << " | " << avarage[i] << "pt." << std::endl;
		
	}
	
	
	
}

void calculateMAX(students* ptr,lectures* ptr1,int nStudent,int nLecture){
	
	std::cout << "+--Max & Min--+" << std::endl;
	int* tempMax = new int[nLecture];
	int* tempMin = new int[nLecture];
	
	for(int i = 0;i < nLecture ; i++){
		
		tempMax[i] = 0;
		tempMin[i] = 100;
		for(int j = 0;j < nStudent ; j++){
		
		if(ptr[j].sLectures[i].Grade.sGrade > tempMax[i])
			tempMax[i] = 	ptr[j].sLectures[i].Grade.sGrade;
		
		if(ptr[j].sLectures[i].Grade.sGrade < tempMin[i])
			tempMin[i] = 	ptr[j].sLectures[i].Grade.sGrade;
	
	}
	
std::cout << ptr1[i].name << " | Max: " << tempMax[i] << " | Min: " << tempMin[i] << std::endl;
		
		
	}
	
	
	
	delete[] tempMax;
	delete[] tempMin;
}


int main(){

	int checker,nStudent = 0,nLecture = 0;
	students* arrayStudent = nullptr;
	lectures* arrayLecture = nullptr;
	std::setprecision(3);
	while(true){
	
		welcomeScreen();
		
	while (true) {
    std::cout << "+--Process(1,2,3,4,5): "; 
    std::cin >> checker;
    std::cin.ignore();
    std::cout << "\n";
    if (checker >= 1 && checker <= 6){  break;  
	}
    else
    std::cout<< "Invalid Input" << std::endl; } 
    
    if(checker == 6)
    break;
    
    switch(checker){
    	
    	case 1:
    		
    		std::cout <<"+------------+" << std::endl;
    	addLecture(arrayLecture,nLecture);
    	    std::cout <<"+------------+\n" << std::endl;
    	    
    	break;
    	
    	
    	case 2:
    		
    	std::cout <<"+------------+" << std::endl;
    	addStudent(arrayStudent,arrayLecture,nStudent,nLecture);
    	std::cout <<"+------------+\n" << std::endl;
    	
    	break;
    	
    	case 3:
    		seeGrades(arrayStudent,nStudent,nLecture);
    		std::cout <<"+------------+\n" << std::endl;
    		break;
    	
    	
    	case 4:
    		calculateAvarage(arrayStudent,arrayLecture,nStudent,nLecture);
    		std::cout <<"+------------+\n" << std::endl;
    		break;
    		
    	case 5:
    		calculateMAX(arrayStudent,arrayLecture,nStudent,nLecture);
    		std::cout <<"+------------+\n" << std::endl;
    	default: 
    	break;
    	
	} 
}



return 0;
}
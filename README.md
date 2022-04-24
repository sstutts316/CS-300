# CS-300 (C++)
# Data Structures and algorithms

# 1. What was the problem you were solving in the projects for this course?
We had to use data structures and algorithms to design code to correctly read a course data file, create a menu that prompts a user for menu options, load data from the file into a data structure, and sort and print out a list of the courses in the Computer Science program in alphanumeric order, print course information.

# 2. How did you approach the problem? Consider why data structures are important to understand.
Reading the problem carefully and brainstorming ideas to reach the expected output. By learning data structures, you will be able to organize, manage, and store data efficiently.  

# 3. How did you overcome any roadblocks you encountered while going through the activities or project?
A great rule of thumb is to always test your code as you write, because it is easier to pin point problem areas before your code gets to extensive. By doing this, you will be able to overcome potential roadblocks.

# 4. How has your work on this project expanded your approach to designing software and developing programs?
We have a better understanding of seeing the end product before we start to code. By using algorithms, we can map out and manipulate your data to behave the way you want and produce a great fully functional program.

# 5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Redundant code is your enemy, using functions make your code more readable and will help you to write code that you might be able to reuse on another project. By writing reusable code, you can maintain and adapt your code to fit almost any project.


**ABC_CourseInfo Coded Solution**

#include <iostream>

#include <fstream>

#include <vector>

#include <string>

using namespace std;

// Definition of structure course

struct Course {

    string courseNumber;

    string name;

    vector<string> prerequisites;

};

// Function to split string to list of strings on the basis of given delimiter

vector<string> tokenize(string s, string del = " ") {

    vector<string> stringArray;

    int start = 0;

    int end = s.find(del);

    while (end != -1) {

        stringArray.push_back(s.substr(start, end - start));

        start = end + del.size();

        end = s.find(del, start);

    }

    stringArray.push_back(s.substr(start, end - start));

    return stringArray;

}

// Function to load file and store the details into list of courses

vector<Course> LoadDataStructure() {

    // Creating an object of iftsream class to open file

    ifstream fin("ABCU_Advising_Program_Input.txt", ios::in);

    if (!fin.is_open()) {
        cout << "File not found" << endl;
        exit(1);
    }


    vector<Course> courses;

    string line;

    // Infinite loop

    while (getline(fin, line)) {


        //if end of file is reached then break the loop

        if (line == "-1")

            break;

        Course course;

        // getting tokenized information which is separated by commas

        vector<string> tokenizedInformation = tokenize(line, ",");

        // Storing information on the structure course

        course.courseNumber = tokenizedInformation[0];

        course.name = tokenizedInformation[1];



        // if there are prerequisites then storing them too

        for (int i = 2; i < tokenizedInformation.size(); i++) {

            course.prerequisites.push_back(tokenizedInformation[i]);

        }

        // appending the course into list of courses

        courses.push_back(course);

    }

    // closing the file

    fin.close();


    // return the list of courses

    return courses;

}

// printing course information of given course in proper format

void printCourse(Course course) {

    string courseNumber = course.courseNumber;

    string name = course.name;

    vector<string> prerequisites = course.prerequisites;


    cout << "Course Number: " << courseNumber << endl;

    cout << "Course Name: " << name << endl;

    cout << "Prerequisites: " << endl;

    for (int i = 0; i < prerequisites.size(); i++) {

        cout << prerequisites[i] << " " << endl;

    }

    cout << "" << endl;

}

// printing course information of all courses in proper format

void printCourseList(vector<Course> courses) {

    int n = courses.size();


    // Using bubble sort to sort the list

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (courses[j].courseNumber > courses[j + 1].courseNumber) {

                swap(courses[j + 1], courses[j]);

            }

        }

    }



    // traversing list of courses to print all courses information

    for (int i = 0; i < n; i++) {

        printCourse(courses[i]);

    }


}

// search the course for the user entered course number

void searchCourse(vector<Course> courses) {

    int n = courses.size();

    string courseNumber;

    int f = 0;



    cout << "Enter courseNumber: ";

    cin >> courseNumber;



    for (int i = 0; i < n; i++)

    {

        // if course found then print it

        if (courses[i].courseNumber == courseNumber) {

            f = 1;

            printCourse(courses[i]);

            break;

        }

    }



    // if course with given course name not found then print error message

    if (f == 0) {

        cout << "Course with given course number not found" << endl;

    }

}

int main(int argc, char** argv) {

    vector<Course> courses;

    // Printing menu

    cout << "1.Load Data Structure" << endl;

    cout << "2.Print Course List" << endl;

    cout << "3.Print Course" << endl;

    cout << "4.Exit" << endl;

    int ch;

    // loop will break once user enter 4

    do {

        // Prompt user to enter choice

        cout << "Enter your choice: ";

        cin >> ch;


        switch (ch) {

        case 1: courses = LoadDataStructure();

            break;

        case 2: printCourseList(courses);

            break;

        case 3: searchCourse(courses);

            break;

        case 4: cout << "Exit" << endl;

            break;


        default: cout << "Invalid Choice" << endl;

        }

    }

    while (ch != 4);

    return 0;

}

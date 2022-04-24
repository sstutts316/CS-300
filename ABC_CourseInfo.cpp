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


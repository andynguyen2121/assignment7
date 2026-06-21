//
// Name: Andy Nguyen
// Date: 6/18/26
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 7 Lab - Student Course Enrollment System
//

#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
// PART 4: Namespace definition
// Place your enum, typedefs, and function prototypes inside here
namespace EnrollmentSystem
{
    // PART 1: Define the courseType enum here.
    // Also declare a variable currentCourse of type courseType in the same statement.
    // TODO: enum courseType { ... } currentCourse;
    enum courseType{ ENGLISH, MATH, HISTORY, CPP, BIOLOGY, ART } currentCourse;
 
    // PART 2: typedef aliases
    // TODO: typedef int StudentID;
    // TODO: typedef double CreditHours;
    typedef int StudentID;
    typedef double CreditHours;
 
    // Function prototypes (fill in parameter types)
    // TODO: void printCourse(...);
    // TODO: courseType readCourse();
    // TODO: double calcTuition(...);
    // TODO: void printStudentInfo(...);
    void printCourse(courseType c);
    courseType readCourse();
    double calcTuition(CreditHours credits);
    void printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours hours);
}
 
using namespace EnrollmentSystem;

// PART 1b: printCourse

// used namespace so the complier doesnt error out
void EnrollmentSystem::printCourse(courseType c)
{
    // TODO: Use a switch statement. 
    // Each case should output the matching course name string.
    switch (c) {
        case ENGLISH:
            cout << "English Composition";
            break;
        case MATH:
            cout << "College Algebra";
            break;
        case HISTORY:
            cout << "U.S. History";
            break;
        case CPP:
            cout << "C++ Programming";
            break;
        case BIOLOGY:
            cout << "General Biology";
            break;
        case ART:
            cout << "Art Appreciation";
            break;
        default:
            cout << "Unknown Course";
            break;
    }
}
 
// PART 1c: readCourse
courseType EnrollmentSystem::readCourse()
{
    string input;
    cout << "Enter course (english/math/history/cpp/biology/art): ";
    cin >> input;
    // TODO: Use if/else if to compare input to each course name and return matching courseType.
    // If no match, print an error and return ENGLISH as default.
    if (input == "english") {
        return ENGLISH;
    }
    else if (input == "math") {
        return MATH;
    }
    else if (input == "history") {
        return HISTORY;
    }
    else if (input == "cpp") {
        return CPP;
    }
    else if (input == "biology") {
        return BIOLOGY;
    }
    else if (input == "art") {
        return ART;
    }

    cout << "Invalid input, defaulting to English" << endl;
    return ENGLISH;
}
 
// PART 2: calcTuition
double EnrollmentSystem::calcTuition(CreditHours credits)
{
    // TODO: return credits * 150.0;
    return credits * 150.0;
}
 
// PART 3b: printStudentInfo
void EnrollmentSystem::printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits)
{
    cout << endl << "--- Enrollment Summary ---" << endl;
    // TODO: Print fullName, id, email, course (via printCourse), credits, and tuition (via calcTuition).
    // Use setprecision(2) and fixed for dollar amounts.
    cout << "Name: " << fullName << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;

    cout << "Course: ";
    printCourse(course);
    cout << endl;

    cout << "Credit Hours: " << credits << endl;
    cout << fixed << setprecision(2);

    cout << "Tuition: $" << calcTuition(credits) << endl;

}
 
int main()
{
    // --- Welcome banner (use string concatenation) ---
    string line = "=====================================";
    // TODO: Build and print a welcome banner using + operator.
    cout << line << endl;
    cout << " Welcome! " << endl;
    cout << line << endl << endl;
 
    // --- PART 3: String operations ---
    string firstName, lastName, fullName;
    string emailUser, email;
 
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
 
    // TODO 1: Concatenate firstName + " " + lastName into fullName.
    // TODO 2: Output fullName.length() with a label.
    // TODO 3: Use substr to extract and print the first name only (hint: use find to locate space).
    // TODO 4: Use at(0) or [0] to print the first initial.
    // TODO 5: Use find(' ') to find and print the space position.
    fullName = firstName + " " + lastName;
    cout << "Full Name: " << fullName << endl;

    cout << "Name length: " << fullName.length() << endl;

    size_t spacePos = fullName.find(' ');
    cout << "First name extracted: " << fullName.substr(0, spacePos) << endl;

    cout << "First initial: " << fullName.at(0) << endl;

    cout << "Space found at index: " << spacePos << endl;

    cout << "Enter email username (e.g. jsmith): ";
    cin >> emailUser;
 
    // TODO 6: Check empty() on emailUser before proceeding.
    // TODO 7: Use insert to append "@sanjac.edu" at the end. Store result in email.
    // TODO 8: Use replace to fix a demo typo (e.g., replace "sanjac" with "SanJac").
    // TODO 9: Use erase to strip trailing punctuation if present.
    if (emailUser.empty()) {
        cout << "Email username is empty" << endl;
    }

    email = emailUser;
    email.insert(email.length(), "@sanjac.edu");


    size_t pos = email.find("sanjac");
    if (pos != string::npos) {
        email.replace(pos, 6, "SanJac");
    }

    if (!email.empty() && ispunct(email[email.length() - 1])) {
        email.erase(email.length() - 1, 1);
    }
    
    // TODO 10: Declare a second string lastName2 = "Smith" and use compare() to print alphabetical order.

    string lastName2 = "Smith";
    int cmp = lastName.compare(lastName2);
    if (cmp < 0) {
        cout << lastName << " comes before " << lastName2 << endl;
    }
    else if (cmp > 0) {
        cout << lastName << " comes after " << lastName2 << endl;
    }
    else {
        cout << "Last names are the same" << endl;
    }
 
    // --- PART 1: Enum operations ---
    currentCourse = readCourse();
    cout << "You selected: ";
    printCourse(currentCourse);
    cout << endl;
 
    // TODO: Advance currentCourse by one using static_cast (check that it is not already ART first).
    // Print the next course name.
 
    // TODO: for loop print all courses using printCourse.
    currentCourse = MATH;
    cout << "Math was assigned to currentCourse" << endl;

    if (currentCourse != ART) {
        currentCourse = static_cast<courseType>(currentCourse + 1);
        cout << "Next course after MATH: ";
        printCourse(currentCourse);
        cout << endl;
    }

    cout << "All courses: " << endl;
    for (int c = ENGLISH; c <= ART; c++) {
        printCourse(static_cast<courseType>(c));
        cout << endl;
    }
    
    // TODO: Declare two courseType variables, compare with <, and print which comes later.
    courseType a = MATH, b = CPP;
    if (a < b) {
        cout << "MATH comes before CPP" << endl;
    }
    else {
        cout << "CPP comes before MATH" << endl;
    }
 
    // --- PART 2: Tuition ---
    CreditHours hours;
    StudentID sid = 10045; // demo student ID
    cout << "\nEnter credit hours: ";
    cin >> hours;
    // TODO: Call calcTuition(hours) and print result.
    cout << fixed << setprecision(2);
    cout << "Tuition cost: $" << calcTuition(hours) << endl;

    // --- Summary ---
    // TODO: Call printStudentInfo with the correct arguments.
    printStudentInfo(fullName, email, currentCourse, sid, hours);
    // PART 4 DEMO: Access one namespace member with full prefix
    // cout << EnrollmentSystem::... 
    printCourse(ENGLISH); // use full namespace so the complier doesn't error
 
    return 0;

    /**/
}
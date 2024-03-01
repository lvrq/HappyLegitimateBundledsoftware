/* 
Ian Pinegar
2-24-2024 
Working with class (object) Data Type and functions
//private attributes (variables)
//setter and getter MVC method
*/

#include<iostream>
#include<string>
using namespace std;

/********GreenTea Class Declaration****/
class GreenTea {
private:
    bool delicious;
    string nameTea;
public:
    // Setter and getter methods for delicious attribute
    void setDelicious(bool);
    bool getDelicious();
    // Setter and getter methods for nameTea attribute
    void setNameTea(string);
    string getNameTea();
};

// Implementation of GreenTea class methods
void GreenTea::setDelicious(bool d) {
    delicious = d;
}

bool GreenTea::getDelicious() {
    return delicious;
}

void GreenTea::setNameTea(string nt) {
    nameTea = nt;
}

string GreenTea::getNameTea() {
    return nameTea;
}

/********Student Class Declaration****/
class Student {
private:
    string name;
    int id;
    char letterGrade;
    GreenTea preference;
public:
    // Setter and getter methods for name attribute
    void setName(string);
    string getName();
    // Setter and getter methods for id attribute
    void setId(int);
    int getId();
    // Setter and getter methods for letterGrade attribute
    void setLetterGrade(char);
    char getLetterGrade();
    // Setter and getter methods for preference attribute
    void setPreference(GreenTea);
    GreenTea getPreference();
    // Method to print student transcript
    void printTranscript();
};

// Implementation of Student class methods
void Student::setName(string n) {
    name = n;
}

string Student::getName() {
    return name;
}

void Student::setId(int i) {
    id = i;
}

int Student::getId() {
    return id;
}

void Student::setLetterGrade(char lg) {
    letterGrade = lg;
}

char Student::getLetterGrade() {
    return letterGrade;
}

void Student::setPreference(GreenTea p) {
    preference = p;
}

GreenTea Student::getPreference() {
    return preference;
}

void Student::printTranscript() {
    cout << "\nName: " << name;
    cout << "\nID: " << id;
    cout << "\nGrade: " <<letterGrade;
    cout << "\nTea Name: " << preference.getNameTea();

    if(preference.getDelicious() == true) {
        cout << "\nWell said, McMillanite, "<< preference.getNameTea() <<", green tea is great!!!" << endl;
    } else {
        cout << "\n :'(" << endl;
    }
}

/********Function Definitions****/
// Function to populate a student with default data
void populateStudentWithDefaultData(Student &s) {
    GreenTea ut;
    ut.setNameTea("Matcha Green Tea - China");
    ut.setDelicious(true);

    s.setName("YourName");
    s.setId(123456);
    s.setLetterGrade('F');
    s.setPreference(ut);

    cout << "Start Data: ";
    s.printTranscript();
}

// Function demonstrating pass by value
void fnClass(Student student) {
    cout << "\nA pass by value object process (least effective):";
    char newGrade = '\0';

    cout << "\nINSIDE fnClass()" << endl;
    cout << "\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();

    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade;
    student.setLetterGrade(newGrade);

    cout << "\n\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by value ****" << endl;
    student.printTranscript();
}

// Function demonstrating pass by reference
void fnClassRef(Student &student) {
    cout << "\nA pass by REFERENCE object process (Best method):";
    char newGrade = '\0';

    cout << "\nINSIDE fnClassRef()" << endl;
    cout << "\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();

    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade;
    student.setLetterGrade(newGrade);

    cout << "\n\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by references (&)) ****" << endl;
    student.printTranscript();
}

// Function demonstrating pass by pointer
void funClassPtr(Student* student) {
    cout << "\nA pass by pointer * object process (Alternative method):";
    char newGrade = '\0';

    cout << "\nINSIDE fnClassPtr()" << endl;
    cout << "\t" << student->getId() << ":" << student->getName() << " earned a(n): " << student->getLetterGrade();

    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade;
    student->setLetterGrade(newGrade);

    cout << "\n\t" << student->getId() << ":" << student->getName() << " earned a(n): " << student->getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by references (*)) ****" << endl;
    student->printTranscript();
}

// Main function
int main() {
    cout << "\nPrint Undergraduate Student" << endl;

    // Create an undergraduate student and populate with default data
    Student undergraduate;
    populateStudentWithDefaultData(undergraduate);

    // Create a graduate student and populate with default data
    GreenTea gt;
    gt.setNameTea("Sencha");
    gt.setDelicious(false);

    Student graduate;
    graduate.setId(1587);
    graduate.setName("
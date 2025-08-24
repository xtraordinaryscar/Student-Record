#include <iostream>
#include <cstdlib>
#define MAX 100

using namespace std;

struct Student {
    string name;
    int quiz1, quiz2, quiz3;
    float average;
};

Student students[MAX];

int last = -1, i, qz1, qz2, qz3;
string nm;

int mainMenu();
bool isFull();
bool isEmpty();
int locate(string name);
void addRecord(string studentName, int q1, int q2, int q3);
void deleteRecord(string name);
void updateRecord(string name, int q1, int q2, int q3);
void displayRecords();
float getAverage(int q1, int q2, int q3);

int main() {
    while (true) {
        switch (mainMenu()) {
        case 1:
            system("cls");

            if (isFull()) {
                cout << "Record is full." << endl;
                system("pause");
                break;
            }

            cout << "Enter name: ";
            cin >> nm;
            cout << "Enter quiz 1: ";
            cin >> qz1;
            cout << "Enter quiz 2: ";
            cin >> qz2;
            cout << "Enter quiz 3: ";
            cin >> qz3;

            addRecord(nm, qz1, qz2, qz3);
            break;

        case 2:
            system("cls");

            if (isEmpty()) {
                cout << "Record is empty, nothing to delete." << endl;
                system("pause");
                break;
            }

            cout << "Enter name: ";
            cin >> nm;

            deleteRecord(nm);
            break;

        case 3:
            system("cls");

            if (isEmpty()) {
                cout << "Record is empty, nothing to delete." << endl;
                system("pause");
                break;
            }

            cout << "Enter name: ";
            cin >> nm;
            cout << "Enter quiz 1: ";
            cin >> qz1;
            cout << "Enter quiz 2: ";
            cin >> qz2;
            cout << "Enter quiz 3: ";
            cin >> qz3;

            updateRecord(nm, qz1, qz2, qz3);
            break;

        case 4:
            system("cls");
            displayRecords();
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "Bye" << endl;
            exit(0);
            break;

        default:
            cout << "Invalid input." << endl;
            system("pause");
        }
    }
}

int mainMenu() {
    system("cls");
    int userChoice;
    cout << "1. Add Record" << endl;
    cout << "2. Delete Record" << endl;
    cout << "3. Update Record" << endl;
    cout << "4. Display Records" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "Select: ";
    cin >> userChoice;

    return userChoice;
}

bool isFull() {
    if (last == MAX - 1) {
        return true;
    }

    return false;
}

bool isEmpty() {
    if (last == -1) {
        return true;
    }

    return false;
}


void addRecord(string studentName, int q1, int q2, int q3) {
    last++;
    students[last].name = studentName;
    students[last].quiz1 = q1;
    students[last].quiz2 = q2;
    students[last].quiz3 = q3;
    students[last].average = getAverage(q1, q2, q3);

    cout <<"\nRecord Added Successfully.\n";
    system("pause");
}

int locate(string name) {
    for (i = 0; i <= last; i++) {
        if (name == students[i].name) {
            return i;
        }
    }

    return -1;
}

void deleteRecord(string name) {
    if (locate(name) == -1) {
        cout << "Record of " << name << " is not found." << endl;
        system("pause");
    } else {
        for (i = locate(name); i <= last; i++) {
            students[i] = students[i + 1];
        }
        last--;

        cout << "Record deleted." << endl;
        system("pause");
    }
}

void updateRecord(string name, int q1, int q2, int q3) {
    int index = locate(name);

    if (index == -1) {
        cout << "Record of " << name << " not found." << endl;
        system("pause");
    } else {
        students[index].name = name;
        students[index].quiz1 = q1;
        students[index].quiz2 = q2;
        students[index].quiz3 = q3;
        students[index].average = getAverage(q1, q2, q3);

        cout << "Updated Successfully." << endl;
        system("pause");
    }
}

void displayRecords() {
    cout << "Name\t\tQuiz 1\t\tQuiz 2\t\tQuiz 3\t\tAverage\t\tRemarks" << endl;

    for (i = 0; i <= last; i++) {
        cout << students[i].name << "\t\t" << students[i].quiz1 << "\t\t" << students[i].quiz2 << "\t\t" << students[i].quiz3 << "\t\t" << students[i].average << "\t\t" << (students[i].average >= 75 ? "PASSED" : "FAILED") << endl;
    }
}

float getAverage(int q1, int q2, int q3) {
    float average;

    average = (q1 + q2 + q3) / 3.00;

    return average;
}

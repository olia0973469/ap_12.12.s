#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string surname;
    int grade1;
    int grade2;
    int grade3;

    double average() const {
        return (grade1 + grade2 + grade3) / 3.0;
    }
};

class StudentGroup {
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void removeStudent(const std::string& surname) {
        students.erase(
            std::remove_if(students.begin(), students.end(),
                [&](const Student& s) { return s.surname == surname; }),
            students.end());
    }

    void editStudent(const std::string& surname, const Student& newDetails) {
        auto it = std::find_if(students.begin(), students.end(),
            [&](const Student& s) { return s.surname == surname; });
        if (it != students.end()) {
            *it = newDetails;
        }
    }

    void sortBySurname() {
        std::sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.surname < b.surname; });
    }

    void sortByAverageGrade() {
        std::sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.average() > b.average(); });
    }

    void sortByGrade(int subjectIndex) {
        std::sort(students.begin(), students.end(),
            [subjectIndex](const Student& a, const Student& b) {
                switch (subjectIndex) {
                case 1: return a.grade1 > b.grade1;
                case 2: return a.grade2 > b.grade2;
                case 3: return a.grade3 > b.grade3;
                default: return false;
                }
            });
    }

    void print() const {
        for (const auto& student : students) {
            std::cout << std::setw(15) << student.surname
                << " " << student.grade1
                << " " << student.grade2
                << " " << student.grade3
                << "  Average grade:"
                << " " << student.average() << std::endl;
        }
    }

private:
    std::vector<Student> students;
};

int main() {
    StudentGroup group;

    group.addStudent({ "Biba", 85, 90, 92 });
    group.addStudent({ "Boba", 100, 96, 100 });
    group.addStudent({ "Alliams", 90, 95, 88 });

    std::cout << "Initial list:" << std::endl;
    group.print();;

    char choice;
    do {
        std::cout << "\n\nMenu:";
        std::cout << "\n1. Sort students by surname";
        std::cout << "\n2. Sort students by average grade";
        std::cout << "\n3. Sort students by exam 2";
        std::cout << "\n4. Edit student";
        std::cout << "\n5. Remove student";
        std::cout << "\n6. Add student";
        std::cout << "\n7. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            group.sortBySurname();
            std::cout << "\nSorted by surname:" << std::endl;
            group.print();
            break;
        }
        case '2': {
            group.sortByAverageGrade();
            std::cout << "\nSorted by average grade:" << std::endl;
            group.print();
            break;
        }
        case '3': {
            group.sortByGrade(2);
            std::cout << "\nSorted by exam 2 grade:" << std::endl;
            group.print();
            break;
        }
        case '4': {
            group.editStudent("Biba", { "Bibaba", 1, 2, 3 });
            std::cout << "\nAfter editing Biba:" << std::endl;
            group.print();
            break;
        }
        case '5': {
            group.removeStudent("Boba");
            std::cout << "\nAfter removing Boba:" << std::endl;
            group.print();
            break;
        }
        case '6': {
            group.addStudent({ "Boba", 100, 96, 100 });
            std::cout << "\nAfter adding Boba:" << std::endl;
            group.print();
            break;
        }
        case '7': {
            std::cout << "Exiting program" << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }
        }
    } while (choice != '7');

    return 0;
}

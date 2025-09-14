#include <iostream>
#include <Windows.h>
using namespace std;


class Student {
private:
    char* name;
    int age;
    int course;

public:

    Student() {
        name = new char[1];
        name[0] = '\0';
        age = 0;
        course = 1;
    }

    Student(const char* n, int a, int c) {
        name = new char[strlen(n) + 1];
        (name, n);
        age = a;
        course = c;
    }

    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        (name, other.name);
        age = other.age;
        course = other.course;
    }


    ~Student() {
        delete[] name;
    }


    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            (name, other.name);
            age = other.age;
            course = other.course;
        }
        return *this;
    }


    const char* getName() const { return name; }
    int getAge() const { return age; }
    int getCourse() const { return course; }

    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        (name, n);
    }

    void setAge(int a) { age = a; }
    void setCourse(int c) { course = c; }


    void printInfo() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Курс: " << course << endl;
    }
};

class Group {
private:
    char* groupName;
    Student* students;
    int studentCount;
    int capacity;

public:

    Group() {
        groupName = new char[1];
        groupName[0] = '\0';
        studentCount = 0;
        capacity = 2;
        students = new Student[capacity];
    }

    Group(const char* name) {
        groupName = new char[strlen(name) + 1];
        (groupName, name);
        studentCount = 0;
        capacity = 2;
        students = new Student[capacity];
    }


    Group(const Group& other) {
        groupName = new char[strlen(other.groupName) + 1];
        (groupName, other.groupName);
        studentCount = other.studentCount;
        capacity = other.capacity;
        students = new Student[capacity];
        for (int i = 0; i < studentCount; i++) {
            students[i] = other.students[i];
        }
    }


    ~Group() {
        delete[] groupName;
        delete[] students;
    }


    Group& operator=(const Group& other) {
        if (this != &other) {
            delete[] groupName;
            delete[] students;

            groupName = new char[strlen(other.groupName) + 1];
            (groupName, other.groupName);
            studentCount = other.studentCount;
            capacity = other.capacity;
            students = new Student[capacity];
            for (int i = 0; i < studentCount; i++) {
                students[i] = other.students[i];
            }
        }
        return *this;
    }


    const char* getGroupName() const { return groupName; }
    int getStudentCount() const { return studentCount; }

    void setGroupName(const char* name) {
        delete[] groupName;
        groupName = new char[strlen(name) + 1];
        (groupName, name);
    }


    void resize() {
        capacity *= 2;
        Student* newStudents = new Student[capacity];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }

    void addStudent(const Student& student) {
        if (studentCount >= capacity) {
            resize();
        }
        students[studentCount] = student;
        studentCount++;
        cout << "Студента додано успішно!" << endl;
    }


    void removeStudent(int index) {
        if (index < 0 || index >= studentCount) {
            cout << "Неправильний індекс!" << endl;
            return;
        }

        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Студента видалено успішно!" << endl;
    }

    void removeStudentByName(const char* name) {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                removeStudent(i);
                return;
            }
        }
        cout << "Студента з таким ім'ям не знайдено!" << endl;
    }

    void printAllStudents() const {
        if (studentCount == 0) {
            cout << "У групі немає студентів." << endl;
            return;
        }

        cout << "Група: " << groupName << endl;
        cout << "Кількість студентів: " << studentCount << endl;
        cout << "Список студентів:" << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << i + 1 << ". ";
            students[i].printInfo();
        }
    }

    void findStudentByName(const char* name) const {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                cout << "Студента знайдено:" << endl;
                cout << i + 1 << ". ";
                students[i].printInfo();
                return;
            }
        }
        cout << "Студента з таким ім'ям не знайдено!" << endl;
    }
};

void showMenu() {
    cout << "\n=== МЕНЮ УПРАВЛІННЯ ГРУПОЮ ===" << endl;
    cout << "1. Створити нову групу" << endl;
    cout << "2. Додати студента" << endl;
    cout << "3. Видалити студента за індексом" << endl;
    cout << "4. Видалити студента за ім'ям" << endl;
    cout << "5. Показати всіх студентів" << endl;
    cout << "6. Знайти студента за ім'ям" << endl;
    cout << "7. Показати назву групи" << endl;
    cout << "0. Вийти" << endl;
    cout << "Оберіть опцію: ";
}

int main() {
    setlocale(0, "");

    Group* group = nullptr;
    int choice;

    cout << "Ласкаво просимо до системи управління групою студентів!" << endl;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            char groupName[100];
            cout << "Введіть назву групи: ";
            cin >> groupName;

            delete group;
            group = new Group(groupName);
            cout << "Група '" << groupName << "' створена успішно!" << endl;
            break;
        }

        case 2: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            int age, course;

            cout << "Введіть ім'я студента: ";
            cin >> name;
            cout << "Введіть вік студента: ";
            cin >> age;
            cout << "Введіть курс студента: ";
            cin >> course;

            Student newStudent(name, age, course);
            group->addStudent(newStudent);
            break;
        }

        case 3: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            int index;
            cout << "Введіть номер студента для видалення (починаючи з 1): ";
            cin >> index;
            group->removeStudent(index - 1);
            break;
        }

        case 4: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            cout << "Введіть ім'я студента для видалення: ";
            cin >> name;
            group->removeStudentByName(name);
            break;
        }

        case 5: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }
            group->printAllStudents();
            break;
        }

        case 6: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            cout << "Введіть ім'я студента для пошуку: ";
            cin >> name;
            group->findStudentByName(name);
            break;
        }

        case 7: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }
            cout << "Назва групи: " << group->getGroupName() << endl;
            cout << "Кількість студентів: " << group->getStudentCount() << endl;
            break;
        }

        case 0: {
            cout << "До побачення!" << endl;
            delete group;
            return 0;
        }

        default: {
            cout << "Неправильний вибір! Спробуйте ще раз." << endl;
            break;
        }
        }
    }

    return 0;
}#include <iostream>
#include <Windows.h>
using namespace std;


class Student {
private:
    char* name;
    int age;
    int course;

public:

    Student() {
        name = new char[1];
        name[0] = '\0';
        age = 0;
        course = 1;
    }

    Student(const char* n, int a, int c) {
        name = new char[strlen(n) + 1];
        (name, n);
        age = a;
        course = c;
    }

    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        (name, other.name);
        age = other.age;
        course = other.course;
    }


    ~Student() {
        delete[] name;
    }


    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            (name, other.name);
            age = other.age;
            course = other.course;
        }
        return *this;
    }


    const char* getName() const { return name; }
    int getAge() const { return age; }
    int getCourse() const { return course; }

    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        (name, n);
    }

    void setAge(int a) { age = a; }
    void setCourse(int c) { course = c; }


    void printInfo() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Курс: " << course << endl;
    }
};

class Group {
private:
    char* groupName;
    Student* students;
    int studentCount;
    int capacity;

public:

    Group() {
        groupName = new char[1];
        groupName[0] = '\0';
        studentCount = 0;
        capacity = 2;
        students = new Student[capacity];
    }

    Group(const char* name) {
        groupName = new char[strlen(name) + 1];
        (groupName, name);
        studentCount = 0;
        capacity = 2;
        students = new Student[capacity];
    }


    Group(const Group& other) {
        groupName = new char[strlen(other.groupName) + 1];
        (groupName, other.groupName);
        studentCount = other.studentCount;
        capacity = other.capacity;
        students = new Student[capacity];
        for (int i = 0; i < studentCount; i++) {
            students[i] = other.students[i];
        }
    }


    ~Group() {
        delete[] groupName;
        delete[] students;
    }


    Group& operator=(const Group& other) {
        if (this != &other) {
            delete[] groupName;
            delete[] students;

            groupName = new char[strlen(other.groupName) + 1];
            (groupName, other.groupName);
            studentCount = other.studentCount;
            capacity = other.capacity;
            students = new Student[capacity];
            for (int i = 0; i < studentCount; i++) {
                students[i] = other.students[i];
            }
        }
        return *this;
    }


    const char* getGroupName() const { return groupName; }
    int getStudentCount() const { return studentCount; }

    void setGroupName(const char* name) {
        delete[] groupName;
        groupName = new char[strlen(name) + 1];
        (groupName, name);
    }


    void resize() {
        capacity *= 2;
        Student* newStudents = new Student[capacity];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }

    void addStudent(const Student& student) {
        if (studentCount >= capacity) {
            resize();
        }
        students[studentCount] = student;
        studentCount++;
        cout << "Студента додано успішно!" << endl;
    }


    void removeStudent(int index) {
        if (index < 0 || index >= studentCount) {
            cout << "Неправильний індекс!" << endl;
            return;
        }

        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Студента видалено успішно!" << endl;
    }

    void removeStudentByName(const char* name) {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                removeStudent(i);
                return;
            }
        }
        cout << "Студента з таким ім'ям не знайдено!" << endl;
    }

    void printAllStudents() const {
        if (studentCount == 0) {
            cout << "У групі немає студентів." << endl;
            return;
        }

        cout << "Група: " << groupName << endl;
        cout << "Кількість студентів: " << studentCount << endl;
        cout << "Список студентів:" << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << i + 1 << ". ";
            students[i].printInfo();
        }
    }

    void findStudentByName(const char* name) const {
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                cout << "Студента знайдено:" << endl;
                cout << i + 1 << ". ";
                students[i].printInfo();
                return;
            }
        }
        cout << "Студента з таким ім'ям не знайдено!" << endl;
    }
};

void showMenu() {
    cout << "\n=== МЕНЮ УПРАВЛІННЯ ГРУПОЮ ===" << endl;
    cout << "1. Створити нову групу" << endl;
    cout << "2. Додати студента" << endl;
    cout << "3. Видалити студента за індексом" << endl;
    cout << "4. Видалити студента за ім'ям" << endl;
    cout << "5. Показати всіх студентів" << endl;
    cout << "6. Знайти студента за ім'ям" << endl;
    cout << "7. Показати назву групи" << endl;
    cout << "0. Вийти" << endl;
    cout << "Оберіть опцію: ";
}

int main() {
    setlocale(0, "");

    Group* group = nullptr;
    int choice;

    cout << "Ласкаво просимо до системи управління групою студентів!" << endl;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            char groupName[100];
            cout << "Введіть назву групи: ";
            cin >> groupName;

            delete group;
            group = new Group(groupName);
            cout << "Група '" << groupName << "' створена успішно!" << endl;
            break;
        }

        case 2: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            int age, course;

            cout << "Введіть ім'я студента: ";
            cin >> name;
            cout << "Введіть вік студента: ";
            cin >> age;
            cout << "Введіть курс студента: ";
            cin >> course;

            Student newStudent(name, age, course);
            group->addStudent(newStudent);
            break;
        }

        case 3: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            int index;
            cout << "Введіть номер студента для видалення (починаючи з 1): ";
            cin >> index;
            group->removeStudent(index - 1);
            break;
        }

        case 4: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            cout << "Введіть ім'я студента для видалення: ";
            cin >> name;
            group->removeStudentByName(name);
            break;
        }

        case 5: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }
            group->printAllStudents();
            break;
        }

        case 6: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }

            char name[100];
            cout << "Введіть ім'я студента для пошуку: ";
            cin >> name;
            group->findStudentByName(name);
            break;
        }

        case 7: {
            if (group == nullptr) {
                cout << "Спочатку створіть групу!" << endl;
                break;
            }
            cout << "Назва групи: " << group->getGroupName() << endl;
            cout << "Кількість студентів: " << group->getStudentCount() << endl;
            break;
        }

        case 0: {
            cout << "До побачення!" << endl;
            delete group;
            return 0;
        }

        default: {
            cout << "Неправильний вибір! Спробуйте ще раз." << endl;
            break;
        }
        }
    }

    return 0;
}

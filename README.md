# Student Management System

This project is a simple console-based Student Management System written in C. It allows the user to perform various operations such as adding a new student, finding students by roll number or name, updating student information, and managing student fees.

## Features

- **Add Student**: Add a new student to the system with details like first name, last name, roll number, CGPA, and course IDs.
- **Find Student by Roll Number**: Retrieve student details using their roll number.
- **Count Students**: Display the total number of students.
- **Delete Student**: Remove a student from the system using their roll number.
- **Update Student**: Update details of a student including name, roll number, CGPA, and courses.
- **Find Student by Name**: Search for a student using their first name.
- **Find Students by Course ID**: List students enrolled in a specific course.
- **Check Fee Status**: Check if a student's fee is paid or unpaid.
- **Update Fee Status**: Update the fee status of a student.

## Getting Started

### Prerequisites

To run this program, you need:

- A C compiler (like `gcc`)

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/student-management-system.git
    ```

2. Navigate to the project directory:
    ```bash
    cd student-management-system
    ```

3. Compile the program:
    ```bash
    gcc -o student_management_system student_management_system.c
    ```

4. Run the program:
    ```bash
    ./student_management_system
    ```

## Usage

Once you run the program, you'll be presented with a menu of options to manage students. Here are the steps for using each feature:

1. **Add Student**: Follow the prompts to enter the student's first name, last name, roll number, CGPA, and course IDs. The fee status will be set to unpaid by default.

2. **Find Student by Roll Number**: Enter the roll number to retrieve the student's details.

3. **Count Students**: Display the total number of students currently in the system.

4. **Delete Student**: Enter the roll number of the student to remove them from the system.

5. **Update Student**: Enter the roll number of the student to update their details. You can choose to update the first name, last name, roll number, CGPA, or courses.

6. **Find Student by Name**: Enter the first name to search for a student and display their details.

7. **Find Students by Course ID**: Enter a course ID to list all students enrolled in that course.

8. **Check Fee Status**: Enter the roll number to check if the student's fee is paid or unpaid.

9. **Update Fee Status**: Enter the roll number and the new fee status (1 for paid, 0 for unpaid).

10. **Exit**: Exit the program.

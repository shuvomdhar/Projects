student_grades = {}

# Add new student
def add_student(name, grade):
    student_grades[name] = grade
    print(f"Student {name} added with grade {grade}")

# Update a student
def update_student(name, grade):
    if name in student_grades:
        student_grades[name] = grade
        print(f"Student {name} updated with grade {grade}")
    else:
        print(f"Student {name} not found")

# Delete a student
def delete_student(name):
    if name in student_grades:
        del student_grades[name]
        print(f"Student {name} deleted")
    else:
        print(f"Student {name} not found")

# View all students
def view_students():
    if student_grades:
        print("All Students:")
        for name, grade in student_grades.items():
            print(f"{name}: {grade}")
    else:
        print("No students")

# main logic
def main():
    while True:
        print("\nOptions:")
        print("1. Add Student")
        print("2. Update Student")
        print("3. Delete Student")
        print("4. View All Students")
        print("5. Exit")

        choice = input("Choose an option: ")
        if choice == "1":
            name = input("Enter student name: ")
            grade = int(input("Enter student grade: "))
            add_student(name, grade)
        elif choice == "2":
            name = input("Enter student name: ")
            grade = int(input("Enter new grade: "))
            update_student(name, grade)
        elif choice == "3":
            name = input("Enter student name: ")
            delete_student(name)
        elif choice == "4":
            view_students()
        elif choice == "5":
            print("Closing program....")
            break
        else:
            print("Invalid choice. Please choose a valid option.")
            continue

if __name__ == "__main__":
    main()
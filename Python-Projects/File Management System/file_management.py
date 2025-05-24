import os

def create_file(filename):
    try:
        with open("File Management System/" + filename, 'x') as f:
            print(f"File {filename} created successfully")
    except FileExistsError:
        print(f"File {filename} already exists")
    except Exception as e:
        print(f"An error occurred: {e}")

def view_all_files():
    files = os.listdir()
    if not files:
        print("No files in the directory")
    else:
        print("Files in the directory:")
        for file in files:
            print(file)

def delete_file(filename):
    try:
        os.remove("File Management System/" + filename)
        print(f"File {filename} deleted successfully")
    except FileNotFoundError:
        print(f"File {filename} not found")
    except Exception as e:
        print(f"An error occurred: {e}")

def read_file(filename):
    try:
        with open(filename, 'r') as f:
            content = f.read()
            print(f"File {filename} content: \n{content}")
    except FileNotFoundError:
        print(f"File {filename} not found")
    except Exception as e:
        print(f"An error occurred: {e}")

def edit_file(filename):
    try:
        with open(filename, 'a') as f:
            content = input("Enter the content to be added: ")
            f.write(content + "\n")
            print(f"Content added to file {filename} successfully")
    except FileNotFoundError:
        print(f"File {filename} not found")
    except Exception as e:
        print(f"An error occurred: {e}")

def main():
    while True:
        print("\nFile Management System")
        print("1. Create a file")
        print("2. View all files")
        print("3. Delete a file")
        print("4. Read a file")
        print("5. Edit a file")
        print("6. Exit")

        choice = input("Enter your choice: ")
        
        if choice == "1":
            filename = input("Enter the filename: ")
            create_file(filename)
        elif choice == "2":
            view_all_files()
        elif choice == "3":
            filename = input("Enter the filename: ")
            delete_file(filename)
        elif choice == "4":
            filename = input("Enter the filename: ")
            read_file(filename)
        elif choice == "5":
            filename = input("Enter the filename: ")
            edit_file(filename)
        elif choice == "6":
            print("Exiting the program....")
            break
        else:
            print("Invalid choice. Please choose a valid option.")
            continue

if __name__ == "__main__":
    main()
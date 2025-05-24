# empty dictionary
contacts = {}

while True:
    print("\nContact Book App")
    print("1. Create contact")
    print("2. View contact")
    print("3. Update contact")
    print("4. Delete contact")
    print("5. Search contact")
    print("6. Count contact")
    print("7. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter contact name: ")
        if name in contacts:
            print("Contact already exists.")
        else:
            age = input("Enter contact age: ")
            email = input("Enter contact email: ")
            phone = input("Enter contact phone number: ")
            contacts[name] = {"age": int(age), "email": email, "phone": phone}
            print("Contact created successfully.")
    elif choice == "2":
        if not contacts:
            print("No contacts available.")
        else:
            name = input("Enter contact name: ")
            if name in contacts:
                contact = contacts[name]
                print(f"Name: {name}, Age: {age}, Email: {email}, Phone: {phone}")
            else:
                print("Contact not found.")
    elif choice == "3":
        if not contacts:
            print("No contacts available.")
        else:
            name = input("Enter contact name: ")
            if name in contacts:
                age = input("Enter contact age: ")
                email = input("Enter contact email: ")
                phone = input("Enter contact phone number: ")
                contacts[name] = {"age": int(age), "email": email, "phone": phone}
                print("Contact updated successfully.")
            else:
                print("Contact not found.")
    elif choice == "4":
        if not contacts:
            print("No contacts available.")
        else:
            name = input("Enter contact name: ")
            if name in contacts:
                del contacts[name]
                print("Contact deleted successfully.")
            else:
                print("Contact not found.")
    elif choice == "5":
        if not contacts:
            print("No contacts available.")
        else:
            search_name = input("Enter contact name to search: ")
            if search_name in contacts:
                contact = contacts[search_name]
                print(f"Name: {contact['name']}, Age: {contact['age']}, Email: {contact['email']}, Phone: {contact['phone']}")
            else:
                print("Contact not found.")
    elif choice == "6":
        if not contacts:
            print("No contacts available.")
        else:
            print(f"Total contacts in your book: {len(contacts)}")
    elif choice == "7":
        print("Closing contact book...")
        break
    else:
        print("Invalid choice. Please choose a valid option.")
        continue
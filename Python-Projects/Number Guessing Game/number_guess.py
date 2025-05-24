import random

number = random.randint(1, 100)
while True:
    try:
        guess = int(input("Guess a number between 1 and 100: "))
        if guess == number:
            print("Congratulations, you guessed it!")
            break
        elif guess > number:
            print("Too high!")
        else:
            print("Too low!")
    except ValueError:
        print("Invalid input. Please enter a number.")
        
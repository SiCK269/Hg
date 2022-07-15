from __future__ import print_function

import random


print('H A N G M A N # 8 attempts\n')

menu = ["play", "results", "exit"]
win = 0
loses = 0
time = "times"

while True:
    user_input = input('Type "play" to play the game, "results" to show the scoreboard, and "exit" to quit: ')
    play_count = 0
    if user_input == "play":
        play_count += 1
        game_words = ["python", "java", "swift", "javascript"]
        chosen_word = random.choice(game_words)
        word_length = len(chosen_word)

        display = []
        for i in range(0, word_length):
            display.append("-")

        cont = True
        guessed = []
        user_lives = 8

        while cont:
            guess = input(f"{''.join(display)}\nInput a letter: ")

            if len(guess) != 1:
                print("Please, input a single letter.")
            elif not guess.islower() or guess.isdigit():
                print("Please, enter a lowercase letter from the English alphabet.")
            elif guess in display or guess in guessed:
                print("You've already guessed this letter.")
            elif guess not in chosen_word:
                print("That letter doesn't appear in the word.")
                user_lives -= 1

            i = 0
            for n in range(0, word_length):
                if guess == chosen_word[n]:
                    i += 1
                    display[i - 1] = guess
                else:
                    i += 1
            guessed.append(guess)
            print()

            if "-" not in display:
                cont = False
                win =+ 1
                print(f"You guessed the word {chosen_word}!\nYou survived!")

            if user_lives == 0:
                loses += 1
                print("You lost!")
                cont = False
    if user_input == "results":
        print("You won:", win, "times")
        print("You lost:", loses, "times")

    if user_input == "exit":
        break

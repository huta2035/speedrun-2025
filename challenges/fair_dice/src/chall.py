#!/usr/bin/env python3

import os


FLAG = open("flag.txt", "r").read()
FLAG_PRICE = 1100

class AI:
    def __init__(self):
        self.balance = 1000
    
    def play(self):
        r = int.from_bytes(os.urandom(1)) # pulls from /dev/urandom, so it's 100% secure
        if r%3 == 0:
            return "rock"
        if r%3 == 1:
            return "paper"
        if r%3 == 2:
            return "scissors"

def is_user_winner(user_play, AI_play):
    assert user_play != AI_play, "Ties should be handled before this function"

    if user_play == "rock":
        return AI_play == "scissors"
    if user_play == "paper":
        return AI_play == "rock"
    if user_play == "scissors":
        return AI_play == "paper"
    return False


myAI = AI()
player_balance = 1000

print("Come and play Rock Paper Scissors against my AI!")
print("But before that, you need to know that each one of us has to bet 1$ on each game.")
print(f"The flag costs {FLAG_PRICE}$")


while True:
    print(f"Your current balance is {player_balance}$.")
    print("What do you want to do?")
    print("1 - Play a game against the AI")
    print("2 - Buy the flag")
    
    choice = int(input("What is your choice? "))
    if choice == 1:
        user_input = input("Rock, paper or scissors? ").lower().strip()
        AI_input = myAI.play()
        if user_input == AI_input:
            print("Tie!")
        else:
            if is_user_winner(user_input, AI_input):
                print("You win!")
                myAI.balance -= 1
                player_balance += 1
            else:
                print("You lose!")
                myAI.balance += 1
                player_balance -= 1
    elif choice == 2:
        if player_balance >= FLAG_PRICE:
            print("Here is the flag:", FLAG)
            player_balance -= FLAG_PRICE
        else:
            print("You cannot afford the flag, sorry")


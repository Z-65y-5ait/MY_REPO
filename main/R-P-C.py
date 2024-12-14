import random
myscore = 0
yourscore = 0
coup = True
while coup:
    choix = str(input("Choisissez votre coup (C, R, P): ").upper())
    while choix not in ['C', 'R', 'P']:
        choix = str(input("Invalid choice! Choose (C, R, P): ").upper())
    choix2 = random.choice(['C', 'R', 'P'])
    print(f"Your choice: {choix}, Computer's choice: {choix2}")
    if choix == choix2:
        print("DRAW")
    elif (choix == 'P' and choix2 == 'R') or (choix == 'R' and choix2 == 'C') or (choix == 'C' and choix2 == 'P'):
        print("YOU LOSE")
        myscore += 1
    else:
        print("YOU WON")
        yourscore += 1
    choix3 = str(input("Do you want to continue? (y/n): ").lower())
    if choix3 == 'n':
        coup = False
print(f"YOUR SCORE: {yourscore} - COMPUTER'S SCORE: {myscore}")
print("GAME OVER")

import random
from hangman_pic import games, words
endGame=False
lives=6
random_word=random.choice(words) #random 단어를 words에서 가져오기
#print(random_word)

randomWord=[] #빈 리스트
for i in random_word:
    randomWord+="_"
print(randomWord)

#while True:

while not endGame:
     user=input("알파벳을 맞춰보세요").lower() #소문자

     if user in randomWord:
        print("맞췄던 알파벳 입니다")
     else:
        if user in random_word:
            for index in range(len(random_word)):
                guess_letter=random_word[index]
                if guess_letter==user:
                    randomWord[index]=guess_letter
            print(randomWord)
        else:
            print("틀렸습니다")
            lives-=1
            if lives==0:
              endGame=True
              print("game over!")

        if "_" not in randomWord:
            endGame=True
            print("you win")

        print(games[lives])
print("정답: ",random_word)

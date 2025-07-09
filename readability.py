#import get string from cs50
from cs50 import get_string
#Get user's input
text = get_string("Text: ")
#Start the count
letters = 0
words = 1   #starting @ 1 to count the last word
sentences = 0

#to count words, letters and sentences
for char in text:
    if char.isalpha():
        letters += 1
    elif char == ' ':
        words += 1
    elif char in ['.', '!', '?']:
        sentences += 1
#calculate L and S
L = (letters / words) * 100
S = (sentences / words) * 100

#Coleman -Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

#print grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

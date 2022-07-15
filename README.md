# 1.	Article Classification Program 

•	Read from a file and output the subject of the content in the file:
o	Culinary recipe
o	Sports Article
o	News Article
•	The program will output the score of the inputted file to be any of the above subjects

# 2.	How was it done?

•	2 Parts:

o	One is going to take 30 articles from each subject and analyze the words from each article and save it in one file containing these words and the score of each word
	This is also going to ignore the 100 most common words in the English language.
	This is also going to ignore case and punctuation
	The Score is the sum of all the appearance of the word in the 30 articles divided by the total number of words

o	The other one is going to take the article from the user and compare it to each file of the common words
	After comparing, it’s going to sum the scores for each type and output it.
	The one with higher score is the most likely to be the type of the article. 

o	It was used file I/O, vectors and class to store the words and their scores.


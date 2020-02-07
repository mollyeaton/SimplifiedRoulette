# Molly Eaton Project 2
## Answers to project questions

Question 1:
Why did you choose this class?
>I chose to make make my project a simplified roulette game because to incorporate
>optionals it has to be a field that can have no value, which makes
>bets a perfect option.

Question 2:
Why does it make sense for this field to be an
optional?
>Using optionals for both of the bet fields allows the player the
>option to either make the bet or not.

Question 3:
Why did you use a pointer here?
>I used two smart pointers in my main function, because they are
>temporary variables created just for ease of coding. Since smart pointers
>are automatically deallocated at the end of the run, I thought this was the 
>most efficient use.

Question 4:
Did all of your test cases pass on
the first try? 
>No. I ran into issues with the random number generator for a while
>as well as the verifyBets function. I also previously had the displayIntro
>function run whenever a game was created, but because of all of the output to 
>the console while testing it was hard to keep track of where I was. 

Question 5:
Why do you think you did not have these cases before you implemented the
algorithm(s)?
>It was hard to test functions that required user input and know what values to put
>in for the test cases so I added output to the console to keep track of which
>functions were being tested and what values to put in. I also added a test case
>in the spinWheel to verify the spins were not the same with each go (which was traced 
>to not seeding the random number generator correctly).




Saishnu Ramesh Kumar 
CSCI 178 - Game Development (Midterm) README File 

These are the tasks and approaches I have made for this assignment:

1) Three different scenes, player detection when hits side of screen to change level, different objects and movement implementation in each level:

I have picked three backgrounds in order to show a change of scene when the player has reached the side of the screen. I used switch case statements to help with that change and also had implemented a reset so that the player will always start on the left side of the screen. The program will go from case to case until it reaches the end of case 3, whereby I implemented case 4 to exit the program immediately. For each scene there are different enemy types that I had picked, the first level is a bowling ball, the second is an apple, and the third is a bomb. Using the rand() functions I was able to create different movements for each object in their respective levels. 

2) Animations to run both direcitons (Left and Right): 

Using what we have learned in class, I have made keybinds such that the player has the ability to use the left and right arrow keys to move left and right within a specific scene whenever they would like. Those are the only keybinds added to the game in regard to player movement. 


3 Make an animated run and stop to avoid collision with falling objects: 

4 Hit count set to 5 and if player exceeds that the game resets with the current scene:

8) Reset the hit count to 0 at the beginning of each scene: 

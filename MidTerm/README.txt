Tasks:
1) Have two animations for a player (run and jump)
2) Move the parallax opposite direction of the player running
3) Have random objects move towards the player
4) Make player jump over objects with jump animation (up key pressed)
5) Make objects disappear if player collide

Approach
1) create and animate custom sprite using Aseprite
	1a) custom assets: player(idle, left, right, jump), obstacle(idle, moving), parallax1(mountain), parallax2(sky)
2) parallax moves according to the players movement
	2a) uses the keypress to determine player movement and change parallax direction accordingly
3) random objects are spawned randomly on either the left side or right side of the screen
	3a) direction is determined whether it is spawned on the left or right side relative to the player
4) player can jump 
	4a) up arrow, w key, space to jump
5) obstacles and player have a box collider and it checks every object that has a collider whether it is hitting the player
	5a) obstacles dissappear when it hits the player

Controls
move left: W, LeftArrow
move right: D, RightArrow
jump: A, UpArrow, SpaceBar

Customs
all custom sprites and art
custom collider box
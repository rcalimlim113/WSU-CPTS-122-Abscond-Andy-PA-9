# WSU-CPTS-122-Abscond-Andy-PA-9
Ryan Calimlim and Austin Smith's CPTS 122 PA 9 implementation, a game where you run away from Andy, our CPTS 122 professor.

Game Ideas/Goals

Title Screen
Settings menu with a volume slider
Controls Menu, shows controls for the game
Play button that goes to a character selection screen with the characters proved by Aozora Short
Once character selected spawn in room
Make the map dark and add a light bubble around the player
Spawn andy 3 seconds-ish later
Develop a collision model for the player with walls and andy as well as power-ups and the end point
Spawn the random end point
Implement the text boxes with code for the player to decide where the erroris and then pick the correct correction option
If player is correct spawn back in the player at the start of the level
If player is incorrect, game over, back to the menu
5 Test Cases: Win Die Power-up Complete the gulag Fail gulag

Menu Ideas/Goals

Title Screen
3 buttons - Play, Settings, Exit
Play enters a character selection screen with the characters given by Aozora
Settings brings up a volume control slider and a back button
Exit exits the game
Win Screen - Andy photo with the thumbs up
Lose Screen - Flashes andy waving finger photos

Map Ideas/Goals

Draw out a map
Create wall sprites for the map
Create a floor sprite
Create collision for wall sprites
Determine end goal locations
Create end goal collision for the player
Develop obstacles
Develop obstacle collision
Create 7 levels with varying obstacles
projectile shooter?

Basic Gameplay Ideas/Goals

Create window for the game to run in
Create a sprite for the player (a box for now)
Implement WASD movement for the player character
Create a camera system that is locked to the player (player in middle of screen always)
Create a sprite for Andy (A different box)
Get Andy sprite to follow player
Add collision from Andy to the player
Add collision from both character sprites to the walls of the maze
Add collision from the player to the end goal
Add collision from the player to power-ups

Audio Ideas/Goals

Get deep fake andy voice files
Get walking sound effect
Get obstacle sound
Death sound
Win sound
Implement sounds in the game
For Andy's sound have it's effect's volume be correlated to distance to the player

Sprites Ideas/Goals

image Boy Sprite image Girl Sprite Using WSU color palette. Main Menu - Character Selection Menu - Select Button - Play Button - Exit Button - Settings Button - Settings Menu - Floor Sprite (gray box) Wall Sprites - Make small so we can fit everything together Andy Sprite - Win Objective Sprite - Code Test Menu - Obstacle Sprites: Wall With A Shooter in it Projectile Sprite (fireball/cannon ball/ arrow)

gameplay loop in switch case:
	int option = 0;
	switch (option)
	{
	case 1://maze
		//if touch andy/fireball
		//option = 2
	case 2://gulag
		//if win gulag
		//option = 1
		//if lose gulag
		//option = 4
	case 3://start menu
		//click play
		//option = 1
		//click quit
		//option = 6
	case 4://death menu
		//click play again
		//option = 1
		//click quit
		//option = 6
	case 5://win menu
		//click play again
		//option = 1
		//click quit
		//option = 6
	case 6://quit game
	}

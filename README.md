# Computer-Graphics

This project is a simple Flappy Bird game developed using OpenGL and GLUT for a Computer Graphics course. The main goal of the project is to show how basic OpenGL shapes and functions can be used to build an interactive 2D game without using any advanced graphics libraries.



The game world is created using a fixed 2D coordinate system. The background includes a blue sky, sun, moving clouds, hills, grass, and trees. All these elements are drawn using only simple shapes like rectangles, circles, and triangles. Parallax movement is added by moving clouds, hills, and trees at different speeds to give a sense of depth.



The bird is designed using circles and triangles. It has animated wings that flap up and down, making the bird feel alive. Gravity continuously pulls the bird downward, and when the player presses the space bar, the bird jumps upward, simulating a flap.



The pipes act as obstacles and are drawn using rectangles. They move from right to left using a timer function. Each time the bird successfully passes a pipe, the score increases, and the game gradually becomes harder by increasing the pipe speed.



Collision detection is implemented to check if the bird hits a pipe, the ground, or the top of the screen. When a collision occurs, the game ends, and the high score is updated. The game also includes basic UI elements like score display, start instructions, and game-over messages.


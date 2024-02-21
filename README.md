# RayCaster in SFML

This project is made in order to learn how ray casting method work. Ray casting is a technique of drawing 2D game to appear as 3D game.
In short terms we just cast rays from players position and when the ray hits a wall we calculate distance of the point at which ray has hit the wall.
With that distance we can calculate hight of the wall to be drawn.
This technique was used in many early games, for example wolfenstein 3D.

## Custom map
In the project we can find a **world.map** file.
It is used to build a world in this project. First line of that file contains a number which represents width of the map (map is a grid)
Second line contains length of the map. Wall size is calculated based on resolution of the window and dimensions of the map.
Below those 2 lines there is matrix of numbers representing a map.
These numbers represent:
0 - Free Space
1 - Red Wall
2 - Green Wall
3 - Blue Wall
4 - Yellow Wall
9 - Spawn Point.

### Example map file:
```
20
21
11111111111111111111
10000000030000000001
10090022030000000001
10000000030000000001
10003044440011111111
10103000030000000001
10103040030000000001
10003040030000000001
12222220030011111111
10000000000000000001
10000000000000000001
10000000000000000001
10000000040000000001
10000000040000000001
10022000040000000001
10000000040000000001
10000000040000000001
10000000040000000001
10000000040000000001
11111001111111111111
00000440000000000000
```
## FOV
**FOV** can be changed in the **update** method in a player's class by changind the value by which dir vector is multiplied.
```cpp
plane.x = -dir.y * 1.f;
plane.y = dir.x * 1.f;
```


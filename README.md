[![fr](https://img.shields.io/badge/language-fr-blue.svg)](https://github.com/anbahmani/so_long/blob/main/README.fr.md)

# 🎮 SO LONG

It's a simple 2D game where the player has to collect all the items on a map and escape using the shortest possible route.

## 🌟 Project highlights
This project, which is an integral part of my educational path at École 42, has several significant strengths and learning opportunities. Here are a few highlights:
- Development of computer graphics skills: Using the graphics library introduced me to the basic principles of computer graphics, an essential area of modern computing. I learned how to manage user interactions, graphic rendering and game dynamics, skills that are transferable to more complex projects.
- Creativity and customization: The project offers the freedom to create your own game world. This flexibility stimulates creativity and can be very rewarding, as it enabled me to add a personal touch and explore ideas that go beyond the basic requirements.

## 🧐 How does it work?
The project is structured into several crucial segments, each performing a vital function in the creation of the game:
- Data analysis and interpretation (Parsing): This crucial phase involves the meticulous extraction and organization of the data contained in the game map. It includes the precise location of the player, obstacles such as walls, exit points, enemy entities and other interactive elements. This step is fundamental, as it prepares all the information needed for the game's subsequent visual rendering.
- Graphics rendering: Using the graphics library provided by École 42, this segment is responsible for the visual transposition of the game world. It requires careful definition of the textures and graphic elements that will make up every visual aspect of the game, from the immersive environment to the unique characters, ensuring a rich and engaging user experience.
- Interaction management and game dynamics: This involves defining and manipulating the game's reactions to user actions. It dictates how the game unfolds in response to various player decisions and actions (for example, the consequences of moving to a cell containing an item, or encountering an enemy). This part is essential to ensure coherent and logical interaction within the game, contributing directly to the overall player experience.

Each of these steps is interdependent, requiring precise execution and close coordination to ensure smooth gameplay, visual immersion and an interactive user experience. Together, they form the backbone of a coherent and captivating virtual game environment.

## Preview

<img src="https://github.com/anbahmani/so_long/blob/main/preview/so_long.gif"/>

Extra game : 
<img src="https://github.com/anbahmani/so_long/blob/main/preview/so_long_bonus.gif"/>

## 🧑‍💻 Run game

Run classic game :

```
  git clone git@github.com:anbahmani/so_long.git
  cd so_long ; make ; ./so_long map/map2.ber
```

Run extra game :

```
  git clone git@github.com:anbahmani/so_long.git
  cd so_long ; make ; ./so_long_bonus map/map3.ber
```

## ⌨️ Commands

| Key           | Action        |
| ------------- |:-------------:|
| `ESC`         | quit     		|
| `A`           | move left     |
| `D`           | move right    |
| `W`           | move forward  |
| `S`           | move backward |
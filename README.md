# 🕹️ 2D Game Framework

*A lightweight 2D game framework developed in C++ with a focus on modularity and extendibility, using the SDL2 library.*

## 🚀 Features

- **Entity-Component System (ECS)**: A flexible architecture using an entity-component system to improve code organization and expandability.
- **Modular Components**: Includes predefined components such as `Button`, `Image`, `Rigidbody`, and `Text` for creating user interfaces, visual elements, and managing physics.
- **Rendering and Sprites**: Supports working with sprites through the `Image` class, which allows for loading and rendering textures and images.
- **Input Handling**: The `Button` component handles mouse click and movement events, enabling the creation of interactive UI elements.
- **Scene Management**: The `SceneManager` automates object storage and cleanup, simplifying state management and transitions between game scenes.
- **Event-Driven System**: Event handling, such as mouse button clicks or key presses, is implemented for more interactive control.
- **Event Distribution**: Components can react to events like clicks or movements without tight coupling between them.

## 🛠️ Getting Started

### Prerequisites
- **CMake**: The project uses CMake to handle building and dependencies.
- **SDL2, SDL2_image, SDL2_ttf, Minizip**: Install these libraries for additional functionalities.

### Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/your-username/2d-game-framework.git
    ```
2. **Navigate to the Project Directory**:
    ```sh
    cd 2d-game-framework
    ```
3. **Go to the "Build" Folder**:
    ```sh
    mkdir build
    cd build
    cmake ..
    ```
4. **Build the Project**:
    ```sh
    make
    ```
5. **Copy Required Assets**:
    ```sh
    cp -r ../Assets/ 
    cp -r ../DefaultAssets/
    
6. **Running the Game**
    ```sh
    ./game  
    ```

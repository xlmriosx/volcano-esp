![workflow](https://github.com/xlmriosx/volcano-esp/actions/workflows/build-tag-publish.yaml/badge.svg)

# 🌋 **Volcano's ESP** 🔥

## 🖼️ **Showcase - Screenshots**

![ESP](https://github.com/MaxPriani/volcano-esp/blob/main/src/assets/images/1.png?raw=true)

![ESP](https://github.com/MaxPriani/volcano-esp/blob/main/src/assets/images/2.png?raw=true)

![ESP](https://github.com/MaxPriani/volcano-esp/blob/main/src/assets/images/3.png?raw=true)

## 📚 **Project Description**

**Volcano's ESP** is a personal integrative project developed for educational purposes to learn and deepen knowledge in advanced **C++** and **reverse engineering** concepts. The main goal of this project is to create an **overlay** for a game using techniques such as **memory reading**, **process scanning**, **offsets**, and **rendering** with **DirectX 11**. Key concepts implemented during development include:

- **Process Scanning**: Scanning and interacting with running processes, such as **cs2.exe**, to retrieve information like **PID**, **loaded DLLs**, etc., using the **Windows API**.

- **Memory Reading**: Reading and modifying the memory of a running process to retrieve real-time information.

- **Offsets**: Using specific offsets to access information within a game's memory.

- **Overlays and Rendering**: Using DirectX 11 to create an overlay that displays relevant information about players in the game.

- **Reverse Engineering**: Understanding how a game’s internal processes work to extract information without direct access.

- **Linear Algebra**: Implementing the **view matrix** and coordinate transformations to project 3D world positions to 2D screen coordinates.

- **Object-Oriented Programming**: The project is implemented using **C++** and **object-oriented programming** concepts to efficiently organize code.

⚠️ **Important**: This project was developed **only for educational purposes**. It is not designed to be **undetectable** nor intended for use on servers with protection systems like **VAC** (Valve Anti-Cheat). **It is not recommended for use in online games or to cheat in secure servers.**

## 🔧 **Requirements**

To run this project on your machine, ensure that you have the following requirements:

- **Operating System**: Windows 10 or later.
- **Visual Studio 2022** or later with support for **C++20** and **DirectX 11**.
- **ImGui** for the graphical interface (must be included in **VC++ Directories**).
- **DirectX 11 SDK** for rendering interfaces.
- **CMake** (if you prefer to use it for build management, you will need to create your own `CMakeLists.txt`).

## 🛠️ **Build in Visual Studio**

1. **Clone the repository** to your local machine:
   ```bash
   git clone https://github.com/MaxPriani/volcano-esp.git
   ```
   
2. **Open the project in Visual Studio**:
   - Open **Visual Studio** and select `File > Open > Project/Solution`.
   - Navigate to the directory where you cloned the repository and open the `.sln` solution file.

3. **Build the project**:
   - Once the project is configured, select `Build > Build Solution` to compile the project.
   - This will generate the executable file in the `build/` directory.

4. **Run the ESP**:
   - After building, run the generated `ESP.exe` file to see the overlay in action. Keep in mind that the ESP only activates if the game is running, as it needs to scan the **cs2.exe** process.

## 🖥️ **ESP Features**

The **Volcano's ESP** overlay offers several useful features for analyzing the game state, such as:

- **ESP Box** 📦: Displays boxes around players, indicating their position and size.
- **Player Health** ❤️: Shows the health of players based on their health level, with the text color changing according to health.
- **Distance** 🏃‍♂️: Displays the distance between the local player and nearby enemies. Based on the distance set by the user in the UI (e.g., 3,000 units), the ESP will not render enemies that are farther than the specified distance.
- **Player Names** 🏷️: Displays the player's name above their head.
- **Dynamic Configuration** ⚙️: Adjust values such as box thickness, text size, max enemy distance, colors, and more.

### Hotkeys:
- **[F4]**: Toggle the interactive graphical interface on/off.

## 📝 **How It Works**

### External ESP:
This project is an **external ESP**, meaning it does not inject itself into the game's memory or modify it. Instead, the ESP **reads the game's memory** to gather information about players (such as health, position, team, etc.) using **offsets**. This information is then used to render the overlay on top of the game using **DirectX 11**. This approach makes the ESP safer to use, as it does not require direct modification or interaction with the game's memory.

**Important**: The overlay **only works in Windowed or Borderless mode**. This is because external overlays like this one cannot interact with the game in **Exclusive Fullscreen** mode.

### Overlay:
An **overlay** is a screen that sits on top of the game, displaying additional information without interfering with the game's flow. In this project, **DirectX 11** is used to create a transparent window that is placed over the game. This window continuously renders the ESP (information about players) while the game is running.

### Memory Reading:
The project uses the `Memory` class to read the game's process memory, looking for specific addresses (using **offsets**) that contain relevant information such as player health, name, etc.

### Coordinate Transformations:
Linear algebra is used to transform 3D world coordinates into 2D screen coordinates, allowing the overlay elements to be correctly drawn on the player's screen.

### Rendering with DirectX 11:
Using the **DirectX 11 API**, the project renders the player boxes, names, health, and distance smoothly over the game.

### Graphical Interface with ImGui:
**ImGui** is used to create an interactive graphical interface that allows the user to adjust the ESP settings in real time.

# Prayercli

Prayercli is a terminal-based application which foucuses on enhancing the daily lives of Muslims, through making boring everyday tasks much easier. 

## 🧠 Features

-  **Fetch prayer times** — Using python and api.aladhan.com , the program fetches prayer times based on the date and location given by user.
-  **Random hadith** — Displays a random hadith and it's source.
-  **PLay azan/para/athkar** - plays : para 29/1, morning athkar, azan and ruqia.
-  **Modular Design** — Organized source code with headers and implementation separated cleanly.
-  **CMake Build** — Fully CMake-integrated for easy cross-platform building.
-  **and more to come soon...**

## 📁 Project Structure

``` html
├── build                  # CMake build output
| 
|── lib                    #external libraries 
|   └── json
│   └── SFML
|
├── include                # Header files
│   ├── prayerlogic.hpp
│   └── commandparsing.hpp
|
├── src                    # Source code
│   ├── main.cpp
│   ├── commandparsing.cpp
│   ├── fetchdata.py
│   └── prayerlogic.cpp
|
├── .gitignore
├── .gitmodules
├── CMakeLists.txt
└── README.md              # This file
```

## ⚙️ Build Instructions

### 📦 Requirements

- C++17-compatible compiler (e.g., `g++`, `clang++`)
- [CMake](https://cmake.org/download/) (version 3.10+)

### 🛠️ Building

```bash
git clone --recurse-submodules <https://github.com/Indective/prayercli.git>
cd prayercli
mkdir build && cd build
cmake ..
make
```

### ▶️ Running

```bash
./Prayercli
```

## 🚀 Usage

-  **Command Structure** - "prayer [command name] [args]"

note : no command takes arguments except prayertimes and para, prayertimes takes the date in a "DD-MM-YYYY" format, and a city name.
while para takes 1 argument which is the para number, only 29 and 1 are avaliable for now.

## 🛠️ Tech Stack

- **C++17**
- **CMake**
- **nlohmann/json** (for parsing JSON)
- **SFML** (for playing sounds)

## 📄 License

This project is released under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to open issues or submit pull requests to suggest improvements or new features.

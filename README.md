# YaCAD

![Static Badge](https://img.shields.io/badge/Chumakov--Anton--I-YaCAD-YaCAD)
![GitHub top language](https://img.shields.io/github/languages/top/Chumakov-Anton-I/YaCAD)
![GitHub License](https://img.shields.io/github/license/Chumakov-Anton-I/YaCAD)
![GitHub Org's stars](https://img.shields.io/github/stars/Chumakov-Anton-I%2FYaCAD)

YaCAD is Yet Another CAD application.

## Purposes

There are lots of different CAD application, so you can ask me, why? 
This is a test version. I want to try my ideas. Then I will develop a more advanced application.

## Building

### Requirements
Before building make sure you have CMake version 3.16 or newer and Qt Toolkit 6.8 or newer.
Older versions of Qt can be used but they were not tested.

### Dependencies
The current version of the project does not depend on other frameworks or libraries except Qt.

### Build the project
Clone the repository
```
git clone git@github.com:Chumakov-Anton-I/YaCAD.git
```
or
```
https://github.com/Chumakov-Anton-I/YaCAD.git
```
on your computer.
> [!NOTE]
> You can also use QtCreator to open the project and build it.

Now build the application
```
cd YaCAD
cmake -S . -B <build-tree>
cmake --build <build-tree>
```
> [!WARNING]
> Type your path to `<build-tree>`. We recommend to use *out-of-tree* building.

> [!WARNING]
> If you are a Windows user, open the special prepared for Qt command line. This can be done on the Start menu.

## Using

> [!WARNING]
> The project is really raw, and does not have even the minimal set of necessary features.

Just start the `yacad.exe` file in your build directory (`<build-tree>`).

## Development notes

To simplify the development use these labels in commit messages:

| Label   | Description                                            |
|---------|--------------------------------------------------------|
| Build   | Project building or dependencies changing              |
| Docs    | Documentation updating                                 |
| Feature | New features                                           |
| BugFix  | Bug fixing                                             |
| Perf    | Perfomance improving                                   |
| Refact  | Code editing without bug fixing or adding new features |
| Revert  | Reverting to old commits                               |
| Test    | Tests adding                                           |
| Ressrc  | Resources adding (icons, images etc.)                  |
| Other   | Other small changing                                   |

Example:
```
git commit -m "Other: update README.md"
```

## Other

![No AI generated code](./images/NoAI.png)

My projects don't have AI generated code. But I'm not an AI-luddite and don't think it's generally a bad idea.
If you want to use some AI assistants, use them!

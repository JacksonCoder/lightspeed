# LightSpeed- The C/C++ package manager

## Features
- Complete package manager for C++ applications
- Install binaries or compile from source
- Intuitive command line interface that's easy to learn but powerful for professionals
- Install packages from central and decentralized repostories
- Compile CMake files for dependencies

## Commands
```lightspeed install <package>```: Installs the specified package

```lightspeed version```: Prints the version

```lightspeed status```: Prints the current status of the project

```lightspeed create <project name>```: Creates a new project in the specified directory

```lightspeed search <package name>```: Searches for a package with a certain name

```lightspeed load <file>``` Loads a LightSpeed configuration file for the manager

```lightspeed build```: Build a CMake file that uses the locally required packages

```lightspeed remove <package>```: Uninstalls the package

```lightspeed repo <add/remove/exists> <repository name>```: Commands to add, remove and check potential code repositories

## LightSpeed file formatting
LightSpeed uses a JSON file format for specifying package requirements and settings for a project. The default file that LightSpeed looks for is ```LightSpeed.json```.

## Example

```LightSpeed.json```:

```
{
    "requirements" : {
        "sfml" : {
            "version" : "2.0",
            "flags": "!no-network"
        }
    },
    "settings" : {
        "install" : "local"
    }
}
```
First, set up the package repository:
```lightspeed repo add http://<some-repo-url>```

By running:

```lightspeed load```
and then
```lightspeed build```
a ```LightSpeed.cmake``` file will be generated, and a ```cmakebuild``` directory will be created with the SFML library installed.

## More information

Documentation is coming soon regarding the creation of LightSpeed packages.

## Release scheduling

0.1 is scheduled to be released within the next 2 weeks. The application will just be a sandbox for testing out various components of the project. This includes project file parsing, installation, and compilation into CMake files, as well as various utilities.

0.2 will fix bugs in 0.1, and greatly expand documentation of LightSpeed. A lot of code cleanup will also be part of it. Set to be released in early January.

0.3 will fix bugs from 0.2 and expand LightSpeed's command list/functionality. Release time TBD.

Other releases and their features will be annouced as time goes on.

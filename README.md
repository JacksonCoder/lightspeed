# LightSpeed
## The C/C++ package manager

## Features
- Complete package manager for C++ applications
- Install binaries or compile from source
- Intuitive command line interface that's easy to learn but powerful for professionals
- Install both local and global packages
- Compile CMake files for dependencies

## Commands
```lightspeed install <package>```: Installs the specified package
```lightspeed version```: Prints the version
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

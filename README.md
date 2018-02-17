# LightSpeed- The Fastest, Easiest (and cross-platform) C/C++ package manager
[![Build Status](https://travis-ci.org/JacksonCoder/lightspeed.svg?branch=master)](https://travis-ci.org/JacksonCoder/lightspeed)
[![Waffle.io - Columns and their card count](https://badge.waffle.io/JacksonCoder/lightspeed.svg?columns=To%20Do,In%20Progress,Done,Later%20Version)](https://waffle.io/JacksonCoder/lightspeed)

LightSpeed is designed (from the ground up) for speed and ease of use. It's built with optimized C++ code, with minimal bloat that limits installation time only to network connection.

It is incredibly easy to configure for your project, with only one file, `LightSpeed.json`, that's needed. Everything: the project manifest, build commands, and exports can be controlled from that one JSON file. No complex build setups, no custom configuration languages to learn (we're looking at you, Conan), and best of all, no need to modify any other part of your project. LightSpeed works with header-only libraries and regular libraries, leveraging the CMake build system to create cross-platform compatibility of libraries.

LightSpeed also will feature the LightWeight build system, a system that cuts down on dependency bloat by only preserving the binaries and include files of a dependency. This feature will be introduced later, but for now, you can still use the traditional CMake dependency-source-build-then-linkage feature.

## Commands

`lightspeed sandbox`: Run the sandbox mode for LightSpeed, testing beta features. 

`lightspeed version`: Display the version of LightSpeed.


## More information

Documentation is coming soon regarding the creation of LightSpeed packages. The Github Wiki associated with this project may offer some help regarding package creation or contributing.

## Release scheduling

0.1 has just been released! This release includes the ability to test all the components that will eventually make up the LightSpeed toolchain.

0.2 will fix bugs in 0.1, and greatly expand documentation of LightSpeed. It will also move all the beta features into their respective commands, so rudimentary package building will be possible. Set to be
released at the end of February.

0.3 will fix bugs from 0.2 and expand LightSpeed's command list/functionality. Release time TBD.

Other releases and their features will be annouced as time goes on.

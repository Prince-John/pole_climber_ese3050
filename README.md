# Pole Climber Code Base

Code base for automated pole climbing robot built for ESE3050. 


*Note:* To build the code the PICO sdk needs to be a environment variable. I have done this by having a .vscode folder inside the `micro_ros_raspberrpi_pico_sdk` directory with a `settings.json` file containing the following: 

```json
{
    "cmake.configureEnvironment": {
        "PICO_SDK_PATH": "<Path where this repo has been cloned>/pole_climber_ese3050/pico-sdk",
    }

}
```

The directory structure would look something like this:
```
pole_climber_ese3050/
                |
                |__ micro_ros_raspberrypi_pico_sdk/
                |                       |__ .vscode/
                |                       |      |__settings.json
                |                       |...     
                |__ pico_sdk/
                |       |...    
                |
                |__ README.md 
```

Doing this exact way is not necessary you can make the pico sdk a global environment variable as well. 

Depending on your text editor/IDE you will also need to configure the compiler for CMAKE. 

For vscode I followed this guide: https://ubuntu.com/blog/getting-started-with-micro-ros-on-raspberry-pi-pico


Here is the relavent quote from the page. 

> Before running the CMake configuration and building it, we must select the appropriate ‘kit’ (maybe VSCode has already asked you to do so). Open the palette (ctrl+shift+p) and search for CMake: Scan for Kits and then CMake: Select a Kit and make sure to select the compiler we’ve installed above, that is GCC for arm-non-eabi.

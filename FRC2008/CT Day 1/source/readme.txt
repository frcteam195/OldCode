To use this project, just create one in the folder where all your files are. Make sure the .lkr and the .lib files are also located in this folder.
The .lkr file should be named either 18f8722.lkr or 18f8520.lkr
The .lib file should be named either ifi_frc_8722.lib or ifi_frc_8520.lib

There are by default 6 build targets
Normal - Use the 18f8722 Processor (RCs 2006 and later), generate a map file, same as a default mplab compile
Optimized - Same as normal but enable all optimizations on the compiler
COD - Same as normal but don't disable the generation of a COD file, this restricts the size of your path so only use it if you really need a COD file
8520 - Same as normal but use the 18f8520 Processor instead
8520 Optimized - Same as optimized but use the 18f8520 Processor instead
8520 COD - Same as COD but use the 18f8520 Processor instead
You should only use one of these targetss

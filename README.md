# FISC-Assembler
FISC-Assembler is the Assembler tool which is used in the FISC project.


# How to Build the Source Code
* From the top folder of the project, run `toolchain/launcher.pyc build`

* You can see what scripts are available by running `toolchain/launcher.pyc -h`

* The output file will be the assembler executable, which will be outputted into the folder 'bin'

# How to Run the Assembler

* In order to run the assembler simply go to 'bin' and execute:
 `flasm filename -o binfile`.

* You can also do this by going into the folder 'testbench', where you can **drag and drop** a test file into the script 'run_test.pyc'. The test file's **filename** must have this format: test_yourname.txt.
**Example filenames**: test1, test_mytest.txt, test_trythis.vc

# Command line Options
`-h : Show help message`  
`-o <filename> : Output pure binary file`  
`-a : Convert output into ASCII formatted output, also using newlines`  
`--stdio : Output only to the console the binary result`  
`--debug : Output Instructions and their attributes to the stdio`  
  
**NOTE**: If no arguments are given, the Assembler will produce a.out.  
Also remember that you can combine these options.

Command line examples:  
1- Normal usage: **`flasm hello_world.asm -o hello_world.o`**  
2- Output to stdio AND to file: **`flasm hello_world.asm -o hello_world.o --stdio`**  
3- Output only to stdio and debug (no files are produced): **`flasm hello_world.asm --stdio --debug`**  

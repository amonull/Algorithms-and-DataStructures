# Intro

These are a collection of algorithms and datastructures that i am currently learning written in C as i am also learning C.


# How doc works

The doc folder under algorithms or datastructures is just a collection of notes i took that help me visualize and explain an algorithm or datastructure.


# File structure
```
                                 src/ -> holds .c files

Base(Algorithm/Datastructure) -> include/ -> holds .h files commonly used by src/ and tests/

                                 tests/ -> holds usually only test.c or all files used for testing including .h files 

                                 doc/ -> markdown files explaining my thought process or how I visualize the algorithm/datastructure
```

Because of the file structure above when compiling with `gcc` the flag option `-I ./include/` must be added to include the header files.

# Important

I try to create the algorithms and datastructures using what is commonly avaliable in C11 however sometimes I might use another library that the user needs to install and set the compile flags accordingly and it should be noted that the tests are done using the CUnit framework so to compile the tests CUnit must be on system

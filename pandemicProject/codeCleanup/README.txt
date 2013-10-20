*** README ***

file(s):  ALL OF THEM

COMPILING FROM THE COMMAND LINE:

Compiles under Visual Studio's Developer's Command Prompt
Go to the working directory and run: cl /EHsc mainGame.cpp

I went through all of the files and cleaned them up, added proper
preprocessor commands, adjusted code structure/spacing,
minimized "using" statements to only those necessary, etc...

Please feel free to look them over to see if you agree with this structure,
because we need to decide on a general format for code from this point
forward.  One of the biggest issue I had while consolidating file was
the lack of proper preprocessor directives:

either:
#pragma once

or:
#ifndef FOO_H
#define FOO_H
.
.
.
#endif

A bonus addition I added was including the associating .cpp file
from within its header file by added this just before "#endif":

#include "Bar.cpp"

(if anyone doesn't know, the foo/bar combo is simply placeholder
 names referring to whatever would actually fit in that statement.)

Thanks,

-- Derrick(3dfxScorpion)



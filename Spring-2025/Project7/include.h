#ifndef INCLUDE_H
#define INCLUDE_H

void Include(void) {
  char examples;  // used for user input

  printf("*** Include ***\n\n"
         "Include is a C preprocessor directive. It serves to incorporate\n"
         "the contents of another file into the current one. Usually, it\n"
         "is used to include header files from the C standard library or\n"
         "user defined ones. Include is usually placed at the start of a\n"
         "C file, before any of the other code. Included files can either\n"
         "be in the same directory as the file that includes them or can\n"
         "be added to the preprocessor using different flags depending\n"
         "on the compiler. Common header files are \n"
         "     stdio.h     // file and input/output functions and types\n"
         "     stdlib.h    // memory allocation, random\n"
         "     string.h    // see string function tutor\n"
         "     stdbool.h   // boolean type\n"
         "     math.h   // advanced math functions\n"
         "Header files are text files, typically ending with the .h extension.\n"
         "While they can contain full C code and definitions, they usually only\n"
         "contain declarations. The point is to provide different source files\n"
         "with public declarations for functions, variables, types, and more.\n"
         "The actual definitions are usually in a corresponding c file. The C\n"
         "code is then shared and used across all files that include the header,\n"
         "without recompiling the definitions each time.\n\n"
         "The syntax of include is \n"
         "     #include <(C standard library file)>\n"
         "     #include \"(user defined file)\"\n\n"
         "Do you want to see examples (type y for yes)?");
  examples = getchar();
  if(examples == 'y' || examples == 'Y') {
    printf("\n\n\n"
           "*** Include Examples ***\n\n"
           "     #include <stdio.h>\n"
           "This instance of include serves to add all the functions located\n"
           "in the standard library stdio.h file to the current source code.\n"
           "It will allow the code to use functions such as printf, and types\n"
           "such as FILE.\n\n"
           "     #include \"myheader.h\"\n"
           "In this instance, include takes all the contents from myheader.h,\n"
           "which is completely user defined.\n\n"
           "     #include \"module1.h\"\n"
           "Here, include is used to incorporate all the contents from a user\n"
           "defined module. This module can be part of a bigger project, where\n"
           "code separation and modularity become essential. Include allows\n"
           "developers to make their code as modular as they want.\n");
  }
}

#endif // !INCLUDE_H

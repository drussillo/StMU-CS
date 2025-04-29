#ifndef MAININ_H 
#define MAININ_H

void MainParameters(void) {
  char examples; // used for user input

  printf("*** Main Parameters ***\n\n"
         "Main functions in C can accept two different parameters. These\n"
         "are argc and argv. These are meant to be used for command-line\n"
         "arguments that are passed to the program when it is executed.\n"
         "The integer argc represents the amount of arguments (including\n"
         "the executable itself), while argv is an array of strings.\n"
         "Again, the name of the executable is always included, so argc\n"
         "will always be at least one, and argv at index 0 will be the\n"
         "executable's name.\n\n"
         "The syntax of main parameters is\n"
         "     int main(int argc, char *argv[]) {\n"
         "       // code\n"
         "       return 0;\n"
         "     }\n\n"
         "Use argc to get the amount of arguments.\n"
         "Use argv to get the arguments as strings.\n\n"
         "Do you want to see examples (type y for yes)?");
  examples = getchar();
  if(examples == 'y' || examples == 'Y') {
    printf("\n\n\n"
           "*** Main Parameters Examples ***\n\n"
           "     test.exe first second third\n"
           "This is an example of executing a C program from the command-line,\n"
           "while passing three arguments. In this case, argc would be equal\n"
           "to 4, while argv[0] would be test.exe, argv[1] would be first,\n"
           "argv[2] would be second, and argv[3] would be third.\n\n"
           "     printf(\"%%s\\n\", argv[0]);\n"
           "This code is printing the first argument in the argv parameter.\n"
           "This is going to be the executable name, so if the file is test.c\n"
           "and the executable is test.exe, this code will print ./test.exe.\n\n"
           "     printf(\"%%d, %%s\\n\", argc, argv[argc - 1]);\n"
           "In this code, n and the nth argument are being printed, where n\n"
           "is the amount of arguments (argc). Looking at the previous examples,\n"
           "the output would be '4, third'.\n\n"
           "     int i;\n"
           "     for(i = 0; i < argc; i++) {\n"
           "       printf(\"%%d, %%s\\n\", i, argv[i]);\n"
           "     }\n"
           "Here, each index and equivalent argument is being printed. Looking\n"
           "at the previous examples, the output would be '0, ./test', then '1,\n"
           "first', then '2, second', and then '3, third'.\n");
  }
}

#endif // !INCLUDE_H

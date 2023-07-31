import os

env = Environment()

env.StaticLibrary('libs/cpu6502',['include/cpu6502.c'])

env.Program(target = "bin/nes.exe",source = "main.c",LIBS = 'cpu6502', LIBPATH = 'libs/')
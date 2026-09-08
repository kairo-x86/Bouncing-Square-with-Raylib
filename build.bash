#for raylib projects
#replace /home/user/whatever with your directories.
#replace main with your project name

gcc main.c -o main -I/home/USER/raylib/include -L/home/USER/raylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
LD_LIBRARY_PATH=~/raylib/lib ./main 
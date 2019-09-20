# script to delete all files with extention .cpp.o

echo please enter a directory:
read directory
echo "$directory1"
cd $directory

echo files to be deleted:  
ls *.cpp.o
echo "type 1 to delete"
read deleteyn
if [ "$deleteyn" -eq 1 ]; then
    rm *.cpp.o
    fi


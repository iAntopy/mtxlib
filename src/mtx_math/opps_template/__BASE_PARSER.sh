grep 'void' __BASE*.c | while read -r line;
do 
    echo $line
    echo $line | cut -d'(' -f1 | cut -d' ' -f2 #| awk '{print $2}'
done
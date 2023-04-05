for file in *
do
    if [ ! -d "$file" ]     # Check if the "file" is a directory
    then
        filename="$file"
        i=1
        while read -r line  # The slash is not defined as an escape character.
        do
            if [ $((i % 2)) -eq 0 ]
            then
                echo "$filename: $line"
            fi
            ((i++))
        done < "$file"
    fi
done
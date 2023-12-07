#!/bin/bash

SERVER="http://localhost:8080"

FILENAMES=("testfile1.txt" "testfile2.txt" "testfile3.txt")
CONTENTS=("Hello, HTTP Server 1!" "Hello, HTTP Server 2!" "Hello, HTTP Server 3!")

for i in "${!FILENAMES[@]}"; do
    FILENAME=${FILENAMES[$i]}
    CONTENT=${CONTENTS[$i]}
    echo "Sending PUT request for $FILENAME with content: $CONTENT"
    curl -X PUT -d "$CONTENT" "$SERVER/$FILENAME" &
done

wait

echo -e "\n"

for FILENAME in "${FILENAMES[@]}"; do
    echo "Sending GET request for $FILENAME"
    curl "$SERVER/$FILENAME" &
done

wait

echo -e "\n"

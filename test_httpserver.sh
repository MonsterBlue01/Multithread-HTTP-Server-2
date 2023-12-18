#!/bin/bash

SERVER="http://localhost:8080"

FILENAMES=("testfile1.txt" "testfile2.txt" "testfile3.txt")
CONTENTS=("Hello, HTTP Server 1!" "Hello, HTTP Server 2!" "Hello, HTTP Server 3!")

# Test PUT requests
for i in "${!FILENAMES[@]}"; do
    FILENAME=${FILENAMES[$i]}
    CONTENT=${CONTENTS[$i]}
    echo "Sending PUT request for $FILENAME with content: $CONTENT"
    curl -X PUT -d "$CONTENT" "$SERVER/$FILENAME"
    echo -e "\n"
done

# Short delay to let server process
sleep 2
echo -e "\n"

# Test GET requests (first time should populate cache)
for FILENAME in "${FILENAMES[@]}"; do
    echo "Sending GET request for $FILENAME"
    curl "$SERVER/$FILENAME"
    echo -e "\n"
done

# Short delay before testing cache hits
sleep 2
echo "Testing cache hits"
echo -e "\n"

# Test GET requests again (should hit cache)
for FILENAME in "${FILENAMES[@]}"; do
    echo "Sending GET request for $FILENAME (Cache Test)"
    curl "$SERVER/$FILENAME"
    echo -e "\n"
done

echo "Testing completed."

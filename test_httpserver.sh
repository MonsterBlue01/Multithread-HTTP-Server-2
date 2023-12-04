#!/bin/bash

SERVER="http://localhost:8080"

FILENAME="testfile.txt"

CONTENT="Hello, HTTP Server!"

echo "Sending PUT request with content: $CONTENT"
curl -X PUT -d "$CONTENT" "$SERVER/$FILENAME"
echo -e "\n"

echo "Sending GET request for $FILENAME"
curl "$SERVER/$FILENAME"
echo -e "\n"

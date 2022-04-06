int main() {
    FILE *out = NULL;
    out = fopen("output.txt", "w");

    List head = newList();
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);
    append(head, 10);
    prepend(head, 4);
    deleteFront(head);
    deleteBack(head);
    printf("front: %d\n", front(head));
    printf("back: %d\n", back(head));
    printf("length: %d\n", head->length);
    moveFront(head);
    prepend(head, 3);
    printf("index: %d\n", head->index);
    printList(out, head);
    printf("\n");

    List new = copyList(head);
    printList(out, new);
    printf("\n");

    fclose(out);
}

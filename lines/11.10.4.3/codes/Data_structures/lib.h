typedef struct Node {
    double value;
    int row;
    int col;
    struct Node* next;
} Node;



Node* createNode(double value, int row, int col) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

void insert_node(Node **head, int row, int col, double val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}
// Function to create a matrix using linked lists
Node* loadtxt(char *str,int numRows,int numCols) {
    FILE *fp = fopen(str, "r");
    Node* head = NULL;
    Node* currentRow =NULL;

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++) {
            double value;
            fscanf(fp,"%lf", &value);

            if (value != 0) {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } else {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }
    fclose(fp);
    return head;
}




Node *matmul(Node* A, Node* B, int numRowsA, int numColsB) {
    // Create a new empty linked list for the result
    Node* resultHead = NULL;
    
    // Loop through each row in A
    for (int i = 0; i < numRowsA; i++) {
        // Loop through each column in B
        for (int j = 0; j < numColsB; j++) {
            int dotProduct = 0;
        
            for (Node* currA = A; currA != NULL && currA->row == i; currA = currA->next) {
                for (Node* currB = B; currB != NULL && currB->col == j; currB = currB->next) {
                    if (currA->col == currB->row) {
                        dotProduct += currA->value * currB->value;
                    }
                }
            }
            if (dotProduct != 0 || dotProduct==0) {
                Node* newNode = createNode(dotProduct, i, j);
                if (resultHead == NULL) {
                    resultHead = newNode;
                } else {
                    Node* prev = NULL;
                    Node* currR = resultHead;
                    while (currR != NULL && (currR->row < newNode->row || (currR->row == newNode->row && currR->col < newNode->col))) {
                        prev = currR;
                        currR = currR->next;
                    }
                    if (prev == NULL) {
                        resultHead = newNode;
                    } else {
                        prev->next = newNode;
                    }
                    newNode->next = currR;
                }
            }
        }
    }
    
    
    return resultHead;
}



void print(Node *head) {
    if (head == NULL) {
        printf("%lf\n",0.0);
        return;
    }

    int max_row = head->row;
    int max_col = head->col;

    Node *current = head;
    while (current != NULL) {
        if (current->row > max_row) {
            max_row = current->row;
        }
        if (current->col > max_col) {
            max_col = current->col;
        }
        current = current->next;
    }

    for (int i = 0; i <= max_row; i++) {
        for (int j = 0; j <= max_col; j++) {
            current = head;
            double val;
            while (current != NULL) {
                if (current->row == i && current->col == j) {
                    val = current->value;
                    break;
                }
                current = current->next;
            }
            printf("%lf", val);
        }
        printf("\n");
    }
}


Node *linalg_sub(Node *a, Node *b) {
    Node *result = NULL;

    while (a != NULL && b != NULL) {
        if (a->row < b->row || (a->row == b->row && a->col < b->col)) {
            insert_node(&result, a->row, a->col, a->value);
            a = a->next;
        } else if (a->row == b->row && a->col == b->col) {
            double val = a->value - b->value;
            if (val != 0 || val==0) {
                insert_node(&result, a->row, a->col, val);
            }
            a = a->next;
            b = b->next;
        } else {
            insert_node(&result, b->row, b->col, -b->value);
            b = b->next;
        }
    }

    while (a != NULL) {
        insert_node(&result, a->row, a->col, a->value);
        a = a->next;
    }

    while (b != NULL) {
        insert_node(&result, b->row, b->col, -b->value);
        b = b->next;
    }

   return result;

}


Node *transpose_matrix(Node *head) {
    Node *result = NULL;
    Node *current = head;

    while (current != NULL) {
        insert_node(&result, current->col, current->row, current->value);
        current = current->next;
    }

   return result;
}


            // If the dot product is not 0, create a new node and add it to the matrix


double linalg_norm(Node* head, int numRows, int numCols)
{
    double sumOfSquares = 0;

    // Loop through each column
    for (int j = 0; j < numCols; j++) 
    {
        double colSum = 0;

        // Loop through each element in the column
        Node* current = head;
        while (current != NULL) 
	{
            if (current->col == j) 
	    {
                colSum += pow(current->value, 2);
            }
            current = current->next;
        }

        sumOfSquares += colSum;
    }
    return sqrt(sumOfSquares);
}

void save(char *filename, Node* head, int numRows, int numCols) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* current = head;
        int j = 0;

        // Loop through each column in the current row
        while (current != NULL && current->row == i) {
            // Fill in any missing values with 0
            while (j < current->col) {
                fprintf(fp, "%lf ", 0.0);
                j++;
            }

            // Write the value of the current node to the file
            fprintf(fp, "%lf ", current->value);
            j++;
            current = current->next;
        }

        // Fill in any remaining empty columns with 0
        while (j < numCols) {
            fprintf(fp, "%lf ", 0.0);
            j++;
        }

        // Add a newline character at the end of each row
        fprintf(fp, "\n");
    }

    fclose(fp);
}




Node* mat_val(Node* head, double scalar) {
    // Loop through each node in the linked list
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        // Multiply the value of the node with the scalar
        double result = scalar * curr->value;
        
        curr->value = result;
    }
    
    return head;
}

double degrees(double rad)
{
	double deg;
	deg=rad*(180/M_PI);
	return deg;
}




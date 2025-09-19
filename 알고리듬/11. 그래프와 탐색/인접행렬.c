#define MAX_SIZE 5

static int matrix[MAX_SIZE][MAX_SIZE] = {{ 0, 1, 1, 0, 0 },
                                      { 1, 0, 0, 1, 0 }, 
                                      { 1, 0, 0, 0, 1 },
                                      { 0, 1, 0, 0, 1 },
                                      { 0, 0, 1, 1, 0 }};
                                      
static int DirectionMatrix[MAX_SIZE][MAX_SIZE]
                                   = {{ 0, 1, 1, 0, 0 },
                                      { 0, 0, 0, 1, 0 }, 
                                      { 0, 0, 0, 0, 1 },
                                      { 0, 0, 0, 0, 1 },
                                      { 0, 0, 0, 0, 0 }};
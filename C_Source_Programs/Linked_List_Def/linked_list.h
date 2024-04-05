// Struct declaration
typedef struct Product {

    int code;
    char name[40];
    int amount;
    struct Product *next;

} Product;

// Function prototypes
int update_elem_dif_names(Product *current, char name[], int amount);
int update_elem_same_names(Product *current, int amount);
int insertion_validation(Product **product_list, int code, char name[], int amount);
void insert_at_the_beginning(Product **product_list, int code, char name[], int amount);
void insert_at_the_end(Product **product_list, int code, char name[], int amount);
int validate_code_existence(Product **product_list, int ref_code);
void insert_at_the_middle(Product **product_list, int code, char name[], int amount, int ref_code);
void insert_sorted(Product **product_list, int code, char name[], int amount);
void remove_element(Product **product_list, int code, int amount);
Product* search_element(Product **product_list, int code);
void print_list(Product *product_list);
void free_memory(Product *product_list);
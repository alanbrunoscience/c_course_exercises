// Struct declaration
typedef struct Product {

    int code;
    char name[40];
    int quantity;
    struct Product *next;

} Product;

// Function prototypes
int update_elem_dif_names(Product *current, char name[], int quantity);
int update_elem_same_names(Product *current, int quantity);
int update_existing_item(Product **product_list, int code, char name[], int quantity);
void insert_at_the_beginning(Product **product_list, int code, char name[], int quantity);
void insert_at_the_end(Product **product_list, int code, char name[], int quantity);
int validate_code_existence(Product **product_list, int ref_code);
void insert_at_the_middle(Product **product_list, int code, char name[], int quantity, int ref_code);
void insert_sorted(Product **product_list, int code, char name[], int quantity);
void remove_element(Product **product_list, int code, int quantity);
Product* search_element(Product **product_list, int code);
void print_list(Product *product_list);
void free_memory(Product *product_list);
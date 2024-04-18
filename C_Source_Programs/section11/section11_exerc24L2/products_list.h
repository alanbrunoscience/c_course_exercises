// Structs declaration
typedef struct Available_prod {

    int code;
    char name[40];
    int quantity;
    struct Available_prod *next;

} Available_prod;

typedef struct Unavailable_prod {

    int code;
    char name[40];
    int quantity;
    struct Unavailable_prod *next;

} Unavailable_prod;

// Function prototypes
int check_item_existence_av_prod_list(Available_prod **av_prod_list, int code, char name[], int quantity);
int update_available_item_diff_name(Available_prod *aux_av, char name[], int quantity);
int update_available_item_same_name(Available_prod *aux_av, int quantity);
int check_item_existence_unav_prod_list(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, int code, char name[], int quantity);
int update_unavailable_item_diff_name(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, Unavailable_prod *aux_unav, char name[], int quantity);
int update_unavailable_item_same_name(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, Unavailable_prod *aux_unav, char name[], int quantity);
void insert_in_available_prod_list(Available_prod **av_prod_list, int code, char name[], int quantity);
void remove_from_unavailable_list(Unavailable_prod **unav_prod_list, int code);
void remove_from_available_listI(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, int code, int quantity);
void remove_from_available_listII(Available_prod **av_prod_list, int code);
void remove_av_prod_permanently(Available_prod **av_prod_list, int code);
void remove_unav_prod_permanently(Unavailable_prod **unav_prod_list, int code);
void insert_in_unavailable_prod_list(Unavailable_prod **unav_prod_list, int code, char name[], int quantity);
Available_prod* search_available_product(Available_prod **av_prod_list, int code);
Unavailable_prod* search_unavailable_product(Unavailable_prod **unav_prod_list, int code);
int validate_code_existence_av_list(Available_prod **av_prod_list, int code);
int validate_code_existence_unav_list(Unavailable_prod **unav_prod_list, int code);
void generate_available_prod_report(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_av_prod[]);
void generate_unavailable_prod_report(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_unav_prod[]);
void print_av_prod_list(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_av_prod[]);
void print_unav_prod_list(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_unav_prod[]);
void free_memory(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list);
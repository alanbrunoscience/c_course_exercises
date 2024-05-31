// Struct declaration
typedef struct Node {

    int phone_number[11];
    // int year_of_birth;
    // int month_of_birth;
    // int day_of_birth;
    struct Node* next;
    wchar_t full_name[];
    
} Node;

// Functions prototype
void initialize_lists(Node* contact_list[]);
void format_name_variable(wchar_t name[], size_t* total_length);
void create_full_name_variable(wchar_t** full_name, size_t total_length, wchar_t first_name[], wchar_t last_name[]);
int validate_phone_number(wchar_t phone_number[]);
int validate_leap_year(int year_of_birth);
int validate_day_of_birth(int is_leap_year, int month_of_birth, int day_of_birth);
int get_index(wchar_t full_name[]);
void insert_contact(Node** head, wchar_t* full_name);
Node* create_node(wchar_t* full_name);
void print_list(Node* contact_list[]);
void free_list(Node* head);
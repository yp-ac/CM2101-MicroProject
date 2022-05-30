#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32  
// If the machine is windows then import windows lib for sleep()
#include <Windows.h>
#else  
// else import the unistd lib for sleep()
#include <unistd.h>
#endif

#define N_ITEMS 5

enum Items {
    BREAD = 0,
    FLAVOR = 1,
    CHEESE = 2,
    VEGGIES = 3,
    SAUCE = 4
};

const char* options[N_ITEMS][5] = {
    { "Wheat Bread", "Multi Grain Bread", "Italian Bread", "Italian Herg and Cheese Bread", "Flatbread" }, // Bread
    { "Hara-Bhara Kabab", "aloo Patty", "Mexican Patty", "Paneer Tikka", "Tandoori Tofu" }, // Flavor
    { "Mozzarella Cheese", "Cheddar Cheese", "Peppar Jack Cheese", "Feta Cheese", "Swiss CHeese" }, // Cheese
    { "Cucumber", "Red onion", "Lettuce", "Spinach", "Tomatoes" }, // Veggies
    { "Barbecue Sauce", "Honey Mustard Sauce", "Veg Mayonnaise Sauce", "Mustard Sauce", "Sweet Onion Sauce" } // Sauce
};

const int prices[N_ITEMS][5] = {
    {20, 30, 35, 40, 35},
    {70, 45, 50, 65, 55},
    {45, 40, 50, 45, 55},
    {25, 20, 25, 25, 20},
    {35, 30, 25, 35, 30}
};

const char* line = "_____________________________________________________";

void loading_dots();
void display_logo();

void selection_choice(int* p, char* category, enum Items cat_num);
void prepare_cat(int* storage, enum Items cat, char* category);
void combo_price_func(enum Items cat, int* storage, int* invoice_arr, int offset);

int main()
{
    int choice[5][3] = {-1};
    char* names[] = {"Bread", "Flavour", "Cheese", "Veggies", "Sauce"};
    int offsets[5] = {0, 1, 2, 3, 6}; // offset for the category to live in the `combo_price` array.
    
    int combo_price[9] = {0};
    
    int invoice_combo = 0;
    int invoice_service = 60;
    int invoice_tax;

    enum Items item; // Iterable
    int i;

    display_logo();
    puts("[*] Select Your Combo");
    
    for ( item = BREAD; item <= SAUCE; item++ )
        selection_choice(choice[item], names[item], item);

    puts("\nYour Combo has been Selected successfully!!\n");
    puts(line);
    printf("Preparing your combo");
    loading_dots();
    printf("\n");

    for ( item = BREAD; item <= SAUCE; item++ )
        prepare_cat(choice[item], item, names[item]);

    puts("\n_____________________________________________________\n");
    puts("                  Enjoy Your Combo                     ");
    puts("_____________________________________________________\n");
    puts("                       Invoice                         ");
    puts("_____________________________________________________\n");
    puts("                       Subway                          ");
    puts("                  Central Mall, Pune                   ");
    puts("_____________________________________________________\n");
    puts("                  Make your own Sub                    ");
    puts("_____________________________________________________\n\n");

    for ( item = BREAD; item <= SAUCE; item++ )
        combo_price_func(item, choice[item], combo_price, offsets[item]);

    for ( i = 0; i < 9; i++ )
        invoice_combo += combo_price[i];

    invoice_tax = ((invoice_combo + invoice_service) * 9)/100;

    printf("Sr.     Item          Cost\n\n");
    printf("[1]  Combo Value       %d\n", invoice_combo);
    printf("[2]  Service Charges   %d\n", invoice_service);
    printf("[3]  Taxes             %d\n", invoice_tax);
    puts("\n\n");
    puts("_____________________________________________________\n");
    printf("Total Amount : %d\n", (invoice_combo + invoice_service + invoice_tax));
    puts("_____________________________________________________");
    puts("_____________________________________________________\n");
    puts("         Thank You for visting and shopping!!         ");
    puts("                     Subway                          ");
    puts("                    Eat Fresh                        ");
    puts("\n_____________________________________________________");
    puts("             Created by Yash Thakare                    ");

    return EXIT_SUCCESS;
}

void loading_dots()
{
    int i;
    for ( i = 0; i < 3; i++ )
    {
        fflush(stdout);

        #ifndef DEBUG
            sleep(1);
        #endif

        printf(".");
    }
}

void display_logo()
{
    const char* logo[5] = {
        "  ||||||  ||  ||  ||||||  ||   ||  ||||||  ||   ||",
        "  ||      ||  ||  ||  ||  ||   ||  ||  ||   || || ",
        "  ||||||  ||  ||  |||||   ||   ||  ||||||     ||  ",
        "      ||  ||  ||  ||  ||  || | ||  ||  ||     ||  ",
        "  ||||||  ||||||  ||||||  ||| |||  ||  ||     ||  "
    };

    puts(line);
    for ( int i = 0; i < 5; i++ )
    {
        puts(logo[i]);
        fflush(stdout);

        #ifndef DEBUG  // use -DDEBUG flag for gcc/clang to swith between debug and non-debug mode
            sleep(1);
        #endif
    }
    puts(line);
}

void selection_choice(int* storage, char* category, enum Items cat_num)
{
    int i, j, choice, cond = 1;
    puts(line);
    printf("Options for %s : \n", category);
    puts(line);

    if ( ( cat_num == VEGGIES ) || ( cat_num == SAUCE ))
    {
        printf("* Not Needed\n");
        cond = 3;
    }

    puts("[0] Exit");
    for ( i = 0; i < N_ITEMS; i++ )  // Print the Options
        printf("[%d] %s \n", i + 1, options[cat_num][i]);

    for ( i = 0; i < cond; i++ )
    {
        for ( j = 0; j <= 5; j++ )
        {
            printf("Please enter your choice code for %s: ", category);
            scanf("%d", &choice);
            if ( j == 4 )
            {
                printf("Too many Failed attempts");
                loading_dots();
                puts("\nTry Again");
                puts(line);
                puts("              Thank You for visting                  ");
                exit(-1);
            }
            else if (choice < 0 && choice > 5)
            {
                puts("[-] Invalid option, please try again");
                continue;
            }
            
            if (choice == 0)
            {
                if ((cat_num != VEGGIES) && (cat_num != SAUCE))
                {    
                    printf("This is a mandatory option, please try again");
                    puts(line);
                    continue;
                }
                else 
                {
                    i = 3;
                    break; 
                }
            }
         
            choice--; // to align with C programming language indexing
            printf("%s selected\n", options[cat_num][choice]);
            storage[i] = choice;
            puts(line);
            break;
        } 

        if ((cat_num != VEGGIES) && (cat_num != SAUCE))
            break;
    }
}

void prepare_cat(int* storage, enum Items cat, char* category)
{
    int i, cond = 1, choice;

    if (cat == VEGGIES || cat == SAUCE)
        cond = 3;

    for ( i = 0; i < cond; i++ )
    {
        choice = storage[i];

        if (choice == -1)
            break;

        printf("\nAdding %s", options[cat][choice]);
        loading_dots();
    }
}

void combo_price_func(enum Items cat, int* storage, int* invoice_arr, int offset)
{
    int i, cond = 1, choice;

    if (cat == VEGGIES || cat == SAUCE)
        cond = 3;
    
    for ( i = 0; i < cond; i++ )
    {
        choice = storage[i];

        if (choice == -1)
            break;

        invoice_arr[i + offset] = prices[cat][choice];
    }
}

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32  
// If the machine is windows then import windows lib for sleep()
#   include <Windows.h>
#else  
// else import the unistd lib for sleep()
#   include <unistd.h>
#endif

#define N_ITEMS 5
#define line "---------------------------------------------------------"

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


void loading(char*);
void display_logo(unsigned int);
void wait(unsigned int);
void clrscr();

void selection_choice(int* p, char* category, enum Items cat_num);
void prepare_cat(int* storage, enum Items cat, char* category);
void combo_price_func(enum Items cat, int* storage, int* invoice_arr, int offset);

int main()
{
    int choice[5][3] = {{-1}};
    char* names[] = {"Bread", "Flavour", "Cheese", "Veggies", "Sauce"};
    int offsets[5] = {0, 1, 2, 3, 6}; // offset for the category to live in the `combo_price` array.
    
    int combo_price[9] = {0};
    
    int invoice_combo = 0;
    int invoice_service = 60;
    int invoice_tax;

    enum Items item; // Iterable
    int i;

    clrscr();

    display_logo(1);
    puts("[*] Select Your Combo");
    
    for ( item = BREAD; item <= SAUCE; item++ )
    {
        selection_choice(choice[item], names[item], item);
        loading("*");
        clrscr();
    }

    puts("\nYour Combo has been Selected successfully!!\n");
    puts(line);
    printf("Preparing your combo");
    loading(".");
    printf("\n");

    for ( item = BREAD; item <= SAUCE; item++ )
        prepare_cat(choice[item], item, names[item]);

    puts(line);
    puts("                  Enjoy Your Combo                     ");
    puts(line);
    puts("\n                       Invoice                         ");
    puts(line);
    puts("\n                       Subway                          ");
    puts("                    GPP Mall, Pune                     ");
    puts(line);
    puts("\n                  Make your own Sub                    ");
    puts(line);
    puts("\n");

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
    puts(line);
    printf("\nTotal Amount : %d\n", (invoice_combo + invoice_service + invoice_tax));
    puts(line);
    puts(line);
    puts("\n         Thank You for visting and shopping!!         ");
    puts("                     Subway                          ");
    puts("                    Eat Fresh                        \n");
    puts(line);
    puts("             Created by: Group 1            ");

    return EXIT_SUCCESS;
}

void wait(unsigned int __seconds)
{
    #ifndef DEBUG  // use -DDEBUG flag for gcc/clang to swith between debug and non-debug mode
    #   ifdef _WIN32
            Sleep(__seconds);
    #   else
            sleep(__seconds);
    #   endif
    #endif
}

void clrscr()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void loading(char* animation_str)
{
    int i;
    for ( i = 0; i < 3; i++ )
    {
        fflush(stdout);
        wait(1);

        printf("%s", animation_str);
    }
}

void display_logo(unsigned int wait_time)
{
    const char* logo[6] = {
        "\x1B[33m __  __ _               \x1B[32m ____            _           _   ",
        "\x1B[33m|  \\/  (_) ___ _ __ ___ \x1B[32m|  _ \\ _ __ ___ (_) ___  ___| |_ ",
        "\x1B[33m| |\\/| | |/ __| '__/ _ \\\x1B[32m| |_) | '__/ _ \\| |/ _ \\/ __| __|",
        "\x1B[33m| |  | | | (__| | | (_) \x1B[32m|  __/| | | (_) | |  __/ (__| |_ ",
        "\x1B[33m|_|  |_|_|\\___|_|  \\___/\x1B[32m|_|   |_|  \\___// |\\___|\\___|\\__|",
        "                                      |__/                 \x1B[0m"
    };

    puts(line);
    for ( int i = 0; i < 6; i++ )
    {
        puts(logo[i]);
        if (wait_time > 0)
        {
            fflush(stdout);
            wait(wait_time);
        }
    }
    puts(line);
}

void selection_choice(int* storage, char* category, enum Items cat_num)
{
    int i, j, choice, cond = 1;
    puts(line);
    printf("Options for %s : \n", category);
    // puts(line);

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
            printf("\nPlease enter your choice code for %s: ", category);
            scanf(" %d", &choice);

            if ( j == 4 )
            {
                printf("\nToo many Failed attempts");
                loading(".");
                puts("\nTry Again");
                puts(line);
                puts("              Thank You for visting                  ");
                exit(-1);
            }
            else if (choice < 0 || choice > 5)
            {
                puts("\x1B[31m[-] Invalid option, please try again\x1B[0m");
                continue;
            }
            
            if (choice == 0)
            {
                if ((cat_num != VEGGIES) && (cat_num != SAUCE))
                {    
                    puts("This is a mandatory option, please try again");
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
            printf("\x1B[34m%s selected\x1B[0m\n", options[cat_num][choice]);
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

        printf("\n\x1B[32mAdding %s\x1B[0m", options[cat][choice]);
        loading(".");
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

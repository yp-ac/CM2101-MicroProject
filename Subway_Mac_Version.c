/*
    @author : Yash Thakare
    @topic: Making a Subway Combo Selector
*/

#include <stdio.h>
#include <stdlib.h>
//#include <Windows.h>
#include <unistd.h>

#define BREAD 1
#define FLAVOR 2
#define CHEESE 3
#define VEGGIES 4
#define SAUCE 5

void dot(void);
void selection_choice(int* p, int cat_num, char* category, char* a, char* b, char* c, char* d, char* e);
void preparation(int* p, int cat_num, char* category, char* a, char* b, char* c, char* d, char* e);
void combo_price_func(int cat_num, int* category_options, int* ptr_cat_arr, int* ptr_combo_arr, int combo_arr_num);

int main(void)
{   
    puts("_____________________________________________________\n");
    puts("  ||||||  ||  ||  ||||||  ||   ||  ||||||  ||   ||"); fflush(stdout); sleep(1);
    puts("  ||      ||  ||  ||  ||  ||   ||  ||  ||   || || "); fflush(stdout); sleep(1);
    puts("  ||||||  ||  ||  |||||   ||   ||  ||||||     ||   "); fflush(stdout); sleep(1);
    puts("      ||  ||  ||  ||  ||  || | ||  ||  ||     ||   "); fflush(stdout); sleep(1);
    puts("  ||||||  ||||||  ||||||  ||| |||  ||  ||     ||  "); fflush(stdout); sleep(1);
    puts("\n_____________________________________________________\n");
    puts("                 Select Your Combo                   ");
    puts("\n_____________________________________________________");   
    int c_bread[3] = {0, 0, 0};
    int c_flavor[3] = {0, 0, 0};
    int c_cheese[3] = {0, 0, 0};
    int c_veggies[3] = {0, 0, 0};
    int c_sauce[3] = {0, 0, 0};

    int bread_prices[5] = {20, 30, 35, 40, 35};
    int flavor_prices[5] = {70, 45, 50, 65, 55};
    int cheese_prices[5] = {45, 40, 50, 45, 55};
    int veggies_prices[5] = {25, 20, 25, 25, 20};
    int sauce_prices[5] = {35, 30, 25, 35, 30};

    int combo_price[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int invoice_combo = 0;
    int invoice_service = 60;
    int invoice_tax;


    selection_choice(&c_bread[0], BREAD, "Bread", "Wheat Bread", "Multi Grain Bread", "Italian Bread", "Italian Herb and Cheese Bread", "Flatbread");
    selection_choice(&c_flavor[0], FLAVOR, "Flavor", "Hara-Bhara Kabab", "Aloo Patty", "Mexican Patty", "Paneer Tikka", "Tandoori Tofu");
    selection_choice(&c_cheese[0], CHEESE, "Cheese", "Mozzarella Cheese", "Cheddar Cheese", "Pepper Jack Cheese", "Feta Cheese", "Swiss Cheese");
    selection_choice(&c_veggies[0], VEGGIES, "Veggies", "Cucumber", "Red onion", "Lettuce", "Spinach", "Tomatoes");
    selection_choice(&c_sauce[0], SAUCE, "Sauce", "Barbecue Sauce", "Honey Mustard Sauce", "Veg Mayonnaise Sauce", "Mustard Sauce", "Sweet Onion Sauce");

    puts("\nYour Combo has been selected successfully!!\n");
    puts("_____________________________________________________\n");
    printf("Preparing your combo");
    dot();
    printf("\n");

    preparation(&c_bread[0], BREAD, "Bread", "Wheat Bread", "Multi Grain Bread", "Italian Bread", "Italian Herb and Cheese Bread", "Flatbread");
    preparation(&c_flavor[0], FLAVOR, "Flavor", "Hara-Bhara Kabab", "Aloo Patty", "Mexican Patty", "Paneer Tikka", "Tandoori Tofu");
    preparation(&c_cheese[0], CHEESE, "Cheese", "Mozzarella Cheese", "Cheddar Cheese", "Pepper Jack Cheese", "Feta Cheese", "Swiss Cheese");
    preparation(&c_veggies[0], VEGGIES, "Veggies", "Cucumber", "Red onion", "Lettuce", "Spinach", "Tomatoes");
    preparation(&c_sauce[0], SAUCE, "Sauce", "Barbecue Sauce", "Honey Mustard Sauce", "Veg Mayonnaise Sauce", "Mustard Sauce", "Sweet Onion Sauce");

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
    combo_price_func(BREAD, &c_bread[0], &bread_prices[0], &combo_price[0], 0);
    combo_price_func(FLAVOR, &c_flavor[0], &flavor_prices[0], &combo_price[0], 1);
    combo_price_func(CHEESE, &c_cheese[0], &cheese_prices[0], &combo_price[0], 2);
    combo_price_func(VEGGIES, &c_veggies[0], &veggies_prices[0], &combo_price[0], 3);
    combo_price_func(SAUCE, &c_sauce[0], &sauce_prices[0], &combo_price[0], 6);

    int i;
    int sum = 0;
    
    for(i = 0; i < 9; i++)
    {
        sum = combo_price[i] + sum;
    }
    
    invoice_combo = sum;

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

    return(0);
}

void selection_choice(int* p, int cat_num, char* category, char* a, char* b, char* c, char* d, char* e)
{
    int i;
    int j;
    int choice;
    int cond = 0;
    puts("_____________________________________________________\n");
    printf("Options for %s : \n\n", category);
    puts("_____________________________________________________\n");
    if((cat_num == VEGGIES) || (cat_num == SAUCE))
    {
        printf("[0] Not Needed \n");
    }
    printf("[1] %s \n[2] %s \n[3] %s \n[4] %s \n[5] %s\n\n", a, b, c, d, e);
    puts("_____________________________________________________\n");

    if((cat_num == VEGGIES) || (cat_num == SAUCE))
    {
        cond = 2;
    }

    for(i = 0; i <= cond; i++)
    {   
        for(j = 0; j <= 5; j ++)
        {
            printf("Please enter your choice code for %s: ", category);
            scanf("%d", &choice);
            if(choice >= 0 && choice < 6)
            {
                switch(choice)
                {   
                    case 0:
                        if((cat_num == VEGGIES) || (cat_num == SAUCE))
                        {
                            *(p + i) = 0;
                        }
                        else
                        {
                            printf("Was a mandatory option");
                            dot();
                            puts("\nTry again");
                            puts("_____________________________________________________");
                            puts("              Thank You for visting                  ");
                            puts("                     Subway                          ");
                            puts("                    Eat Fresh                        ");
                            exit(-1);
                        }
                        break;
                    case 1: 
                        printf("%s selected\n", a);
                        *(p + i) = 1;
                        break;
                    case 2: 
                        printf("%s selected\n", b);
                        *(p + i) = 2;
                        break;
                    case 3: 
                        printf("%s selected\n", c);
                        *(p + i) = 3;
                        break;
                    case 4: 
                        printf("%s selected\n", d);
                        *(p + i) = 4;
                        break;
                    case 5: 
                        printf("%s selected\n", e);
                        *(p + i) = 5;
                        break;
                }
                puts("_____________________________________________________");
                break;
            }

            else if(j == 4)
            {
                printf("Too many failed attempts");
                dot();
                printf("\nTry again\n");
                puts("_____________________________________________________");
                puts("              Thank You for visting                  ");
                puts("                     Subway                          ");
                puts("                    Eat Fresh                        ");
                exit(-1);
            }

        }
        if((cat_num != VEGGIES) && (cat_num != SAUCE))
        {
            break;
        }
    }
}

void preparation(int* p, int cat_num, char* category, char* a, char* b, char* c, char* d, char* e)
{   
    int i;
    int cond = 1;

    if((cat_num == VEGGIES) || (cat_num == SAUCE))
    {
        cond = 3;
    }

    for(i = 0; i < cond; i++)
    {
        switch(*(p + i))
        {   
            case 0:
                break;
            case 1: 
                printf("\nAdding %s", a);
                dot();
                break;
            case 2: 
                printf("\nAdding %s", b);
                dot();
                break;
            case 3: 
                printf("\nAdding %s", c);
                dot();
                break;
            case 4: 
                printf("\nAdding %s", d);
                dot();
                break;
            case 5: 
                printf("\nAdding %s", e);
                dot();
                break;
        }
    }
}

void combo_price_func(int cat_num, int* category_options, int* ptr_cat_arr, int* ptr_combo_arr, int combo_arr_num)
{
    int i;
    int cond = 1;

    if((cat_num == VEGGIES) || (cat_num == SAUCE))
    {
        cond = 3;
    }

    for(i = 0; i < cond; i++)
    {
        switch(*(category_options + i))
        {   
            case 0:
                break;
            case 1: 
                *(ptr_combo_arr + i + combo_arr_num) = *(ptr_cat_arr + 0);
                break;
            case 2: 
                *(ptr_combo_arr + i + combo_arr_num) = *(ptr_cat_arr + 1);
                break;
            case 3: 
                *(ptr_combo_arr + i + combo_arr_num) = *(ptr_cat_arr + 2);
                break;
            case 4: 
                *(ptr_combo_arr + i + combo_arr_num) = *(ptr_cat_arr + 3);
                break;
            case 5: 
                *(ptr_combo_arr + i + combo_arr_num) = *(ptr_cat_arr + 4);
                break;
        }
    }
}

void dot(void)
{   
    int i;
    for (i = 0; i <= 2; i++)
    {
        fflush(stdout);
        sleep (1);
        printf(".");
    }
    return;
}















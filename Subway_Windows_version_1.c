/*
    @author : Yash Thakare
    @topic: Making a Subway Combo Selector
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void dot(void);
int selection_choice(char* a, char* b, char* c, char* d, char* e);
void preparation(int choice, char* category, char* a, char* b, char* c, char* d, char* e);

int main(void)
{   
    puts("_____________________________________________________\n");
    puts("  ||||||  ||  ||  ||||||  ||   ||  ||||||  ||   ||"); Sleep(500);
    puts("  ||      ||  ||  ||  ||  ||   ||  ||  ||   || || "); Sleep(500);
    puts("  ||||||  ||  ||  |||||   ||   ||  ||||||     ||   "); Sleep(500);
    puts("      ||  ||  ||  ||  ||  || | ||  ||  ||     ||   "); Sleep(500);
    puts("  ||||||  ||||||  ||||||  ||| |||  ||  ||     ||  "); Sleep(500);
    puts("\n_____________________________________________________\n");
    puts("                 Select Your Combo                   ");
    puts("\n_____________________________________________________");   
    int c_bread, c_flavor, c_cheese, c_veggies, c_sauce;
    c_bread = selection_choice("Bread", "Wheat Bread", "Multi Grain Bread", "Italian Bread", "Italian Herb and Cheese Bread", "Flatbread");
    c_flavor = selection_choice("Flavor", "Hara-Bhara Kabab", "Aloo Patty", "Mexican Patty", "Paneer Tikka", "Tandoori Tofu");
    c_cheese = selection_choice("Cheese", "Mozzarella Cheese", "Cheddar Cheese", "Pepper Jack Cheese", "Feta Cheese", "Swiss Cheese");
    c_veggies = selection_choice("Veggies", "Cucumber", "Red onion", "Lettuce", "Spinach", "Tomatoes");
    c_sauce = selection_choice("Sauce", "Barbecue Sauce", "Honey Mustard Sauce", "Veg Mayonnaise Sauce", "Mustard Sauce", "Sweet Onion Sauce");

    puts("\nYour Combo has been selected successfully!!\n");
    puts("_____________________________________________________\n");
    printf("Preparing your combo");
    dot();
    printf("\n");

    preparation(c_bread, "Bread", "Wheat Bread", "Multi Grain Bread", "Italian Bread", "Italian Herb and Cheese Bread", "Flatbread");
    preparation(c_flavor, "Flavor", "Hara-Bhara Kabab", "Aloo Patty", "Mexican Patty", "Paneer Tikka", "Tandoori Tofu");
    preparation(c_cheese, "Cheese", "Mozzarella Cheese", "Cheddar Cheese", "Pepper Jack Cheese", "Feta Cheese", "Swiss Cheese");
    preparation(c_veggies, "Veggies", "Cucumber", "Red onion", "Lettuce", "Spinach", "Tomatoes");
    preparation(c_sauce, "Sauce", "Barbecue Sauce", "Honey Mustard Sauce", "Veg Mayonnaise Sauce", "Mustard Sauce", "Sweet Onion Sauce");

    puts("\n_____________________________________________________\n");
    puts("                  Enjoy Your Combo                     ");
    puts("_____________________________________________________\n");
    puts("         Thank You for visting and shopping!!         ");
    puts("                     Subway                          ");
    puts("                    Eat Fresh                        ");
    puts("\n_____________________________________________________");
    puts("             Created by Yash Thakare                    ");

    return(0);
}

int selection_choice(char* category, char* a, char* b, char* c, char* d, char* e)
{
    int i;
    int choice;
    puts("_____________________________________________________\n");
    printf("Options for %s : \n\n", category);
    puts("_____________________________________________________\n");
    printf("[1] %s \n[2] %s \n[3] %s \n[4] %s \n[5] %s\n\n", a, b, c, d, e);
    puts("_____________________________________________________\n");

    for(i = 0; i <= 5; i++)
    {
        printf("Please enter your choice code for %s: ", category);
        scanf("%d", &choice);
        if(choice > 0 && choice < 6)
        {
            switch(choice)
            {
                case 1: 
                    printf("%s selected\n", a);
                    choice = 1;
                    break;
                case 2: 
                    printf("%s selected\n", b);
                    choice = 2;
                    break;
                case 3: 
                    printf("%s selected\n", c);
                    choice = 3;
                    break;
                case 4: 
                    printf("%s selected\n", d);
                    choice = 4;
                    break;
                case 5: 
                    printf("%s selected\n", e);
                    choice = 5;
                    break;
            }
            puts("_____________________________________________________");
            break;
        }

        else if(i == 4)
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

    return(choice);
}

void preparation(int choice, char* category, char* a, char* b, char* c, char* d, char* e)
{   
    switch(choice)
        {
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

void dot(void)
{   
    int i;
    for (i = 0; i <= 2; i++)
    {
        Sleep(1000);
        printf(".");
    }
    return;
}














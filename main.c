#include <stdio.h>
#include <stdlib.h>
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define MAGENTA "\x1b[35m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"

/* The destination state is accessed by an input value of either(1 or 0) plus the current state:
 The Output depends on the current state. A destination state, right after it has been accessed, it becomes
 a current state, so it's output value will be the emoji that was assigned to it.
 EXAMPLE: The current state is S2(10), it's output is ANGRY FACE. But you want smiley face, you need an input of
 (1) to access your destination state S3(11) and has an output of smiley face. Your current state(x1=1, x2=0)+input(x3=1) will
 get you to S3(11) or smiley face. The output is: S3(x1=1, x2=1). So the equation for output is, Y=x1*x2, so your destination
 state is now a current state,and the output is smiley face.
*/

int main()
{

// defined equations here to access through out my code
#define get_state_value1() ((x3[i] * x2[i]) + (x1[i] * (!(x2[i]))))
#define get_state_value2() (((!(x2[i]) * (x3[i] * !(x1[i]) + (!(x3[i]) * x1[i])))))

    int x3[1]; //{0, 1, 0, 1, 0, 1, 0, 1};
    int x2[1]; //{0, 0, 1, 1, 0, 0, 1, 1};
    int x1[1]; //{0, 0, 0, 0, 1, 1, 1, 1};
    int i, next_state_value1, next_state_value2;

    char *y;
   

    // The program will first calculate the next state based on these current_state_values and the input via the above equations
    // Initial State is the Normal_Mood(state)
    x1[i] = 0;
    x2[i] = 0;
    printf("x3: ");
    scanf("%d,%s", &x3[i], y);
    if (x3[i]!=0 & x3[i]!=1)
    {
        printf("wrong input, please compile the program again\n");
        exit(0);
    }
    next_state_value1 = get_state_value1();
    next_state_value2 = get_state_value2();

    if (next_state_value1 == 0 && next_state_value2 == 1)
        goto Sad_Mood;
    if (next_state_value1 == 0 && next_state_value2 == 0)
        goto Normal_Mood;

//defining label for goto statement directions
Happy_Mood:
    y = (YELLOW "HAPPINESS IS THE BEST MAKEUP!!\n \U0001F604\n"); // smiley face
    printf("\n%s\n", y);

    x1[i] = 1;
    x2[i] = 1;
    printf("x3: ");
    scanf("%d,%s", &x3[i], y);
    if (x3[i] !=0 & x3[i] != 1)
    {
        printf("wrong input, please compile the program again\n");
        exit(0);
    }
    next_state_value1 = get_state_value1();
    next_state_value2 = get_state_value2();

    if (next_state_value1 == 1 && next_state_value2 == 0)
        goto Angry_Mood;
    else if (next_state_value1 == 0 && next_state_value2 == 0)
        goto Normal_Mood;

Normal_Mood:
    y = (MAGENTA "Neutral Mood! Hope your mood improves\n \U0001F610\n"); // normal face

    printf("\n%s\n", y);

    x1[i] = 0;
    x2[i] = 0;
    printf("x3: ");
    scanf("%d,%s", &x3[i], y);
    if (x3[i] != 0 & x3[i] != 1)
    {
        printf("wrong input, please compile the program again\n");
        exit(0);
    }
    next_state_value1 = get_state_value1();
    next_state_value2 = get_state_value2();
    if (next_state_value1 == 0 && next_state_value2 == 0)
        goto Normal_Mood;
    if (next_state_value1 == 0 && next_state_value2 == 1)
        goto Sad_Mood;

Angry_Mood:
    y = (RED "ANGER IS JUST ONE LETTER SHORT OF DANGER\n \U0001F621\n"); // angry face
    printf("\n%s\n", y);

    x1[i] = 1;
    x2[i] = 0;
    printf("x3: ");
    scanf("%d,%s", &x3[i], y);
    if (x3[i] != 0 & x3[i] != 1)
    {
        printf("wrong input, please compile the program again\n");
        exit(0);
    }
    next_state_value1 = get_state_value1();
    next_state_value2 = get_state_value2();

    if (next_state_value1 == 1 && next_state_value2 == 0)
        goto Angry_Mood;
    if (next_state_value1 == 1 && next_state_value2 == 1)
        goto Happy_Mood;

Sad_Mood:
    y = (BLUE "'I SAY I DON'T KNOW EVERYTHING WHEN I'M IN A BAD MOOD'\n \U0001F625\n"); // sad face
    printf("\n%s\n", y);

    x1[i] = 0;
    x2[i] = 1;
    printf("x3: ");
    scanf("%d,%s", &x3[i], y);
    if (x3[i] != 0 & x3[i] != 1)
    {
        printf("wrong input, please compile the program again\n");
        exit(0);
    }
    next_state_value1 = get_state_value1();
    next_state_value2 = get_state_value2();

    if (next_state_value1 == 0 && next_state_value2 == 0)
        goto Normal_Mood;
    if (next_state_value1 == 1 && next_state_value2 == 0)
        goto Angry_Mood;
}
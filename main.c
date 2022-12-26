#include <stdio.h>
#include <stdlib.h>
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define MAGENTA  "\x1b[35m"
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

    int x3[1]; //={0, 1, 0, 1, 0, 1, 0, 1};
    int x2[1]; //={0, 0, 1, 1, 0, 0, 1, 1};
    int x1[1]; //={0, 0, 0, 0, 1, 1, 1, 1};
    int i, next_state_value1, next_state_value2;
    char *y;
    printf(CYAN "Enter x1(current_mood_state_value1): ");
    scanf(" %d, %s\n", &x1[i], y);
    printf(CYAN "current_mood_state_value2): ");
    scanf(" %d,%s\n", &x2[i], y);
    printf(CYAN "Enter x3(input value to get to your destination state mood): ");
    scanf(" %d, %s\n", &x3[i], y);
    {

        // for (i = 0; i < 8; i++)
        {
            // if(x1[i]==1*x2[i]==1);
            // y=1;

            /* THE FOLLOWING EQUATIONS ARE THE EXACT SAME EQUATIONS(IN THE same FORM) DERIVED FROM THE K-MAP*/
            next_state_value1 = ((x3[i] * x2[i]) + (x1[i] * (!(x2[i]))));
            next_state_value2 = (((!(x2[i]) * (x3[i] * !(x1[i] == 1) + (!(x3[i]) * x1[i])))));

            /*WHEN NEXT STATES VALUES ARE ACCESSED WITH THE INPUT VALUE, THEY BECOME THE CURRENT STATE OR WILL BE REGARDED
            AS CURRENT STATE, SINCE THE Y (OUTPURT ALREADY STORED THE OUTPUTS) AND THE EQUATION FOR OUTPUT IS:  Y(X1*X2), AND IT IS
            REPRESESENT BY THE IF STATEMENT SINCE THE OUTPUT WILL BE AN EMOJI.
            WILL PRINT THE CURRENT STATES'S OUTPUT.*/

            /*Outout Equation: y=(x1*x2), so in this case, we want the output to be emojis, so
            we treate the x1 and x2 as values so the program knows the current state, and output the corresponing
            output*/
            if (next_state_value1 == 1 && next_state_value2 == 1)
            {
                y = (YELLOW"HAPPINESS IS THE BEST MAKEUP!!\n \U0001F604\n"); // smiley face
            }
            else if (next_state_value1 == 1 && next_state_value2 == 0)
            {
                y = (RED "ANGER IS JUST ONE LETTER SHORT OF DANGER\n \U0001F621\n"); // angry face
            }
            else if (next_state_value1 == 0 && next_state_value2 == 0)
            {
                y = (MAGENTA"Neutral Mood! Hope your mood improves\n \U0001F610\n"); // normal face
            }
            else if (next_state_value1 == 0 && next_state_value2 == 1)
            {
                y = (BLUE"'I SAY I DON'T KNOW EVERYTHING WHEN I'M IN A BAD MOOD'\n \U0001F625\n"); // sad face
            }

            printf("\n%s\n", y);
        }
    }
}

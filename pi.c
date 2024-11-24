
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
This program will simulate points within a square containing a circle
We will then display the probability in terms of pi for the points within the circle

1. We first ask for the user's input for a seed number, then number of iterations
2. We simulate the points by generating random numbers that act as points
    - We check if the point is within the circle by using its hypotenuse
        1. if so, we increment the number of points in the circle by 1
3. We calculate the probability of the point in the circle in terms of pi
4. We display the value of pi to the user
*/

double findProbInCircle(int pointsInCircle, int iterations) {
    double probInCircle;
    /*
    Finds the probability of the points in the circle in terms of pi
    @pointsInCircle: the number of points that were in the circle
    @iterations: the number of points that we simulated
    @probInCircle: the probability of the point being in the circle
    @returns: probInCircle
    */
    probInCircle = (double) pointsInCircle / (double) iterations;
    probInCircle = probInCircle * 4;

    return probInCircle;
}

double findHyp(double x, double y) {
    double hypotenuse;
    double a, b;
    /*
    Finds the hypotenuse of the x and y points generated
    @x: the point on the x axis
    @y: the point on the y axis
    @hypotenuse: the hypotenuse of the x and y points
    @a, b: the squared values of x and y in the form of pythagorean theorem (sqrt(a^2 + b^2))
    @returns: the length of the hypotenuse
    */
    a = pow(x, 2);
    b = pow(y, 2);
    hypotenuse = sqrt(a + b);

    return hypotenuse;
}

double rand_double(double low, double high) {
    double rand_num;
/*
generate a random double between low and high inclusive
@rand_num will be the random number between low and high
@low: the lowest possible double that can be generated
@high: the highest possible double that can be generated
@returns: a random number between low and high
*/
    rand_num = low + ((double) rand()) / (((double) RAND_MAX / (high - low)));
    return rand_num;
}

int simulatePoints(int iterations) {
    double x, y;
    int pointsInCircle = 0;
/*
simulates the points within range of the square (-1, 1) and counts how many of them are in the circle
@iterations: the number of times we will simulate points
@x, y: the value of the points on the x and y axis
@pointsInCircle: a counter for the number of points that are within the circle
@returns: the number of points that are within the circle
*/
    for (int i=0; i < iterations; i++) {
        x = rand_double(-1.0, 1.0);
        y = rand_double(-1.0, 1.0);
        if (findHyp(x, y) <= 1) {
            pointsInCircle += 1;
        }
    }

    return pointsInCircle;
}

int askSeed() {
/*
Asks for the seed value
@seed: seed value given by user
@returns: seed value
*/
    int seed;

    printf("Enter the seed for the random number generator: ");
    scanf(" %d", &seed);

    return seed;
}

int askIterations() {
    int iterations;
/*
Asks for the number of iterations/points we will simulate
@iterations: number of iterations given by user
@returns: iterations value
*/
    printf("Enter the number of iterations to run: ");
    scanf(" %d", &iterations);

    return iterations;
}

int main() {
    int seed, iterations;
    int pointsInCircle;
    double probInCircle;
/*
1. Asks for input
2. Sets the seed for srand
3. Simulate points in circle
4. Find the probability of number of points in circle in terms of pi
5. Displays the vaue of pi to the user
@seed, iterations: user inputs
@pointsInCircle: number of points that landed in the circle
@probInCircle: probability of point landing in the circle
@returns: 0 for completion
*/

    /* ask for input */
    seed = askSeed();
    iterations = askIterations();

    /* setting the seed for srand */
    srand(seed);

    /* 
    simulate points in circle,
    find probability of number of points in circle
    */
    pointsInCircle = simulatePoints(iterations);
    probInCircle = findProbInCircle(pointsInCircle, iterations);
    
    /* Display the value of pi to the user */
    printf("The value of pi is %.2f.\n", probInCircle);

    return 0;
}
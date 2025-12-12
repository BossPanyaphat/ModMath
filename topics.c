#include <stdio.h>
#include <stdlib.h>
#include "topics.h"
#include "quiz.h"
#include "menu.h"

/* Display Arithmetic lesson */
void displayArithmeticLesson() {
    clearScreen();
    printf("========================================\n");
    printf("   ARITHMETIC LESSON\n");
    printf("========================================\n\n");
    
    printf("ADDITION (+)\n");
    printf("Addition is combining two or more numbers.\n");
    printf("Example: 5 + 3 = 8\n\n");
    
    printf("SUBTRACTION (-)\n");
    printf("Subtraction is finding the difference between numbers.\n");
    printf("Example: 10 - 4 = 6\n\n");
    
    printf("MULTIPLICATION (×)\n");
    printf("Multiplication is repeated addition.\n");
    printf("Example: 4 × 3 = 12 (means 4 + 4 + 4)\n\n");
    
    printf("DIVISION (÷)\n");
    printf("Division is splitting into equal parts.\n");
    printf("Example: 15 ÷ 3 = 5\n\n");
    
    printf("KEY RULES:\n");
    printf("- Addition and Subtraction are inverse operations\n");
    printf("- Multiplication and Division are inverse operations\n");
    printf("- Order of operations: PEMDAS (Parentheses, Exponents,\n");
    printf("  Multiplication/Division, Addition/Subtraction)\n");
    
    printf("\n========================================\n");
}

/* Display Algebra lesson */
void displayAlgebraLesson() {
    clearScreen();
    printf("========================================\n");
    printf("   ALGEBRA LESSON\n");
    printf("========================================\n\n");
    
    printf("VARIABLES\n");
    printf("Variables are letters that represent unknown numbers.\n");
    printf("Example: x, y, z, a, b, c\n\n");
    
    printf("SIMPLE EQUATIONS\n");
    printf("An equation shows that two expressions are equal.\n");
    printf("Example: x + 5 = 12\n");
    printf("Solution: x = 7 (because 7 + 5 = 12)\n\n");
    
    printf("SOLVING EQUATIONS\n");
    printf("To solve for x:\n");
    printf("1. x + 5 = 12\n");
    printf("2. Subtract 5 from both sides: x = 12 - 5\n");
    printf("3. x = 7\n\n");
    
    printf("LINEAR EXPRESSIONS\n");
    printf("Example: 2x + 3 = 11\n");
    printf("1. Subtract 3 from both sides: 2x = 8\n");
    printf("2. Divide both sides by 2: x = 4\n\n");
    
    printf("KEY CONCEPTS:\n");
    printf("- Whatever you do to one side, do to the other\n");
    printf("- Inverse operations help isolate the variable\n");
    printf("- Check your answer by substituting back\n");
    
    printf("\n========================================\n");
}

/* Display Number Theory lesson */
void displayNumberTheoryLesson() {
    clearScreen();
    printf("========================================\n");
    printf("   NUMBER THEORY LESSON\n");
    printf("========================================\n\n");
    
    printf("PRIME NUMBERS\n");
    printf("A prime number has exactly two factors: 1 and itself.\n");
    printf("Examples: 2, 3, 5, 7, 11, 13, 17, 19, 23...\n");
    printf("Note: 1 is NOT a prime number\n\n");
    
    printf("COMPOSITE NUMBERS\n");
    printf("A composite number has more than two factors.\n");
    printf("Examples: 4, 6, 8, 9, 10, 12...\n\n");
    
    printf("GREATEST COMMON DIVISOR (GCD)\n");
    printf("The largest number that divides both numbers evenly.\n");
    printf("Example: GCD(12, 18) = 6\n");
    printf("Factors of 12: 1, 2, 3, 4, 6, 12\n");
    printf("Factors of 18: 1, 2, 3, 6, 9, 18\n");
    printf("Common factors: 1, 2, 3, 6 → Greatest is 6\n\n");
    
    printf("DIVISIBILITY RULES\n");
    printf("- Divisible by 2: Last digit is even (0,2,4,6,8)\n");
    printf("- Divisible by 3: Sum of digits is divisible by 3\n");
    printf("- Divisible by 5: Last digit is 0 or 5\n");
    printf("- Divisible by 10: Last digit is 0\n\n");
    
    printf("EVEN AND ODD NUMBERS\n");
    printf("- Even: divisible by 2 (2, 4, 6, 8...)\n");
    printf("- Odd: not divisible by 2 (1, 3, 5, 7...)\n");
    
    printf("\n========================================\n");
}

/* Launch topic based on choice */
void launchTopic(int choice, const char *username) {
    const char *topicName = NULL;
    int score;
    
    switch (choice) {
        case 1:
            displayArithmeticLesson();
            topicName = "Arithmetic";
            break;
        case 2:
            displayAlgebraLesson();
            topicName = "Algebra";
            break;
        case 3:
            displayNumberTheoryLesson();
            topicName = "Number Theory";
            break;
        default:
            return;
    }
    
    pauseScreen();
    
    /* Start quiz after lesson */
    printf("\n\nReady to take the quiz? Press Enter...");
    getchar();
    
    score = startQuiz(username, topicName);
    
    clearScreen();
    printf("========================================\n");
    printf("   QUIZ COMPLETED!\n");
    printf("========================================\n");
    printf("Your score: %d/5\n", score);
    
    if (score == 5) {
        printf("Perfect! Excellent work!\n");
    } else if (score >= 3) {
        printf("Good job! Keep practicing!\n");
    } else {
        printf("Keep studying and try again!\n");
    }
    
    pauseScreen();
}
/* 
 * Project 1)
 * Purpose: This program can be used as a math tutor for a young student.
 *          It repeatedly allow the user to practice solving math questions untill the user clicks "4" to stop.
 *          When the practice for the user stops, this program generates the report:
 *          (1) the list of questions with correct answers which the user has practiced;
 *          (2) the total number of questions the user has solved;
 *          (3) the total number of mistakes the user has made;
 *          (4) display either "Great job!"(if (2) > (3)) or "You will do better next time..."          (otherwise)
 *          it then quits the program.
 * Author: Aiden Koknat
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "MathOperations.h"
#include "MathReport.h"
                    
using namespace std;
        
int main()
{
    
    int intChoice; // Placeholder while I figure out how to change string to int
    MathReport userReport; // The user report for using Math Tutor program
    string choice; // The user's choice: either answer the question or quit  
    while (intChoice != 4) 
    {

    // Displaying Menu
    cout << "   Math Is Fun! Take a challenge..." << endl;
    cout << "-------------------------------------" << endl;

    cout << "1. Addition problem" << endl;
    cout << "2. Subtraction problem" << endl;
    cout << "3. Multiplication problem" << endl;
    cout << "4. Quit this program" << endl;
    cout << "-------------------------------------" << endl;

    
    cout << "Enter your choice (1-4): ";
    cin >> choice; // Add in to make sure it repeats if an unknown choice is selected.
    cout << "--------------------------" << endl;
    
        while ((choice != "1") && (choice != "2") && (choice != "3") && (choice != "4"))  {
            
        cout << "Invalid Choice! The valid choices are 1, 2, 3, and 4: ";
        cout << "   Math Is Fun! Take a challenge..." << endl;
        cout << "-------------------------------------" << endl;

        cout << "1. Addition problem" << endl;
        cout << "2. Subtraction problem" << endl;
        cout << "3. Multiplication problem" << endl;
        cout << "4. Quit this program" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        }
        intChoice = stoi(choice);
    switch(intChoice) {
        case 1: // Addition Coding (CURRENTLY COPYING LAB 6 AS OF NOW) 
        {

            // Seed the random number generator.
            srand(time(0));
            getline(cin, choice);
                int num1;          // The first random number
                int num2;          // The second random number
                int studentAnswer; // The student's answer
                MathOperations question; // the question for user to solve

                // Generate two random numbers: 
                // The first one is in the range of [1, 100];
                // The second one is in the range of [1 - 9].
                num1 = 1 + rand() % 100;   
                num2 = 1 + rand() % 9;
                question.setOperands(num1, num2);
                question.Addition();
                // Display the problem.
                question.print();
                cout << "Your answer is: ";
                cin  >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear(); // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin  >> studentAnswer;
                    cin.ignore(256, '\n');
                }

                // when the user input is valid
                // check if it is the correct answer
                if (question.checkAnswer(studentAnswer))
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                else
                    cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

                //add the current question and the user answer into the user report
                userReport.insert(question, studentAnswer);

            } break;
        case 2: // Subtraction Coding (CURRENTLY COPING LAB 6 AS OF NOW)
        {
            
            // Seed the random number generator.
            srand(time(0));
                int num1;          // The first random number
                int num2;          // The second random number
                int studentAnswer; // The student's answer
                MathOperations question; // the question for user to solve

                // Generate two random numbers: 
                // The first one is in the range of [1, 100];
                // The second one is in the range of [1 - 9].
                num1 = 1 + rand() % 100;   
                num2 = 1 + rand() % 9;
                question.setOperands(num1, num2);
                question.Subtraction();
                // Display the problem.
                question.print();
                cout << "Your answer is: ";
                cin  >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear(); // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin  >> studentAnswer;
                    cin.ignore(256, '\n');
                }

                // when the user input is valid
                // check if it is the correct answer
                if (question.checkAnswer(studentAnswer))
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                else
                    cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

                //add the current question and the user answer into the user report
                userReport.insert(question, studentAnswer);
            
        } break;
        case 3: // Multiplication Coding (I THINK DONE BUT CHECK)
        {

            // Seed the random number generator.
            srand(time(0));
                int num1;          // The first random number
                int num2;          // The second random number
                int studentAnswer; // The student's answer
                MathOperations question; // the question for user to solve

                // Generate two random numbers: 
                // The first one is in the range of [1, 100];
                // The second one is in the range of [1 - 9].
                num1 = 1 + rand() % 100;   
                num2 = 1 + rand() % 9;
                question.setOperands(num1, num2);
                question.Multiplication();
                // Display the problem.
                question.print();
                cout << "Your answer is: ";
                cin  >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear(); // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin  >> studentAnswer;
                    cin.ignore(256, '\n');
                }

                // when the user input is valid
                // check if it is the correct answer
                if (question.checkAnswer(studentAnswer))
                    cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
                else
                    cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

                //add the current question and the user answer into the user report
                userReport.insert(question, studentAnswer); 
        } break; 

        default: 
            break;

    }
    }
    userReport.generateReport();
    cout << "Thank you for using Math Wizard!" << endl;
}

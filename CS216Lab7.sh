#!/bin/bash
# Provide a simple math tutor for a second-grade student in an elementary school
# Repeatedly display the main menu to let the user choose an option (enter Q or q to quit):
#    if opiton is 1, generate an addition problem for the user to solve
#    if opiton is 2, generate a subtraction problem for the user to solve (the answer can not be a negative number)
#    if opiton is 3, generate a multiplication problem for the user to solve
#    if other option, display the message of invalid choice.
# For each option of 1, 2, or 3, it should wait for the user to enter the answer
#    if the answer is correct, a message of congratulations should be displayed
#    if the answer is wrong, the correct answer should be displayed
while [ "$usr_option" != "Q" ] && [ "$usr_option" != "q" ]
do
echo "     Math Is Fun! Take a challenge..."
echo "-------------------------------------"
echo "1. Addition problem"
echo "2. Subtraction problem"
echo "3. Multiplication problem"
echo "-------------------------------------"
echo "Please input your menu option (enter Q or q to quit)"
read usr_option

# Your script should start here
# create a loop to repeatedly ask the user to input the option from the main menu until the user enters Q or q to quit
    case $usr_option in
            1)      min=1
                    max=500
                        rnum1=$(((RANDOM % (max - min + 1)) +min))
                        rnum2=$(((RANDOM % (max - min + 1)) +min))
                    echo "$rnum1 + $rnum2 = "
                    read usr_answer
                    correct_answer=$(( rnum1 + rnum2 ))
                    if [ $correct_answer == $usr_answer ] 
                    then
                    echo "Congratulations! $correct_answer is the right answer"
                    else
                    echo "Sorry, the correct answer is $correct_answer"
                    fi;;

            2) echo "You chose the second choice"
                    min=1
                    max=500
                             rnum1=$(((RANDOM % (max - min + 1)) +min))
                             rnum2=$(((RANDOM % (max - min + 1)) +min))
                    echo "$rnum1 - $rnum2 = "
                    read usr_answer
                    if [ $(( rnum1 - rnum2 )) == $usr_answer ] 
                    then
                    echo "Congratulations! $usr_answer is the right answer"
                    else
                        echo "Sorry, the correct answer is $(( rnum1 - rnum2 ))"
                    fi;;
            3) echo "You chose the third choice"
                    min=1
                    max=100
                    max2=9
                             rnum1=$(((RANDOM % (max - min + 1)) +min))
                             rnum2=$(((RANDOM % (max2 - min + 1)) +min))
                    echo "$rnum1 * $rnum2 = "
                    read usr_answer
                    if [ $(( rnum1 * rnum2 )) == $usr_answer ] 
                    then
                    echo "Congratulations! $usr_answer is the right answer"
                    else
                        echo "Sorry, the correct answer is $(( rnum1 * rnum2 ))"
                    fi;;
            Q) break;;

            *) echo "Your choice is not valid"
                read usr_option;;
    esac
done
echo "Hope you enjoy solving Math problems, see you later..."

    

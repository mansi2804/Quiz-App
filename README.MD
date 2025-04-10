# Quiz Application

## Description
This is a simple console-based Quiz Application written in C++. It allows users to take a quiz, answer multiple-choice questions, and view their final score and feedback. The user can select a programming language (C++, Python, or Java) before starting the quiz, and the questions will be specific to the selected language.

## How to Compile
1. Open a terminal and navigate to the project directory:
   ```
   cd /Users/mansipatil/Documents/Projects/Quiz_app
   ```
2. Run the following command to compile the program:
   ```
   g++ -std=c++11 -o quiz_app quiz_app.cpp
   ```

## How to Run
1. After compiling, run the program using:
   ```
   ./quiz_app
   ```
2. Follow the on-screen instructions to start the quiz, view instructions, or exit.

## Features
- **Language Selection**: Users can choose between C++, Python, or Java before starting the quiz.
- **Multiple-choice Questions**: Each question has four options (A, B, C, D).
- **Scoring**: Each correct answer gives 1 point. No negative marking for incorrect answers.
- **Results Summary**: At the end of the quiz, the application displays:
  - Total number of questions
  - Number of correct and incorrect answers
  - Final score
  - Percentage score
  - Feedback message based on the percentage:
    - "Excellent" for scores above 80%
    - "Good Job" for scores between 60% and 79%
    - "Keep Practicing" for scores below 60%

## Instructions
1. Select "Start Quiz" from the main menu.
2. Choose a programming language (C++, Python, or Java).
3. Answer the questions by typing the letter corresponding to your choice (A, B, C, or D) and pressing Enter.
4. View your results at the end of the quiz.

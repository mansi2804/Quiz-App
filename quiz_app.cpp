#include <iostream>
#include <vector>
#include <iomanip>

class Question {
    std::string text;
    std::string options[4];
    char correctAnswer;

public:
    Question(std::string t, std::string o1, std::string o2, std::string o3, std::string o4, char correct)
        : text(t), correctAnswer(correct) {
        options[0] = o1;
        options[1] = o2;
        options[2] = o3;
        options[3] = o4;
    }

    void display() const {
        std::cout << text << "\n";
        std::cout << "A. " << options[0] << "\n";
        std::cout << "B. " << options[1] << "\n";
        std::cout << "C. " << options[2] << "\n";
        std::cout << "D. " << options[3] << "\n";
    }

    bool isCorrect(char answer) const {
        return toupper(answer) == correctAnswer;
    }
};

class Quiz {
    std::vector<Question> cplusplusQuestions;
    std::vector<Question> pythonQuestions;
    std::vector<Question> javaQuestions;
    std::vector<Question> selectedQuestions;
    int correctAnswers = 0;
    int incorrectAnswers = 0;

public:
    Quiz() {
        cplusplusQuestions = {
            Question("Which of the following is a valid C++ data type?", "integer", "int", "number", "float", 'B'),
            Question("What is the output of 'cout << 5 + 5;'?", "10", "55", "Error", "None of the above", 'A'),
            Question("Which keyword is used to define a class in C++?", "struct", "class", "define", "object", 'B'),
            Question("Which operator is used to access members of a class?", ".", "->", "::", "All of the above", 'A'),
            Question("What is the default access specifier for class members in C++?", "public", "private", "protected", "None", 'B'),
            Question("Which of the following is not a loop in C++?", "for", "while", "foreach", "do-while", 'C'),
            Question("What does 'new' keyword do in C++?", "Deletes memory", "Allocates memory", "Creates a variable", "None of the above", 'B'),
            Question("Which of the following is used to define a constant in C++?", "const", "define", "constant", "Both A and B", 'D'),
            Question("What is the purpose of a destructor in C++?", "Initialize an object", "Free resources", "Copy an object", "None of the above", 'B')
        };

        pythonQuestions = {
            Question("What is the keyword to define a function in Python?", "func", "def", "function", "lambda", 'B'),
            Question("Which of the following is used to create a list in Python?", "{}", "[]", "()", "<>", 'B'),
            // ... Add more Python questions ...
        };

        javaQuestions = {
            Question("Which keyword is used to define a class in Java?", "class", "Class", "define", "object", 'A'),
            Question("What is the default access specifier for class members in Java?", "public", "private", "protected", "None", 'B'),
            // ... Add more Java questions ...
        };
    }

    void displayInstructions() const {
        std::cout << "Instructions:\n";
        std::cout << "1. Each question has four options (A, B, C, D).\n";
        std::cout << "2. Type the letter corresponding to your answer and press Enter.\n";
        std::cout << "3. Each correct answer gives you 1 point. No negative marking.\n";
        std::cout << "4. Your final score will be displayed at the end.\n\n";
    }

    void selectLanguage() {
        std::cout << "Select a language for the quiz:\n";
        std::cout << "1. C++\n";
        std::cout << "2. Python\n";
        std::cout << "3. Java\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                selectedQuestions = cplusplusQuestions;
                break;
            case 2:
                selectedQuestions = pythonQuestions;
                break;
            case 3:
                selectedQuestions = javaQuestions;
                break;
            default:
                std::cout << "Invalid choice. Defaulting to C++ questions.\n";
                selectedQuestions = cplusplusQuestions;
        }
    }

    void startQuiz() {
        correctAnswers = 0;
        incorrectAnswers = 0;

        for (const auto& question : selectedQuestions) {
            question.display();
            std::cout << "Your answer: ";
            char answer;
            std::cin >> answer;

            if (question.isCorrect(answer)) {
                correctAnswers++;
            } else {
                incorrectAnswers++;
            }
            std::cout << "\n";
        }

        displayResults();
    }

    void displayResults() const {
        int totalQuestions = selectedQuestions.size();
        int score = correctAnswers;
        double percentage = (static_cast<double>(score) / totalQuestions) * 100;

        std::cout << "Quiz Results:\n";
        std::cout << "Total Questions: " << totalQuestions << "\n";
        std::cout << "Correct Answers: " << correctAnswers << "\n";
        std::cout << "Incorrect Answers: " << incorrectAnswers << "\n";
        std::cout << "Final Score: " << score << "\n";
        std::cout << "Percentage: " << std::fixed << std::setprecision(2) << percentage << "%\n";

        if (percentage > 80) {
            std::cout << "Feedback: Excellent\n";
        } else if (percentage >= 60) {
            std::cout << "Feedback: Good Job\n";
        } else {
            std::cout << "Feedback: Keep Practicing\n";
        }
    }
};

int main() {
    Quiz quiz;
    while (true) {
        std::cout << "Main Menu:\n";
        std::cout << "1. Start Quiz\n";
        std::cout << "2. View Instructions\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                quiz.selectLanguage();
                quiz.startQuiz();
                break;
            case 2:
                quiz.displayInstructions();
                break;
            case 3:
                std::cout << "Exiting the Quiz Application. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

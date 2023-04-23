#include <Windows.h>

#include <ctime>
#include <iostream>
#include <string>
#include <thread>

std::string keyCodes {
"| Key Code | Key Description           |\n"
"| -------- | ------------------------- |\n"
"| 1        | Left mouse button         |\n"
"| 2        | Right mouse button        |\n"
"| 4        | Middle mouse button       |\n"
"| 5        | X1 mouse button           |\n"
"| 6        | X2 mouse button           |\n"
"| 8        | BACKSPACE key             |\n"
"| 9        | TAB key                   |\n"
"| 12       | CLEAR key                 |\n"
"| 13       | ENTER key                 |\n"
"| 16       | SHIFT key                 |\n"
"| 17       | CTRL key                  |\n"
"| 18       | ALT key                   |\n"
"| 19       | PAUSE key                 |\n"
"| 20       | CAPS LOCK key             |\n"
"| 27       | ESC key                   |\n"
"| 32       | SPACEBAR                  |\n"
"| 33       | PAGE UP key               |\n"
"| 34       | PAGE DOWN key             |\n"
"| 35       | END key                   |\n"
"| 36       | HOME key                  |\n"
"| 37       | LEFT ARROW key            |\n"
"| 38       | UP ARROW key              |\n"
"| 39       | RIGHT ARROW key           |\n"
"| 40       | DOWN ARROW key            |\n"
"| 41       | SELECT key                |\n"
"| 42       | PRINT key                 |\n"
"| 43       | EXECUTE key               |\n"
"| 44       | PRINT SCREEN key          |\n"
"| 45       | INS key                   |\n"
"| 46       | DEL key                   |\n"
"| 47       | HELP key                  |\n"
"| 48       | 0 key                     |\n"
"| 49       | 1 key                     |\n"
"| 50       | 2 key                     |\n"
"| 51       | 3 key                     |\n"
"| 52       | 4 key                     |\n"
"| 53       | 5 key                     |\n"
"| 54       | 6 key                     |\n"
"| 55       | 7 key                     |\n"
"| 56       | 8 key                     |\n"
"| 57       | 9 key                     |\n"
"| 65       | A key                     |\n"
"| 66       | B key                     |\n"
"| 67       | C key                     |\n"
"| 68       | D key                     |\n"
"| 69       | E key                     |\n"
"| 70       | F key                     |\n"
"| 71       | G key                     |\n"
"| 72       | H key                     |\n"
"| 73       | I key                     |\n"
"| 74       | J key                     |\n"
"| 75       | K key                     |\n"
"| 76       | L key                     |\n"
"| 77       | M key                     |\n"
"| 78       | N key                     |\n"
"| 79       | O key                     |\n"
"| 80       | P key                     |\n"
"| 81       | Q key                     |\n"
"| 82       | R key                     |\n"
"| 83       | S key                     |\n"
"| 84       | T key                     |\n"
"| 85       | U key                     |\n"
"| 86       | V key                     |\n"
"| 87       | W key                     |\n"
"| 88       | X key                     |\n"
"| 89       | Y key                     |\n"
"| 90       | Z key                     |\n"
"| 91       | Left Windows key          |\n"
"| 92       | Right Windows key         |\n"
"| 93       | Applications key          |\n"
"| 96       | Numeric keypad 0 key      |\n"
"| 97       | Numeric keypad 1 key      |\n"
"| 98       | Numeric keypad 2 key      |\n"
"| 99       | Numeric keypad 3 key      |\n"
"| 100      | Numeric keypad 4 key      |\n"
"| 101      | Numeric keypad 5 key      |\n"
"| 102      | Numeric keypad 6 key      |\n"
"| 103      | Numeric keypad 7 key      |\n"
"| 104      | Numeric keypad 8 key      |\n"
"| 105      | Numeric keypad 9 key      |\n"
"| 106      | Multiply key              |\n"
"| 107      | Add key                   |\n"
"| 108      | Separator key             |\n"
"| 109      | Subtract key              |\n"
"| 110      | Decimal key               |\n"
"| 111      | Divide key                |\n"
"| 112      | F1 key                    |\n"
"| 113      | F2 key                    |\n"
"| 114      | F3 key                    |\n"
"| 115      | F4 key                    |\n"
"| 116      | F5 key                    |\n"
"| 117      | F6 key                    |\n"
"| 118      | F7 key                    |\n"
"| 119      | F8 key                    |\n"
"| 120      | F9 key                    |\n"
"| 121      | F10 key                   |\n"
"| 122      | F11 key                   |\n"
"| 123      | F12 key                   |\n"
"| 144      | NUM LOCK key              |\n"
"| 145      | SCROLL LOCK key           |\n"
"| 160      | Left SHIFT key            |\n"
"| 161      | Right SHIFT key           |\n"
"| 162      | Left CONTROL key          |\n"
"| 163      | Right CONTROL key         |\n"
"| 164      | Left ALT key              |\n"
"| 165      | Right ALT key             |\n"
};

bool terminateThread = false;

void leftClicker(int leftKey, int leftClickDelay, int leftRandomOffset, int leftHoldTime) {
    int leftSubtractedOffset = leftClickDelay - leftRandomOffset;
    int leftAddedOffset = leftClickDelay + leftRandomOffset;

    if (leftSubtractedOffset < 1) {
        leftSubtractedOffset = 1;
    }

    while (!terminateThread) {
        if (GetKeyState(leftKey)) {
            int randomNumber = ((rand() % (leftAddedOffset - leftSubtractedOffset + 1)) + leftSubtractedOffset);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(leftHoldTime);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(randomNumber);
        }
    }
}

void rightClicker(int rightKey, int rightClickDelay, int rightRandomOffset, int rightHoldTime) {
    int rightSubtractedOffset = rightClickDelay - rightRandomOffset;
    int rightAddedOffset = rightClickDelay + rightRandomOffset;

    if (rightSubtractedOffset < 1) {
        rightSubtractedOffset = 1;
    }

    while (!terminateThread) {
        if (GetKeyState(rightKey)) {
            int randomNumber = (rand() % (rightAddedOffset - rightSubtractedOffset + 1)) + rightSubtractedOffset;
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            Sleep(rightHoldTime);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(randomNumber);
        }
    }
}

int main() {
    // left click settings
    int leftKey = 88;  // x
    int leftClickDelay = 100;
    int leftRandomOffset = 50;
    int leftHoldTime = 0;

    // right click settings
    int rightKey = 4;  // middle mouse button
    int rightClickDelay = 100;
    int rightRandomOffset = 50;
    int rightHoldTime = 0;

    srand(time(0));

    int value;
    std::string command;
    while (true) {
        std::thread leftThread(leftClicker, leftKey, leftClickDelay, leftRandomOffset, leftHoldTime);
        std::thread rightThread(rightClicker, rightKey, rightClickDelay, rightRandomOffset, rightHoldTime);

        std::cout << "type 'help' for commands: -> ";
        std::cin >> command;
        if (command == "leftKey") {
            std::cout << "leftKey = ";
            std::cin >> value;
            std::cout << "you have set leftKey = " << value << "\n";
            leftKey = value;
        } else if (command == "leftClickDelay") {
            std::cout << "leftClickDelay = ";
            std::cin >> value;
            std::cout << "you have set leftClickDelay = " << value << " milliseconds"
                      << "\n";
            leftClickDelay = value;
        } else if (command == "leftRandomOffset") {
            std::cout << "leftRandomOffset = ";
            std::cin >> value;
            std::cout << "you have set leftRandomOffset = " << value << " milliseconds"
                      << "\n";
            leftRandomOffset = value;
        } else if (command == "leftHoldTime") {
            std::cout << "leftHoldTime = ";
            std::cin >> value;
            std::cout << "you have set leftHoldTime = " << value << " milliseconds"
                      << "\n";
            leftHoldTime = value;
        } else if (command == "rightKey") {
            std::cout << "rightKey = ";
            std::cin >> value;
            std::cout << "you have set rightKey = " << value << "\n";
            rightKey = value;
        } else if (command == "rightClickDelay") {
            std::cout << "rightClickDelay = ";
            std::cin >> value;
            std::cout << "you have set rightClickDelay = " << value << " milliseconds"
                      << "\n";
            rightClickDelay = value;
        } else if (command == "rightRandomOffset") {
            std::cout << "rightRandomOffset = ";
            std::cin >> value;
            std::cout << "you have set rightRandomOffset = " << value << " milliseconds"
                      << "\n";
            rightRandomOffset = value;
        } else if (command == "rightHoldTime") {
            std::cout << "rightHoldTime = ";
            std::cin >> value;
            std::cout << "you have set rightHoldTime = " << value << " milliseconds"
                      << "\n";
            rightHoldTime = value;
        } else if (command == "list") {
            std::cout << keyCodes;
        } else if (command == "help") {
            std::cout << "'leftKey'           - change keybind for left click"
                      << "\n";
            std::cout << "'leftClickDelay'    - change left click delay in milliseconds"
                      << "\n";
            std::cout << "'leftRandomOffset'  - change the amount of random offset applied to the left click"
                      << "\n";
            std::cout << "'leftHoldTime'      - change how long the left mouse button is pressed and released"
                      << "\n";
            std::cout << "'rightKey'          - change keybind for right click"
                      << "\n";
            std::cout << "'rightClickDelay'   - change right click delay in milliseconds"
                      << "\n";
            std::cout << "'rightRandomOffset' - change the amount of random offset applied to the right click"
                      << "\n";
            std::cout << "'rightHoldTime'     - change how long the right mouse button is pressed and released"
                      << "\n";
            std::cout << "'list'              - list all the key codes and descriptions"
                      << "\n";
            std::cout << "'quit'              - quit the program"
                      << "\n";
        } else if (command == "quit") {
            terminateThread = true;
            leftThread.join();
            rightThread.join();
            break;
        } else {
            std::cout << "'" << command << "' "
                      << "is not recognized"
                      << "\n";
        }

        terminateThread = true;
        leftThread.join();
        rightThread.join();
        terminateThread = false;
    }
    return 0;
}

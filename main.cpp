#include <Windows.h>

#include <ctime>
#include <iostream>
#include <string>
#include <thread>

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

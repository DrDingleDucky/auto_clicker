#include <Windows.h>

#include <ctime>
#include <iostream>
#include <thread>

void leftClicker(int leftKey, int leftClickDelay, int leftRandomOffset, int leftHoldTime) {
    int leftSubtractedOffset = leftClickDelay - leftRandomOffset;
    int leftAddedOffset = leftClickDelay + leftRandomOffset;

    if (leftSubtractedOffset < 1) {
        leftSubtractedOffset = 1;
    }

    while (true) {
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

    while (true) {
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
    int leftKey = 0x58;  // x
    int leftClickDelay = 100;
    int leftRandomOffset = 50;
    int leftHoldTime = 0;

    // right click settings
    int rightKey = VK_MBUTTON;  // middle mouse button
    int rightClickDelay = 100;
    int rightRandomOffset = 50;
    int rightHoldTime = 0;

    srand(time(0));

    std::thread leftThread(leftClicker, leftKey, leftClickDelay, leftRandomOffset, leftHoldTime);
    std::thread rightThread(rightClicker, rightKey, rightClickDelay, rightRandomOffset, rightHoldTime);

    std::puts("press enter to exit...");
    std::getchar();
    return 0;
}

#include <windows.h>

int KeyPressed(int key){
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}
 
int main(){
    INPUT inputs[4] = {};
    bool mouseIsDown = false;

    for(int i = 0; i < 4; ++i) {
        inputs[i].type = INPUT_KEYBOARD;
        inputs[i].ki.wScan = 0;
        inputs[i].ki.time = 0;
        inputs[i].ki.dwExtraInfo = 0;
    }

    inputs[0].ki.wVk = 0x57;    //W
    inputs[1].ki.wVk = 0x41;    //A
    inputs[2].ki.wVk = 0x53;    //S
    inputs[3].ki.wVk = 0x44;    //D

    while (true) {
        if (KeyPressed(VK_LBUTTON)) {
            if (!mouseIsDown){
                mouseIsDown = true;

                for(int i = 0; i < 4; ++i) {
                    inputs[i].ki.dwFlags = 0;
                }

                SendInput(4, inputs, sizeof(INPUT));
            }
        }
        else if (mouseIsDown) {
            mouseIsDown = false;

            for(int i = 0; i < 4; ++i) {
                inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
            }

            SendInput(4, inputs, sizeof(INPUT));
        }

        Sleep(0);
    }
}
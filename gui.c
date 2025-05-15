#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "validate.c"

HWND hNum1, hNum2, hResultado;

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    char buffer1[256], buffer2[256], result[256];
    int num1, num2, mcm;

    switch (msg) {
        case WM_CREATE: {
            RECT rect;
            GetClientRect(hwnd, &rect);

            int windowWidth = rect.right - rect.left;
            int windowHeight = rect.bottom - rect.top;

            // Title
            CreateWindow("STATIC", "Calculadora de MCM", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         0, 10, windowWidth, 30, hwnd, NULL, NULL, NULL);

            // Input labels and fields
            CreateWindow("STATIC", "Numero 1:", WS_VISIBLE | WS_CHILD,
                         20, 60, 80, 20, hwnd, NULL, NULL, NULL);
            hNum1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_CENTER,
                         110, 60, 150, 25, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Numero 2:", WS_VISIBLE | WS_CHILD,
                         20, 100, 80, 20, hwnd, NULL, NULL, NULL);
            hNum2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_CENTER,
                         110, 100, 150, 25, hwnd, NULL, NULL, NULL);

            // Button
            CreateWindow("BUTTON", "Calcular MCM", WS_VISIBLE | WS_CHILD | BS_CENTER | BS_PUSHBUTTON,
                         (windowWidth - 150) / 2, 150, 150, 30, hwnd, (HMENU)1, NULL, NULL);

            // Result display
            hResultado = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
                         20, 200, windowWidth - 40, 30, hwnd, NULL, NULL, NULL);

            // Background color
            HBRUSH hBrush = CreateSolidBrush(RGB(240, 240, 240));
            SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);
            break;
        }
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                GetWindowText(hNum1, buffer1, 256);
                GetWindowText(hNum2, buffer2, 256);
                mcm = processMCM(buffer1, buffer2, result);

                if (mcm == -3) {
                    sprintf(result, "Error: No deje espacios vacíos.");
                } else if (mcm == -2) {
                    sprintf(result, "Error: Ingrese solo números válidos.");
                } else if (mcm == -1) {
                    sprintf(result, "Ingrese numeros mayores a cero.");
                } else {
                    sprintf(result, "MCM: %d", mcm);
                }

                SetWindowText(hResultado, result);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

// Función principal
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"mcmWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"mcmWindow", L"Calculadora MCM", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 400, 300, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

HWND hNum1, hNum2, hResultado;

// Función para calcular el MCD
int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para calcular el MCM
int calcularMCM(int a, int b) {
    int mcd = calcularMCD(a, b);
    return (a * b) / mcd;
}

// Función de manejo de eventos de la ventana
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    char buffer1[256], buffer2[256], result[256];
    int num1, num2, mcm;

    switch(msg) {
        case WM_CREATE:
            RECT rect;
            GetClientRect(hwnd, &rect); 

            int windowWidth = rect.right - rect.left;
            int windowHeight = rect.bottom - rect.top;

            CreateWindow("STATIC", "Ingrese dos numeros enteros", WS_VISIBLE | WS_CHILD,
                ((windowWidth - 200) / 2), 20, 200, 20, hwnd, NULL, NULL, NULL);    
            CreateWindow("STATIC", "Numero 1:", WS_VISIBLE | WS_CHILD,
                         20, 50, 80, 20, hwnd, NULL, NULL, NULL);
            hNum1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                         100, 50, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Numero 2:", WS_VISIBLE | WS_CHILD,
                         20, 80, 80, 20, hwnd, NULL, NULL, NULL);
            hNum2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                         100, 80, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Calcular MCM", WS_VISIBLE | WS_CHILD,
                         ((windowWidth-120)/2), 120, 120, 25, hwnd, (HMENU) 1, NULL, NULL);

            hResultado = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD,
                         20, 150, 250, 20, hwnd, NULL, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                GetWindowText(hNum1, buffer1, 256);
                GetWindowText(hNum2, buffer2, 256);
                num1 = atoi(buffer1);
                num2 = atoi(buffer2);

                if (num1 > 0 && num2 > 0) {
                    mcm = calcularMCM(num1, num2);
                    sprintf(result, "MCM: %d", mcm);
                } else {
                    sprintf(result, "Ingrese números válidos (> 0)");
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
                  100, 100, 300, 230, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

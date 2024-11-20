#include <windows.h>

int left = 50;
int top = 50;
int right = 150;
int bottom = 150;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {
        SetTimer(hwnd, 1, 8, NULL);
    } break;
    case WM_TIMER: {
        InvalidateRect(hwnd, NULL, FALSE);
    } break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        // Set square's dimensions
        // Draw the square
        Rectangle(hdc, left, top, right, bottom);
        right += 1;
        bottom += 1;
        EndPaint(hwnd, &ps);
    } break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = (LPCSTR)CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0,                                   // Optional window styles.
                               (LPCSTR)CLASS_NAME,                  // Window class
                               (LPCSTR) "Learn to Program Windows", // Window text
                               WS_OVERLAPPEDWINDOW,                 // Window style

                               // Size and position
                               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

                               NULL,      // Parent window
                               NULL,      // Menu
                               hInstance, // Instance handle
                               NULL       // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    KillTimer(hwnd, 1);

    return 0;
}

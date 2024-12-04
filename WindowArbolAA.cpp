#include "WindowArbolAA.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static ArbolAA* arbol;
    static int cxClient, cyClient;
    static SCROLLINFO si;

    switch (uMsg) {
    case WM_CREATE:
        arbol = (ArbolAA*)((CREATESTRUCT*)lParam)->lpCreateParams;
        // Inicializar barras de scroll
        si.cbSize = sizeof(si);
        si.fMask = SIF_RANGE | SIF_PAGE;
        si.nMin = 0;
        si.nMax = 2000;
        si.nPage = 800;
        SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
        SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
        return 0;

    case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);
        return 0;

    case WM_HSCROLL:
        si.cbSize = sizeof(si);
        si.fMask = SIF_ALL;
        GetScrollInfo(hwnd, SB_HORZ, &si);

        switch (LOWORD(wParam)) {
        case SB_LINELEFT:
            si.nPos -= 50;
            break;
        case SB_LINERIGHT:
            si.nPos += 50;
            break;
        case SB_PAGELEFT:
            si.nPos -= si.nPage;
            break;
        case SB_PAGERIGHT:
            si.nPos += si.nPage;
            break;
        case SB_THUMBTRACK:
            si.nPos = si.nTrackPos;
            break;
        default:
            break;
        }

        si.fMask = SIF_POS;
        SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_VSCROLL:
        si.cbSize = sizeof(si);
        si.fMask = SIF_ALL;
        GetScrollInfo(hwnd, SB_VERT, &si);

        switch (LOWORD(wParam)) {
        case SB_LINEUP:
            si.nPos -= 50;
            break;
        case SB_LINEDOWN:
            si.nPos += 50;
            break;
        case SB_PAGEUP:
            si.nPos -= si.nPage;
            break;
        case SB_PAGEDOWN:
            si.nPos += si.nPage;
            break;
        case SB_THUMBTRACK:
            si.nPos = si.nTrackPos;
            break;
        default:
            break;
        }

        si.fMask = SIF_POS;
        SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        si.cbSize = sizeof(si);
        si.fMask = SIF_POS;
        GetScrollInfo(hwnd, SB_HORZ, &si);
        int xPos = si.nPos;

        GetScrollInfo(hwnd, SB_VERT, &si);
        int yPos = si.nPos;

        // Limpiar el área de dibujo
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

        if (arbol) {
            arbol->DibujarArbolAA(hdc, -xPos, -yPos, 1.0);
        }

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

void lanzarInterfazGraficaConArbolAA(ArbolAA* arbol) {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    const wchar_t CLASS_NAME[] = L"ArbolAAWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Árbol AA",
        WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        arbol
    );

    if (hwnd == NULL) {
        return;
    }

    ShowWindow(hwnd, SW_SHOW);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
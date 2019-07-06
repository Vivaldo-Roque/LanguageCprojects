#include <windows.h>
#include "res.h"

#define bt1 1
#define edit1 2
#define edit2 3
#define edit3 4
#define edit4 5
#define edit5 6
#define edit6 7
#define edit7 8
#define edit8 9
#define edit9 10
#define edit10 11
#define edit111 12
#define edit122 13
#define label1 14
#define label2 15
#define label3 16
#define bt2 17
#define edited1 18
#define edited2 19
#define edited3 20
#define edited4 21
#define edited5 22
#define edited6 23
#define label4 24
#define label5 25

HWND bt11, bt22, edit11, edit22, edit33, edit44, edit55, edit66, edit77, edit88, edit99, edit101, edit102, edit103, label11, label22, label33, label44, label55, edited11, edited22, edited33, edited44, edited55, edited66;

/* This is where all the input to the window goes to */

int * matriz2(int matriz[][2],int i[2])
{
	int matrizB[2];
	int det[3]={0,0,0};
	static int k[2];
	
	det[0]= (((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1])));
	
	matrizB[0]=matriz[0][0];
	matrizB[1]=matriz[1][0];
	
	matriz[0][0]=i[0];
	matriz[1][0]=i[1];
	
	
	det[1]= (((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1])));
	
	matriz[0][0]=matrizB[0];
	matriz[1][0]=matrizB[1];
	
	matrizB[0]=matriz[0][1];
	matrizB[1]=matriz[1][1];
	
	matriz[0][1]=i[0];
	matriz[1][1]=i[1];
	
	det[2]= (((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1])));
	
	k[0] = det[1]/det[0];
	k[1] = det[2]/det[0];
	
	return k;
}

int * matriz3(int matriz[][3],int i[3])
{
	int matrizB[3];
	int det[4]={0,0,0,0};
	static int k[3];
	
	det[0]= (((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1])));
	
	matrizB[0]=matriz[0][0];
	matrizB[1]=matriz[1][0];
	matrizB[2]=matriz[2][0];
	
	matriz[0][0]=i[0];
	matriz[1][0]=i[1];
	matriz[2][0]=i[2];
	
	
	det[1]= (((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1])));
	
	matriz[0][0]=matrizB[0];
	matriz[1][0]=matrizB[1];
	matriz[2][0]=matrizB[2];
	
	matrizB[0]=matriz[0][1];
	matrizB[1]=matriz[1][1];
	matrizB[2]=matriz[2][1];
	
	matriz[0][1]=i[0];
	matriz[1][1]=i[1];
	matriz[2][1]=i[2];
	
	det[2]= (((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1])));
	
	matriz[0][1]=matrizB[0];
	matriz[1][1]=matrizB[1];
	matriz[2][1]=matrizB[2];
	
	matrizB[0]=matriz[0][2];
	matrizB[1]=matriz[1][2];
	matrizB[2]=matriz[2][2];
	
	matriz[0][2]=i[0];
	matriz[1][2]=i[1];
	matriz[2][2]=i[2];

	det[3]= (((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1])));
	
	k[0] = det[1]/det[0];
	k[1] = det[2]/det[0];
	k[2] = det[3]/det[0];
	
	return k;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE:{
			
			edit11 = CreateWindow(TEXT("edit"), TEXT("X1"),
			WS_VISIBLE | WS_CHILD, 0,10,80,25,
			hwnd, (HMENU) edit1, NULL, NULL
			);
			
			edit22 = CreateWindow(TEXT("edit"), TEXT("Y1"),
			WS_VISIBLE | WS_CHILD, 100,10,80,25,
			hwnd, (HMENU) edit2, NULL, NULL
			);
			
			edit33 = CreateWindow(TEXT("edit"), TEXT("Z1"),
			WS_VISIBLE | WS_CHILD, 200,10,80,25,
			hwnd, (HMENU) edit3, NULL, NULL
			);
			
			edit44 = CreateWindow(TEXT("edit"), TEXT("0"),
			WS_VISIBLE | WS_CHILD, 300,10,80,25,
			hwnd, (HMENU) edit4, NULL, NULL
			);
			
			edit55 = CreateWindow(TEXT("edit"), TEXT("X2"),
			WS_VISIBLE | WS_CHILD, 0,50,80,25,
			hwnd, (HMENU) edit5, NULL, NULL
			);
			
			edit66 = CreateWindow(TEXT("edit"), TEXT("Y2"),
			WS_VISIBLE | WS_CHILD, 100,50,80,25,
			hwnd, (HMENU) edit6, NULL, NULL
			);
			
			edit77 = CreateWindow(TEXT("edit"), TEXT("Z2"),
			WS_VISIBLE | WS_CHILD, 200,50,80,25,
			hwnd, (HMENU) edit7, NULL, NULL
			);
			
			edit88 = CreateWindow(TEXT("edit"), TEXT("0"),
			WS_VISIBLE | WS_CHILD, 300,50,80,25,
			hwnd, (HMENU) edit8, NULL, NULL
			);
			
			edit99 = CreateWindow(TEXT("edit"), TEXT("X3"),
			WS_VISIBLE | WS_CHILD, 0,100,80,25,
			hwnd, (HMENU) edit9, NULL, NULL
			);
			
			edit101 = CreateWindow(TEXT("edit"), TEXT("Y3"),
			WS_VISIBLE | WS_CHILD, 100,100,80,25,
			hwnd, (HMENU) edit10, NULL, NULL
			);
			
			edit102 = CreateWindow(TEXT("edit"), TEXT("Z3"),
			WS_VISIBLE | WS_CHILD, 200,100,80,25,
			hwnd, (HMENU) edit111, NULL, NULL
			);
			
			edit103 = CreateWindow(TEXT("edit"), TEXT("0"),
			WS_VISIBLE | WS_CHILD, 300,100,80,25,
			hwnd, (HMENU) edit122, NULL, NULL
			);
			
			label11 = CreateWindow(TEXT("edit"), TEXT("X="),
			WS_VISIBLE | WS_CHILD, 500,10,80,25,
			hwnd, (HMENU) label1, NULL, NULL
			);
			
			label22 = CreateWindow(TEXT("edit"), TEXT("Y="),
			WS_VISIBLE | WS_CHILD, 500,50,80,25,
			hwnd, (HMENU) label2, NULL, NULL
			);
			
			label33 = CreateWindow(TEXT("edit"), TEXT("Z="),
			WS_VISIBLE | WS_CHILD, 500,100,80,25,
			hwnd, (HMENU) label3, NULL, NULL
			);
			
			bt11 = CreateWindow(TEXT("button"), TEXT("Calcular"),
			WS_VISIBLE | WS_CHILD, 400,50,80,25,
			hwnd, (HMENU) bt1, NULL, NULL
			);
			
			edited11 = CreateWindow(TEXT("edit"), TEXT("X1"),
			WS_VISIBLE | WS_CHILD, 0,200,80,25,
			hwnd, (HMENU) edited1, NULL, NULL
			);
			
			edited22 = CreateWindow(TEXT("edit"), TEXT("Y1"),
			WS_VISIBLE | WS_CHILD, 100,200,80,25,
			hwnd, (HMENU) edited2, NULL, NULL
			);
			
			edited33 = CreateWindow(TEXT("edit"), TEXT("0"),
			WS_VISIBLE | WS_CHILD, 200,200,80,25,
			hwnd, (HMENU) edited3, NULL, NULL
			);
			
			edited44 = CreateWindow(TEXT("edit"), TEXT("X2"),
			WS_VISIBLE | WS_CHILD, 0,250,80,25,
			hwnd, (HMENU) edited4, NULL, NULL
			);
			
			edited55 = CreateWindow(TEXT("edit"), TEXT("Y2"),
			WS_VISIBLE | WS_CHILD, 100,250,80,25,
			hwnd, (HMENU) edited5, NULL, NULL
			);
			
			edited66 = CreateWindow(TEXT("edit"), TEXT("0"),
			WS_VISIBLE | WS_CHILD, 200,250,80,25,
			hwnd, (HMENU) edited6, NULL, NULL
			);
			
			bt22 = CreateWindow(TEXT("button"), TEXT("Calcular"),
			WS_VISIBLE | WS_CHILD, 300,200,80,25,
			hwnd, (HMENU) bt2, NULL, NULL
			);
			
			label44 = CreateWindow(TEXT("edit"), TEXT("X="),
			WS_VISIBLE | WS_CHILD, 400,200,80,25,
			hwnd, (HMENU) label4, NULL, NULL
			);
			
			label55 = CreateWindow(TEXT("edit"), TEXT("Y="),
			WS_VISIBLE | WS_CHILD, 400,250,80,25,
			hwnd, (HMENU) label5, NULL, NULL
			);
			
			break;
		}
		
		case WM_COMMAND:{
			
			char v1[50]="0", v2[50]="0", v3[50]="0", v4[50]="0", v5[50]="0", v6[50]="0",
			 v7[50]="0", v8[50]="0", v9[50]="0", v10[50]="0", v11[50]="0", v12[50]="0";
			 
			char x1[50]="0", x2[50]="0", x3[50]="0", x4[50]="0", x5[50]="0", x6[50]="0";
			 
			char det1[50]="0", det2[50]="0", det3[50]="0",det4[50]="0", det5[50]="0";
			
			int matriz[3][3]={{0,0,0},{0,0,0},{0,0,0}};
			int matrizA[2][2]={{0,0},{0,0}};
			int i[3]={0,0,0};
			int e[2]={0,0};
			int * det;
			int * detA;
			
			SendMessage((HWND)edit11,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v1);
			SendMessage((HWND)edit22,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v2);
			SendMessage((HWND)edit33,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v3);
			SendMessage((HWND)edit44,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v4);
			SendMessage((HWND)edit55,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v5);
			SendMessage((HWND)edit66,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v6);
			SendMessage((HWND)edit77,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v7);
			SendMessage((HWND)edit88,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v8);
			SendMessage((HWND)edit99,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v9);
			SendMessage((HWND)edit101,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v10);
			SendMessage((HWND)edit102,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v11);
			SendMessage((HWND)edit103,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &v12);
			SendMessage((HWND)edited11,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x1);
			SendMessage((HWND)edited22,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x2);
			SendMessage((HWND)edited33,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x3);
			SendMessage((HWND)edited44,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x4);
			SendMessage((HWND)edited55,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x5);
			SendMessage((HWND)edited66,(UINT) EM_GETLINE, (WPARAM) 1, (LPARAM) &x6);
			//divisão
			
			matriz[0][0] = atoi(v1);
			matriz[0][1] = atoi(v2);
			matriz[0][2] = atoi(v3);
			matriz[1][0] = atoi(v5);
			matriz[1][1] = atoi(v6);
			matriz[1][2] = atoi(v7);
			matriz[2][0] = atoi(v9);
			matriz[2][1] = atoi(v10);
			matriz[2][2] = atoi(v11);
			
			matrizA[0][0] = atoi(x1);
			matrizA[0][1] = atoi(x2);
			matrizA[1][0] = atoi(x4);
			matrizA[1][1] = atoi(x5);
			
			i[0] = atoi(v4);
			i[1] = atoi(v8);
			i[2] = atoi(v12);
			
			e[0] = atoi(x3);
			e[1] = atoi(x6);
			
			if(LOWORD(wParam) == bt1){
				
				det = matriz3(matriz,i);
				
				itoa(det[0],det1,10);
				itoa(det[1],det2,10);
				itoa(det[2],det3,10);
				
				SendMessage((HWND)label11,(UINT) WM_SETTEXT, (WPARAM) 1, (LPARAM) &det1);
				SendMessage((HWND)label22,(UINT) WM_SETTEXT, (WPARAM) 1, (LPARAM) &det2);
				SendMessage((HWND)label33,(UINT) WM_SETTEXT, (WPARAM) 1, (LPARAM) &det3);
				
			}
			
			if(LOWORD(wParam) == bt2){
				
				detA = matriz2(matrizA,e);
				
				itoa(detA[0],det4,10);
				itoa(detA[1],det5,10);
				
				SendMessage((HWND)label44,(UINT) WM_SETTEXT, (WPARAM) 1, (LPARAM) &det4);
				SendMessage((HWND)label55,(UINT) WM_SETTEXT, (WPARAM) 1, (LPARAM) &det5);
				
			}

			break;
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_NO);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);//(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MEUICONE)); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MEUICONE)); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Regra de Crammer",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

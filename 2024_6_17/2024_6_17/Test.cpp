#define _CRT_SECURE_NO_WARNINGS

#include "workerManage.h"

int main() {
	workerManage w;
	while (true) {
		int ret = w.showMenu();
		switch (ret)
		{
		case 0:
			w.exitP();
			break;
		case 1:
		
			break;
		case 2:
			
			break;
		case 3:
		
			break;
		case 4:
			
			break;
		case 5:
		
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}
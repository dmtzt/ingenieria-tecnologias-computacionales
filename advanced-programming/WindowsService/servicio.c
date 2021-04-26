/*
 * Windows Service - servicio
 *
 * Servicio de Windows que escribe la fecha y hora en archivo cada minuto.
 * El archivo se abre y se cierra en cada iteración.
 * 
 * Christian Alvarez A00818801
 * David Alejandro Martínez Tristán A01610267
 * 
 * 20/Abril/2021
*/

#include <stdio.h>
#include <malloc.h>
#include <sys/types.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <windows.h>
#include <winsvc.h>
#define SLEEP_TIME_MILIS 60000

long estado=0;	//Indicador para rastrear la actividad del servicio
				// (no muy importante en este ejemplo)
int fh_dia,fh_mes,fh_anio,fh_hora,fh_minuto,fh_segundo;


FILE *arch;

SERVICE_STATUS_HANDLE interfaz_al_SCM;
SERVICE_STATUS serviceStatus;
SERVICE_TABLE_ENTRY tabla;
char nombreServicio[]="ProgAva_Srv";
 
HANDLE elThread;
DWORD elThreadID;

VOID WINAPI ServiceMain(DWORD dwArgc,LPTSTR *lpszArgv);
VOID WINAPI mainHandle(DWORD fdwControl);


void main(void)
{
	tabla.lpServiceName=nombreServicio;	
	tabla.lpServiceProc=&ServiceMain;
	StartServiceCtrlDispatcher(&tabla);
}


void setServiceStatusState(unsigned int state) {
	serviceStatus.dwServiceType=SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState=state;
	serviceStatus.dwControlsAccepted=SERVICE_CONTROL_INTERROGATE
										|SERVICE_ACCEPT_STOP
										|SERVICE_ACCEPT_PAUSE_CONTINUE
										|SERVICE_ACCEPT_SHUTDOWN;
	serviceStatus.dwWin32ExitCode=NO_ERROR;
	serviceStatus.dwServiceSpecificExitCode=0;
	serviceStatus.dwCheckPoint=estado++;
	serviceStatus.dwWaitHint=100;	
}

DWORD WINAPI corre(LPVOID lpParameter) {
	setServiceStatusState(SERVICE_RUNNING);	//Avisar que YA ESTAMOS CORRIENDO!!!
	SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

	while(1)
	{
		arch = fopen("D:/Users/david/Documents/GitHub/ingenieria-tecnologias-computacionales/advanced-programming/WindowsService/Log.txt", "a");
	    time_t t = time(NULL);
		
		if(arch != NULL) 
		{
			struct tm tm = *localtime(&t);
			fprintf(arch, "Fecha y Hora: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		}

		fclose(arch);
		Sleep(SLEEP_TIME_MILIS);
	}
}

VOID WINAPI mainHandle(DWORD fdwControl) {
	switch(fdwControl) {
		case SERVICE_CONTROL_STOP:
					setServiceStatusState(SERVICE_STOP_PENDING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					if (TerminateThread(elThread,0)) {
						setServiceStatusState(SERVICE_STOPPED);
						SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					}
					break;
		case SERVICE_CONTROL_PAUSE:
					setServiceStatusState(SERVICE_PAUSE_PENDING);	//Avisar que YA ESTAMOS CORRIENDO!!!
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					SuspendThread(elThread);
					
					setServiceStatusState(SERVICE_PAUSED);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
		case SERVICE_CONTROL_CONTINUE:
					setServiceStatusState(SERVICE_CONTINUE_PENDING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					ResumeThread(elThread);

					setServiceStatusState(SERVICE_RUNNING);	//Avisar que YA ESTAMOS CORRIENDO!!!
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
		default:
					setServiceStatusState(SERVICE_RUNNING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
	}
}


VOID WINAPI ServiceMain(DWORD dwArgc,LPTSTR *lpszArgv) {
	interfaz_al_SCM=RegisterServiceCtrlHandler(nombreServicio,mainHandle);

	setServiceStatusState(SERVICE_START_PENDING);
	SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Avisar que estamos "alive and kicking!"

	elThread=CreateThread(NULL,0,corre,NULL,0,&elThreadID);
}


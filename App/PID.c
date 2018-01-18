#include "PID.h"

void PID_init (PID_Str* pid,int kp,int ki,int kd,int stack_overload,int command_out_overload)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->stack_overload = stack_overload;
	pid->command_out_overload =command_out_overload;
	
	for (int i = 0;i< PROFONDEUR_KD;i++)
		pid->etat[i] = 0;
}

void kp_stack (PID_Str* pid)
{
	pid->kp_stack = (pid->kp)*((pid->command_in)-(pid->etat[0]));
}

void ki_stack (PID_Str* pid,float Te)
{
	pid->ki_stack += (pid->ki)*(int)((pid->command_in - pid->etat[0])*Te);
	if (pid->ki_stack > pid->stack_overload) pid->ki_stack = pid->stack_overload;
}

void kd_stack (PID_Str* pid,float Te)
{
		pid->kd_stack = pid->kd*(pid->etat[0] - pid->etat[PROFONDEUR_KD-1])/Te;
}

void command_edit (PID_Str* pid)
{
	int com;
	com = pid->kd_stack+pid->ki_stack+pid->kp_stack;
	if (com > pid->command_out_overload) pid->command_out = pid->command_out_overload;
	else pid->command_out = com;
}

void etat_edit(PID_Str* pid,int new_etat)
{
	for(int i = (PROFONDEUR_KD-1); i > 1;i--)
	{
		pid->etat[i-1] = pid->etat[i];
	}
	pid->etat[0] = new_etat;
}

void etat_edit_f (PID_Str*  pid, float new_etat)
{
	int etat;
	etat = (int)(new_etat * command_out_overload);
	etat_edit(pid,etat);
}

void PID_filter(PID_Str* pid,int Te)
{
	kd_stack(pid,Te);
	ki_stack(pid,Te);
	kp_stack(pid);
}

int PID_full_update(PID_Str* pid,int etat,int command_in,int Te)
{
	etat_edit(pid,etat);
	pid->command_in = command_in;
	PID_filter(pid,Te);
	command_edit(pid);
	return pid->command_out;
}

float PID_full_update_f (PID_Str* pid,float etat, float new_command,int Te)
{
	etat_edit_f(pid,etat);
	pid->command_in = (int)(command_in*command_out_overload);
	PID_filter(pid,Te);
	command_edit(pid);
	return ((float)pid->command_out /((float)command_out_overload));
}

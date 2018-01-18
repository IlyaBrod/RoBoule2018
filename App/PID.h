#ifndef PID_H
#define PID_H

/*PID_Str
*@kp,ki,kd : variable a init, definition du filtre
*@stack_overload : limite la charge de ki_stack et le depacement de l'integrateur
*@command_in,_out : valeur de commande
*@etat[] : profondeur pour kd : nombre de point pris en compte etat[0] dernier retour d'etat
*@command_out_overload : limite le niveau de la commande
*/
#define PROFONDEUR_KD 3

typedef struct
{
	int kp,ki,kd;
	int kp_stack,ki_stack,kd_stack;
	int stack_overload;
	int command_in;
	int command_out;
	int command_out_overload;
	int etat[PROFONDEUR_KD];

	float command_out_f;
	float command_in_f;
}PID_Str;


void PID_init (PID_Str*,int kp,int ki,int kd,int stack_overload,int command_out_overload);
void kp_stack (PID_Str* pid);
void ki_stack (PID_Str* pid,float Te);
void kd_stack (PID_Str* pid,float Te);
void command_edit (PID_Str* pid);
void etat_edit(PID_Str* pid,int new_etat);
void etat_edit_f (PID_Str*  pid, float new_etat);
void PID_filter(PID_Str* pid,int Te);



int PID_full_update(PID_Str* pid,int etat,int command_in,int Te);
float PID_full_update_f (PID_Str* pid,float etat, float new_command,int Te);

#endif



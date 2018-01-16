#ifndef PID_H
#define PID_H

/*PID_str
*@kp,ki,kd : variable a init, definition du filtre
*@stack_overload : limite la charge de ki_stack et le depacement de l'integrateur
*@command_in,_out : valeur de commande
*@etat[] : profondeur pour kd : nombre de point pris en compte etat[0] dernier retour d'etat
*@command_out_overload : limite le niveau de la commande
*/
struct PID_Str
{
	int kp,ki,kd;
	int kp_stack,ki_stack,kd_stack;
	int stack_overload;
	int command_in;
	int command_out;
	int command_out_overload;
	int etat[PROFONDEUR_KD];
};
typedef struct PID_str PID_str;

void PID_init (*PID_str pid,int kp,int ki,int kd,int stack_overload);
void kp_stack (*PID_str pid);
void ki_stack (*PID_str pid);
void kd_stack (*PID_str pid);
void command_edit (*PID_str pid);
void etat_edit(*PID_str pid,int new_etat);
void PID_filter(*PID_str pid);
void PID_full_update(*PID_str pid,int etat,int command_in);

#endif



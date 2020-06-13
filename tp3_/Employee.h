#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int auto_id(LinkedList* this);
//auto incrementa el id con un int static
Employee* employee_new();
/*
 * La utilizo para tomar datos nuevos del imput.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/*
 * La utilizo para tomar los datos del parseo.
 *
 */
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmpleado(Employee* pArrayList);

int emp_ord_id(void* emp_1,void* emp_2);
int emp_ord_sueldo(void* emp_1,void* emp_2);
int emp_ord_nombre(void* emp_1,void* emp_2);
int emp_ord_horas_trabajadas(void* emp_1,void* emp_2);
//ordena empleados por sueldo

#endif // employee_H_INCLUDED

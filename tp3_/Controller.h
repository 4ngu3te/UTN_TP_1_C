int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * Valida la direccion del archivo, y desde el parser carga los datos.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/*
 * Setea un nuevo empleado, valido entradas, guardo y compruebo que haya sigo agregado
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/*
 * Itera el ll_get para concidir el id del getter,menu de edicion
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/*
 * Itera el ll_get para concidir el id,ll_remove hace su trabajo
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/*
 * Itera el ll_get para mostrar el empleado
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/*
 * Con el puntero a funcion de los datos de ordenamiento el ll_sort los ordena
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



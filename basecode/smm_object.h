//
//  smm_object.h
//  SMMarble object
//
//  Created by Juyeop Kim on 2023/11/05.
//

#ifndef smm_object_h
#define smm_object_h

#define MAX_CHARNAME                200


typedef struct {
	char smm_name[MAX_CHARNAME];// array size [100][200]
	int smm_type;
	int smm_credit;
	int smm_energy;
	int smm_grade;
} smmObj_object_t;

/* node type :
    lecture,
    restaurant,
    laboratory,
    home,
    experiment,
    foodChance,
    festival
*/


typedef enum {
	GRADE_A_PLUS = 0,
	GRADE_A_ZERO ,
	GRADE_A_MINUS,
	GRADE_B_PLUS,
	GRADE_B_ZERO,
	GRADE_B_MINUS,
	GRADE_C_PLUS,
	GRADE_C_ZERO,
	GRADE_C_MINUS,
	GRADE_D_PLUS,
	GRADE_D_ZERO,
	GRADE_D_MINUS,
	GRADE_F
}smmGrade_e;



//object generation
int smmObj_genNode(char* name, int type, int credit, int energy);

//member retrieving
char* smmObj_getName(int node_nr); // return node name
int smmObj_getNodeType(int node_nr); // return node type
int smmObj_getNodeCredit(int node_nr); // return credit
int smmObj_getNodeEnergy(int node_nr); // return energy

//element to string
char* smmObj_getTypeName(int node_type); // return node type name(char*)
char* smmObj_getGradeName(smmGrade_e grade);


#endif/* smm_object_h */

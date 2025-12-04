//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR			100
#define MAX_NODETYPE    7
#define MAX_GRADE       9

#define SMMNODE_TYPE_LECTURE						0
#define SMMNODE_TYPE_RESTAURANT					1
#define SMMNODE_TYPE_LABORATORY					2
#define SMMNODE_TYPE_HOME								3
#define SMMNODE_TYPE_GOTOLAB						4
#define SMMNODE_TYPE_FOODCHANGE					5
#define SMMNODE_TYPE_FESTIVAL						6

static char smmNodeName[MAX_NODETYPE][MAX_CHARNAME] { // array size [7][200]
						"lecture",
						"restaurant",
						"laboratory",
						"home",
						"gotlab",
						"foodchange",
						"festival"
};

typedef struct {
	char smm_name[MAX_CHARNAME];// array size [100][200]
	int smm_type;
	int smm_credit;
	int smm_energy;
} smmObj_board_t;

static smmObj_board_t smmObj_board[MAX_NODENR];

//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
		strcpy(smmObj_board[smm_nodeNr].name,name);
    smmObj_board[smm_nodeNr].type = type;
    smmObj_board[smm_nodeNr].credit = credit;
    smmObj_board[smm_nodeNr].energy = energy;
    
    smm_nodeNR++;
    
    return (smm_nodeNr);

}



//member retrieving
char* smmObj_getNodeName(int node_nr)
{
	return(smmObj_board[node_nr].name);
}

char* smmObj_getNodeType(int node_nr)
{
	return(smmObj_board[node_nr].type);
}

char* smmObj_getNodeCredit(int node_nr)
{
	return(smmObj_board[node_nr].credit);

char* smmObj_getNodeEnergy(int node_nr)
{
	return(smmObj_board[node_nr].energy);
}

char* smmObj_getTypeName(int node_nr)
{
	return (smmObj_nodeName[node_type].name);

#if 0
//element to string
char* smmObj_getNodeName(smmNode_e type);
{
    return smmNodeName[type];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif


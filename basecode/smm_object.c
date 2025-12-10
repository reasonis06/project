//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR											100
#define MAX_NODETYPE   									7
#define MAX_GRADE      									13

#define SMMNODE_TYPE_LECTURE						0
#define SMMNODE_TYPE_RESTAURANT					1
#define SMMNODE_TYPE_LABORATORY					2
#define SMMNODE_TYPE_HOME								3
#define SMMNODE_TYPE_GOTOLAB						4
#define SMMNODE_TYPE_FOODCHANGE					5
#define SMMNODE_TYPE_FESTIVAL						6

//구조체로 만들기 
//struct int smm_players[MAX_PLAYER];
	
typedef struct {
	int player_pos[MAX_PLAYER];
	int player_credit[MAX_PLAYER];
	char player_name[MAX_PLAYER][MAX_CHARNAME];
	int player_energy[MAX_PLAYER];
	int flag_graduated[MAX_PLAYER];

} smm_player_t;

static 	smm_player_t smm_players;
static int smm_PlayerNr = 0;
static int smm_nodeNr = 0;

static char smmNodeName[MAX_NODETYPE][MAX_CHARNAME] = { // array size [7][200]
						"lecture",
						"restaurant",
						"laboratory",
						"home",
						"gotlab",
						"foodchange",
						"festival"
};

static char smmNodegradeName[MAX_GRADE][MAX_CHARNAME] = { // array size [7][200]
						"A+",
						"A0",
						"A-",
						"B+",
						"B0",
						"B-",
						"C+",
						"C0",
						"C-",
						"D+",
						"D0",
						"D-",
						"F"
};

static smmObj_object_t *smmObj_board[MAX_NODENR];

// 1. PlayerNr setting and return
void smmObj_setPlayerNr(int n) {
	smm_playerNr = n;
	}
	
int smmObj_getPlayerNr(void) {
	return smm_playerNr;
	}

// 2. Initialization and update function
void smmObj_updatePlayerPos(int player, int pos) {
    smm_players.player_pos[player] = pos;
}

void smmObj_updatePlayerCredit(int player, int credit) {
    smm_players.player_credit[player] += credit;
}

void smmObj_updatePlayerEnergy(int player, int energy) {
    smm_players.player_energy[player] += energy;
}

void smmObj_updateGraduatedFlag(int player, int flag) {
    smm_players.flag_graduated[player] = flag;
}

// 3. Get Function
char* smmObj_getPlayerName(int player) {
    return smm_players.player_name[player]; 
}

void smmObj_setPlayerName(int player, char* name) {
    strcpy(smm_players.player_name[player], name);
}

int smmObj_getPlayerPos(int player) {
    return smm_players.player_pos[player];
}

int smmObj_getPlayerCredit(int player) {
    return smm_players.player_credit[player];
}

int smmObj_getPlayerEnergy(int player) {
    return smm_players.player_energy[player];
}

int smmObj_getGraduatedFlag(int player) {
    return smm_players.flag_graduated[player];
}

//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
	if (smm_nodeNr >= MAX_NODENR) {
		return -1;
	}
	
	smmObj_board[smm_nodeNr] = (smmObj_object_t*)malloc(sizeof(smmObj_object_t));
	if (smmObj_board[smm_nodeNr] ==NULL) {
		return -1;
	}
	
	strcpy(smmObj_board[smm_nodeNr]->smm_name, name);
  smmObj_board[smm_nodeNr]->smm_type = type;
  smmObj_board[smm_nodeNr]->smm_credit = credit;
	smmObj_board[smm_nodeNr]->smm_energy = energy;
	smmObj_board[smm_nodeNr]->smm_grade = 0; // initialization
    
  smm_nodeNr++;
    
  return (smm_nodeNr);

}



//member retrieving
char* smmObj_getNodeName(int node_nr)
{
	return(smmObj_board[node_nr]->smm_name);
}

int smmObj_getNodeType(int node_nr)
{
	return(smmObj_board[node_nr]->smm_type);
}

int smmObj_getNodeCredit(int node_nr)
{
	return(smmObj_board[node_nr]->smm_credit);
}

int smmObj_getNodeEnergy(int node_nr)
{
	return(smmObj_board[node_nr]->smm_energy);
}

char* smmObj_getTypeName(int node_type)
{
	return (smmNodeName[node_type]);
}

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

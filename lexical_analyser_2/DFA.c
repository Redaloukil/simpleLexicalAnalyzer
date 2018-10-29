#include "DFA.h"
#include <stdlib.h>
#include <string.h>

void dfa_makeNextTransition(DFA* dfa, char c)
{
	int transitionID;
	DFAState* pCurrentState = dfa->states[dfa->currentStateID];
	for (transitionID = 0; transitionID < pCurrentState->numberOfTransitions; transitionID++)
	{
		if (pCurrentState->transitions[transitionID].condition(c) == 1)
		{	
			dfa->currentStateID = pCurrentState->transitions[transitionID].toStateID;
			// return;
			
		}
	}
	printf("after reading %c the current state is : %d\n" ,c, dfa->currentStateID);
	//take the default transition
	dfa->currentStateID = pCurrentState->defaultToStateID;
	
}

void dfa_addState(DFA* pDFA, DFAState* newState)
{	
	newState->ID = pDFA->numberOfStates;
	pDFA->states[pDFA->numberOfStates] = newState;
	pDFA->numberOfStates++;
}

void dfa_addTransition(DFA* dfa, int fromStateID, int(*condition)(char), int toStateID)
{
	DFAState* state = dfa->states[fromStateID];
	state->transitions[state->numberOfTransitions].condition = condition;
	state->transitions[state->numberOfTransitions].toStateID = toStateID;
	state->numberOfTransitions++;

}

DFAState* dfa_createState(int hasAction, char* actionName)
{
	DFAState* newState = (DFAState*)malloc(sizeof(DFAState));
	strcpy(newState->actionName, actionName);
	newState->defaultToStateID = -1;
	newState->hasAction = hasAction;
	newState->ID = -1;
	newState->numberOfTransitions = 0;

	return newState;
	
}

DFA* dfa_createDFA()
{
	DFA* dfa = (DFA*)malloc(sizeof(DFA));
	dfa->numberOfStates = 0;
	dfa->startStateID = -1;
	dfa->currentStateID = -1;
	return dfa;
}

void dfa_reset(DFA* dfa)
{
	dfa->currentStateID = dfa->startStateID;
}

void intializeToken(Token *token){
	token->len = 0;
}

void addCharToken(Token *token , char c){
	token->body[token->len] = c;
	token->len = token->len + 1;
}

void analyseToken(Token *token , DFA *dfa){
	for (int i=0 ; i< token->len ; i++){
		printf("%c\n" , token->body[i]);
		dfa_makeNextTransition(dfa , token->body[i]);
	}
}
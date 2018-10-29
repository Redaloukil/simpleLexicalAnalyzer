#define _DFA_H_

#define MAX_TRANSITIONS 50
#define MAX_STATES 100
#define TOKEN_LEN 10



typedef struct
{
	int (*condition)(char); //a bool-returning and char-taking function pointer which is used to test whether this transition is to be taken.
	int toStateID;
} DFATransition;

typedef struct
{
	int ID; //unique ID associated with every state
	int hasAction; //indicates whether any action should be taken when DFA is in this state
	int numberOfTransitions; //number of outgoing transitions excluding the default (other) transition
	char actionName[256]; //the string based on which action is taken
	DFATransition transitions[MAX_TRANSITIONS]; //list of outgoing transitions
	int defaultToStateID; //the default (other) transition. This is taken when no other transition is possible
} DFAState;

typedef struct
{
	int startStateID;
	int currentStateID;
	int numberOfStates;
	DFAState* states[MAX_STATES];
} DFA;

typedef struct Token {
	char body[10];
	int len;
} Token;

DFA* dfa_createDFA();
void dfa_reset(DFA* dfa); //makes the dfa ready for consumption. i.e. sets the current state to start state.
void dfa_makeNextTransition(DFA* dfa, char c);
void dfa_addState(DFA* pDFA, DFAState* newState);
DFAState* dfa_createState(int hasAction, char* actionName);
void dfa_addTransition(DFA* dfa, int fromStateID, int(*condition)(char), int toStateID);

//Token Functions
void intializeToken(Token *token);
void addCharToken(Token *token , char c);


//Analyse with given token and automaton

void analyseToken(Token *token , DFA *dfa);
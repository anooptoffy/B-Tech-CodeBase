% nfa that accepts string with odd number of zero's

final(q1).

tran(q0,_,q0).
tran(q0,0,q1).
accepts(State,[]):-
	final(State),
	nl,
	write('string accepted').

accepts(State,[X|Rest]):-
	tran(State,X,State1),
	accepts(State1,Rest).
	
main(A):-
	accepts(q0,A).

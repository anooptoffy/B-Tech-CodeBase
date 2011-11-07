% append two list in prolog

append([],X,X).

append([H|T],L,[H|R]):-
	append(T,L,R).
main(A,B):-
	append(A,B,L),
	write(L).

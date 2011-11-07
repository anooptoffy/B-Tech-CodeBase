% print odd numbers in a given range in prolog

odd(X,Y):-
	X>Y.
odd(X,Y):-
	write(X),
	tab(6),
	Z is X+2,
	odd(Z,Y).
main(A,B):-
	C is floor((A/2))*2+1,
	odd(C,B).


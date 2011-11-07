% fibonacci series

main(V):-
	fib(0,1,V).
fib(_,_,L):-
	L<1.
fib(F,S,L):-
	L>0,
	tab(6),
	T is F+S,
	write(F),
	P is L-1,
	fib(S,T,P).
	


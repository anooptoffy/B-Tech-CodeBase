% Gcd of two numbers in prolog

gcd(X,X,X).
gcd(A,B,C):-
	A>B,
	D is A-B,
	gcd(D,B,C).
gcd(A,B,C):-
	B>A,
	D is B-A,
	gcd(A,D,C).
main(A,B):-
	gcd(A,B,C),
	write(C).

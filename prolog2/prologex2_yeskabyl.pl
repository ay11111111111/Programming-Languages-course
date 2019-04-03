cartesian( [], X, [] ).

cartesian( [F | R], X, C3) :- cartesian( R, X, C1), 
			      product( F, X, C2),
			      append( C1, C2, C3).

product( X, [], [] ). 
product( X, [ F | R ], [ pair(X,F) | L ] ) :- product( X, R, L ).


cartesian2(X,Y,Z):- findall(pair(M,N),(member(M,X),member(N,Y)),Z).

deepmember(X, [X|_]).
deepmember(X, [F | R]) :- deepmember(X, F).
deepmember(X, [F | R]) :- deepmember(X, R). 

notcontains(X, L) :- \+ member(X, L).

setinsertion(X, S1, S2) :- member(X, S1), S1 = S2.
setinsertion(X, S1, S2) :- notcontains(X, S1),
			   S2 = [X|S1].

setinsertion1(X, L, L):- member(X, L).
setinsertion1(X, L, [X|L]):- \+ member(X, L).

setinsertion2(X, L, L):- member(X, L), !.
setinsertion2(X, L, [X|L]).

				
graph1( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 4 ], [ 4, 1 ] ] ).
graph2( [ [ 1, 2 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ],
	[ 4, 3 ], [ 3, 1 ], [ 4, 1 ] ] ).
graph3( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 2 ],
	[ 3, 4 ], [ 2, 4 ], [ 4, 6 ], [ 4, 5 ],
	[ 5, 6 ], [ 6, 5 ], [ 6, 7 ], [ 5, 7 ],
	[ 7, 1 ] ] ).


allvertices([], []).
allvertices([[F, S]|Z], L) :-  allvertices(Z, L3),
				setinsertion(F, L3, L2),
				setinsertion(S, L2, L).

connected( V0, V1, G) :- S1 = [V0, V1], member(S1, G). 


path(_, V, 1, _, [V], V).
path(G, Vbegin, N, Forbidden, Path, Vend) :- 
	N1 is N - 1,
	connected(Vbegin, Next, G), 
	notcontains(Next, Forbidden), 
	path(G, Next, N1 , [Next|Forbidden], NewPath, Vend),
	Path = [Vbegin|NewPath].


hamiltoniancircuit( G, C ) :- 
	allvertices( G, Vert ),
	Vert = [ V0 | _ ],
	length( Vert, N ),
	path( G, V0, N, [ V0 ], C, LastV ),
	connected( LastV, V0, G ).

sorted([]).
sorted([X]).
sorted([F, S | T]) :- F =< S, sorted([S| T]).

permutation( [], [] ).
permutation( [ F | R1 ], R3 ) :-
	permutation( R1, R2 ), insertion( F, R2, R3 ).



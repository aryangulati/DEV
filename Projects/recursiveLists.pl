% 1. Predicate that tell if all the elements in a list are equal

equals([X,X]):- !.

equals([Header,Header|Tail]):- 
    equals([Header|Tail]).

% 2. Predicate that returns the length of a list   
 
long([],0).
long([_|Tail],Long):- 
    lon(Tail,Long1) , 
    Long is Long1+1.

% 3. Delete the first element of a list

delete([],_).
delete([_|Tail],Tail).
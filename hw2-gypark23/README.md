


    1. Essentially, both for-loop and do-while-loop I made do the same thing with two iterators i and j. Therefore, they should have the same efficiency
    and same runtime. However, it is apparent that code-lengthwise, for-loop is much shorter than do-while loop. This is because for for-loop,
    the iterators i and j could be defined within the loop condition and therefore are easy to keep track of. For do-while loop, I had to
    manually define the iterators i and j and add them at the end of the loops. Therefore, I believe for this program, for-loop is much efficient
    than do-while loop.


    2. For my solution of cipher program, I asked for the shifting integer and I added that integer to the string. The edge-caseI could
    think of in this program is if the shifting integer provided by the user is too big or negative, the decimal ascii value might be inaccurate
    and thus prints out the weird code. For example, 'z' + 100 correspond to 222, which doesn't exist in ASCII. Same thing, if a negative number is given
    and it shifts out from 0, it might also give a letter that doesn't exist. 
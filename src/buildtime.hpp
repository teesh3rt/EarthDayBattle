/*  buildtime.h

    This file is used to let VSCode know of defined variables
    and set defaults for them in the case they are not defined.
    (usually when the builder uses a build system other than the one we have set up)

    In which case, why are you being the bane of my existence.
    Of your existence too actually, you need those variables for compilation success.
*/

#ifndef GIT_HASH
#define GIT_HASH "UNKNOWN"
#endif // GIT_HASH
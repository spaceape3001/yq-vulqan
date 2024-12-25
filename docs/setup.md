#! Setup & Configuration

Setting up to use this library... options are
1.  Symbolic link (either as `yq-toolbox` and `toolbox`)
2.  Include from a greater project
    
    project/
        CMakeLists.txt (which adds the two submodules)
        yq-toolbox/
        yq-vulqan/

**NOTE** This method allows for GIT-worktree gymnastics.  For instance, mine is like..

    code/
        toolbox/
            dev/
                Debug/
                src/
            master/
                Release/
                src/
        vulqan/
            dev/
                Debug/
                src/
                    yq-toolbox (symbolic link to code/toolbox/dev/src)
            master/
                Release/
                src/
                    yq-toolbox (symbolic link to code/toolbox/master/src)
           



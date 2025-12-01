////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

void    help()
{
    std::cout <<R"VOGON(
    recode [cmd/options] <input> <output>
    
    Tool for recoding assets; ie, coordinate transforms on meshes, inflating/shrinking images, etc.
    
    A simple reformatting can be done with (or even extraction with URL syntax)
    
        recode MyImage.jpg MyImage.png
        
)VOGON" ;
}

int main(int argc, char* argv[])
{
    if(argc < 3){
        help();
        return 0;
    }
    
    //  yep... figuring this out....
    
    return 0;
}

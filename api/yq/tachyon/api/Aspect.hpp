////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    /*
        Nothing here, not really, simply an annotation to the goal of an 
        aspect.
        
        It's meant to be a simple little thing to capture a property
        and notify of change.
        
        CONVENTIONS
            A${name}    Aspect itself (not templated)
            C${name}    Templated aspect, which will derive from A${name}
            
            As a general rule, a tachyon should only derive from either A${name} or ONE 
            C${name} for a particular ${name}.
            
            (Tree will be the most important to keep straight, BTW.)
    */
}

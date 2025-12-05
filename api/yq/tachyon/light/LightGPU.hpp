////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/config/glm.hpp>

namespace yq::tachyon {

    //! Light uniform buffer object (common to all shaders)
    struct LightUBO {
        struct Span {
            uint32_t  begin, end;
        };
        
        glm::vec4   gamma = { 1., 1., 1., 1. };
        
        Span        ambient;   // indices into the buffer
        Span        uni;
        Span        plane;
        Span        point;
        Span        spot;
    };
    
    //! Light storage buffer object (common to all shaders)
    struct LightSBOData {
        glm::vec4   rgbi;
        //glm::vec3   pt;
        //float       dd;     // cos cone angle for spot, "D" for plane
        //glm::vec3   dir;
        //float       pow;    // corrective power???
        //float       fk, fl, f1, f2;
    };
}

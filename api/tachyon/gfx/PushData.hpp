////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/config/glm.hpp>
#include <tachyon/config/vulqan.hpp>

namespace yq::tachyon {

    //  COMMON cards have 256 byte restriction, each mat4 is 64 bytes, whereas dmat4 is 128

    //! Standard Push Data
    struct StdPushData {
        //! Either a model -> screen matrix, or world -> screen matrix, depending on the enumeration
        glm::mat4   matrix      = {};
        
        //! Color by color gamma multipliers
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        
        //! Primary color for object
        glm::vec4   pricolor    = {};
        
        //! Secondary color for object
        glm::vec4   seccolor    = {};
        
        //! Clock time
        float       time        = 0;
    };
    
    static_assert(sizeof(StdPushData) <= MAX_PUSH);
    
    struct StdPushDataMVP {
        glm::mat4   model; 
        glm::mat4   view; 
        glm::mat4   projection; 

        //! Color by color gamma multipliers
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        
        //! Primary color for object
        glm::vec4   pricolor    = {};
        
        //! Secondary color for object
        glm::vec4   seccolor    = {};
        
        //! Clock time
        float       time        = 0;
        
        //  And this structure has 12 bytes to spare...
    };

    static_assert(sizeof(StdPushDataMVP) <= MAX_PUSH);

    struct StdPushDataViewProj {
        glm::mat4   view; 
        glm::mat4   projection; 

        //! Color by color gamma multipliers
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        
        //! Primary color for object
        glm::vec4   pricolor    = {};
        
        //! Secondary color for object
        glm::vec4   seccolor    = {};
        
        //! Clock time
        float       time        = 0;
    };

    static_assert(sizeof(StdPushDataViewProj) <= MAX_PUSH);

    struct StdPushDataView64Proj {
        glm::dmat4  view; 
        glm::mat4   projection; 

        //! Color by color gamma multipliers
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        
        //! Primary color for object
        glm::vec4   pricolor    = {};
        
        //! Secondary color for object
        glm::vec4   seccolor    = {};
        
        //! Clock time
        float       time        = 0;
        
        //  And this structure has 12 bytes to spare...
    };

    static_assert(sizeof(StdPushDataView64Proj) <= MAX_PUSH);
}

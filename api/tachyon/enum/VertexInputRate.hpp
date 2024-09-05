////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

namespace yq::tachyon {

    //! Vertex Input Rate
    YQ_ENUM(VertexInputRate, , 
    
        //! Vertex based Vertex Input Rate
        Vertex = 0,
        
        //! Instance based Vertex Input Rate
        Instance = 1
    )
}
YQ_TYPE_DECLARE(yq::tachyon::VertexInputRate)

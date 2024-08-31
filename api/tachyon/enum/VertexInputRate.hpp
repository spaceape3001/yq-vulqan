////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

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

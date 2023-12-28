////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Topology 
    
        This is the topology of an object going into the pipeline to be rendered.
    */
    YQ_ENUM(Topology, , 
        //! List of points
        PointList = 0,
        
        //! Line list
        LineList = 1,
        
        //! Line strip
        LineStrip = 2,
        
        //! List of triangles
        TriangleList = 3,
        
        //! Triangle strip
        TriangleStrip = 4,
        
        //! Triangle fan
        TriangleFan = 5,
        
        //! Line list with adjacency
        LineListWithAdjacency = 6,
        
        //! Line strip with adjacency
        LineStripWithAdjacency = 7,
        
        //! Triangle list with adjacency
        TriangleListWithAdjacency = 8,
        
        //! Triangle strip with adjacency
        TriangleStripWithAdjacency = 9,
        
        //! Patch list
        //! (note, use this if you're doing GPU tessellation)
        PatchList = 10
    )
}

YQ_TYPE_DECLARE(yq::tachyon::Topology)

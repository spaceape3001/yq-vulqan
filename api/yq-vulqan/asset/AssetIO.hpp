////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Any.hpp>
#include <yq-toolbox/typedef/string_maps.hpp>

namespace yq::tachyon {
    enum class FileCollisionStrategy {
        Abort,
        Overwrite,
        Backup
    };
    
    struct AssetLoadOptions {
        //! Generic parameter map... 
        string_any_map_t            parameters;
    };
    
    struct AssetSaveOptions {
        //! How to deal with file collisions (on drive)
        FileCollisionStrategy       collision   = FileCollisionStrategy::Abort;
        
        //! TRUE to set the name.  (CAUTION, don't do this with cached-assets)
        bool                        set_name    = false;

        //! Generic parameter map... 
        string_any_map_t            parameters;
    };
}

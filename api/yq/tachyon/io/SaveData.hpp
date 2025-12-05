////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/io/SaveTypes.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/typedef/any_maps.hpp>
#include <yq/typedef/string_maps.hpp>

namespace yq::tachyon {
    struct ObjectSave {
        std::string             class_;
        template_t              origin; 
        save_str_value_xmap_t   properties;
    };
    
    
    struct StateSave {
        save_str_value_xmap_t   ustate;
        save_u32_value_mmap_t   pstate;
        
        save_value_t            state(uint32_t) const;
        save_value_t            state(const std::string&) const;
    };
    
    struct DelegateSave : public ObjectSave, public StateSave {
        uint64_t                id      = 0;
        
        // expect delegates to fill in (& read)
    };


    struct TachyonSave : public ObjectSave, public StateSave {
        uint64_t                id      = 0;
        uint64_t                parent  = 0;
        owner_spec_t            owner;
        string_u64_xmap_t       delegates;
        string_url_xmap_t       resources;
        std::vector<uint64_t>   children;
        string_any_map_t        uattrs;     // user defined attributes
        uint32_any_map_t        pattrs;     // programmatically defined attributes (note, integer must be FIXED, forever)
    };
    
    struct ThreadSave : public TachyonSave {
    };
}

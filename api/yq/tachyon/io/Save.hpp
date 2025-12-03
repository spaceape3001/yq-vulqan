////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/enum/SaveFlags.hpp>
#include <yq/tachyon/enum/SaveType.hpp>
#include <yq/tachyon/typedef/builder.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/typedef/string_maps.hpp>
#include <variant>

namespace yq::tachyon {
    class Tachyon;
    class Delegate;

    struct ObjectSave {
        std::string             type;
        string_any_xmap_t       properties;

        // TODO overrides
    };
    
    struct DelegateSave : public ObjectSave {
        uint64_t                id      = 0;
        string_any_xmap_t       state;
        string_u64_xmap_t       ids;    // IDs that are being referenced as these will need to be remapped
    };

    using owner_spec_t = std::variant<std::monostate, uint64_t, StdThread>;

    struct TachyonSave : public ObjectSave {
        uint64_t                id      = 0;
        uint64_t                parent  = 0;
        owner_spec_t            owner;
        string_any_xmap_t       state;      // Normal state data
        string_u64_xmmap_t      stateIDs;   // IDs that are being referenced as these need to be remapped
        string_u64_xmap_t       delegates;
        string_url_xmap_t       resources;
        std::vector<uint64_t>   children;
    };
    
    struct ThreadSave : public TachyonSave {
    };

    struct ReincarnationConfig {
        TachyonID           parent;     //!< Used to force a parent (owner check auto-disabled)
        string_any_map_t    variables;  //!< Used to override anything in the save
        ThreadSpec          owner;      //!< Set to override threads (if scheduling)
    };

    /*! \brief Threads
    
        \note Game saving shouldn't happen until *AFTER* the application has started with all threads running. 
    *//*
        Implementation notes:
        1)  Starting with pure save/load
        2)  Will factor in the template stuff later (might need a hybrid ID system)
    */
    class Save : public Resource {
        YQ_RESOURCE_DECLARE(Save, Resource)
    public:
    
        Save();
        virtual ~Save();
        
        static void    init_meta();
        
        Save& operator<<(const Object&);
        
        template <typename T>
        struct SMap {
            std::vector<T>              data;
            std::map<uint64_t,size_t>   byId;
        };
        
        SMap<DelegateSave>    delegates;
        SaveFlags             flags;
        SMap<TachyonSave>     tachyons;
        SMap<ThreadSave>      threads;
        SaveType              type = SaveType::General;
        
        size_t                data_size() const override;

        DelegateSave&   _delegate(const Delegate&);
        TachyonSave&    _tachyon(const Tachyon&);
        ThreadSave&     _thread(const Thread&);
    };
}

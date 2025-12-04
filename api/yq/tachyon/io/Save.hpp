////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/enum/SaveFlags.hpp>
#include <yq/tachyon/enum/SaveType.hpp>
#include <yq/tachyon/typedef/builder.hpp>
#include <yq/tachyon/typedef/save.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/typedef/any_maps.hpp>
#include <yq/typedef/string_maps.hpp>
#include <variant>

namespace yq::tachyon {
    class Tachyon;
    class Delegate;

    using save_origin_t          = std::variant<std::monostate, std::string, Url>;
    using save_value_t           = std::variant<std::monostate, Any, uint64_t>;
    using save_key_t             = std::variant<std::monostate, uint32_t, std::string>;
    using save_u32_value_map_t   = std::map<uint32_t, save_value_t>;
    using save_str_value_map_t   = std::map<std::string, save_value_t, IgCase>;
    using save_str_value_xmap_t  = std::map<std::string, save_value_t>;

    using save_u32_value_mmap_t  = std::multimap<uint32_t, save_value_t>;
    using save_str_value_mmap_t  = std::multimap<std::string, save_value_t, IgCase>;
    using save_str_value_xmmap_t = std::multimap<std::string, save_value_t>;

    struct ObjectSave {
        std::string             class_;
        string_u64_xmap_t       idprops;
        save_origin_t           origin; 
        save_str_value_xmap_t   properties;
    };
    
    using uint32_u64_mmap_t     = std::multimap<uint32_t, uint64_t>;
    
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

    using owner_spec_t = std::variant<std::monostate, uint64_t, StdThread>;

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

    struct ReincarnationConfig {
        TachyonID               parent;     //!< Used to force a parent (owner check auto-disabled)
        save_str_value_map_t    variables;  //!< Used to override anything in the save
        ThreadSpec              owner;      //!< Set to override threads (if scheduling)
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
        void    add(const Object&);
        
        template <typename T>
        struct SMap {
            std::vector<T>              data;
            std::map<uint64_t,size_t>   byId;
        };
        
        SMap<DelegateSave>      delegates;
        SaveFlags               flags;
        SMap<TachyonSave>       tachyons;
        SMap<ThreadSave>        threads;
        SaveType                type = SaveType::General;
        std::vector<Url>        uses;
        
        size_t                data_size() const override;

        DelegateSave&   _delegate(const Delegate&);
        TachyonSave&    _tachyon(const Tachyon&);
        ThreadSave&     _thread(const Thread&);
        
        size_t              count(delegate_k) const;
        size_t              count(tachyon_k) const;
        size_t              count(thread_k) const;
        
        const DelegateSave* delegate(uint64_t) const;
        const TachyonSave*  tachyon(uint64_t) const;
        const ThreadSave*   thread(uint64_t) const;

        /*! \brief Executes the save to create new tachyons
        
            \note This one does not schedule the tachyons onto any threads... that's left 
            to the caller
        */
        std::error_code         execute(TachyonPtrVector&, const ReincarnationConfig&cfg={}) const;
        
        /*! \brief Executes the save to create & schedule new tachyons
        */
        std::error_code         execute(schedule_k, const ReincarnationConfig&cfg={}, TachyonIDSet* pIDs=nullptr) const;
        
        struct Reincarnator;
    };
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/save.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/core/Ref.hpp>
//#include <tbb/spin_rw_mutex.h>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/typedef/string_maps.hpp>

namespace yq {
    class Object;
    class ObjectMeta;
    class PropertyMeta;
    class Resource;
    class ResourceMeta;
}

namespace yq::tachyon {

    class Delegate;
    class DelegateMeta;
    class Tachyon;
    class TachyonMeta;
    class Thread;
    class ThreadMeta;
        
    class SaveResource;
    class SaveDelegate;
    class SaveObject;
    class SaveTachyon;
    class SaveThread;

    struct ReincarnationConfig {
        TachyonID           parent;     //!< Used to force a parent (owner check auto-disabled)
        string_any_map_t    variables;  //!< Used to override anything in the save
        ThreadSpec          owner;      //!< Set to override threads (if scheduling)
    };

    class Save {
    public:
        
        SaveDelegate*           delegate(uint64_t);
        const SaveDelegate*     delegate(uint64_t) const;
        SaveObject*             object(uint64_t);
        const SaveObject*       object(uint64_t) const;
        SaveResource*           resource(uint64_t);
        const SaveResource*     resource(uint64_t) const;
        SaveTachyon*            tachyon(uint64_t);
        const SaveTachyon*      tachyon(uint64_t) const;
        SaveThread*             thread(uint64_t);
        const SaveThread*       thread(uint64_t) const;

        Save(SaveOptions opts={});
        ~Save();
        
        SaveDelegate*           insert(const Delegate&);
        //SaveObject*             insert(const Object&); // disabled until we've got a supported path
        SaveResource*              insert(const Resource&);
        SaveThread*             insert(const Thread&);
        SaveTachyon*            insert(const Tachyon&);
        
        SaveDelegate*           create(const DelegateMeta*);
        //SaveObject*             create(const ObjectMeta*); // disabled until we've got a supported path
        SaveResource*           create(const ResourceMeta*, const std::filesystem::path&);
        SaveTachyon*            create(const TachyonMeta*);
        SaveThread*             create(const ThreadMeta*);
        
        //! Let us know what the resource paths are (used for saving)
        void    add_resource_path(const std::filesystem::path&);
        
        size_t                  count(object_k) const;
        
        //! Finishes the save for saving (whatever needs to be done)
        void    bake() { _bake(); }
        
    
        std::filesystem::path    relativize(const std::filesystem::path&) const;
    
        using ObjectMap     = std::map<uint64_t, SaveObject*>;
        
        const ObjectMap&            objects() const { return m_objects; }
        const string_any_map_t&     variables() const { return m_variables; }
    
        void    add_variable(const std::string&, Any&&);
    
        std::optional<StdThread>   std_thread(ThreadID) const;
        
        void    build();
        
        bool    record_owners() const { return !m_options(SaveOption::SkipOwnership); }
        bool    option(SaveOption so) const { return m_options(so); }
        
        /*! \brief Executes the save to create new tachyons
        
            \note This one does not schedule the tachyons onto any threads... that's left 
            to the caller
        */
        std::error_code         execute(TachyonPtrVector&, const ReincarnationConfig&cfg={}) const;
        
        /*! \brief Executes the save to create & schedule new tachyons
        */
        std::error_code         execute(schedule_k, const ReincarnationConfig&cfg={}, TachyonIDSet* pIDs=nullptr) const;
        
    private:
        ObjectMap                           m_objects;
        string_any_map_t                    m_variables;
        std::vector<std::filesystem::path>  m_resourcePath;
        StdThreadRevMap                     m_threads;
        SaveOptions                         m_options = {};
        bool                                m_prepped   = false;
        //mutable tbb::spin_rw_mutex          m_mutex;

        //! Prepares the save for saving (call before insert/add-resource-path)
        void    _prep();
        
        void    _bake();
        
        SaveObject*             saver(const Object&);
        
        static SaveObject*      save_resource(Save&, const Object&);
        static SaveObject*      save_delegate(Save&, const Object&);
        static SaveObject*      save_object(Save&, const Object&);
        static SaveObject*      save_nullptr(Save&, const Object&);
        static SaveObject*      save_tachyon(Save&, const Object&);
        static SaveObject*      save_thread(Save&, const Object&);
        static SaveObject*      samk(Save&, const Object&);
        
        struct Reincarnator;
    };
}


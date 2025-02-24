////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yt/keywords.hpp>
#include <yt/typedef/save.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/typedef/thread.hpp>
#include <yt/api/ID.hpp>
#include <yq/core/Ref.hpp>
//#include <tbb/spin_rw_mutex.h>
#include <yt/api/StdThread.hpp>
#include <yq/typedef/string_maps.hpp>

namespace yq {
    class Object;
    class ObjectInfo;
    class PropertyInfo;
    class Asset;
    class AssetInfo;
}

namespace yq::tachyon {

    class Delegate;
    class DelegateInfo;
    class Resource;
    class Tachyon;
    class TachyonInfo;
    class Thread;
    class ThreadInfo;
        
    class SaveAsset;
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
        
        SaveAsset*              asset(uint64_t);
        const SaveAsset*        asset(uint64_t) const;
        SaveDelegate*           delegate(uint64_t);
        const SaveDelegate*     delegate(uint64_t) const;
        SaveObject*             object(uint64_t);
        const SaveObject*       object(uint64_t) const;
        SaveTachyon*            tachyon(uint64_t);
        const SaveTachyon*      tachyon(uint64_t) const;
        SaveThread*             thread(uint64_t);
        const SaveThread*       thread(uint64_t) const;

        Save(SaveOptions opts={});
        ~Save();
        
        SaveAsset*              insert(const Asset&);
        SaveDelegate*           insert(const Delegate&);
        //SaveObject*             insert(const Object&); // disabled until we've got a supported path
        SaveThread*             insert(const Thread&);
        SaveTachyon*            insert(const Tachyon&);
        
        SaveAsset*              create(const AssetInfo*, const std::filesystem::path&);
        SaveDelegate*           create(const DelegateInfo*);
        //SaveObject*             create(const ObjectInfo*); // disabled until we've got a supported path
        SaveTachyon*            create(const TachyonInfo*);
        SaveThread*             create(const ThreadInfo*);
        
        //! Let us know what the asset paths are (used for saving)
        void    add_asset_path(const std::filesystem::path&);
        
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
        std::error_code         execute(schedule_k, const ReincarnationConfig&cfg={}) const;
        
    private:
        ObjectMap                           m_objects;
        string_any_map_t                    m_variables;
        std::vector<std::filesystem::path>  m_assetPath;
        StdThreadRevMap                     m_threads;
        SaveOptions                         m_options = {};
        bool                                m_prepped   = false;
        //mutable tbb::spin_rw_mutex          m_mutex;

        //! Prepares the save for saving (call before insert/add-asset-path)
        void    _prep();
        
        void    _bake();
        
        SaveObject*             saver(const Object&);
        
        static SaveObject*      save_asset(Save&, const Object&);
        static SaveObject*      save_delegate(Save&, const Object&);
        static SaveObject*      save_object(Save&, const Object&);
        static SaveObject*      save_nullptr(Save&, const Object&);
        static SaveObject*      save_tachyon(Save&, const Object&);
        static SaveObject*      save_thread(Save&, const Object&);
        static SaveObject*      samk(Save&, const Object&);
        
        struct Reincarnator;
    };
}


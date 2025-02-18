////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yt/keywords.hpp>
//#include <tbb/spin_rw_mutex.h>
#include <yt/api/StdThread.hpp>

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

        Save();
        ~Save();
        
        SaveAsset*              insert(const Asset&);
        SaveDelegate*           insert(const Delegate&);
        SaveObject*             insert(const Object&);
        SaveThread*             insert(const Thread&);
        SaveTachyon*            insert(const Tachyon&);
        
        SaveAsset*              create(const AssetInfo*, const std::filesystem::path&);
        SaveDelegate*           create(const DelegateInfo*);
        SaveObject*             create(const ObjectInfo*);
        SaveTachyon*            create(const TachyonInfo*);
        SaveThread*             create(const ThreadInfo*);
        
        //! Let us know what the asset paths are (used for saving)
        void    add_asset_path(const std::filesystem::path&);
        
        size_t                  count(object_k) const;
        
        //! Finishes the save for saving (whatever needs to be done)
        void    bake() { _bake(); }
        
    
        std::filesystem::path    relativize(const std::filesystem::path&) const;
    
        using ObjectMap     = std::map<uint64_t, SaveObject*>;
        using VariableMap   = std::map<std::string, Any, IgCase>;
        
        const ObjectMap&    objects() const { return m_objects; }
        const VariableMap&  variables() const { return m_variables; }
    
        void    add_variable(const std::string&, Any&&);
    
        std::optional<StdThread>   std_thread(ThreadID) const;
        
        void    build();
    
    private:
        ObjectMap                           m_objects;
        VariableMap                         m_variables;
        std::vector<std::filesystem::path>  m_assetPath;
        bool                                m_prepped   = false;
        StdThreadRevMap                     m_threads;
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
    };
}


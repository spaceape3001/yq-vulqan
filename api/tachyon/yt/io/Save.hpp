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

namespace yq {
    class Object;
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
        
    class SaveAsset;
    class SaveDelegate;
    class SaveObject;
    class SaveResource;
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
        SaveResource*           resource(uint64_t);
        const SaveResource*     resource(uint64_t) const;
        SaveTachyon*            tachyon(uint64_t);
        const SaveTachyon*      tachyon(uint64_t) const;
        SaveThread*             thread(uint64_t);
        const SaveThread*       thread(uint64_t) const;

        Save();
        ~Save();
        
        SaveAsset*              insert(const Asset&);
        SaveDelegate*           insert(const Delegate&);
        SaveObject*             insert(const Object&);
        SaveResource*           insert(const Resource&);
        SaveThread*             insert(const Thread&);
        SaveTachyon*            insert(const Tachyon&);
    
    private:
        std::map<uint64_t, SaveObject*>     m_objects;
        std::map<std::string, Any, IgCase>  m_variables;
        //mutable tbb::spin_rw_mutex          m_mutex;
        
        SaveObject*             saver(const Object&);
        
        static SaveObject*      save_asset(Save&, const Object&);
        static SaveObject*      save_delegate(Save&, const Object&);
        static SaveObject*      save_object(Save&, const Object&);
        static SaveObject*      save_nullptr(Save&, const Object&);
        static SaveObject*      save_resource(Save&, const Object&);
        static SaveObject*      save_tachyon(Save&, const Object&);
        static SaveObject*      save_thread(Save&, const Object&);
        static SaveObject*      samk(Save&, const Object&);
    };
}


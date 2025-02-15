////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yt/keywords.hpp>

namespace yq {
    class Object;
    class PropertyInfo;
    class Asset;
    class AssetInfo;
}

namespace yq::tachyon {

    class Delegate;
    class DelegateInfo;
    class Tachyon;
    class TachyonInfo;
        
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
    
    private:
        std::map<uint64_t, SaveObject*>     m_objects;
        std::map<std::string, Any, IgCase>  m_variables;
    };
}


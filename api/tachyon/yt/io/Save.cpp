////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yt/api/Delegate.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/Resource.hpp>
#include <yt/tags.hpp>
#include <yq/meta/ObjectInfo.hpp>
#include <yq/meta/PropertyInfo.hpp>
#include <yt/io/save/SaveAsset.hpp>
#include <yt/io/save/SaveDelegate.hpp>
#include <yt/io/save/SaveObject.hpp>
#include <yt/io/save/SaveResource.hpp>
#include <yt/io/save/SaveTachyon.hpp>
#include <yt/io/save/SaveThread.hpp>

namespace yq::tachyon {
    Save::Save()
    {
    }
    
    Save::~Save()
    {
        for(auto itr : m_objects){
            delete itr.second;
        }
        m_objects.clear();
    }

    SaveAsset*              Save::asset(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj -> isAsset())
            return static_cast<SaveAsset*>(obj);
        return nullptr;
    }
    
    const SaveAsset*        Save::asset(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj -> isAsset())
            return static_cast<const SaveAsset*>(obj);
        return nullptr;
    }
    
    SaveDelegate*           Save::delegate(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj -> isDelegate())
            return static_cast<SaveDelegate*>(obj);
        return nullptr;
    }
    
    const SaveDelegate*     Save::delegate(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj -> isDelegate())
            return static_cast<const SaveDelegate*>(obj);
        return nullptr;
    }
    
    SaveObject*             Save::object(uint64_t i)
    {
        auto itr = m_objects.find(i);
        if(itr != m_objects.end())
            return itr->second;
        return nullptr;
    }
    
    const SaveObject*       Save::object(uint64_t i) const
    {
        auto itr = m_objects.find(i);
        if(itr != m_objects.end())
            return itr->second;
        return nullptr;
    }
    
    SaveResource*           Save::resource(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj -> isResource())
            return static_cast<SaveResource*>(obj);
        return nullptr;
    }
    
    const SaveResource*     Save::resource(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj -> isResource())
            return static_cast<const SaveResource*>(obj);
        return nullptr;
    }
    
    SaveTachyon*            Save::tachyon(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj -> isTachyon())
            return static_cast<SaveTachyon*>(obj);
        return nullptr;
    }
    
    const SaveTachyon*      Save::tachyon(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj -> isTachyon())
            return static_cast<const SaveTachyon*>(obj);
        return nullptr;
    }
    
    SaveThread*             Save::thread(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj -> isThread())
            return static_cast<SaveThread*>(obj);
        return nullptr;
    }
    
    const SaveThread*       Save::thread(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj -> isThread())
            return static_cast<const SaveThread*>(obj);
        return nullptr;
    }
}

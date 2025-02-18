////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yt/api/Delegate.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/Thread.hpp>
#include <yt/tags.hpp>
#include <yq/meta/ObjectInfo.hpp>
#include <yq/meta/PropertyInfo.hpp>
#include <yt/io/save/SaveAsset.hpp>
#include <yt/io/save/SaveDelegate.hpp>
#include <yt/io/save/SaveObject.hpp>
#include <yt/io/save/SaveTachyon.hpp>
#include <yt/io/save/SaveThread.hpp>
#include <yq/asset/Asset.hpp>
#include <yq/file/FileResolver.hpp>
#include <tbb/spin_rw_mutex.h>

namespace yq::tachyon {
    static bool has_dotdot(const std::filesystem::path& fp)
    {
        for(auto& i : fp){
            if(i == "..")
                return true;
        }
        return false;
    }

    SaveObject* Save::samk(Save&save, const Object& obj)
    {
        typedef SaveObject* (*FN)(Save&, const Object&);
        static std::unordered_map<uint32_t, FN> s_functions;
        static tbb::spin_rw_mutex               s_mutex;
        
        FN  fn  = nullptr;
        
        {
            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, false);
            auto i = s_functions.find(obj.metaInfo().id());
            if(i != s_functions.end()){
                fn  = i->second;
            }
        }
        
        if(!fn){
            if(dynamic_cast<const Asset*>(&obj)){
                fn  = &Save::save_asset;
            } 
            
            if(dynamic_cast<const Delegate*>(&obj)){
                fn      = &Save::save_delegate;
            }
            
            if(dynamic_cast<const Tachyon*>(&obj)){
                if(dynamic_cast<const Thread*>(&obj)){
                    fn  = &Save::save_thread;
                } else {
                    fn  = &Save::save_tachyon;
                }
            }
            
            if(!fn){
                if(dynamic_cast<const UniqueID*>(&obj)){
                    fn      = &Save::save_object;
                } else {
                    fn      = &Save::save_nullptr;
                }
            }

            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, true);
            s_functions[obj.metaInfo().id()]    = fn;
        }
        
        return (*fn)(save, obj);
    }

    SaveObject* Save::save_asset(Save&save, const Object&obj)
    {
        return new SaveAsset(save, dynamic_cast<const Asset&>(obj));
    }
    
    SaveObject* Save::save_delegate(Save&save, const Object&obj)
    {
        return new SaveDelegate(save, dynamic_cast<const Delegate&>(obj));
    }
    
    SaveObject* Save::save_nullptr(Save&, const Object&)
    {
        return nullptr;
    }

    SaveObject* Save::save_object(Save&save, const Object&obj)
    {
        return new SaveObject(save, obj, dynamic_cast<const UniqueID&>(obj).id());
    }
    
    SaveObject* Save::save_tachyon(Save&save, const Object&obj)
    {
        return new SaveTachyon(save, dynamic_cast<const Tachyon&>(obj));
    }
    
    SaveObject* Save::save_thread(Save&save, const Object&obj)
    {
        return new SaveThread(save, dynamic_cast<const Thread&>(obj));
    }

    ////////////////////////////////////////////////////////////////////////////////

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

    void    Save::_bake()
    {
        //  currently nothing...but here nonetheless
    }

    void    Save::_prep()
    {
        if(m_prepped)
            return;
        m_assetPath = Asset::resolver().paths();
        m_prepped   = true;
        m_threads   = Thread::standard_thread_reverse_map();
    }

    void    Save::add_asset_path(const std::filesystem::path&fp)
    {
        _prep();
        m_assetPath.push_back(fp);
    }

    void    Save::add_variable(const std::string& k, Any&&v)
    {
        m_variables[k] = std::move(v);
    }

    SaveAsset*              Save::asset(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isAsset())
            return static_cast<SaveAsset*>(obj);
        return nullptr;
    }
    
    const SaveAsset*        Save::asset(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isAsset())
            return static_cast<const SaveAsset*>(obj);
        return nullptr;
    }

    void    Save::build()
    {
    }
    
    size_t                  Save::count(object_k) const
    {
        return m_objects.size();
    }

    SaveAsset*              Save::create(const AssetInfo*info, const std::filesystem::path& fp)
    {
        uint64_t id = 1+m_objects.size();
        SaveAsset* ret = new SaveAsset(*this, info, id, fp);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveDelegate*           Save::create(const DelegateInfo*info)
    {
        uint64_t id = 1+m_objects.size();
        SaveDelegate* ret = new SaveDelegate(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveObject*             Save::create(const ObjectInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveObject* ret = new SaveObject(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveTachyon*            Save::create(const TachyonInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveTachyon* ret = new SaveTachyon(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveThread*             Save::create(const ThreadInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveThread* ret = new SaveThread(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }

    SaveDelegate*           Save::delegate(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isDelegate())
            return static_cast<SaveDelegate*>(obj);
        return nullptr;
    }
    
    const SaveDelegate*     Save::delegate(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isDelegate())
            return static_cast<const SaveDelegate*>(obj);
        return nullptr;
    }

    SaveAsset*    Save::insert(const Asset& a)
    {
        return dynamic_cast<SaveAsset*>(saver(a));
    }
    
    SaveDelegate*    Save::insert(const Delegate&d)
    {
        return dynamic_cast<SaveDelegate*>(saver(d));
    }
    
    SaveObject*    Save::insert(const Object& obj)
    {
        return saver(obj);
    }
    
    SaveTachyon*    Save::insert(const Tachyon& tac)
    {
        return dynamic_cast<SaveTachyon*>(saver(tac));
    }
    
    SaveThread*    Save::insert(const Thread&th)
    {
        return dynamic_cast<SaveThread*>(saver(th));
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

    std::filesystem::path    Save::relativize(const std::filesystem::path&fp) const
    {
        for(const std::filesystem::path& dir : m_assetPath){
            std::filesystem::path rfile = fp.lexically_relative(dir);
            if(!has_dotdot(rfile))
                return rfile;
        }
        return fp;
    }
    
    SaveObject*             Save::saver(const Object& obj)
    {
        _prep();
        const UniqueID* uuid = dynamic_cast<const UniqueID*>(&obj);
        if(!uuid)
            return nullptr;
        
        auto [itr, ins]    = m_objects.emplace(uuid->id(), nullptr);
        if(ins){
            itr->second = samk(*this, obj);
            itr->second->m_remapId  = m_objects.size();
        }
        return itr->second;
    }

    std::optional<StdThread>    Save::std_thread(ThreadID id) const
    {
        auto i = m_threads.find(id);
        if(i!=m_threads.end())
            return i->second;
        return {};
    }
    
    SaveTachyon*            Save::tachyon(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isTachyon())
            return static_cast<SaveTachyon*>(obj);
        return nullptr;
    }
    
    const SaveTachyon*      Save::tachyon(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isTachyon())
            return static_cast<const SaveTachyon*>(obj);
        return nullptr;
    }
    
    SaveThread*             Save::thread(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isThread())
            return static_cast<SaveThread*>(obj);
        return nullptr;
    }
    
    const SaveThread*       Save::thread(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isThread())
            return static_cast<const SaveThread*>(obj);
        return nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/asset/AssetCache.hpp>
#include <tachyon/asset/Asset.hpp>

namespace yq {
    namespace tachyon {

        const Asset*    AssetCache::_find(const std::filesystem::path&p) const
        {
            tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
            auto j = m_byPath.find(p);
            if(j != m_byPath.end())
                return j->second;
            return nullptr;
        }
        
        const Asset*    AssetCache::_find(uint64_t i) const
        {
            tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
            auto j = m_byId.find(i);
            if(j != m_byId.end())
                return j->second;
            return nullptr;
        }
        
        const Asset*    AssetCache::_insert(const Asset* a)
        {
            if(!a)
                return nullptr;
                
            tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, true);
            auto [i,f]  = m_byId.try_emplace(a->id(),a);
            if(!f)
                return i->second;
            m_byPath[a->filepath()] = a;    // clober
            return nullptr;
        }
        
        
        AssetCache::AssetCache()
        {
        }
        
        AssetCache::~AssetCache()
        {
        }
    }
}

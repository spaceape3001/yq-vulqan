////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <tbb/spin_rw_mutex.h>
#include <unordered_map>

namespace yq::tachyon {
    struct ViVisualizer;

    template <typename V, typename A>
    class ViAssetManager {
    public:
        
        using v_ptr_t           = Ref<V>;
        using v_cptr_t          = Ref<const V>;
        using map_t             = std::unordered_map<uint64_t, v_cptr_t>;
        using mutex_t           = tbb::spin_rw_mutex;
        
        ViAssetManager(ViVisualizer& viz) : m_viz(viz) {}
        ~ViAssetManager()
        {
            cleanup();
        }
    
        void            cleanup()
        {
            m_hash.clear();
        }
        
        v_cptr_t    create(const A& asset)
        {
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(asset.id());
                if(j != m_hash.end())
                    return j->second;
            }

            v_cptr_t    ret, p;
            
            p       = new V(m_viz, asset);
            if(!p->valid())
                return {};
            
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto [j,f]  = m_hash.try_emplace(asset.id(), p);
                if(f){
                    std::swap(p, ret);
                } else
                    ret = j->second;
            }

            return ret;
        }
        
        void            erase(const A& asset)
        {
            erase(asset.id());
        }
        
        void            erase(uint64_t i)
        {
            v_cptr_t    va;
            {
                mutex_t::scoped_lock _lock(m_mutex, true);
                auto j  = m_hash.find(i);
                if(j != m_hash.end()){
                    std::swap(va,j->second);
                    m_hash.erase(j);
                }
            }
        }
        
        v_cptr_t    get(uint64_t i) const
        {
            {
                mutex_t::scoped_lock _lock(m_mutex, false);
                auto j = m_hash.find(i);
                if(j != m_hash.end())
                    return j->second;
            }

            return {};
        }
        
        bool            has(uint64_t i) const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.contains(i);
        }

    private:
        ViAssetManager(const ViAssetManager&) = delete;
        ViAssetManager(ViAssetManager&&) = delete;
        ViAssetManager& operator=(const ViAssetManager&) = delete;
        ViAssetManager& operator=(ViAssetManager&&) = delete;
        
        map_t               m_hash;
        mutable mutex_t     m_mutex;
        ViVisualizer&       m_viz;
    };
}

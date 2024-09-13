////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/trait/indices.hpp>
#include <tbb/spin_rw_mutex.h>
#include <tuple>
#include <unordered_map>

namespace yq::tachyon {
    struct ViVisualizer;

    template <typename V, typename A, typename ... Args>
    class ViManager {
    public:
        
        static constexpr const size_t   ARG_COUNT   = sizeof...(Args);
        using v_ptr_t           = Ref<V>;
        using v_cptr_t          = Ref<const V>;
        using map_t             = std::unordered_map<uint64_t, v_cptr_t>;
        using mutex_t           = tbb::spin_rw_mutex;
        using data_t            = std::tuple<Args...>;
        
        ViManager(ViVisualizer& viz) : m_viz(viz) {}

        ViManager(ViVisualizer& viz, data_t dat) : m_viz(viz), m_data(dat) 
        {
        }

        ~ViManager()
        {
            m_hash.clear();
        }
    
        void        clear()
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_hash.clear();
        }
        
        template <unsigned... Is>
        v_cptr_t    _create(const A& asset)
        {
            return new V(m_viz, asset, get<Is, Args...>(m_data)...);
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
            
            if constexpr (sizeof...(Args) != 0){
                p       = _create<indices_gen<ARG_COUNT>()>(asset);
            }
            
            if constexpr (sizeof...(Args) == 0){
                p       = new V(m_viz, asset);
            }
            
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
        
        bool            empty() const
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.empty();
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
        
        size_t          size() const 
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            return m_hash.size();
        }
        
        void            update(Args...args)
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            m_data      = { args... };
        }

    private:
        ViManager(const ViManager&) = delete;
        ViManager(ViManager&&) = delete;
        ViManager& operator=(const ViManager&) = delete;
        ViManager& operator=(ViManager&&) = delete;
        
        ViVisualizer&       m_viz;
        map_t               m_hash;
        mutable mutex_t     m_mutex;
        data_t              m_data;
    };
}

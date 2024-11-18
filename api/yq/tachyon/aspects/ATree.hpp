////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interfaces/ITree.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ATree : public ITree {
    public:
    
        TachyonID   parent() const override;
        Tachyon*    parent(ptr_t) const { return m_parent; }
        
    protected:
        virtual ~ATree(){}
        ATree() {}
    
        Tachyon*                    m_parent        = nullptr;
        std::vector<Tachyon*>       m_childrenPtrs;
        std::vector<TachyonID>      m_childrenID;
    };
    
    template <SomeTachyon T>
    class CTree : public ATree {
    public:
        T*                      parent(ptr_t) const { return m_parent; }
        std::vector<Ref<T>>     children(ptr_t) const { return m_children; }
    
    protected:
        T*                      m_parent;
        std::vector<Ref<T>>     m_childrenRef;
    };
    
    
}


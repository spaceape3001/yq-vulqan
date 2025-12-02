////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/builder.hpp>
#include <vector>

namespace yq::tachyon {
    class Save;
    
    class Builder : public virtual RefCount {
    public:
    
        struct SaveAPI; // may or may not go here....
        struct LoadAPI; // may or may not go here....
    
        Builder(Builder* parent=nullptr);
        virtual ~Builder();
        
        Builder*            parent() { return m_parent; }
        const Builder*      parent() const { return m_parent; }
        
    private:
        Builder*                    m_parent = nullptr;
        std::vector<BuilderCPtr>    m_children;
    };

}

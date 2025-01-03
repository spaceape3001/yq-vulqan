////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/model.hpp>

namespace yq::tachyon {
    class Model;

    //! Utiltity to bind a viewer to the whatever...
    class ModelBind {
    public:
        ModelID    model() const { return m_model; }
        
    protected:
        ModelBind(ModelID v) : m_model(v) {}
        ModelBind(const Model* v);
        virtual ~ModelBind() {}
        
        ModelID const m_model;
    };
}

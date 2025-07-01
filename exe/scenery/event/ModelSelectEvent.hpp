////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/model.hpp>

using namespace yq;
using namespace yq::tachyon;

class ModelSelectEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(ModelSelectEvent, EditorEvent)
public:
    ModelSelectEvent(const Header&, ModelID);
    ModelSelectEvent(const ModelSelectEvent&, const Header&);
    ~ModelSelectEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    ModelID        model() const { return m_model; }
    static void init_meta();
private:
    ModelID        m_model;
};
